#include "server_third_new.h"
#include "network.h"
#include "global_.h"
#include <qscrollbar.h>
#include "handle_information.h"
# pragma execution_character_set("utf-8")
static server_third_new *server;
using std::string;

server_third_new::server_third_new(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();

	server = this;
}
server_third_new *&server_third_new::return_server()
{
	return server;
}
server_third_new::~server_third_new()
{

}
void server_third_new::init()
{
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget->setColumnCount(4);
	ui.tableWidget->setRowCount(7);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->horizontalHeader()->setStretchLastSection(true);
	ui.tableWidget->setStyleSheet("selection-backgroud-color:lightblue");
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
	ui.tableWidget->horizontalHeader()->setHighlightSections(false);
	QFont font = ui.tableWidget->horizontalHeader()->font();
	font.setBold(true);
	ui.tableWidget->horizontalHeader()->setFont(font);
	QStringList m_header;
	m_header << QString("名字") << QString("Ip地址") << QString("端口号") << QString("状态");
	ui.tableWidget->setHorizontalHeaderLabels(m_header);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
	ui.tableWidget->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:12px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");

	ui.tableWidget->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width:12px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(stop()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(start()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(restart()));

}
void server_third_new::stop()
{

}
void server_third_new::start()
{
	network *net = new network(0);
	net->start();
	ui.pushButton->setEnabled(false);

}
void server_third_new::leave_information(QString str)
{

}
void server_third_new::restart()
{

}
void server_third_new::status_information_(handle_information* information)
{
	QString usename = QString::fromStdString(information->return_string());
	string port, host;
	information->get_port(port);
	information->get_host(host);
	if (information->return_status() == login_successful)
	{
		int value = information->return_value();
		information->set_timer_start(value);
		if (ui.tableWidget->findItems(usename, 0).isEmpty())
		{
			
		//	int value = information->return_value();
			
			QTableWidgetItem *id_item = new QTableWidgetItem(usename);
			id_item->setToolTip(usename);
			QTableWidgetItem *id_status = new QTableWidgetItem("上线");
			id_status->setToolTip("上线");
			QTableWidgetItem *port_item = new QTableWidgetItem(QString::fromStdString(port));
			port_item->setToolTip(QString::fromStdString(port));
			QTableWidgetItem *ip_item = new QTableWidgetItem(QString::fromStdString(host));
			ip_item->setToolTip(QString::fromStdString(host));
			ui.tableWidget->setItem(row, 0, id_item);
			ui.tableWidget->setItem(row, 1, ip_item);
			ui.tableWidget->setItem(row, 2, port_item);
			ui.tableWidget->setItem(row, 3, id_status);
			row++;
		}
	}
	else if (information->return_status() == leave_successful)
	{
		if (!ui.tableWidget->findItems(usename, 0).isEmpty())
		{
			int row = ui.tableWidget->row(ui.tableWidget->findItems(usename, 0)[0]);
			ui.tableWidget->removeRow(row--);
		}
	}
}
void server_third_new::out_information(QString str)
{

}
void server_third_new::warning_information(QString str)
{
	
}
void server_third_new::wrong_information(QString str)
{

}
void server_third_new::other_information(QString str)
{

}
