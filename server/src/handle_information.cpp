#include "handle_information.h"
#include "server_third_new.h"
#include <eXosip2/eXosip.h>
handle_information::handle_information(QObject *parent, string usename_, string passwd_)
	: QObject(parent)
{
	time_register = new QTimer;
	usename = usename_;
	passwd = passwd_;
	connect(this, SIGNAL(emit_leave(handle_information*)), server_third_new::return_server(), SLOT(status_information_(handle_information*)));
	connect(time_register, SIGNAL(timeout()), this, SLOT(time_out()));
}
void handle_information::set_value(int i)
{
	value = i;
}
int handle_information::return_value()
{
	return value;
}
void handle_information::set_nonce(string str)
{
	nonce = str;
}
void handle_information::get_nonce(string& str)
{
	str = nonce;
}
void handle_information::set_timer_start(int value)
{
	value = value * 1000 + 30;
	time_register->start(value);
}
void handle_information::get_authoration(string& str_usename, string& str_passwd)
{
	str_usename = usename;
	str_passwd = passwd;
}
void handle_information::time_out()
{
	is_online = false;
	value = 0;
	status = leave_successful;
	emit emit_leave(this);
}
void handle_information::set_information(string usename_, string passwd_)
{
	usename = usename_;
	passwd = passwd_;
}
void handle_information::set_stop()
{
	time_register->stop();
}
handle_information::~handle_information()
{

}
string handle_information::return_string()
{
	return usename;
}
void handle_information::set_status(infor i)
{
	status = i;
}
infor handle_information::return_status()
{
	return status;
}
void handle_information::get_port(string& port_)
{
	port_ = port;
}
void handle_information::set_port(string port_)
{
	port = port_;
}
void handle_information::set_host(string& str_host)
{
	host = str_host;
}
void handle_information::get_host(string& str_host)
{
	str_host = host;
}
void handle_information::set_message_invite(eXosip_event_t *&invite)
{
	message_invite_from = invite;
}
void handle_information::get_message_invite(eXosip_event_t *&invite)
{
	invite = message_invite_from;
}
void handle_information::set_message_tid(int i)
{
	tid = i;
}
void handle_information::set_calling_name(QString str)
{
	calling_name = str;
}
QString handle_information::return_call_name()
{
	return calling_name;
}
int handle_information::get_message_tid()
{
	return tid;
}

























