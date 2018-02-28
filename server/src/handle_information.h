#ifndef HANDLE_INFORMATION_H
#define HANDLE_INFORMATION_H

#include <QObject>
#include <string>
#include <qtimer.h>
#include <eXosip2/eXosip.h>
#include "global_.h"
using std::string;

class handle_information : public QObject
{
	Q_OBJECT

public:
	handle_information(QObject *parent = 0, string usename_ = 0, string passwd_ = 0);
	~handle_information();
	void set_information(string, string);
	void set_timer_start(int);
	string return_string();
	void set_stop();
	void get_authoration(string&, string&);
	void set_nonce(string);
	void get_nonce(string&);
	void set_port(string);
	void get_port(string&);
	void set_host(string&);
	void get_host(string&);
	void set_status(infor);
	infor return_status();
	void set_value(int);
	int return_value();
	void set_message_invite(eXosip_event_t *&);
	void get_message_invite(eXosip_event_t *&);
	void handle_information::set_message_tid(int i);
	int handle_information::get_message_tid();
	void set_calling_name(QString);
	QString return_call_name();
private:
	//该名字是为了当服务器给客户端返回180时，不携带发送方任何信息，该信息为了保存发送信息
	QString calling_name;
	int tid;
	int value; //注册时间
	infor status;
	eXosip_event_t *message_invite_from, *to;
	string host;
	string port;
	string nonce;
	QTimer *time_register;
	string usename;
	string passwd;
	bool is_online;
	string display_name;
	private slots:
	void time_out();
	
signals:
	void emit_leave(handle_information*);
	void emit_start(QString);
	
	
};

#endif // HANDLE_INFORMATION_H
