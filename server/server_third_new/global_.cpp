#include "global_.h"
#include "handle_information.h"
#include "sql_.h"

#include "callback.h"
static sql_ *sql;
static Informations information;
static Informations login_information;
static Callback *call_back_;
global_::global_(QObject *parent)
	: QObject(parent)
{

}

global_::~global_()
{

}
void global_::set_callback(Callback* &infor)
{
	call_back_ = infor;
}
Informations& global_::return_login_information()
{
	return login_information;
}
Informations& global_::return_information()
{
	return information;
}
void global_::set_sql(sql_ *&info)
{
	sql = info;
}

sql_*& global_::return_sql()
{
	return sql;
}
Callback *&global_::return_callback()
{
	return call_back_;
}
