#include "listen_call_ui.h"
#include "callback.h"
#include <qpixmap.h>
listen_call_ui::listen_call_ui(QString id, QWidget *parent, bool passive, QString full_name)
	: QWidget(parent)
{
	ui.setupUi(this);
	is_passive = passive;
	ui.pushButton->setEnabled(false);
	if (passive == true)
	{
		ui.pushButton->setIcon(QPixmap("./image/tele_dialog_green.png"));
		ui.pushButton->setIconSize(QSize(80, 50));
		ui.pushButton->setEnabled(true);
		connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(accept()));
	}
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(reject()));
	ui.pushButton_2->setIcon(QPixmap("./image/refuse_phone.png"));
	ui.pushButton_2->setIconSize(QSize(80, 50));
	QPixmap pix("./image/group_image_mot.png");
	pix = pix.scaled(ui.label->size());
	ui.label->setPixmap(pix);
	QString name = id + "\n\n" + full_name;
	ui.label_2->setText(name);
	
}
void listen_call_ui::accept()
{

}
void listen_call_ui::reject()
{
	if (!is_passive)
	{
		//如果是主动呼叫中途放弃,发送cancel
	}
}
listen_call_ui::~listen_call_ui()
{

}
