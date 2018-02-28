#include "jrtp_recv.h"
#include "标头.h"
#include "AudioMgr_recv.h"
using namespace jrtplib;
static void checkerror(int errorcode) {
	if (errorcode < 0)
	{
		std::cout << "ERROR:" << RTPGetErrorString(errorcode) << std::endl;
		exit(-1);
	}
}
jrtp_recv::jrtp_recv(QObject *parent)
	: QObject(parent)
{
	va_g729a_init_decoder();
	WSADATA wsaData;

	//init_audio();
	/** 初始化winsocket */
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		fprintf(stderr, "WAStartup failed!\n");
		return ;
	}

	RTPSession sess;
	//uint16_t portbase = 6644;
	int status;
	bool done = false;

	RTPUDPv4TransmissionParams transparams;
	RTPSessionParams sessparams;
	sessparams.SetOwnTimestampUnit(1.0 / 8000);

	sessparams.SetAcceptOwnPackets(true);

	transparams.SetPortbase(port.toInt());
	status = sess.Create(sessparams, &transparams);
	checkerror(status);
	CAudioMgr_recv *aur = new CAudioMgr_recv;
	sess.BeginDataAccess();
	RTPTime delay(0.020);
	RTPTime starttime = RTPTime::CurrentTime();

	while (!done)
	{
		status = sess.Poll();
		checkerror(status);

		if (sess.GotoFirstSourceWithData())
		{
			do
			{
				RTPPacket *pack;
				short yu[1000] = { 0 };
				char bytes1[1600] = { '\0' };
				while ((pack = sess.GetNextPacket()) != NULL)
				{
					std::string sttd;
					char nn[1000] = { '\0' };
					std::string str((char*)pack->GetPayloadData(), pack->GetPayloadLength());
					for (int i = 0; i < str.length() / L_FRAME_COMPRESSED; i++)
					{
						va_g729a_decoder((unsigned char *)str.data() + i * L_FRAME_COMPRESSED, yu, 0);
						for (int j = 0; j < L_FRAME; j++)
						{
							bytes1[j * 2] = yu[j];
							bytes1[j * 2 + 1] = yu[j] >> 8;
						}
						sttd.append(bytes1, 2 * L_FRAME);
					}
					memcpy(nn, sttd.data(), sttd.size());
					aur->OnAudioDataOut(nn, sttd.size());
					sess.DeletePacket(pack);
				}
			} while (sess.GotoNextSourceWithData());
		}
	}
	sess.EndDataAccess();
	delay = RTPTime(10.0);
	sess.BYEDestroy(delay, 0, 0);
	return ;
}
void jrtp_recv::set_ip_port(QString ip_, QString port_)
{
	ip = ip_;
	port = port_;
}
void jrtp_recv::set_ip(QString ip_)
{
	ip = ip_;
}
void jrtp_recv::set_port(QString port_)
{
	port = port_;
}
jrtp_recv::~jrtp_recv()
{

}
