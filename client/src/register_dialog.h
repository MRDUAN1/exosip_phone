#ifndef REGISTER_DIALOG_H
#define REGISTER_DIALOG_H

#include <QWidget>
#include <qfile.h>
#include "ui_register_dialog.h"

class register_dialog : public QWidget
{
	Q_OBJECT

public:
	register_dialog(QWidget *parent = 0);
	~register_dialog();
	void set_detail();
	void set_file(QFile *);
	void set_detail_(QString = 0, QString = 0, QString = 0, QString = 0, QString = 0);
private:
	bool is_register_ok;
	QFile *file;
	void closeEvent(QCloseEvent *event);
	QString user_id, domain, port, passwd, authoration_name;
	int state_call;
	int state_presence;
	Ui::register_dialog ui;
	private slots:
	void register_ok();
	void hide_slot();
	void change_state_call(int);
	void change_state_presence(int);
signals:
	void warning_message(QString);
	void detail_set(QString _id, QString _authorization_id, QString _port, QString _passwd, QString _domain);
	
};

#endif // REGISTER_DIALOG_H
