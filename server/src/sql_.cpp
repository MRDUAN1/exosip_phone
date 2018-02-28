#include "sql_.h"
#include <qdebug.h>
#include <qsqlrecord.h>
#include <qfile.h>
#include <qsqlerror.h>
#include <qsqlquery.h>
#include <qmessagebox.h>
sql_::sql_(QObject *parent)
	: QObject(parent)
{
	bool create = !QFile::exists("sip_sql.db");
	sql_database = QSqlDatabase::addDatabase("QSQLITE");
	//sql_database.setHostName("localhost");
	sql_database.setDatabaseName("sip_sql.db");
	//sql_database.setUserName("root");
	//sql_database.setPassword("123");
	if (!sql_database.open()){
		qDebug() << "数据库操作失败"; 
		return;
	}
	QSqlQuery sql;
	sql.exec("create table IF NOT EXISTS users(account varchar(21) primary key, "
		"password varchar(21) not null, "
		"sender varchar(21))");
	QSqlQuery sql_query;
	sql_query.prepare("insert into users values(:user, :passwd, 0)");
	sql_query.bindValue(":user", "12345");
	sql_query.bindValue(":passwd", "110");
	sql_query.exec();
	errorSQLOrder(sql, "in create table");
	sql_query.prepare("insert into users values(:user, :passwd, 0)");
	sql_query.bindValue(":user", "5455816");
	sql_query.bindValue(":passwd", "112");
	sql_query.exec();
	errorSQLOrder(sql, "in create table");
}
void sql_::errorSQLOrder(QSqlQuery query, QString mark)
{
	//如果SQL语句错误，就弹出警告信息
	if (!query.isActive())
	{
		QString str = query.lastError().text() + "\n" + mark;
		QMessageBox::warning(NULL, "ERROR", str);
	}
}
void sql_::set_information(Informations &infor)
{
	QSqlQuery sql_query_;
	sql_query_.exec("select account, password from users");
	errorSQLOrder(sql_query_, "in select");
	while (sql_query_.next())
	{
		QString account = sql_query_.value("account").toString();
		QString passwd = sql_query_.value("password").toString();
		handle_information *handle = new handle_information(0, account.toStdString(), passwd.toStdString());
		infor.insert(std::make_pair(account.toStdString(), handle));
	}
}
void sql_::register_new_account(QString user, QString passwd)
{
	QSqlQuery sql_query;
	sql_query.prepare("insert into users values(:user, :passwd, 0)");
	sql_query.bindValue(":user", user);
	sql_query.bindValue(":passwd", passwd);
	sql_query.exec();
	errorSQLOrder(sql_query, "in insert new values");
}
sql_::~sql_()
{

}
