#include "widgetitem.h"
#include "sip_client.h"
#include <qpixmap.h>
#include <QContextMenuEvent>
# pragma execution_character_set("utf-8")
widgetitem::widgetitem(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	action_call = new QAction("ºô½Ð", 0);
	action_video = new QAction("ÊÓÆµºô½Ð", 0);
	action_add = new QAction("Ìí¼Óµ½ÁªÏµÈË", 0);
	delete_ = new QAction("É¾³ý", 0);
	delete_all = new QAction("É¾³ýÈ«²¿", 0);
	copy_number = new QAction("¿½±´ºÅÂë", 0);
	menu = new QMenu;
	menu->addAction(action_call);
	menu->addAction(action_video);
	menu->addAction(action_add);
	menu->addAction(delete_);
	menu->addAction(delete_all);
	menu->addAction(copy_number);
	//this->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(this, SIGNAL(delete_signal(QString)), sip_client::return_sip_client(), SLOT(delete_record(QString)));
	connect(this, SIGNAL(delete_all_signal(QString)), sip_client::return_sip_client(), SLOT(delete_all_record(QString)));
}
/*void widgetitem::call_slot()
{
	sip_network::return_sip_network()->invite_request(username);
}
void widgetitem::video_slot()
{

}
void widgetitem::add_slot()
{

}
void widgetitem::delete_slot()
{
	delete_signal(date);
}
void widgetitem::delete_all_slot()
{

}
void widgetitem::copy_number_slot()
{

}*/
widgetitem::~widgetitem()
{

}
void widgetitem::set_icon(QString icon_name)
{
	ui.label->setPixmap(QPixmap(icon_name));
}
void widgetitem::set_username(QString usename)
{
	username = usename;
	ui.label_2->setText(usename);
	ui.label_3->setText(usename);
}
void widgetitem::set_date(QString date_)
{
	date = date_;
	ui.label_4->setText(date_);
}
void widgetitem::contextMenuEvent(QContextMenuEvent *pos)
{
	QPoint poin = pos->pos();
	poin = mapToGlobal(poin);
	menu->exec(poin);
}

