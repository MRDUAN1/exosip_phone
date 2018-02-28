/********************************************************************************
** Form generated from reading UI file 'server_third_new.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_THIRD_NEW_H
#define UI_SERVER_THIRD_NEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_server_third_newClass
{
public:
    QLabel *label;
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget;

    void setupUi(QWidget *server_third_newClass)
    {
        if (server_third_newClass->objectName().isEmpty())
            server_third_newClass->setObjectName(QStringLiteral("server_third_newClass"));
        server_third_newClass->resize(550, 355);
        label = new QLabel(server_third_newClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 3, 91, 16));
        widget = new QWidget(server_third_newClass);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 253, 550, 100));
        widget->setStyleSheet(QStringLiteral("background-color:rgb(232, 232, 232)"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 60, 110, 28));
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: 2px solid rgb(255, 170, 255);\n"
"    border-radius: 6px;\n"
"    background-color: rgb(255, 170, 127);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: rgb(255, 255, 255); /* make the default button prominent */\n"
"}"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 60, 111, 28));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: rgb(255, 170, 127);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: rgb(255, 255, 255); /* make the default button prominent */\n"
"}"));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(343, 60, 110, 28));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: 2px solid rgb(255, 170, 255);\n"
"    border-radius: 6px;\n"
"    background-color: rgb(255, 170, 127);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: rgb(255, 255, 255); /* make the default button prominent */\n"
"}"));
        tableWidget = new QTableWidget(server_third_newClass);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 23, 550, 280));
        tableWidget->setStyleSheet(QStringLiteral("background-color:rgb(232, 252, 232);"));

        retranslateUi(server_third_newClass);

        QMetaObject::connectSlotsByName(server_third_newClass);
    } // setupUi

    void retranslateUi(QWidget *server_third_newClass)
    {
        server_third_newClass->setWindowTitle(QApplication::translate("server_third_newClass", "server_third_new", 0));
        label->setText(QApplication::translate("server_third_newClass", "\345\256\242\346\210\267\345\210\227\350\241\250", 0));
        pushButton->setText(QApplication::translate("server_third_newClass", "\345\274\200\345\220\257\346\234\215\345\212\241", 0));
        pushButton_2->setText(QApplication::translate("server_third_newClass", "\345\201\234\346\255\242", 0));
        pushButton_3->setText(QApplication::translate("server_third_newClass", "\351\207\215\345\220\257", 0));
    } // retranslateUi

};

namespace Ui {
    class server_third_newClass: public Ui_server_third_newClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_THIRD_NEW_H
