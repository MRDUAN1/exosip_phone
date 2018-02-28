#ifndef SQL__H
#define SQL__H

#include <QObject>
#include <qsql.h>
#include <qsqldatabase.h>
#include "handle_information.h"
typedef std::map<std::string, handle_information*>Informations;
class sql_ : public QObject
{
	Q_OBJECT

public:
	sql_(QObject *parent);
	void register_new_account(QString user, QString passwd);
	~sql_();
	void set_information(Informations &);
private:
	void sql_::errorSQLOrder(QSqlQuery query, QString mark);
	
	QSqlDatabase sql_database;
};

#endif // SQL__H
