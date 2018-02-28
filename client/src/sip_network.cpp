#include "sip_network.h"
#include "sip_client.h"
#include "callback.h"
#include <stdio.h>
#include <qmessagebox.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <sys/types.h>
#include <qtimer.h>
static sip_network *network_sip;
static char* audio_sdp_text, *video_sdp_text;
# pragma execution_character_set("utf-8")
char*& sip_network::return_audio_sdp_text()
{
	return audio_sdp_text;
}
char*& sip_network::return_video_sdp_text()
{
	return video_sdp_text;
}
sip_network::sip_network(QObject *parent)
	: QThread(parent)
{
	time = new QTimer;
	//临时赋值
	port_audio = "6000";
	audio_sdp_text = new char[4096];
	memset(audio_sdp_text, 0, 4096);
	video_sdp_text = new char[4096];
	memset(video_sdp_text, 0, 4096);
	connect(this, SIGNAL(start_time_register()), this, SLOT(slot_time_start()));
	connect(time, SIGNAL(timeout()), this, SLOT(register_time_out()));
	connect(this, SIGNAL(success_information(QString)), sip_client::return_sip_client(), SLOT(successful_infortation(QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(failure_information(QString)), sip_client::return_sip_client(), SLOT(wrong_infortation(QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(register_state(int)), sip_client::return_sip_client(), SLOT(register_state_(int)), Qt::QueuedConnection);
	network_sip = this;
	getlocaladdress();
	Callback *call = new Callback;
}
void sip_network::register_successful(QString)
{
	time->stop();
}
void sip_network::slot_time_start()
{
	time->start(10000);
	emit register_state(1);
}
void sip_network::register_time_out()
{
	QMessageBox::warning(NULL, "警告", "注册失败");
	time->stop();
	
}
void sip_network::getlocaladdress()
{
	hostent *temp_source_detail;
	char temp_name[50] = { '\0' };
	gethostname(temp_name, 50);
	temp_source_detail = gethostbyname(temp_name);
	struct in_addr *addr = (struct in_addr*)temp_source_detail->h_addr;
	source_address = inet_ntoa((*addr));
}
void sip_network::register_request()
{
	int retVal;
	eXosip_lock();
	regid = eXosip_register_build_initial_register(source_str.toStdString().data(), dest_str.toStdString().data(), nullptr, 100, &message);
	if (regid < 0)
	{
		emit failure_information("初始化注册信息失败");
	}
	retVal = eXosip_register_send_register(regid, message);
	if (retVal != 0)
	{
		emit failure_information("发送注册信息失败");
	}
	eXosip_unlock();
}
void sip_network::send_message(QString id, QString text)
{
	QString dest = "sip:" + id + "@" + domain + ":5062";
	osip_message_t *message = nullptr;
	eXosip_message_build_request(&message, "MESSAGE", dest.toStdString().data(), source_str.toStdString().data(), nullptr);
	osip_message_set_body(message, text.toStdString().data(), text.size());
	osip_message_set_content_type(message, "text/xml");
	eXosip_message_send_request(message);
}
void sip_network::build_audio_text()
{

	snprintf(audio_sdp_text, 4096,
		"v=0\r\n"                           // SDP版本  
		"o=josua 0 0 IN IP4 %s\r\n"         // 用户名、ID、版本、网络类型、地址类型、IP地址  
		"s=conversation\r\n"                // 会话名称  
		"c=IN IP4 %s\r\n"
		"t=0 0\r\n"                         // 开始时间、结束时间。此处不需要设置  
		"m=audio %s RTP/AVP 0 8 101\r\n"    // 音频、传输端口、传输类型、格式列表  
		"a=rtpmap:18 G729a/8000\r\n"          // 以下为具体描述格式列表中的  
		"a=rtpmap:8 PCMA/8000\r\n"
		"a=rtpmap:101 telephone-event/8000\r\n"
		"a=fmtp:101 0-11\r\n", source_address.data(), source_address.data(), port_audio.toLocal8Bit().data());
}
void sip_network::build_video_text()
{

}
void sip_network::invite_request(QString str, bool video)
{
	QString dt = "sip:" + str + "@" + domain + ":5062";
	osip_message_t *invite = nullptr;
	void *ference;
	int i = eXosip_call_build_initial_invite(&invite, dt.toStdString().data(), source_str.toStdString().data(), nullptr, "This is a call for a conversation");
	if (i != 0)
	{
		return ;
	}
	osip_message_set_supported(invite, "100rel");
	if (!video)
	{
		build_audio_text();
		osip_message_set_body(invite, audio_sdp_text, strlen(audio_sdp_text));
	}
	osip_message_set_content_type(invite, "application/sdp");
	eXosip_lock();
	id_call = eXosip_call_send_initial_invite(invite); // 发送INVITE请求  
	if (id_call > 0)
	{
		//eXosip_call_set_reference(i, ference);

	}

	eXosip_unlock();
}
sip_network *&sip_network::return_sip_network()
{
	return network_sip;
}
void sip_network::register_leave()
{
	eXosip_lock();
	osip_message_t *reg;
	eXosip_register_build_register(regid, 0, &reg);
	eXosip_register_send_register(regid, reg);
	eXosip_unlock();
}
void sip_network::set_detail(QString _id, QString _domain, QString _passwd, QString port_name_, QString _authoration_name)
{
	id = _id;
	authorization_id = _authoration_name;
	port_name = port_name_;
	passwd = _passwd;
	domain = _domain;
	this->start();
}
sip_network::~sip_network()
{

}
void sip_network::run()
{
	source_str = "sip:" + id + "@" + source_address + ":" + port_name;
	dest_str = "sip:" + id + "@" + domain + ":5062";
	listening();
}
void sip_network::get_source_dest_str(QString &str_source, QString &dest_source)
{
	str_source = source_str;
	dest_source = source_str;
	
}
void sip_network::init_subscr()
{
	osip_message_t *subscribe;
	int t = eXosip_init();

	t = eXosip_listen_addr(IPPROTO_UDP, nullptr, 5063, AF_INET, 0);
	if (eXosip_subscribe_build_initial_request(&subscribe, "sip:321@127.0.0.1:5061", "sip:1221@127.0.0.1:5062", NULL, "presence.winfo", 3600))
	{
		//	AfxMessageBox("UCTIMSCLIENT: Error building presence.winfo subscribe message. Probably an invalid URI.\n");
		eXosip_unlock();
		return ;
	}
	eXosip_lock();
	int i = eXosip_subscribe_send_initial_request(subscribe);
	eXosip_unlock();
}
void sip_network::get_source_dest_address(QString& str_address, QString&passwd_, QString &domain_)
{
	if (authorization_id.isEmpty() || authorization_id.isNull())
	{
		str_address = id;
	}
	else
	{
		str_address = authorization_id;
	}
	passwd_ = passwd;
	domain_ = domain;
}
void sip_network::listening()
{
	int i = eXosip_init();
	if (i != 0)
	{
		//提出警告
		return ;
	}
	
	i = eXosip_listen_addr(IPPROTO_UDP, nullptr, 5061, AF_INET, 0);
	if (i != 0)
	{
		eXosip_quit();
		//提出警告
		fprintf(stderr, "Couldn't initialize transport layer!\n");
		return ;
	}
	register_request();
	emit start_time_register();
	while (1)
	{
		event = eXosip_event_wait(0, 200);
		eXosip_lock();
		eXosip_automatic_refresh();
		eXosip_default_action(event);
		eXosip_unlock();
		if (event == nullptr) continue;
		Callback::return_callback()->onProtobufMessage(event);
	}
}
