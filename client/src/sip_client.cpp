#include "sip_client.h"
#include "tool_widget.h"
#include "register_dialog.h"
#include "widgetitem.h"
#include "chat_intetface.h"
#include "global_header.h"
#include "listen_call_ui.h"
#include <qboxlayout.h>
#include <qmessagebox.h>
#include <Windows.h>
#include <qmap.h>
#include <qevent.h>
#include <qfile.h>
#include <qdebug.h>
#include <qdir.h>
#include <qpixmap.h>
#include <qicon.h>
#include <qdatetime.h>
#include <qbitmap.h>
#include <qmap.h>
#include "jrtp_recv.h"
#include "jrtp_send.h"
# pragma execution_character_set("utf-8")
static sip_client *client_sip;
static chat_intetface *interface_;
static QMap<QString, QListWidgetItem*>date_item;
//menu时指向当前正在用的listwidgetitem
static QListWidgetItem *listWidget_temp;
static QListWidget *list_favorite;
static QMap<QPushButton*, eXosip_event_t*>call_subject_pushbutton_id;  //主动只有cancel
static QMap<QPushButton*, eXosip_event_t*>call_passive_pushbutton_id;
static QMap<QPushButton*, eXosip_event_t*>call_passive_reject_pushbutton_id;
static QString getCurrentDateTime()
{
	QTime time = QTime::currentTime();
	QDate date = QDate::currentDate();
	return QString("%1 %2").arg(date.toString(Qt::ISODate))
		.arg(time.toString(Qt::ISODate));
}
sip_client::sip_client(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	set_icon();

	set_menu_action();
	interface_ = new chat_intetface;
	//ui.pushButton_state
	is_register_ok = false;
	list_widget = (QListWidget*)ui.stackedWidget->widget(1)->children()[1];
	list_favorite = (QListWidget*)ui.stackedWidget->widget(2)->children()[1];
	//qDebug() << typeid(ui.stackedWidget->widget(1)->children()[1]).name() << "jgggggg\n\n\n\n";
	list_widget_record = (QListWidget*)ui.stackedWidget->widget(3)->children()[1];
	home_num = 0, friend_num = 1, colleague_num = 2;
	item_friend = new QListWidgetItem(QIcon("./image/right_arow.png"), "朋友");
	item_home = new QListWidgetItem(QIcon("./image/right_arow.png"), "家人");
	item_colleague = new QListWidgetItem(QIcon("./image/right_arow.png"), "同事");
	ui.pushButton_delete->setIcon(QIcon("./image/delete_image.png"));
	list_widget->addItem(item_home);
	list_widget->addItem(item_friend);
	list_widget->addItem(item_colleague);
	client_sip = this;
	sip_net = new sip_network(0);
	ui.stackedWidget->widget(0)->setEnabled(false);
	ui.pushbutton_call->setEnabled(false);
	ui.pushButton_call_menu->setEnabled(false);
	ui.comboBox->setEnabled(false);
	ui.pushButton_delete->setEnabled(false);
	file_account = new QFile("account.txt");
	file_account->open(QIODevice::ReadWrite);
	account_num = file_account->readLine().toStdString();
	if (!account_num.empty())
	{
		split_string(account_num);
	}
	else
	{
		QPixmap pix("./image/away.png");
		ui.pushButton_state->setIcon(pix);
	}
	QDir *dir = new QDir;
	tool_widget *widget = new tool_widget(this);
	widget->setGeometry(ui.frame->width() - widget->width(), 0, widget->width(), widget->height());
	widget->show();
	menu_setting = new QMenu;
	menu_help = new QMenu;
	ui.pushbutton_setting->setMenu(menu_setting);
	action_register = new QAction("注册", menu_setting);
	set_connect();
	menu_setting->addAction(action_register);
	list_widget_record->setContextMenuPolicy(Qt::CustomContextMenu);
	ui.stackedWidget->setCurrentIndex(0);
}
void sip_client::set_menu_action()
{
	action_call = new QAction("呼叫", 0);
	action_video = new QAction("视频呼叫", 0);
	action_add = new QAction("添加到联系人", 0);
	delete_ = new QAction("删除", 0);
	delete_all = new QAction("删除全部", 0);
	copy_number = new QAction("拷贝号码", 0);
	message_action = new QAction("发送信息", 0);
	menu = new QMenu;
	menu->addAction(action_call);
	menu->addAction(message_action);
	menu->addAction(action_video);
	menu->addAction(action_add);
	menu->addAction(delete_);
	menu->addAction(delete_all);
	menu->addAction(copy_number);

	menu_pushbutton_call = new QMenu;
	action_call_ = new QAction("呼叫", 0);
	action_video_ = new QAction("视频", 0);
	message_action_ = new QAction("发消息", 0); 
	menu_pushbutton_call->addAction(action_call_);
	menu_pushbutton_call->addAction(action_video_);
	menu_pushbutton_call->addAction(message_action_);
	ui.pushButton_call_menu->setMenu(menu_pushbutton_call);
	connect(message_action_, SIGNAL(triggered()), this, SLOT(message_slot_()));
	connect(action_call_, SIGNAL(triggered()), this, SLOT(call_invite()));
	menu_concat = new QMenu;
	action_add->setMenu(menu_concat);
	family = new QAction("家人", 0);
	friend_ = new QAction("朋友", 0);
	colleague = new QAction("同事", 0);
	menu_concat->addAction(family);
	menu_concat->addAction(friend_);
	menu_concat->addAction(colleague);
	connect(family, SIGNAL(triggered()), this, SLOT(insert_family()));
	connect(friend_, SIGNAL(triggered()), this, SLOT(insert_friend()));
	connect(colleague, SIGNAL(triggered()), this, SLOT(insert_colleague()));
}
void sip_client::insert_family()
{
	QString str = get_action_name();
	insert_friend(str, 0);
}
void sip_client::insert_friend()
{
	QString str = get_action_name();
	insert_friend(str, 1);
}
void sip_client::insert_colleague()
{
	QString str = get_action_name();
	insert_friend(str, 3);
}
void sip_client::message_slot_()
{
	interface_->insert_new_widget(caculate_str);
	interface_->show();
}
void sip_client::closeEvent(QCloseEvent * event)
{
	emit send_leave();
	Sleep(1000);
}
void sip_client::insert_friend(QString name, int group)
{
	QListWidgetItem *item = new QListWidgetItem(QIcon("./image/linker.png"), name);
	item->setSizeHint(QSize(list_widget->size().width(), 40));
	if (group == 0)
	{
		home_num++;
		friend_num++;
		colleague_num++;
		list_widget->insertItem(home_num, item);
	}
	else if (group == 1)
	{
		friend_num++;
		colleague_num++;
		list_widget->insertItem(friend_num, item);
	}
	else if (group == 2)
	{
		colleague_num++;
		list_widget->insertItem(colleague_num, item);
	}
}
void sip_client::resizeEvent(QResizeEvent * event)
{
	this->setFixedSize(event->size());
}
void sip_client::split_string(std::string str)
{
	char *d = ",";
	char data[100] = { '\0' };
	strcpy(data, str.data());
	QString tem_str;
	tem_str = user_id = strtok(data, d);
	int i = 1; //i的作用是计数当为0，表示用户名，1表示域名以此类推
	while (!(tem_str.isEmpty() || tem_str.isNull()))
	{
		if (i == 1)
		{
			tem_str = domain_ = strtok(nullptr, d);
		}
		else if (i == 2)
		{
			tem_str = passwd_ = strtok(nullptr, d);
		}
		else if (i == 3)
		{
			tem_str = display_name_ = strtok(nullptr, d);
		}
		else if (i == 4)
		{
			tem_str = authorization_name_ = strtok(nullptr, d);
		}
		i++;
	}
	is_register_ok = true;
	sip_net->set_detail(user_id, domain_, passwd_, display_name_, authorization_name_);
	//sip_net->start();
}
void sip_client::delete_record(QString date)
{
	QListWidgetItem *item = date_item[date];
	list_widget_record->takeItem(list_widget_record->row(item));
}
void sip_client::delete_all_record(QString)
{
	list_widget_record->clear();
}
void sip_client::set_icon()
{
	QPixmap pix_ok("./image/check_ok.png");
	pix_ok = pix_ok.scaled(50, 50);
	QPixmap pix_busy("./image/busy.png");
	pix_busy = pix_busy.scaled(50, 50);
	QPixmap pix_away("./image/away.png");
	pix_away = pix_away.scaled(50, 50);
	state_menu = new QMenu(ui.pushButton_state);
	ui.pushButton_state->setMenu(state_menu);
	leave = new QAction(QIcon(pix_away), "  离开", state_menu);
	on_line = new QAction(QIcon(pix_ok),"  在线" , state_menu);
	busy = new QAction(QIcon(pix_busy), "  忙碌", state_menu);
	state_menu->addAction(on_line);
	state_menu->addAction(busy);
	state_menu->addAction(leave);
	ui.pushButton_state->setIcon(pix_ok);
	ui.pushButton_state->setText("在线");
	connect(on_line, SIGNAL(triggered()), this, SLOT(on_line_slot()));
	connect(busy, SIGNAL(triggered()), this, SLOT(busy_slot()));
	connect(leave, SIGNAL(triggered()), this, SLOT(leave_slot()));
	ui.pushButton_delete->setIcon(QPixmap("./image/delete_image.png"));
	ui.pushButton_delete->setIconSize(QSize(40, 30));
	ui.pushButton_call_menu->setIcon(QPixmap("./image/down_image.png"));
	ui.pushButton_call_menu->setIconSize(QSize(40, 30));
	ui.pushbutton_message->setIcon(QPixmap("./image/information_image.png"));
	ui.pushbutton_message->setIconSize(QSize(40, 30));
	ui.pushbutton_call->setIcon(QPixmap("./image/tele_dialog_green.png"));
	ui.pushbutton_call->setIconSize(QSize(40, 30));
	ui.statk_list->setIcon(QPixmap("./image/group_image_mot.png"));
	ui.statk_list->setIconSize(QSize(50, 40));
	ui.stack_dialog->setIcon(QPixmap("./image/list_in_image.png"));
	ui.stack_dialog->setIconSize(QSize(50, 40));
	ui.stack_favorite->setIcon(QPixmap("./image/favorite_gray.png"));
	ui.stack_favorite->setIconSize(QSize(50, 40));
	ui.stack_record->setIcon(QPixmap("./image/history_image_not.png"));
	ui.stack_record->setIconSize(QSize(50, 40));
}
void sip_client::register_state_(int i)
{
	if (i == 0)
	{
		QPixmap pix_ok("./image/check_ok.png");
		pix_ok = pix_ok.scaled(50, 50);
		ui.pushButton_state->setIcon(pix_ok);
		ui.pushButton_state->setText("在线");
	}
	else
	{
		QPixmap pix_away("./image/away.png");
		pix_away = pix_away.scaled(50, 50);
		ui.pushButton_state->setIcon(pix_away);
		ui.pushButton_state->setText("离线");
	}
}
void sip_client::on_line_slot()
{
	QPixmap pix_ok("./image/check_ok.png");
	pix_ok = pix_ok.scaled(50, 50);
	ui.pushButton_state->setIcon(pix_ok);
	ui.pushButton_state->setText("在线");
}
void sip_client::busy_slot()
{
	QPixmap pix_busy("./image/busy.png");
	pix_busy = pix_busy.scaled(50, 50);
	ui.pushButton_state->setIcon(pix_busy);
	ui.pushButton_state->setText("忙碌");
}
void sip_client::leave_slot()
{
	QPixmap pix_away("./image/atm-away.png");
	pix_away = pix_away.scaled(50, 50);
	ui.pushButton_state->setIcon(pix_away);
	ui.pushButton_state->setText("离开");
}

