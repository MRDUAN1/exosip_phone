#include "server_third_new.h"
#include <QtWidgets/QApplication>
#pragma comment(lib, "eXosip2.lib")
#pragma comment(lib, "osipparser2.lib")
#include <eXosip2/eXosip.h>
#include <WinSock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <sys/types.h>
#include <WinSock2.h>
#include <Windows.h>
#include <osip2/osip_mt.h>
#include <eXosip2/eXosip.h>
#pragma comment(lib, "WS2_32")
int main(int argc, char *argv[])
{
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(2, 2);
	if (::WSAStartup(sockVersion, &wsaData) != 0)
	{
		exit(0);
	}
	QApplication a(argc, argv);
	server_third_new w;
	w.show();
	return a.exec();
}
