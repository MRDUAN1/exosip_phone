#include "register_dialog.h"
#include"sip_client.h"
#include <qevent.h>
# pragma execution_character_set("utf-8")
register_dialog::register_dialog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	is_register_ok = false;
	sip_network *sip = sip_network::return_sip_network();
	this->setAttribute(Qt::WA_ShowModal, true);
	ui.lineEdit_protol_top->setEnabled(false);
	ui.lineEdit_passwd->setEchoMode(QLineEdit::Password);
	connect(this, SIGNAL(warning_message(QString)), sip_client::return_sip_client(), SLOT(warn_information(QString)));
	connect(ui.pushButton_ok, SIGNAL(clicked()), this, SLOT(register_ok()));
	connect(ui.check_call, SIGNAL(stateChanged(int)), this, SLOT(change_state_call()));
	connect(ui.check_presence, SIGNAL(stateChanged(int)), this, SLOT(change_state_presence(int)));
	connect(this, SIGNAL(detail_set(QString, QString, QString, QString, QString)), sip_network::return_sip_network(), SLOT(set_detail(QString, QString, QString, QString, QString)));
	connect(ui.pushButton_cancel, SIGNAL(clicked()), this, SLOT(hide_slot()));
}
void register_dialog::set_detail()
{
	is_register_ok = true;
	ui.lineEdit_account->setText(user_id);
	ui.lineEdit_domain->setText(domain);
	ui.lineEdit_passwd->setText(passwd);
	ui.lineEdit_port->setText(port);
	ui.lineEdit_authorize->setText(authoration_name);
}
void register_dialog::hide_slot()
{
	this->hide();

}
void register_dialog::set_file(QFile *file_)
{
	file = file_;
}
void register_dialog::set_detail_(QString use_id_, QString domain_, QString passwd_, QString port_name__, QString authoration_name_)
{
	user_id = use_id_;
	domain = domain_;
	passwd = passwd_;
	port = port_name__;
	authoration_name = authoration_name_;
	if (!user_id.isNull())
	{
		ui.lineEdit_account->setText(user_id);
	}
	if (!domain.isNull())
	{
		ui.lineEdit_domain->setText(domain);
	}
	if (!passwd.isNull())
	{
		ui.lineEdit_passwd->setText(passwd);
	}
	if (!port.isNull())
	{
		ui.lineEdit_passwd->setText(port);
	}
	if (!authoration_name.isNull())
	{
		ui.lineEdit_authorize->setText(authoration_name);
	}
}
register_dialog::~register_dialog()
{

}
void register_dialog::register_ok()
{

	QString str = ui.lineEdit_account->text();
	if (ui.lineEdit_account->text().isEmpty() && ui.lineEdit_domain->text().isEmpty())
	{
		emit warning_message("必须填写用户id和域名\n如不设置密码默认密码为0");
		return;
	}
	if ((domain != ui.lineEdit_domain->text()) || (authoration_name != ui.lineEdit_authorize->text()) || (passwd != ui.lineEdit_passwd->text()))
	{
		emit detail_set(ui.lineEdit_account->text(), ui.lineEdit_domain->text(), ui.lineEdit_passwd->text(), ui.lineEdit_port->text(), ui.lineEdit_authorize->text());
	}
	file->close();
	file->open(QIODevice::Truncate);
	file->close();
	file->open(QIODevice::ReadWrite);
	QString write_line = str + "," + ui.lineEdit_domain->text() + "," + ui.lineEdit_passwd->text() + "," + ui.lineEdit_port->text() + "," + ui.lineEdit_authorize->text();
	file->write(write_line.toStdString().data());
	file->flush();
	this->hide();
}
void register_dialog::closeEvent(QCloseEvent *event)
{
	event->ignore();
	this->hide();
}
void register_dialog::change_state_call(int state)
{
	state_call = state;
}
void register_dialog::change_state_presence(int state)
{
	state_presence = state;
}