void sip_client::warn_information(QString str)
{
	QMessageBox::warning(0, "警告", str);
}
void sip_client::wrong_infortation(QString str)
{
	QMessageBox::warning(0, "错误", str);
}
void sip_client::successful_infortation(QString str)
{
	QMessageBox::information(0, "提示", str);

}
sip_client *&sip_client::return_sip_client()
{
	return client_sip;
}
void sip_client::show_menu(const QPoint p)
{
	listWidget_temp = list_widget_record->itemAt(p);
	QPoint parent_pos = static_cast<QPoint>(mapToGlobal(p));
	int y = parent_pos.y() + 180;
	parent_pos.setY(y);
	
	menu->exec(parent_pos);
}
void sip_client::set_connect()
{
	connect(ui.pushbutton_message, SIGNAL(clicked()), this, SLOT(message_pushbutton_slot()));
	connect(list_widget_record, SIGNAL(customContextMenuRequested(const QPoint)), this, SLOT(show_menu(const QPoint)));
	connect(action_call, SIGNAL(triggered()), this, SLOT(call_slot()));
	connect(action_video, SIGNAL(triggered()), this, SLOT(video_slot()));
	connect(action_add, SIGNAL(triggered()), this, SLOT(add_slot()));
	connect(delete_, SIGNAL(triggered()), this, SLOT(deletitem_slot()));
	connect(message_action, SIGNAL(triggered()), this, SLOT(message_slot()));
	connect(delete_all, SIGNAL(triggered()), this, SLOT(delete_all_slot()));
	connect(copy_number, SIGNAL(triggered()), this, SLOT(copy_number_slot()));
	connect(list_widget, SIGNAL(clicked(QModelIndex)), this, SLOT(switchClicked(QModelIndex)));
	connect(ui.pushbutton_call, SIGNAL(clicked()), this, SLOT(call_invite()));
	connect(ui.pushButton_call_menu, SIGNAL(clicked()), this, SLOT(menu_slot()));
	connect(ui.pushButton_delete, SIGNAL(clicked()), this, SLOT(delete_slot()));
	connect(action_register, SIGNAL(triggered()), this, SLOT(register_dialog_slot()));
	connect(ui.stack_dialog, SIGNAL(clicked()), this, SLOT(dialog_show()));
	connect(ui.statk_list, SIGNAL(clicked()), this, SLOT(list_show()));
	connect(ui.stack_favorite, SIGNAL(clicked()), this, SLOT(favorite_show()));
	connect(ui.stack_record, SIGNAL(clicked()), this, SLOT(record_show()));
	connect(ui.one, SIGNAL(clicked()), this, SLOT(one_slot()));
	connect(ui.two, SIGNAL(clicked()), this, SLOT(two_slot()));
	connect(ui.three, SIGNAL(clicked()), this, SLOT(three_slot()));
	connect(ui.four, SIGNAL(clicked()), this, SLOT(four_slot()));
	connect(ui.five, SIGNAL(clicked()), this, SLOT(five_slot()));
	connect(ui.six, SIGNAL(clicked()), this, SLOT(six_slot()));
	connect(ui.seven, SIGNAL(clicked()), this, SLOT(seven_slot()));
	connect(ui.eight, SIGNAL(clicked()), this, SLOT(eight_slot()));
	connect(ui.nine, SIGNAL(clicked()), this, SLOT(nine_slot()));
	connect(ui.jing, SIGNAL(clicked()), this, SLOT(jing_slot()));
	connect(ui.mi, SIGNAL(clicked()), this, SLOT(mi_slot()));
	connect(ui.zero, SIGNAL(clicked()), this, SLOT(zero_slot()));
	connect(this, SIGNAL(send_leave()), sip_network::return_sip_network(), SLOT(register_leave()));
	connect(ui.comboBox, SIGNAL(editTextChanged(const QString &)), this, SLOT(cacluate_slot(QString)));
}
QString sip_client::get_action_name()
{
	//std::string userAndTime;
	QString str;
	if (listWidget_temp == nullptr)
	{
		if (caculate_str.isEmpty())
			return NULL;
		str = caculate_str;
	}
	else
	{
		//str = listWidget_temp->text();
		std::string userAndTime;
		str = listWidget_temp->text();
		userAndTime = listWidget_temp->text().toStdString();
		int num = userAndTime.find_first_of(" ");
		QString usename = str.left(num);
		str = usename;
	}
	return str;
}
void sip_client::message_pushbutton_slot()
{
	interface_->show();
}
void sip_client::call_slot()
{
	QString usename = get_action_name();
	sip_network::return_sip_network()->invite_request(usename);

}
//无bug usename不可能出现空格
void sip_client::message_slot()
{
	std::string userAndTime;
	QString str;
	str = listWidget_temp->text();
	userAndTime = listWidget_temp->text().toStdString();
	int num = userAndTime.find_first_of(" ");
	QString usename = str.left(num);
	interface_->insert_new_widget(usename);
	interface_->show();
	listWidget_temp = nullptr;
}
void sip_client::video_slot()
{
	QString usename = get_action_name();
	sip_network::return_sip_network()->invite_request(usename, true);
}
void sip_client::add_slot()
{

}
void sip_client::deletitem_slot()
{
	list_widget_record->takeItem(list_widget_record->row(listWidget_temp));
	listWidget_temp = nullptr;
}
void sip_client::delete_all_slot()
{
	list_widget_record->clear();
}
void sip_client::delete_concat(QString name, int index)
{
	QList<QListWidgetItem*>it = list_widget->findItems(name, Qt::MatchExactly);
	QListWidgetItem *itt = it[0];
	int row = list_widget->row(itt);
	list_widget->takeItem(row);
	if (0 < row < friend_num)
	{
		friend_num--;
		colleague_num--;
	}
	else if (friend_num < row < colleague_num)
	{
		colleague_num--;
	}
	else if (row > colleague_num)
	{

	}
}
void sip_client::copy_number_slot()
{

}
void sip_client::switchClicked(QModelIndex index_)
{
	bool flag;
	int index = index_.row();
	if (index == 0)
	{
		if (home_deploy)
		{
			flag = false;
			item_home->setIcon(QIcon("./image/right_arow"));
			home_deploy = false;
		}
		else
		{
			flag = true;
			item_home->setIcon(QIcon("./image/down_arow"));
			home_deploy = true;
		}
		for (int i = 1; i <= home_num; i++)
		{
			list_widget->setRowHidden(i, flag);
		}
	}
	else if (index == home_num + 1)
	{
		if (friend_deploy)
		{
			flag = false;
			item_friend->setIcon(QIcon("./image/right_arow"));
			friend_deploy = false;
		}
		else
		{
			flag = true;
			item_friend->setIcon(QIcon("./image/down_arow"));
			friend_deploy = true;
		}
		for (int i = home_num + 2; i <= friend_num; i++)
		{
			list_widget->setRowHidden(i, flag);
		}
	}
	else if (index == friend_num + 1)
	{
		int all = list_widget->count();
		if (colleague_deploy)
		{
			flag = false;
			item_colleague->setIcon(QIcon("./image/right_arow"));
			colleague_deploy = false;
		}
		else
		{
			flag = true;
			item_colleague->setIcon(QIcon("./image/down_arow"));
			colleague_deploy = true;
		}
		for (int i = friend_num + 2; i < all; i++)
		{
			list_widget->setRowHidden(i, flag);
		}
	}
	else
	{
		return;
	}
}
void sip_client::invite_status(QString usename, int i)
{
	QString date = getCurrentDateTime();
	QListWidgetItem *item;
	QString str_all = usename + "                  " + date;
	if (i == 0)
	{
		item = new QListWidgetItem(QIcon("./image/call_image_big.png"), str_all);
	}
	else if (i == 1)
	{
		item = new QListWidgetItem(QIcon("./image/call_image_big.png"), str_all);
		//pict_label->setPixmap(QPixmap("./image/call_image_big.png"));
	}
	else if (i == 2)
	{
		item = new QListWidgetItem(QIcon("./image/call_image_big.png"), str_all);
	}
	else if (i == 3)
	{
		item = new QListWidgetItem(QIcon("./image/call_image_big.png"), str_all);
	}
	list_widget_record->addItem(item);
	date_item[date] = item;
	item->setSizeHint(QSize(list_widget_record->width(), 50));
}
void sip_client::cacluate_slot(QString str)
{
	caculate_str = str;
}
void sip_client::call_invite()
{

	sip_network::return_sip_network()->invite_request(caculate_str);

}
void sip_client::menu_slot()
{

}

