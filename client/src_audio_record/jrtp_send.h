#ifndef JRTP_SEND_H
#define JRTP_SEND_H

#include "БъЭЗ.h"
using namespace jrtplib;
class jrtp_send : public QObject
{
	Q_OBJECT

public:
	jrtp_send(QObject *parent, QString, QString);
	void set_ip_port(QString ip, QString port);
	static RTPSession* return_rtp_send_session();
	void set_ip(QString);
	void set_port(QString);
	~jrtp_send();

private:
	RTPSession *sess;
	RTPUDPv4TransmissionParams transparams;
	RTPSessionParams sessparams;
	bool is_ok = false;
	int Count;

	//QByteArray buffer_tx;
	int first;
	QString ip, port;
};

#endif // JRTP_SEND_H
