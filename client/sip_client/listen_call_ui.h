#ifndef LISTEN_CALL_UI_H
#define LISTEN_CALL_UI_H

#include <QWidget>
#include "ui_listen_call_ui.h"

class listen_call_ui : public QWidget
{
	Q_OBJECT

public:
	listen_call_ui(QString, QWidget *parent = 0, bool passive = false, QString full_name = NULL);
	~listen_call_ui();

private:
	Ui::listen_call_ui ui;
	QString full_name, id;
	bool is_passive;
	private slots:
	void accept();
	void reject();
};

#endif // LISTEN_CALL_UI_H
