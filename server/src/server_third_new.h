#ifndef SERVER_THIRD_NEW_H
#define SERVER_THIRD_NEW_H

#include <QtWidgets/QWidget>
#include "ui_server_third_new.h"
class handle_information;
class server_third_new : public QWidget
{
	Q_OBJECT

public:
	server_third_new(QWidget *parent = 0);
	~server_third_new();
	static server_third_new *&return_server();
private:
	int row = 0;
	void init();
	Ui::server_third_newClass ui;
	private slots:
	void stop();
	void start();
	void restart();
public slots:
	void status_information_(handle_information*);
	void out_information(QString);
	void warning_information(QString);
	void wrong_information(QString);
	void other_information(QString);
	void leave_information(QString);
	//void invite(QString);
	
};

#endif // SERVER_THIRD_NEW_H
