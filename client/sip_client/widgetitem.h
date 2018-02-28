#ifndef WIDGETITEM_H
#define WIDGETITEM_H

#include <QWidget>
#include <qmenu.h>
#include <qaction.h>
#include "ui_widgetitem.h"

class widgetitem : public QWidget
{
	Q_OBJECT

public:
	widgetitem(QWidget *parent = 0);
	~widgetitem();
	void set_icon(QString);
	void set_username(QString);
	void set_date(QString);
	
private:
	QString username, date;
	QMenu *menu;
	void contextMenuEvent(QContextMenuEvent *);
	Ui::widgetitem ui;
	QAction *action_call, *action_video, *action_add, *delete_, *delete_all, *copy_number;
	/*private slots :
	void call_slot();
	void video_slot();
	void add_slot();
	void delete_slot();
	void delete_all_slot();
	void copy_number_slot();*/
	
signals:
	void delete_signal(QString);
	void delete_all_signal(QString);
};

#endif // WIDGETITEM_H
