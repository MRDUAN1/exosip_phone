#ifndef SIP_CLIENT_H
#define SIP_CLIENT_H
#include <QtWidgets/QWidget>
#include <qmenu.h>
#include <qaction.h>
#include <qpainter.h>
#include <qbitmap.h>
#include <qfile.h>
#include <qmenu.h>
#include <qaction.h>
#include <qlistwidget.h>
#include <qfile.h>
#include "sip_network.h"
#include "ui_sip_client.h"
#include "register_dialog.h"
# pragma execution_character_set("utf-8")
class register_dialog;
class sip_client : public QWidget
{
	Q_OBJECT

public:
	sip_client(QWidget *parent = 0);
	static sip_client *&return_sip_client();
	void insert_friend(QString name, int group = 1);
	~sip_client();
	void closeEvent(QCloseEvent * event);
	public slots:
	//删除好友
	void delete_concat(QString, int index);
	//主动呼叫
	void call_subject(eXosip_event_t*);
	//被动呼叫
	void call_passive(eXosip_event_t*);
	void delete_record(QString);
	void delete_all_record(QString);
	void warn_information(QString);
	void wrong_infortation(QString);
	void successful_infortation(QString);
	void register_successful(QString);
	void register_state_(int);
	void register_failure(QString);
	//0是成功1是没找到好友或呼叫失败2是拒接
	void invite_status(QString, int);
private:
	QMenu *menu, *menu_pushbutton_call, *menu_concat;
	QAction *family, *friend_, *colleague;
	void set_pushbutton_menu_true();
	QString get_action_name();
	void set_menu_action();
	void set_default_stack_icon();
	QAction *action_call, *action_video, *action_add, *delete_, *delete_all, *copy_number, *message_action;
	QAction *action_call_, *action_video_, *message_action_;
	bool home_deploy = false, friend_deploy = false, colleague_deploy = false;
	QFile *file_account, *file_record;
	bool is_register_ok;
	QListWidget *list_widget, *list_widget_record;
	QListWidgetItem *item_friend, *item_home, *item_colleague;
	sip_network* sip_net;
	QMenu *state_menu;
	QAction *leave, *on_line, *busy;
	std::string account_num;
	register_dialog *regis_dialog = NULL;
	
	void set_connect();
	void split_string(std::string);
	void set_icon();
	void resizeEvent(QResizeEvent * event);
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	QMenu *menu_setting, *menu_help;
	QAction *action_register;
	QPoint windowPos, mousePos, dPos;
	Ui::sip_clientClass ui;
	QPushButton *delete_button;
	QString caculate_str;
	QString user_id, domain_, passwd_, display_name_, authorization_name_;
	int home_num = 0, friend_num = 1, colleague_num = 2;
	private slots:
	void register_dialog_slot();
	void dialog_show();
	void list_show();
	void favorite_show();
	void record_show();
	void one_slot();
	void two_slot();
	void three_slot();
	void four_slot();
	void five_slot();
	void six_slot();
	void seven_slot();
	void eight_slot();
	void nine_slot();
	void jing_slot();
	void mi_slot();
	void zero_slot();
	void on_line_slot();
	void busy_slot();
	void leave_slot();
	void call_invite();
	void menu_slot();
	void delete_slot();
	void cacluate_slot(QString);
	void switchClicked(QModelIndex);
	void call_slot();
	void message_slot();
	void message_slot_();
	void video_slot();
	void add_slot();
	void deletitem_slot();
	void delete_all_slot();
	void copy_number_slot();
	void show_menu(const QPoint);
	void message_pushbutton_slot();
	void insert_family();
	void insert_friend();
	void insert_colleague();
	void reject_call_subject_slot();
	void reject_call_passive_slot();
	void accept_call_slot();
signals:
	void send_leave();
};

#endif // SIP_CLIENT_H
