#include "network.h"
#include "callback.h"
#include <osip2/osip_mt.h>
#include <eXosip2/eXosip.h>
#include <WinSock2.h>
network::network(QObject *parent)
	: QThread(parent)
{
	int i = eXosip_init();
	if (i != 0)
	{
		printf("init wrong\n");
	}
	Callback *call = new Callback;
}
void network::run()
{
	eXosip_event_t *event;
	int i = eXosip_listen_addr(IPPROTO_UDP, NULL, 5062, AF_INET, 0);
	if (i < 0)
	{
		return;
	}
	while (1)
	{
		
		//侦听是否有消息到来
		event = eXosip_event_wait(0, 50);
		if (event == NULL)
			continue;
		eXosip_lock();
		//eXosip_default_action(event);
		//eXosip_automatic_refresh();
		eXosip_unlock();
		Callback::return_callback()->onProtobufMessage(event);
	}
}
network::~network()
{

}
