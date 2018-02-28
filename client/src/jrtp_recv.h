#ifndef JRTP_RECV_H
#define JRTP_RECV_H

#include <QObject>

class jrtp_recv : public QObject
{
	Q_OBJECT

public:
	jrtp_recv(QObject *parent);
	~jrtp_recv();
	void set_ip(QString);
	void set_port(QString);
	void set_ip_port(QString ip_, QString port_);
private:

	QString ip, port;
};

#endif // JRTP_RECV_H
