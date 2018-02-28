#include "global_header.h"
#include "callback.h"
#include "sip_network.h"
#include "sip_client.h"
#include "chat_intetface.h"
#include <memory>
#include <qmessagebox.h>
#include <string>
#include <qfile.h>
#include <qdebug.h>
#include <Windows.h>
using std::string;
static Callback *call_back_;
static bool if_success_register = false;
# pragma execution_character_set("utf-8")
Callback::Callback(QObject *parent)
	: QObject(parent)
{
	call_back_ = this;
	qRegisterMetaType<eXosip_event_t>("eXosip_event_t");
	connect(this, SIGNAL(subject_call(eXosip_event_t*)), sip_client::return_sip_client(), SLOT(call_subject(eXosip_event_t*)));
	connect(this, SIGNAL(passive_call(eXosip_event_t*)), sip_client::return_sip_client(), SLOT(call_passive(eXosip_event_t*)));
	connect(this, SIGNAL(message_com(QString, QString)), chat_intetface::return_chat_interface(), SLOT(insert_class(QString, QString)));
	connect(this, SIGNAL(message_failure(QString)), sip_client::return_sip_client(), SLOT(warn_information(QString)));
	connect(this, SIGNAL(status_invite(QString, int)), sip_client::return_sip_client(), SLOT(invite_status(QString, int)), Qt::QueuedConnection);
	connect(this, SIGNAL(success_information(QString)), sip_client::return_sip_client(), SLOT(successful_infortation(QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(failure_information(QString)), sip_client::return_sip_client(), SLOT(wrong_infortation(QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(success_register(QString)), sip_client::return_sip_client(), SLOT(register_successful(QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(success_register(QString)), sip_network::return_sip_network(), SLOT(register_successful(QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(failure_register(QString)), sip_network::return_sip_network(), SLOT(register_successful(QString)), Qt::QueuedConnection); //槽函数让计时器停止
	connect(this, SIGNAL(failure_register(QString)), sip_client::return_sip_client(), SLOT(register_successful(QString)), Qt::QueuedConnection); //槽函数让计时器停止
	this->registerMessageCallback(EXOSIP_REGISTRATION_NEW, handle_register_request);
	this->registerMessageCallback(EXOSIP_REGISTRATION_SUCCESS, handle_register_success);
	this->registerMessageCallback(EXOSIP_CALL_ANSWERED, handle_call_answer);
	this->registerMessageCallback(EXOSIP_REGISTRATION_FAILURE, handle_register_failure);
	this->registerMessageCallback(EXOSIP_MESSAGE_NEW, handle_new_message);
	this->registerMessageCallback(EXOSIP_CALL_PROCEEDING, handle_invite_proceeding);
	this->registerMessageCallback(EXOSIP_CALL_REQUESTFAILURE, handle_register_failure);
	this->registerMessageCallback(EXOSIP_CALL_INVITE, handle_invite_new);
	this->registerMessageCallback(EXOSIP_CALL_RINGING, handle_riging);
	this->registerMessageCallback(EXOSIP_MESSAGE_REQUESTFAILURE, handle_message_failure);
//	this->registerMessageCallback(EXOSIP_CALL_ANSWERED, handle_call_answer);
	//this->registerMessageCallback()
	defaultCallback_ = unknown;
}
int Callback::handle_call_answer(eXosip_event_t *message)
{
	osip_message_t *ack_message = NULL;
	eXosip_call_build_ack(message->did, &ack_message);
	eXosip_call_send_ack(message->did, ack_message);
	
	return 1;
}
int Callback::handle_message_failure(eXosip_event_t *message)
{
	osip_message_t *mes = nullptr;
	if (message->response == nullptr)
	{
		mes = message->request;
	}
	else
	{
		mes = message->response;

	}
	if (mes->status_code == 404 || mes->status_code == 480)
	{
		QString str = message->request->req_uri->username;
		QString sttr = str + ":该用户不在线或没有注册";
		emit call_back_->message_failure(sttr);
	}
	return 1;
}
int Callback::handle_riging(eXosip_event_t *message)
{
	//正在响铃代码错误
	//Sleep(5);
//	eXosip_call_terminate(message->cid, message->did);
	emit call_back_->subject_call(message);
	/*
	global_header::return_id_string()[message->request->req_uri->username] = message;
	osip_message_t *msg = message->request;
	sdp_message_t *t = eXosip_get_sdp_info(msg);
	osip_message_t *invite = nullptr;
	
	char *tmp = sip_network::return_audio_sdp_text();

	eXosip_call_build_ack(message->did, &invite);
	osip_message_set_body(invite, tmp, strlen(tmp));
	osip_message_set_content_type(invite, "application/sdp");
	//eXosip_call_build_answer(message->tid, 200, &invite);
	eXosip_call_send_ack(message->did, invite);*/
	//振铃的相应代码
	return 1;
}
int Callback::handle_invite_new(eXosip_event_t *message)
{
	eXosip_call_send_answer(message->tid, 180, NULL);
	emit call_back_->passive_call(message);
	/*char *sh = (new char[100]);
	osip_uri_to_str(message->request->req_uri, &sh);
	eXosip_call_send_answer(message->tid, 180, NULL);
	QMessageBox messagebox(QMessageBox::NoIcon, "电话呼叫", sh);
	QPushButton *accept = new QPushButton;
	accept->setFixedSize(70, 70);
	messagebox.addButton(accept, QMessageBox::AcceptRole);
	accept->setFlat(true);
	QPixmap pix("./image/tele_dialog_green.png");
	pix = pix.scaled(70, 70);
	accept->setIcon(pix);
	messagebox.exec();
	*/
	//return_audio_support_name
	string usename = message->request->req_uri->username;
	string audio_port, video_port;
	sdp_message_t * sdp = eXosip_get_remote_sdp(message->did);
	sdp_media_t *video_media = eXosip_get_video_media(sdp);
	sdp_media_t *audio_media = eXosip_get_audio_media(sdp);
	if (audio_media == nullptr)
	{
		audio_port = audio_media->m_port;
	}
	if (video_media == nullptr)
	{
		video_port = video_media->m_port;
	}
	Sleep(1000);
	sdp_connection_t *rt = eXosip_get_audio_connection(sdp);
	int pos = 0;
	string audio_name, video_name;
	while (!osip_list_eol(&(audio_media->a_attributes), pos))
	{
		sdp_attribute_t *at;
		at = (sdp_attribute_t *)osip_list_get(&(audio_media->a_attributes), pos);
		//printf("%s : %s/n", at->a_att_field, at->a_att_value);//这里解释了为什么在SDP消息体中属性a里面存放必须是两列 
		string att = at->a_att_field;
		string attt = at->a_att_value;
		audio_name = att + ":" + attt;
		//audio_name = parse_audio_support_name(attt);
		//if (!audio_name.empty())
			//break;
		if (!(std::find(global_header::return_audio_support_name().begin(), global_header::return_audio_support_name().end(), attt) == global_header::return_audio_support_name().end()))
		{
			break;
		}
		pos++;
	}
	pos = 0;
	if (!(video_media == nullptr))
	{
		while (!osip_list_eol(&(video_media->a_attributes), pos))
		{
			sdp_attribute_t *at;
			at = (sdp_attribute_t *)osip_list_get(&(audio_media->a_attributes), pos);
			//printf("%s : %s/n", at->a_att_field, at->a_att_value);//这里解释了为什么在SDP消息体中属性a里面存放必须是两列 
			string att = at->a_att_field;
			string attt = at->a_att_value;
			video_name = att + ":" +attt;
			if (!(std::find(global_header::return_audio_support_name().begin(), global_header::return_audio_support_name().end(), attt) == global_header::return_audio_support_name().end()))
			{
				break;
			}
			pos++;
		}
	}
	
	return 1;
}
string Callback::parse_audio_support_name(string name)
{
	int p = name.find(' ');
	string auio_name_ = name.substr(p, name.size());
	int p1 = auio_name_.find('/');
	string audio_name = auio_name_.substr(0, p1);
	return audio_name;
}
int Callback::unknown(eXosip_event_t *message)
{
	emit call_back_->failure_information("未知错误");
	return 1;
}
int Callback::handle_invite_proceeding(eXosip_event_t *message)
{
	qDebug() << "正在处理中";
	return 1;
}
Callback*& Callback::return_callback()
{
	return call_back_;
}
int Callback::handle_new_message(eXosip_event_t *message)
{
	osip_message_t *answer = nullptr;
	osip_body_t *body = nullptr;
	QString username = message->request->from->url->username;
	osip_message_get_body(message->request, 0, &body);
	QString message_text = body->body;
	emit call_back_->message_com(username, message_text);
	eXosip_message_build_answer(message->tid, 200, &answer);
	eXosip_message_send_answer(message->tid, 200, answer);
	return 1;
}
int Callback::handle_register_request(eXosip_event_t * message)
{
	return 1;
}
int Callback::handle_register_success(eXosip_event_t * message)
{
	if (if_success_register)
		return 1;
	if_success_register = true;
	emit call_back_->success_register("注册成功");
	return 1;
}
//401代表注册需要认证，407代表invite需要认证
int Callback::handle_register_failure(eXosip_event_t * message)
{
	int i;
	if (!message->response)
	{
		return 1;
	}
	if (401 == message->response->status_code || 407 == message->response->status_code)
	{
		osip_message_t *reg = nullptr;
		eXosip_lock();
		QString id, passwd, domain;
		sip_network::return_sip_network()->get_source_dest_address(id, passwd, domain);
		eXosip_clear_authentication_info(); // 清空认证信息        
		eXosip_add_authentication_info(id.toStdString().data(), id.toStdString().data(), passwd.toStdString().data(), "md5", NULL); // 添加认证信息  
		if (401 == message->response->status_code)
		{
			Sleep(1000);
			int uu = eXosip_register_build_register(message->rid, 10, &reg);
			uu = eXosip_register_send_register(message->rid, reg); // 发送注册请求
		}
		else
		{
			//sip_network::return_sip_network()->invite_request("112");
			i = eXosip_call_build_request(message->did, "INFO", &reg);
			//eXosip_call_send_ack(message->did, reg); // 发送注册请求
			//eXosip_call_build_update(message->did, &reg);
			i = eXosip_call_send_request(message->did, reg);
		}  
		eXosip_unlock();
	}
	else if (403 == message->response->status_code)
	{
		//发射密码或账号错误的信号
		emit call_back_->failure_register("jjj");
	}
	else if (404 == message->response->status_code)
	{
		emit call_back_->failure_information("号码查找失败");
		emit call_back_->status_invite(message->response->to->url->username,1);
	}
	return 1;
}
Callback::~Callback()
{

}

