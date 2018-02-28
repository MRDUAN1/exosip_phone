#include "callback.h"
#include "sql_.h"
#include <qdebug.h>
#include "server_third_new.h"
#include "md5_cacluate.h"
#include "handle_information.h"
#include "global_.h"
#include <sstream>
#include <string>
#include <sstream>
using std::string;
//该系数是由UAS维护的，UAS在接收到UAC的未鉴权报文后，给UAC回复401，在该报文中必须要带相关认证系数和认证方法
//UAS赋值的认证随机数
//UAS默认加密算法
#define ALGORITHTHM "MD5"
static QMap<QString, eXosip_event_t *>id_event;
Callback::Callback(QObject *parent)
	: QObject(parent)
{
	//call_back_ = this;
	sql_ *sql = new sql_(0);
	Callback *temp = this;
	global_::set_callback(temp);
	sql->set_information(global_::return_information());
	defaultCallback_ = default_name;
	//connect(this, SIGNAL(client_information_signal(handle_information*)), )
	connect(this, SIGNAL(warning_information(QString)), server_third_new::return_server(), SLOT(warning_information(QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(quit_information(QString)), server_third_new::return_server(), SLOT(leave_information(QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(client_information_signal(handle_information*)), server_third_new::return_server(), SLOT(status_information_(handle_information*)), Qt::QueuedConnection);
	this->registerMessageCallback(EXOSIP_REGISTRATION_NEW, handle_register_request);
	this->registerMessageCallback(EXOSIP_MESSAGE_NEW, handle_message_new);
	this->registerMessageCallback(EXOSIP_REGISTRATION_REFRESHED, handle_register_refersh);
	this->registerMessageCallback(EXOSIP_CALL_RELEASED, handle_cancel);
	this->registerMessageCallback(EXOSIP_CALL_CANCELLED, handle_ggg);
//	this->registerMessageCallback(EXOSIP_CALL_CANCELLED, handle_ggg);
	//this->registerMessageCallback(EXOSIP_REGISTRATION_TERMINATED, handle_register_failure);
	this->registerMessageCallback(EXOSIP_CALL_INVITE, handle_new_invite);
	this->registerMessageCallback(EXOSIP_CALL_ANSWERED, handle_call_answer);
	this->registerMessageCallback(EXOSIP_CALL_RINGING, handle_riging);
	this->registerMessageCallback(EXOSIP_IN_SUBSCRIPTION_NEW, handle_new_subscr);
	this->registerMessageCallback(EXOSIP_IN_SUBSCRIPTION_NEW, handle_new_subscr);
	this->registerMessageCallback(EXOSIP_IN_SUBSCRIPTION_NEW, handle_new_subscr);
	this->registerMessageCallback(EXOSIP_CALL_CLOSED, handle_cancle_close);
	//this->registerMessageCallback(EXOSIP_CALL_CANCELLED
	//this->registerMessageCallback(EXOSIP_CALL_RINGING, handle_riging);
}
int Callback::handle_ggg(eXosip_event_t *)
{
	exit(0);
}
int Callback::handle_cancle_close(eXosip_event_t *message)
{
	if (id_event.find(message->request->from->url->username) == id_event.end())
	{
		return 1;
	}
	int cid = id_event[message->request->from->url->username]->cid;
	int did = id_event[message->request->from->url->username]->did;
	int y = eXosip_call_terminate(cid, did);
	return 1;
}
int Callback::handle_cancel(eXosip_event_t *event)
{
	/*if (id_event.find(event->request->from->url->username) == id_event.end())
	{
		return 1;
	}
	eXosip_call_terminate(id_event[event->request->from->url->username]->cid, id_event[event->request->from->url->username]->did);*/
	return 1;
}
int Callback::handle_call_answer(eXosip_event_t *message)
{
	osip_message_t *ack_message = NULL;
	eXosip_call_build_ack(message->did, &ack_message);
	eXosip_call_send_ack(message->did, ack_message);
	if (id_event.find(message->request->from->url->username) == id_event.end())
	{
		return 1;
	}
	osip_message_t *answer_message = NULL;
	eXosip_call_build_answer(id_event[message->request->from->url->username]->tid, 200, &answer_message);
	int i = eXosip_call_send_answer(id_event[message->request->from->url->username]->tid, 200, answer_message);
	return 1;
}
int Callback::handle_new_subscr(eXosip_event_t *event)
{
	osip_header_t *event_header = NULL;

	if (!osip_message_header_get_byname(event->request, "Event", 0, &event_header))

	{
		fprintf(stderr, "UCTIMSCLIENT: Received unknown NOTIFY message\n");
		return 1;
	}
	return 1;
}
/*handle_information *&Callback::return_detail_information(eXosip_event_t * message)
{
	
	string source_usename = message->request->to->url->username;
	if (global_::return_login_information().find(source_usename) == global_::return_login_information().end())
	{
		return NULL;
	}
	return global_::return_login_information()[source_usename];
}*/
int Callback::handle_riging(eXosip_event_t *message)
{
	string source_usename = message->request->to->url->username;
	//handle_information* handle = return_detail_information(message);
	if (global_::return_login_information().find(source_usename) == global_::return_login_information().end())
	{
		return 1;
	}
	handle_information* handle = global_::return_login_information()[source_usename];
	eXosip_event_t *exoisp_invite = NULL;
	handle->get_message_invite(exoisp_invite);
	osip_message_t *messages;
	eXosip_call_build_answer(handle->get_message_tid(), 180, &messages);
	messages->from->url->username = message->request->from->url->username;
	int i = eXosip_call_send_answer(handle->get_message_tid(), 180, messages);
	//eXosip_event_t *event;
	//handle->get_message_invite(event);
	//int t = eXosip_call_terminate(event->cid, event->did);
	return 1;
}
int Callback::handle_message_new(eXosip_event_t *message)
{
	if (!MSG_IS_MESSAGE(message->request))//如果接受到的消息类型是MESSAGE
	{
		handle_register_request(message);
	}
	else
	{
		osip_body_t *body;
		osip_message_t *answer;
		QString str = message->request->req_uri->username;
		if (global_::return_login_information().find(str.toStdString()) == global_::return_login_information().end())
		{
			eXosip_lock();
			int i = eXosip_message_build_answer(message->tid, 480, &answer);
			if (i == 0)
			{
				i = eXosip_message_send_answer(message->tid, 480, answer);
			}
			eXosip_unlock();
			answer = nullptr;
		}
		else
		{
			osip_body_t *answ;
			osip_message_get_body(message->request, 0, &answ);
			handle_information* infor = global_::return_login_information()[str.toStdString()];
			string port;
			infor->get_port(port);
			string domain = message->request->req_uri->host;
			string usename = message->request->req_uri->username;
			string sip_use = "sip:" + usename + "@" + domain + ":" + port;
			string domain_source = message->request->from->url->host;
			string usename_source = message->request->from->url->username;
			string port_source = message->request->from->url->port;
			string source = "sip:" + usename_source + "@" + domain_source + ":" + port_source;
			osip_message_t *message = nullptr;
			int i = eXosip_message_build_request(&message, "MESSAGE", sip_use.data(), source.data(), nullptr);
			i = osip_message_set_body(message, answ->body, answ->length);
			i = osip_message_set_content_type(message, "text/xml");
			i = eXosip_message_send_request(message);
		}
	}
	return 1;
}
int Callback::default_name(eXosip_event_t *message)
{
	emit global_::return_callback()->warning_information("没有找到对应类型信息的处理函数");
	return 1;
}
int Callback::handle_register_refersh(eXosip_event_t *message)
{
	string usename = message->request->from->url->username;
	return 1;
}
int Callback::handle_new_invite(eXosip_event_t *message)
{
	//即使覆盖也没有关系
	
	osip_message_t *answer;
	
	osip_proxy_authorization_t* authentication = NULL;
	osip_message_get_proxy_authorization(message->request, 0, &authentication);
	//没有鉴权的数据包
	if (NULL == authentication)
	{
		sdp_message_t * sdp = eXosip_get_remote_sdp(message->did);
		sdp_media_t *video_media = eXosip_get_video_media(sdp);
		sdp_media_t *audio_media = eXosip_get_audio_media(sdp);
		sdp_connection_t *rt = eXosip_get_audio_connection(sdp);
		int pos = 0;
		while (!osip_list_eol(&(audio_media->a_attributes), pos))
		{
			sdp_attribute_t *at;
			at = (sdp_attribute_t *)osip_list_get(&(audio_media->a_attributes), pos);
			//printf("%s : %s/n", at->a_att_field, at->a_att_value);//这里解释了为什么在SDP消息体中属性a里面存放必须是两列 
			string att = at->a_att_field;
			string attt = at->a_att_value;
			pos++;
		}
		make_authoration(message, 407);
	}
	else
	{
		test_authoration(message, 407);
	}
	return 1;
}
Callback*& Callback::return_callback()
{
	return global_::return_callback();
}
int Callback::handle_register_request(eXosip_event_t * message)
{
	register_prase(message);
	return 1;
}
void Callback::get_expire(eXosip_event_t *message, int& expire)
{

}
//realm默认设置为000
void Callback::register_prase(eXosip_event_t *message)
{
	osip_authorization_t* authentication = NULL;
	osip_message_t *request = message->request;
	int tid = message->tid;
	std::string username = request->from->url->username;
	osip_message_get_authorization(request, 0, &authentication);
	//没有鉴权的数据包
	if (NULL == authentication)
	{
		make_authoration(message, 401);
	}
	//带鉴权的数据包
	else
	{
		test_authoration(message, 401);
	}
}
//realm默认设置为000
void Callback::make_authoration(eXosip_event_t *message, int status_code)
{
	int result;
	handle_information *handle;
	osip_message_t* answer = NULL;
	if (status_code == 407)
	{
		result = ::eXosip_call_build_answer(message->tid,
			status_code, &answer);
	}
	else
	{
		result = ::eXosip_message_build_answer(message->tid,
			status_code, &answer);
	}
	
	//由SIP库生成认证方法和认证参数发送客户端
	std::stringstream stream;
	string algorithm = ALGORITHTHM;
	string nonce = cacluate_nonce();
	if (global_::return_information().find(message->request->from->url->username) == global_::return_information().end())
	{
		handle = new handle_information(0);
		global_::return_information().insert(std::make_pair(message->request->from->url->username, handle));
	}
	else
	{
		handle = global_::return_information()[message->request->from->url->username];
	}
	handle->set_nonce(nonce);
	stream << "Digest realm=\"" << "000"
		<< "\",nonce=\"" << nonce
		<< "\",algorithm=" << algorithm;
	qDebug() << stream.str().c_str();
	if (status_code == 401)
	{
		result = osip_message_set_header(answer, "WWW-Authenticate",
			stream.str().c_str());
	}
	else
	{
		result = osip_message_set_header(answer, "Proxy-Authenticate",
			stream.str().c_str());
	}
	
		//发送消息体
	if (status_code == 407)
	{
		result = ::eXosip_call_send_answer(message->tid, status_code,
			answer);
	}
	else
	{
		result = ::eXosip_message_send_answer(message->tid, status_code,
			answer);
	}
}
void Callback::test_authoration(eXosip_event_t *message, int status)
{
	int value;
	osip_proxy_authorization_t* authentication_proxy = NULL;
	osip_authorization_t* authentication_register = NULL;
	if (status == 407)
	{
		osip_message_get_proxy_authorization(message->request, 0, &authentication_proxy);
	}
	else if (status == 401)
	{
		osip_message_get_authorization(message->request, 0, &authentication_register);
	}
	osip_message_t *request = message->request;
	std::string username = request->from->url->username;
	//osip_message_get_authorization(request, 0, &authentication);
	if (global_::return_information().find(username) == global_::return_information().end())
	{
		handle_information *handle = new handle_information(0);
		global_::return_information().insert(std::make_pair(username, handle));
	}
	else
	{
		string uri;
		if (status == 407)
		{
			uri = authentication_proxy->uri;
		}
		else if (status == 401)
		{
			uri = authentication_register->uri;
		}
		uri = uri.substr(1, uri.size() - 2);
		string use, passwd, nonce;
		handle_information *infor = global_::return_information()[username];
		infor->get_authoration(use, passwd);
		HASHHEX hash1, hash2;
		infor->get_authoration(use, passwd);
		infor->get_nonce(nonce);
		DigestCalcHA1(0, message->request->from->url->username, "000", passwd.data(), 0, 0, hash1);
		string str_response;
		if (status == 407)
		{
			DigestCalcResponse(hash1, nonce.data(), NULL, NULL, NULL, 0, "INVITE", uri.data(), NULL, hash2);
			str_response = authentication_proxy->response;
		}
		else if (status == 401)
		{
			DigestCalcResponse(hash1, nonce.data(), NULL, NULL, NULL, 0, "REGISTER", uri.data(), NULL, hash2);
			str_response = authentication_register->response;
		}
		str_response = str_response.substr(1, str_response.size() - 2);
		if (!strcmp(str_response.data(), hash2))
		{
			osip_message_t* answer = NULL;
			if (status == 407)
			{
				string usename = message->request->req_uri->username;
				if (global_::return_login_information().find(usename) == global_::return_login_information().end())
				{
					::eXosip_call_send_answer(message->tid, 404,
						answer);
				}
				else
				{
					handle_information *hand = global_::return_login_information()[usename];
					construct_invite(message, hand);
				}
			}
			else if (status == 401)
			{
				string port = message->request->from->url->port;
				infor->set_port(port);
				string host = message->request->from->url->host;
				infor->set_host(host);
				global_::return_login_information().insert(std::make_pair(message->request->from->url->username, infor));
				osip_message_t* answer = NULL;
				int result = ::eXosip_message_build_answer(message->tid,
					200, &answer);
				osip_message_set_header(answer, "Contact",
					uri.data());
				::eXosip_message_send_answer(message->tid, 200,
					answer);
				osip_header_t* header = NULL;
				osip_message_header_get_byname(message->request, "expires",
					0, &header);
				if (NULL != header && NULL != header->hvalue)
				{
					value = atoi(header->hvalue);
					infor->set_status(login_successful);
					infor->set_value(value);
				}
				else if (NULL != header && NULL == header->hvalue)
				{
					eXosip_register_remove(message->tid);
					infor->set_value(0);
					infor->set_status(leave_successful);
					emit global_::return_callback()->quit_information(QString::fromStdString(use));
					global_::return_login_information().erase(string(message->request->from->url->username));
				}
				emit global_::return_callback()->client_information_signal(infor);
			}
		}
		else
		{
			//osip_message_t* answer = NULL;
			//osip_message_set_header(answer, "Contact",
			//	uri.data());
			
			//::eXosip_message_send_answer(message->tid, 403,
			//	answer);
			return;
		}
	}
}
//handle为目标地址的用户名称
void Callback::construct_invite(eXosip_event_t *message, handle_information* handle)
{
	
	id_event[message->request->from->url->username] = message;
	//eXosip_call_terminate(message->cid, message->did);
	//exit(0);
	handle->set_message_invite(message);
	handle->set_message_tid(message->tid);
	string dest_port, dest_host, dest_uri_usename;
	string source_port, source_host, souce_username;
	string sdp_str;
	dest_uri_usename = message->request->req_uri->username;
	handle->get_host(dest_host);
	handle->get_port(dest_port);
	souce_username = message->request->from->url->username;
	source_host = message->request->from->url->host;
	source_port = message->request->from->url->port;
	string source_url_name = "sip:" + souce_username + "@" + source_host + ":" + source_port;
	int pos = 0;
	sdp_message_t * sdp = eXosip_get_remote_sdp(message->did);
	char *mi;
	sdp_message_to_str(sdp, &mi);
	osip_message_t *invite = NULL;
	string dest_url_name = "sip:" + dest_uri_usename + "@" + dest_host + ":" + dest_port;
	int i = eXosip_call_build_initial_invite(&invite, dest_url_name.data(), source_url_name.data(), NULL, "This is a call for a conversation");
	osip_message_set_body(invite, mi, strlen(mi) + 1);
	osip_message_set_content_type(invite, "application/sdp");
	i = eXosip_call_send_initial_invite(invite); // 发送INVITE请求  
	
	//exit(0);
	if (i > 0)
	{
		//eXosip_call_set_reference(i, ference);

	}
	printf("hhhhh");
}
Callback::~Callback()
{

}