void sip_client::delete_slot()
{
	caculate_str.truncate(caculate_str.size() - 1);
	ui.comboBox->clear();
	ui.comboBox->setCurrentText(caculate_str);
	if (caculate_str.isEmpty())
	{
		ui.pushButton_delete->setEnabled(false);
		ui.pushButton_call_menu->setEnabled(false);
		ui.pushbutton_call->setEnabled(false);
	}
}
void sip_client::set_default_stack_icon()
{
	ui.stack_dialog->setIcon(QPixmap("./image/list_not_image.png"));
	ui.stack_record->setIcon(QPixmap("./image/history_image_not.png"));
	ui.stack_favorite->setIcon(QPixmap("./image/favorite_gray.png"));
	ui.statk_list->setIcon(QPixmap("./image/group_image_mot.png"));
}
void sip_client::dialog_show()
{
	ui.stackedWidget->setCurrentIndex(0);
	set_default_stack_icon();
	ui.stack_dialog->setIcon(QPixmap("./image/list_in_image.png"));
}
void sip_client::list_show()
{
	ui.stackedWidget->setCurrentIndex(1);
	set_default_stack_icon();
	ui.statk_list->setIcon(QPixmap("./image/group_image_in.png"));
}
void sip_client::favorite_show()
{
	ui.stackedWidget->setCurrentIndex(2);
	set_default_stack_icon();
	ui.stack_favorite->setIcon(QPixmap("./image/favorite_red.png"));
}
void sip_client::record_show()
{
	ui.stackedWidget->setCurrentIndex(3);
	set_default_stack_icon();
	ui.stack_record->setIcon(QPixmap("./image/history_image_in.png"));
}
sip_client::~sip_client()
{
	
}
void sip_client::register_dialog_slot()
{
	if (!regis_dialog)
	{
		regis_dialog = new register_dialog;
		regis_dialog->set_file(file_account);
		if (!account_num.empty())
		{
			regis_dialog->set_detail_(user_id, domain_, passwd_, display_name_, authorization_name_);
			regis_dialog->set_detail();
		}
	}
	regis_dialog->show();
	
}
void sip_client::register_successful(QString)
{
	QMessageBox::information(0, "提示", "注册成功");
	ui.stackedWidget->widget(0)->setEnabled(true);
	//ui.pushbutton_call->setEnabled(true);
	//ui.pushButton_call_menu->setEnabled(true);
	//ui.pushButton_delete->setEnabled(true);
	ui.comboBox->setEnabled(true);
	register_state_(0);
	//sip_network::return_sip_network()->invite_request("sip:111@127.0.0.1:5062");
}
void sip_client::register_failure(QString)
{
	register_state_(1);
	QMessageBox::warning(NULL, "警告", "注册失败");
}
void sip_client::paintEvent(QPaintEvent *event)
{
	//eXosip_subscribe_build_initial_request
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
void sip_client::mousePressEvent(QMouseEvent *event)
{
	this->windowPos = this->pos();                // 获得部件当前位置
	this->mousePos = event->globalPos();     // 获得鼠标位置
	this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}
void sip_client::mouseMoveEvent(QMouseEvent *event)
{
	this->move(event->globalPos() - this->dPos);
}
void sip_client::set_pushbutton_menu_true()
{
	ui.pushButton_delete->setEnabled(true);
	ui.pushButton_call_menu->setEnabled(true);
	ui.pushbutton_call->setEnabled(true);
}
void sip_client::one_slot()
{
	caculate_str += "1";
	ui.comboBox->setCurrentText(caculate_str);
	set_pushbutton_menu_true();
}
void sip_client::two_slot()
{
	caculate_str += "2";
	ui.comboBox->setCurrentText(caculate_str);
	set_pushbutton_menu_true();
}

void sip_client::three_slot()
{
	caculate_str += "3";
	ui.comboBox->setCurrentText(caculate_str);
	set_pushbutton_menu_true();
}

void sip_client::four_slot()
{
	caculate_str += "4";
	ui.comboBox->setCurrentText(caculate_str);
	set_pushbutton_menu_true();
}

void sip_client::five_slot()
{
	caculate_str += "5";
	ui.comboBox->setCurrentText(caculate_str);
	set_pushbutton_menu_true();
}

void sip_client::six_slot()
{
	caculate_str += "6";
	ui.comboBox->setCurrentText(caculate_str);
	set_pushbutton_menu_true();
}

void sip_client::seven_slot()
{
	caculate_str += "7";
	ui.comboBox->setCurrentText(caculate_str);
	set_pushbutton_menu_true();
}

void sip_client::eight_slot()
{
	caculate_str += "8";
	ui.comboBox->setCurrentText(caculate_str);
	set_pushbutton_menu_true();
}

void sip_client::nine_slot()
{
	caculate_str += "9";
	ui.comboBox->setCurrentText(caculate_str);
	set_pushbutton_menu_true();
}

void sip_client::jing_slot()
{
	caculate_str += "#";
	ui.comboBox->setCurrentText(caculate_str);
	set_pushbutton_menu_true();
}

void sip_client::mi_slot()
{
	caculate_str += "*";
	ui.comboBox->setCurrentText(caculate_str);
	set_pushbutton_menu_true();
}

void sip_client::zero_slot()
{
	caculate_str += "0";
	ui.comboBox->setCurrentText(caculate_str);
	set_pushbutton_menu_true();
}
//是否中途挂断
void sip_client::reject_call_subject_slot()
{
	//主动拒绝是cancel被动拒绝是busy486
	eXosip_event_t* message = call_subject_pushbutton_id[(QPushButton*)sender()];
	eXosip_call_terminate(message->cid, message->did);
}
//被接电话挂断
void sip_client::reject_call_passive_slot()
{

	//eXosip_call_terminate()
	eXosip_event_t* message = call_passive_reject_pushbutton_id[(QPushButton*)sender()];

}
//接受打电话
void sip_client::accept_call_slot()
{
	eXosip_event_t* message = call_passive_pushbutton_id[(QPushButton*)sender()];
	osip_message_t *answer_message = NULL;
	eXosip_call_build_answer(message->tid, 200, &answer_message);
	int j = eXosip_call_send_answer(message->tid, 200, answer_message);
	
}
//主动呼叫
void sip_client::call_subject(eXosip_event_t* message)
{
	//listen_call_ui *subject_calling = new listen_call_ui(id, 0, false, 0);
	QMessageBox messagebox(QMessageBox::NoIcon, "正在呼叫", message->request->req_uri->username);
	QPushButton *reject = new QPushButton;
	call_subject_pushbutton_id[reject] = message;
	connect(reject, SIGNAL(clicked()), this, SLOT(reject_call_subject_slot()));
	reject->setFixedSize(70, 70);
	messagebox.addButton(reject, QMessageBox::RejectRole);
	reject->setFlat(true);
	QPixmap pix1("./image/refuse_phone.png");
	pix1 = pix1.scaled(70, 70);
	reject->setIcon(pix1);
	messagebox.exec();
}
//被动呼叫
void sip_client::call_passive(eXosip_event_t* message)
{
	char *sh = (new char[100]);
	osip_uri_to_str(message->request->from->url, &sh);
	
	
	QMessageBox messagebox(QMessageBox::NoIcon, "电话呼叫", sh);
	QPushButton *accept = new QPushButton;
	call_passive_pushbutton_id[accept] = message;
	connect(accept, SIGNAL(clicked()), this, SLOT(accept_call_slot()));
	accept->setFixedSize(70, 70);
	messagebox.addButton(accept, QMessageBox::AcceptRole);
	accept->setFlat(true);
	QPixmap pix("./image/tele_dialog_green.png");
	pix = pix.scaled(70, 70);
	
	accept->setIcon(pix);
	

	QPushButton *reject = new QPushButton;
	reject->setFixedSize(70, 70);
	messagebox.addButton(reject, QMessageBox::RejectRole);
	reject->setFlat(true);
	QPixmap pix1("./image/refuse_phone.png");
	pix1 = pix1.scaled(70, 70);
	reject->setIcon(pix1);
	connect(reject, SIGNAL(clicked()), this, SLOT(reject_call_passive_slot()));
	call_passive_reject_pushbutton_id[reject] = message;
	messagebox.exec();
}
