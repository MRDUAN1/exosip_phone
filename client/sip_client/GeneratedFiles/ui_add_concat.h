/********************************************************************************
** Form generated from reading UI file 'add_concat.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_CONCAT_H
#define UI_ADD_CONCAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_concat
{
public:

    void setupUi(QWidget *add_concat)
    {
        if (add_concat->objectName().isEmpty())
            add_concat->setObjectName(QStringLiteral("add_concat"));
        add_concat->resize(400, 300);

        retranslateUi(add_concat);

        QMetaObject::connectSlotsByName(add_concat);
    } // setupUi

    void retranslateUi(QWidget *add_concat)
    {
        add_concat->setWindowTitle(QApplication::translate("add_concat", "add_concat", 0));
    } // retranslateUi

};

namespace Ui {
    class add_concat: public Ui_add_concat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_CONCAT_H
