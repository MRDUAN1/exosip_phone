#include "jrtp_send.h"
#include <qdebug.h>
#include "AudioMgr_send.h"
static jrtp_send *jrtps;
void checkerror(int errorcode) {
	if (errorcode < 0)
	{
		std::cout << "ERROR:" << RTPGetErrorString(errorcode) << std::endl;
		exit(-1);
	}
}
RTPSession* jrtp_send::return_rtp_send_session()
{
	return jrtps->sess;
}
jrtp_send::jrtp_send(QObject *parent, QString ip_, QString port_) :ip(ip_), port(port_)
	, QObject(parent)
{
	jrtps = this;
	
	uint16_t portbase, destport(port.toInt());
	uint32_t destip;
	std::string ipstr;
	int status, i(1);
	int packetlen(0);
	unsigned char *ptr;
	portbase = 6000;
	sessparams.SetOwnTimestampUnit(1.0 / 8000);
	sessparams.SetAcceptOwnPackets(true);
	transparams.SetPortbase(portbase);
	sess = new RTPSession;
	status = sess->Create(sessparams, &transparams);
	checkerror(status);
	sess->SetDefaultPayloadType(18);

	sess->SetDefaultMark(false);
	sess->SetDefaultTimestampIncrement(160);
	//std::cout << RTPGetErrorString(-22);
	uint8_t localip[] = { 127, 0, 0, 1 };
	RTPIPv4Address addr(/*ip.toStdString().data()*/localip, destport);
	status = sess->AddDestination(addr);
	checkerror(status);
	CAudioMgr_send *ty = new CAudioMgr_send;
}
void jrtp_send::set_ip_port(QString ip_, QString port_)
{
	ip = ip_;
	port = port_;
}
void jrtp_send::set_ip(QString ip_)
{
	ip = ip_;
}
void jrtp_send::set_port(QString port_)
{
	port = port_;
}
jrtp_send::~jrtp_send()
{

}
