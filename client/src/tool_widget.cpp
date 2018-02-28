#include "tool_widget.h"
# pragma execution_character_set("utf-8")
tool_widget::tool_widget(QWidget *parent)
: QWidget(parent)
{
	QPushButton *close = new QPushButton(this);
	QPushButton *mini = new QPushButton(this);
	QPushButton *set = new QPushButton(this);
	QPixmap pix("./image/close.png");
	QSize rec = pix.size();
	close->setStyleSheet("QPushButton{border-image:url(./image/close.png);}"
		"QPushButton:press{border-image:url(./image/close_press.png);}"
		"QPushButton:hover{border-image:url(./image/close_hover.png);}");
	close->setFixedSize(rec);
	mini->setStyleSheet("QPushButton{border-image:url(./image/minimize.png);}"
		"QPushButton:press{border-image:url(./image/minimize_press.png);}"
		"QPushButton:hover{border-image:url(./image/minimize_hover.png);}");
	mini->setFixedSize(rec);
	set->setStyleSheet("QPushButton{ border-image:url(./image/btn_set_normal.png); }"
		"QPushButton:press{border-image:url(./image/btn_set_press.png);}"
		"QPushButton:hover{border-image:url(./image/btn_set_hover.png);}");
	set->setFixedSize(rec);
	set->setGeometry(0, -2, set->width(), set->height());
	mini->setGeometry(set->width() - 1, -1, mini->width(), mini->height());
	close->setGeometry(set->width() - 3 + mini->width(), -1, close->width(), close->height());
	this->setFixedSize(3 * set->width() - 5, set->height());
	connect(mini, SIGNAL(clicked()), parent, SLOT(showMinimized()));

	connect(close, SIGNAL(clicked()), parent, SLOT(close()));
	mini->setToolTip(tr("minize"));
	close->setToolTip(tr("close"));



}

tool_widget::~tool_widget()
{

}
