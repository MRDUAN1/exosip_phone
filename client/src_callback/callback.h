#ifndef CALLBACK_H
#define CALLBACK_H

#include <QObject>
#include <QMetaType>
#include <eXosip2/eXosip.h>
#include <osip2/osip_mt.h>
#include <functional>
#include <qfile.h>
#include <string>
using std::string;
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
	static int handle_register_request(eXosip_event_t *);
	static int handle_register_success(eXosip_event_t *);
	static int handle_register_failure(eXosip_event_t *);
	static int handle_new_message(eXosip_event_t *);
	static int handle_invite_proceeding(eXosip_event_t *);
	static int handle_invite_new(eXosip_event_t *);
	static int handle_riging(eXosip_event_t *);
	static int handle_message_failure(eXosip_event_t *);
	static int handle_call_answer(eXosip_event_t *);
	static int unknown(eXosip_event_t *);
	static string parse_audio_support_name(std::string);
signals:
	void message_failure(QString);
	void success_information(QString);
	void failure_information(QString);
	void invite_failure(QString);
	void success_register(QString str);
	void failure_register(QString);
	//0是成功1是没找到好友或呼叫失败2是拒接
	void status_invite(QString, int);
	void message_com(QString, QString);
	void subject_call(eXosip_event_t *message);
	void passive_call(eXosip_event_t *message);
};

#endif // CALLBACK_H
