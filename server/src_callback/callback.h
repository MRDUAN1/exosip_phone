#ifndef CALLBACK_H
#define CALLBACK_H
#include <QObject>
#include <eXosip2/eXosip.h>
#include <osip2/osip_mt.h>
#include <functional>
#include "global_.h"
class Callback : public QObject
{
	Q_OBJECT
public:
	Callback(QObject *parent = 0);
	static Callback*& return_callback();
	~Callback();
	typedef std::function<int(eXosip_event_t*)> MessageCallback;
	explicit Callback(eXosip_event_t *to_client, const MessageCallback& defaultCb = default);
	void onProtobufMessage(eXosip_event_t* message) const
	{
		CallbackMap::const_iterator it = callbacks_.find(message->type);
		if (it != callbacks_.end())
		{
			it->second(message);
		}
		else
		{
			defaultCallback_(message);
		}
	}
	void registerMessageCallback(eXosip_event_type_t desc,
		const MessageCallback& callback)
	{
		callbacks_[desc] = callback;
	}
	static Informations *&return_login_information();
private:
	typedef std::map<eXosip_event_type_t, MessageCallback> CallbackMap;
	static int default(eXosip_event_t* message)
	{
		return 1;
	}
	QString getCurrentDateTime();
	CallbackMap callbacks_;
	MessageCallback defaultCallback_;
	
	
private:
	static int handle_message_new(eXosip_event_t *);
	static int handle_register_request(eXosip_event_t *);
	static int handle_register_refersh(eXosip_event_t *);
	static int handle_register_failure(eXosip_event_t *);
	static int handle_new_invite(eXosip_event_t *);
	static int handle_call_answer(eXosip_event_t *);
	static void register_prase(eXosip_event_t *);
	static void make_authoration(eXosip_event_t *, int );
	static int default_name(eXosip_event_t *);
	static void get_expire(eXosip_event_t *, int&);
	static void test_authoration(eXosip_event_t *, int status);
	static void construct_invite(eXosip_event_t *, handle_information*);
	static int handle_riging(eXosip_event_t *);
	static int handle_cancel(eXosip_event_t *);
	static int handle_new_subscr(eXosip_event_t *);
	static int handle_ggg(eXosip_event_t *);
	static int Callback::handle_cancle_close(eXosip_event_t *);
	//获取对方的handle_information详细信息
//	static handle_information *&return_detail_information(eXosip_event_t *);
signals:
	void success_information(QString);
	void failure_information(QString);
	void success_register(QString str);
	void warning_information(QString str);
	void quit_information(QString str);
	void client_information_signal(handle_information*);
};

#endif // CALLBACK_H
