#ifndef CHAT_INTETFACE_H
#define CHAT_INTETFACE_H

#include <QWidget>
#include "ui_chat_intetface.h"
#include <qmap.h>
#include <qfile.h>
#include <qpainter.h>
#include <qbitmap.h>
class chat_intetface : public QWidget
{
	Q_OBJECT

public:
	chat_intetface(QWidget *parent = 0);
	static chat_intetface*& return_chat_interface();
	~chat_intetface();
	void insert_new_widget(QString);
	void come_new_message(QString);
	public slots:
	void insert_class(QString, QString);
private:
	int num = 0;
	QPoint windowPos, mousePos, dPos;
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	Ui::chat_intetface ui;
	QMap<QString, QFile*>text_detail;
	private slots:
	void switchClicked(QListWidgetItem*);
	void send_message();
	void send_call();
	void send_video();
	void paintEvent(QPaintEvent *event);
};

#endif // CHAT_INTETFACE_H
