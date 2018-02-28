#include "chat_intetface.h"
#include "sip_network.h"
#include <qpixmap.h>
#include <QTime>
#include <qevent.h>
# pragma execution_character_set("utf-8")
static QListWidget *list = nullptr;
static chat_intetface *chat = nullptr;
static QMap<QString, QListWidgetItem*>name_listwidgeitem;
static QString getCurrentDateTime()
{
	QTime time = QTime::currentTime();
	QDate date = QDate::currentDate();
	
	return QString("%1  %2").arg(date.toString(Qt::ISODate))
		.arg(time.toString(Qt::ISODate));
}
chat_intetface*& chat_intetface::return_chat_interface()
{
	return chat;
}
chat_intetface::chat_intetface(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	chat = this;
	//this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明  
	this->setWindowFlags(Qt::FramelessWindowHint);
	//this->setStyleSheet("QWidget{ border-top-left-radius:15px; border-top-right-radius:5px; }");
	QPixmap pix("./image/call_image_big.png");
	pix = pix.scaled(50, 40);
	ui.pushButton_menu->setContentsMargins(0, 0, 0, 0);
	QPixmap pix1("./image/camera_image.png");
	pix1 = pix1.scaled(50, 40);
	QPixmap pix2("./image/_menu_.png");
	pix2 = pix2.scaled(50, 40);
	ui.pushButton_menu->setIcon(pix2);
	ui.pushButton_video->setIcon(pix1);
	ui.pushButton_call->setIcon(pix);
	list = ui.listWidget;
	connect(ui.pushButton_call, SIGNAL(clicked()), this, SLOT(send_call()));
	connect(ui.listWidget, SIGNAL(itemPressed(QListWidgetItem*)), this, SLOT(switchClicked(QListWidgetItem*)));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(send_message()));
}
void chat_intetface::paintEvent(QPaintEvent *event)
{
	QBitmap bitmap(this->size());
	QPainter painter(&bitmap);
	painter.fillRect(bitmap.rect(), Qt::white);
	painter.setBrush(QColor(0, 0, 0));
	painter.setRenderHint(QPainter::Antialiasing);//平滑
	painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::RoundCap,
		Qt::RoundJoin));
	painter.drawRoundedRect(this->rect(), 10, 10, Qt::RelativeSize);
	this->setMask(bitmap);//可设置不同的形	
}
void chat_intetface::send_call()
{
	sip_network::return_sip_network()->invite_request(ui.listWidget->currentItem()->text());
}
void chat_intetface::send_video()
{

}
void chat_intetface::send_message()
{
	if (ui.textEdit_input->toPlainText().isEmpty())
	{
		return;
	}
	QString message = ui.textEdit_input->toPlainText();
	if (ui.listWidget->currentItem() == NULL)
		return;
	QString usename = ui.listWidget->currentItem()->text();
	if (usename.isEmpty() || usename.isNull())
	{
		return;
	}
	ui.textEdit_input->clear();
	QString str = QString("<font size=\"4\" color=blue>%1    %2: </font>")
		.arg("我").arg(getCurrentDateTime());
	ui.textEdit->append(str);
	ui.textEdit->append(message);
	QFile *file = text_detail[usename];
	if (!file->isOpen())
		file->open(QIODevice::Append);
	str = str + "\r\n";
	message = message + "\r\n";
	file->write(str.toStdString().data());
	file->write(message.toStdString().data());
	file->flush();
	sip_network::return_sip_network()->send_message(usename, message);

}
void chat_intetface::mousePressEvent(QMouseEvent *event)
{
	this->windowPos = this->pos();                // 获得部件当前位置
	this->mousePos = event->globalPos();     // 获得鼠标位置
	this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}
void chat_intetface::mouseMoveEvent(QMouseEvent *event)
{
	this->move(event->globalPos() - this->dPos);
}
void chat_intetface::insert_new_widget(QString username)
{
	QListWidgetItem *list;
	if (text_detail.find(username) == text_detail.end())
	{
		list = new QListWidgetItem(QIcon("./image/linker.png"), username);
		name_listwidgeitem.insert(username, list);
		list->setSizeHint(QSize(ui.listWidget->minimumSize().width(), 60));
		ui.listWidget->insertItem(num++, username);
		QFile *file = new QFile(username);
		file->open(QIODevice::Append | QIODevice::Text);
		text_detail[username] = file;
	}
	list = name_listwidgeitem[username];
	int row = ui.listWidget->row(list);
	if (row == -1)
		row = 0;
	if (row == ui.listWidget->currentRow())
	{
		return;
	}
	ui.listWidget->setCurrentRow(row);
	switchClicked(list);
}
chat_intetface::~chat_intetface()
{

}
void chat_intetface::switchClicked(QListWidgetItem* item)
{
	QString str_text = item->text();
	if (text_detail.find(str_text) == text_detail.end())
	{
		return;
	}
	QFile *file = text_detail[str_text];
	if (!file->isOpen())
	file->open(QIODevice::Append);
	ui.textEdit->clear();
	ui.textEdit_input->clear();
	while (!file->atEnd())
	{
		QString str = file->readLine().data();
		//str.chop(2);
		str = str.simplified();
		ui.textEdit->append(str);
	}
}
void chat_intetface::come_new_message(QString text)
{
	QString username = ui.listWidget->currentItem()->text();
	if (text_detail.find(username) == text_detail.end())
	{
		return;
	}
	QFile *file = text_detail[username];
	if (!file->isOpen())
		file->open(QIODevice::Append);
	QString str = QString("<font size=\"4\" color=blue>%1    %2: </font>")
		.arg(username).arg(getCurrentDateTime());
	ui.textEdit->append(str);
	ui.textEdit->append(text);
	str = str + "\r\n";
	text = text + "\r\n";
	file->write(str.toStdString().data());
	file->write(text.toStdString().data());
}
void chat_intetface::insert_class(QString usename, QString text)
{
	insert_new_widget(usename);
	come_new_message(text);
}

