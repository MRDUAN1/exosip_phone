#ifndef ADD_CONCAT_H
#define ADD_CONCAT_H

#include <QWidget>
#include "ui_add_concat.h"

class add_concat : public QWidget
{
	Q_OBJECT

public:
	add_concat(QWidget *parent = 0);
	~add_concat();

private:
	Ui::add_concat ui;
};

#endif // ADD_CONCAT_H
