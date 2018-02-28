#include "sip_client.h"
#include <WinSock2.h>
#include <eXosip2/eXosip.h>
#include <osip2/osip_mt.h>
#include <QtWidgets/QApplication>
#pragma comment(lib, "eXosip2.lib")
#pragma comment(lib, "osipparser2.lib")
#pragma comment(lib, "WS2_32")
#pragma comment(lib,"Winmm")
#pragma comment(lib, "WS2_32")
#pragma comment(lib, "jrtplib_d.lib")
#pragma comment(lib, "jthread_d.lib")
#pragma comment(lib, "va_g729a.lib")
int main(int argc, char *argv[])
{
	WSADATA wsaData;

	WORD sockVersion = MAKEWORD(2, 2);
	if (::WSAStartup(sockVersion, &wsaData) != 0)
	{
		exit(0);
	}
	QApplication a(argc, argv);
	sip_client w;
	w.show();
	return a.exec();
}
