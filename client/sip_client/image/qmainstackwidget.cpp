#include "qmainstackwidget.h"
#include "tool_widget.h"
#include "add_friend_dialog.h"
#include "create_group_.h"
#include "qq_main.h"
#include "look_file.h"
#include <qdir.h>
#include <qfile.h>
#include <stdio.h>
#include "system_tray.h"
extern system_tray *s_tt;

extern networkn *net;
extern look_file *file_dow;
extern qq_main *me;
extern string send_tcp_file_name;
extern long size_;
qmainstackwidget *wip;
map<QString, widget_*>widges_friend;
map<QString, widget_*>widges_stranger;
map<QString, widget_*>widges_balack;
map<QString, widget_*>group_message_;
map<QString, widget_*>system_message;
extern struct _my_information my_information;
extern map<string, friend_information*> friend_detail;
struct file_detail_{
	string sender;
	string file_name;
};
vector<file_detail_*>_file_datail;
extern protobuf_client *pro;
/********************上传****************************************/
QEvent::Type upload_size;
QEvent::Type upload_num;
int upload_num_;
int upload_all;
/*******************************************************************/
qmainstackwidget::qmainstackwidget(protobuf_client *cli, QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	setting = new QPushButton(this);
	create_setting_action();
	widget___ = new QWidget(this);
	widget___->setGeometry(0, 580, 283, 63);
	widget___->setStyleSheet("background-color:rgb(203, 233, 247)");
	client__ = cli;
	quit_button = new QPushButton(this);
	QDir *temp = new QDir;
	bool exist = temp->exists("sound_re");
	if (!exist)
		bool ok = temp->mkdir("sound_re");
	exist = temp->exists("friend_sound");
	if (!exist)
		bool ok = temp->mkdir("friend_sound");
	this->setFixedSize(283, 643);
	//this->setStyleSheet("background:rgb(232, 245, 252);");
	stackwidget = new QStackedWidget(this);
	box_message = new messages(this);
	stackwidget->addWidget(box_message);
	box_people = new toolbox(this);
	stackwidget->addWidget(box_people);
	QPixmap pix;
	stackwidget->setGeometry(0, 161, box_people->width(), box_people->height());

	stackwidget->setCurrentIndex(1);
	set_layout_putton();

	set_editsearch();
	tool_widget *tool_hp = new tool_widget(this);
	tool_hp->setGeometry(167, 0, tool_hp->width(), tool_hp->height());
	my_image_head = new QLabel(this);
	button_name = new QPushButton(this);
	button_name->setGeometry(80, 40, 72, 35);
	button_name->setStyleSheet("background-color:rgb(22, 154, 218)");
	QPalette pal;
	pal.setColor(QPalette::ButtonText, QColor(255, 255, 255));
	button_name->setPalette(pal);
	button_name->setFlat(true);
	button_joingroup = new QLineEdit(this);
	
	button_joingroup->setStyleSheet("text-align:left");
	button_joingroup->setGeometry(80, 70, 130, 30);
	button_joingroup->setStyleSheet("QLineEdit{border: 2px solid rgb(22, 154, 218);padding: 0 8px;background: rgb(22, 154, 218);selection-background-color: rgb(255, 255, 255);color:rgb(255, 255, 255);}");
	my_image_head->setFixedSize(72, 70);
	my_image_head->move(5, 38);
	change_use_name = new QPushButton(this);
	change_use_name->setStyleSheet("background-color:rgb(22, 154, 218)");
	change_use_name->setText("改变昵称");
	change_use_name->setGeometry(0, 585, 60, 30);
	change_use_name->setFlat(true);
	change_the_passwd = new QPushButton(this);
	change_the_passwd->setText("改变密码");
	change_the_passwd->setStyleSheet("background-color:rgb(22, 154, 218)");
	change_the_passwd->setGeometry(112, 585, 60, 30);
	change_the_passwd->setFlat(true);
	change_joingroup = new QPushButton(this);
	change_joingroup->setText("加入群组");
	change_joingroup->setFlat(true);
	change_joingroup->setStyleSheet("background-color:rgb(22, 154, 218)");
	change_joingroup->setGeometry(220, 585, 60, 30);
	setconnect();
	upload_size = (QEvent::Type)5006;
	upload_num = (QEvent::Type)5007;
	num_all = 0;
	wip = this;
	bar = NULL;
	this->show();
}
void qmainstackwidget::quit_client()
{
	for (auto i = widges_friend.begin(); i != widges_friend.end(); i++)
	{
		widget_ *u = i->second;
		u->deleteLater();
	}
	for (auto i = widges_balack.begin(); i != widges_balack.end(); i++)
	{
		widget_ *u = i->second;
		u->deleteLater();
	}
	for (auto i = widges_stranger.begin(); i != widges_stranger.end(); i++)
	{
		widget_ *u = i->second;
		u->deleteLater();
	}
	for (auto i = group_message_.begin(); i != group_message_.end(); i++)
	{
		widget_ *u = i->second;
		u->deleteLater();
	}
	for (auto i = system_message.begin(); i != system_message.end(); i++)
	{
		widget_ *u = i->second;
		u->deleteLater();
	}
	
}
void qmainstackwidget::customEvent(QEvent *event)
{
	if (event->type() == upload_size)
	{
		if (bar == NULL)
		{
			bar = new QProgressBar(this);
			bar->setStyleSheet("QProgressBar{background:transparent;border-radius: 5px;} QProgressBar::chunk{background-color: #CD96CD;width:10px;margin: 0.5px;}");
		}

		bar->move(40, 300);
		bar->setGeometry(20, 320, 240, 40);
		bar->setMinimum(0);
		bar->setMaximum(upload_all);
		bar->setValue(0);
		bar->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
		bar->show();
	}
	else if (event->type() == upload_num)
	{
		bar->setValue(upload_num_);
		if (upload_num_ == upload_all)
		{
			QMessageBox::information(this, "提示", "发送完成");
			upload_num_ = 0;
			upload_all = 0;
			bar->hide();
		}

	}
	
}
void qmainstackwidget::file_information(string file_information)
{
	int pos_ = file_information.find(' ', 0);
	string file_name = file_information.substr(0, pos_);
	string sender = file_information.substr(pos_ + 1);
}
void qmainstackwidget::create_setting_action()
{
	men = new QMenu;
	file = new QAction(this);
	upload_file = new QAction(this);
	set_protect_code = new QAction(this);
	set_protect_code->setText("设置密保");
	file->setText("文件");
	system_setting = new QAction(this);
	system_setting->setText("系统设置");
	setting->setGeometry(150, 50, 35, 20);
	setting->setStyleSheet("background-color:rgb(22, 154, 218)");
	connect(set_protect_code, SIGNAL(triggered()), this, SLOT(handle_protect_code()));
	connect(file, SIGNAL(triggered()), this, SLOT(file_show()));
	connect(upload_file, SIGNAL(triggered()), this, SLOT(handle_upload_file()));
	connect(system_setting, SIGNAL(triggered()), this, SLOT(system_setting_()));
	men->addAction(file);
	upload_file->setText("上传文件");
	men->addAction(upload_file);
	men->addAction(system_setting);
	men->addAction(set_protect_code);
	setting->setMenu(men);
}
void qmainstackwidget::handle_protect_code()
{
	change_passwd_dialog *dia = new change_passwd_dialog(0, true);
	dia->show();
}
void qmainstackwidget::file_show()
{
	file_dow->show();
}
void qmainstackwidget::system_setting_()
{

}
void qmainstackwidget::handle_upload_file()
{
	QString in = QFileDialog::getOpenFileName(this, tr("Open File"));
	send_tcp_file_name = in.toStdString();
	QFileInfo info;
	QString s_tr;
	info = QFileInfo(in);
	s_tr = info.fileName();
	size_ = info.size();
	FILE *fi;
	if (!(fi = fopen(send_tcp_file_name.data(), "rb+")))
	{
		QMessageBox::warning(this, "警告", "打开文件失败\n请检查文件名是否合法");
		return;
	}
	fclose(fi);
	net->send_file();
	pro->handle_upload_file(s_tr.toStdString(), size_);
}
void qmainstackwidget::LoginGroupMember(string group_name_, string member)
{
	QString n = QString::fromStdString(group_name_);
	if (!(group_message_.find(QString::fromStdString(group_name_)) == group_message_.end()))
	{
		widget_ *wi = group_message_[n];
		wi->set_group_member(member);
	}
}
void qmainstackwidget::add_group_(string name)
{
	this->_add_friend(name, name, "0", "0", "0", 3);
}
void qmainstackwidget::init_myname_mymaxim(string name, string mymaxim, string image_, string image_name)
{
	QDir *temp = new QDir;
	bool exist = temp->exists("client_head_image");
	if (!exist)
		bool ok = temp->mkdir("client_head_image");
	string al = "client_head_image/" + image_name; image_name = al;
	int i;
	i = strcmp(image_.data(), "0");
	if ((i = strcmp(image_.data(), "0")))
	{
		QString str = QString::fromStdString(image_name);
		ofstream fd(image_name, std::ios::out | std::ios::binary);
		fd.write(image_.data(), image_.size());
		pix.load(QString::fromStdString(image_name));
	}
	else
		pix.load("./image/qq.png");
	pix = pix.scaled(72, 70);
	button_name->setText(QString::fromStdString(name));
	if (!mymaxim.empty())
		button_joingroup->setText(QString::fromStdString(mymaxim));
	my_image_head->setPixmap(pix);
}
qmainstackwidget::~qmainstackwidget()
{

}

