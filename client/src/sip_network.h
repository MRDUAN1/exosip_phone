#ifndef SIP_NETWORK_H
#define SIP_NETWORK_H

#include <QThread>
#include <eXosip2/eXosip.h>
#include <osip2/osip_mt.h>
#include <qtimer.h>
class sip_network : public QThread
{
	Q_OBJECT

public:
	static sip_network *&return_sip_network();
	static char*& return_audio_sdp_text();
	static char*& return_video_sdp_text();
	sip_network(QObject *parent);
	void register_request();
	void send_message(QString id, QString text);
	void invite_request(QString str, bool video = false);
	void get_source_dest_str(QString &, QString&);
	void get_source_dest_address(QString&, QString&, QString&);
	void init_subscr();
	~sip_network();
	public slots:
	void slot_time_start();
	void register_time_out();
	void register_leave();
	void register_successful(QString);
	void set_detail(QString _id, QString _domain, QString _passwd, QString port_name, QString _authoration_name);
protected:
	void run();

private:
	QString port_audio, port_video;
	void build_audio_text();
	void build_video_text();
	int regid;
	QTimer *time;
	QString id, authorization_id, port_name, passwd, domain;
	QString source_str, dest_str;
	QString source_address;
	int type;
	int id_call;
	eXosip_event_t *event = nullptr;
	osip_message_t *message = nullptr;
	void listening();
	void getlocaladdress();
signals:
	void success_information(QString);
	void failure_information(QString);
	void start_time_register();
	void register_state(int);
};

#endif // SIP_NETWORK_H
