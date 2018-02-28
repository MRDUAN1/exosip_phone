#ifndef TOOL_WIDGET_H
#define TOOL_WIDGET_H

#include <QWidget>
#include <qpixmap.h>
#include <qicon.h>
#include <qpushbutton.h>
#include <qpainter.h>
#include <qboxlayout.h>

class tool_widget : public QWidget
{
	Q_OBJECT

public:
	tool_widget(QWidget *parent);
	~tool_widget();

private:

};

#endif // TOOL_WIDGET_H