void qmainstackwidget::set_layout_putton()
{
	hlayout = new QHBoxLayout;
	message = new QPushButton(this);
	QIcon icon_people("people.png");
	QIcon icon_message("message");
	QIcon icon_other("other");
	message->setIcon(icon_message);
	//message->setStyleSheet("background-color:rgb(58, 146, 216);border:none;");
	message->setFlat(true);
	people = new QPushButton(this);
	people->setFlat(true);
	people->setIcon(icon_people);
	other = new QPushButton(this);
	other->setFlat(true);
	other->setIcon(icon_other);
	/*hlayout->addWidget(message);
	hlayout->addStretch();
	hlayout->addWidget(people);
	hlayout->addStretch();
	hlayout->addWidget(other);*/
	message->setGeometry(0, 135, 30, 30);
	people->setGeometry(125, 135, 30, 30);
	other->setGeometry(260, 135, 30, 30);
	//QRect rect_button(0, 135, 250, message->height());
	//hlayout->setGeometry(rect_button);
	add_friend = new QPushButton(this);
	add_friend->setGeometry(0, 620, 60, 30);
	add_friend->setStyleSheet("background-color:rgb(22, 154, 218)");
	add_friend->setFlat(true);
	add_friend->setText("添加好友");
	connect(add_friend, SIGNAL(clicked()), this, SLOT(add_friend_handle()));
	create_group = new QPushButton(this);
	create_group->setGeometry(112, 620, 60, 30);
	create_group->setStyleSheet("background-color:rgb(22, 154, 218)");
	create_group->setFlat(true);
	create_group->setText("创建群组");
	quit_button->setGeometry(220, 620, 60, 30);
	quit_button->setStyleSheet("background-color:rgb(22, 154, 218)");
	quit_button->setFlat(true);
	quit_button->setText("退出登录");
	connect(quit_button, SIGNAL(clicked()), this, SLOT(quit_login_()));
	connect(create_group, SIGNAL(clicked()), this, SLOT(create_group____()));
}
void qmainstackwidget::quit_login_()
{
	QMessageBox::StandardButton button = QMessageBox::question(this, "消息", "确认要退出登录？");
	if (button == QMessageBox::StandardButton::Yes)
	{
		pro->quit_login___();
		me->show();
		s_tt->exit_success();
		this->quit_client();
		this->deleteLater();
	}
	else if (button == QMessageBox::StandardButton::No) return;
}
void qmainstackwidget::create_group____()
{
	create_group_ *cre = new create_group_("创建群组", 0);
	cre->show();
}
void qmainstackwidget::add_friend_handle()
{
	add_friend_dialog *add_fri = new add_friend_dialog();

}
void qmainstackwidget::paintEvent(QPaintEvent *event)
{
	QBitmap bitmap(this->size());
	QPainter painter(&bitmap);
	painter.fillRect(bitmap.rect(), Qt::white);
	painter.setBrush(QColor(0, 0, 0));
	painter.setRenderHint(QPainter::Antialiasing);//平滑
	painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::RoundCap,
		Qt::RoundJoin));
	painter.drawRoundedRect(this->rect(), 5, 5);
	this->setMask(bitmap);//可设置不同的形
	QPainter painter_;
	painter_.begin(this);
	QColor color(232, 245, 252);

	painter_.setPen(QPen(color, Qt::DashDotLine));
	painter_.setBrush(QBrush(color));
	painter_.drawRect(0, 110, this->width(), this->height());

	painter_.end();
	QPainter painter_top;
	painter_top.begin(this);
	QColor color_top(22, 154, 218);

	painter_top.setPen(QPen(color_top, Qt::DashDotLine));
	painter_top.setBrush(QBrush(color_top));
	painter_top.drawRect(0, 0, this->width(), 110);

	painter_top.end();
	
}
void qmainstackwidget::setconnect()
{
	QObject::connect(message, SIGNAL(clicked()), this, SLOT(setwidget_message()));
	QObject::connect(people, SIGNAL(clicked()), this, SLOT(setwidget_people()));
	QObject::connect(other, SIGNAL(clicked()), this, SLOT(setwidget_other()));
	QObject::connect(change_use_name, SIGNAL(clicked()), this, SLOT(_change_use_name()));
	QObject::connect(change_the_passwd, SIGNAL(clicked()), this, SLOT(change_passwd_name()));
	QObject::connect(change_joingroup, SIGNAL(clicked()), this, SLOT(change_mymaxim_()));
	QObject::connect(button_joingroup, SIGNAL(editingFinished()), this, SLOT(change_maxim()));
	
}
void qmainstackwidget::change_maxim()
{
	QString str = button_joingroup->text();
	pro->change_(str.toStdString(), 2);
}
void qmainstackwidget::_change_use_name()
{
	create_group_ *cre = new create_group_("改变昵称", 1);
	cre->show();
}
void qmainstackwidget::change_passwd_name()
{
	change_passwd_dialog *dia = new change_passwd_dialog;
	dia->show();

}
void qmainstackwidget::change_mymaxim_()
{
	create_group_ *cr = new create_group_("加入群组", 2);
	cr->show();
}
void qmainstackwidget::setwidget_message()
{
	stackwidget->setCurrentIndex(0);
}
void qmainstackwidget::setwidget_people()
{
	stackwidget->setCurrentIndex(1);
}
void qmainstackwidget::setwidget_other()
{
	stackwidget->setCurrentIndex(2);
}
void qmainstackwidget::mousePressEvent(QMouseEvent *event)
{
	this->windowPos = this->pos();                // 获得部件当前位置
	this->mousePos = event->globalPos();     // 获得鼠标位置
	this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}

