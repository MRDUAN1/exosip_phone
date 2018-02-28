#ifndef GLOBAL__H
#define GLOBAL__H
#include <QObject>
//只有房主才能邀请其他人加入会议
class handle_information;
enum infor{
	login_successful,
	leave_successful,
	Inviteing
};
class Callback;
class sql_;
typedef std::map<std::string, handle_information*>Informations;
class global_ : public QObject
{
	Q_OBJECT

public:
	global_(QObject *parent);
	~global_();
	static Informations& return_login_information();
	static Informations& return_information();
	//static void set_callback(Callback*&);
	static void set_sql(sql_ *&);
	static void set_callback(Callback*&);
	static sql_*& return_sql();
	static Callback *&return_callback();
private:
	
};

#endif // GLOBAL__H