void qmainstackwidget::mouseMoveEvent(QMouseEvent *event)
{
	this->move(event->globalPos() - this->dPos);
}
void qmainstackwidget::set_editsearch()
{
	edit_search = new QLineEdit(this);
	edit_search->setGeometry(0, 110, 283, 25);
	edit_search->setFont(QFont("Timers", 10, QFont::StyleOblique));
	edit_search->setStyleSheet("QLineEdit{border: 2px solid rgb(22, 154, 218);padding: 0 8px;background: rgb(21, 127, 178);selection-background-color: darkgray;color:rgb(240, 255, 255);}");
	QPushButton *search = new QPushButton(this);
	search->setFlat(true);
	QPixmap pix;
	pix.load("search.jpg");
	pix = pix.scaled(18, 18);
	QIcon icon_search(pix);
	search->setIcon(icon_search);
	search->setFixedSize(18, 18);
	search->move(edit_search->width() - search->width() - 2, (edit_search->height() - search->height()) / 2);
	search->setGeometry(263, 115, search->width(), search->height());
	search->setStyleSheet("QPushButton{ border-image:url(search.png); }"
		"QPushButton:press{border-image:url(search_press.png);}"
		"QPushButton:hover{border-image:url(search_hover.png);}");
	search->setCursor(QCursor(Qt::PointingHandCursor));
}
QImage qmainstackwidget::toGray(QImage image)
{
	int height = image.height();
	int width = image.width();
	QImage ret(width, height, QImage::Format_Indexed8);
	ret.setColorCount(256);
	for (int i = 0; i < 256; i++)
	{
		ret.setColor(i, qRgb(i, i, i));
	}
	switch (image.format())
	{
	case QImage::Format_Indexed8:
		for (int i = 0; i < height; i++)
		{
			const uchar *pSrc = (uchar *)image.constScanLine(i);
			uchar *pDest = (uchar *)ret.scanLine(i);
			memcpy(pDest, pSrc, width);
		}
		break;
	case QImage::Format_RGB32:
	case QImage::Format_ARGB32:
	case QImage::Format_ARGB32_Premultiplied:
		for (int i = 0; i < height; i++)
		{
			const QRgb *pSrc = (QRgb *)image.constScanLine(i);
			uchar *pDest = (uchar *)ret.scanLine(i);

			for (int j = 0; j < width; j++)
			{
				pDest[j] = qGray(pSrc[j]);
			}
		}
		break;
	}
	return ret;
}
//被handle_friend_ack调用
int qmainstackwidget::_add_friend(string id, string name, string image__, string image_name, string isonline,  int key)
{
	QPixmap pix;
	if (strcmp(image__.data(), "0"))
	{
		QDir *temp = new QDir;
		bool exist = temp->exists("friend_head");
		if (!exist)
			bool ok = temp->mkdir("friend_head");
		QString idd = QString::fromStdString(id);
		string file_name__ = "friend_head/";
		file_name__ += image_name;
		QString gray_name = "friend_head/gray_" + QString::fromStdString(image_name);
		ofstream fd(file_name__, std::ios::out | std::ios::binary);
		fd.write(image__.data(), image__.size());
		fd.close();
		QImage image(QString::fromStdString(file_name__));
		QImage im = toGray(image);
		pix.load(QString::fromStdString(file_name__));	
		im.save(gray_name);
	}
	else
	{
		pix.load(QString::fromStdString("friend_head/qq"));
		
	}
	if (key == 4){
		box_people->add_widget(pix, name.data(), id, 0, isonline);
		
	}
	else
	{
		box_people->add_widget(pix, name.data(), id, key, isonline);
	}
	
	return 1;
}
void qmainstackwidget::message_come(string sender, string text, string time)
{
	//box_message->message_come(sender, text, time);
}
void qmainstackwidget::query_add_friend(string query_friend_, string friend_info, string isgroup)
{
	QString query_friend__ = QString::fromStdString(query_friend_);
	QString friend_info__ = QString::fromStdString(friend_info);
	QMessageBox::StandardButton button;
	if (!strcmp(isgroup.data(), "0"))
	 button = QMessageBox::question(this, QString("%1请求添加好友").arg(query_friend__), QString("请求信息:%1").arg(friend_info__));
	else button = QMessageBox::question(this, QString("%1请求加入群%2").arg(query_friend__).arg(QString::fromStdString(isgroup)), NULL);
	if (button = QMessageBox::StandardButton::Yes)
	{
		client__->send_addfriend_agree(query_friend_, 1, isgroup);
	}
	else if (button = QMessageBox::StandardButton::No)
	{
		client__->send_addfriend_agree(query_friend_, 0, isgroup);
	}
}
int qmainstackwidget::remove_friend(QString name)
{
	return 1;
}
void qmainstackwidget::message_com_set_widget(string sender)
{
	box_message->message_text_image_com(sender);
}

