/********************************************************************************
** Form generated from reading UI file 'register_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_DIALOG_H
#define UI_REGISTER_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_register_dialog
{
public:
    QGroupBox *groupBox_2;
    QCheckBox *check_call;
    QCheckBox *check_presence;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_account;
    QLineEdit *lineEdit_account;
    QLabel *label_4;
    QLabel *label_domain;
    QLineEdit *lineEdit_domain;
    QLabel *label_passwd;
    QLineEdit *lineEdit_passwd;
    QLabel *label_display_name;
    QLineEdit *lineEdit_port;
    QLabel *label_authorize;
    QLineEdit *lineEdit_authorize;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;
    QLabel *label_account_top;
    QLabel *label_protol;
    QLineEdit *lineEdit_account_top;
    QLineEdit *lineEdit_protol_top;

    void setupUi(QWidget *register_dialog)
    {
        if (register_dialog->objectName().isEmpty())
            register_dialog->setObjectName(QStringLiteral("register_dialog"));
        register_dialog->resize(510, 560);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(register_dialog->sizePolicy().hasHeightForWidth());
        register_dialog->setSizePolicy(sizePolicy);
        register_dialog->setMinimumSize(QSize(380, 560));
        register_dialog->setContextMenuPolicy(Qt::DefaultContextMenu);
        register_dialog->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255);"));
        groupBox_2 = new QGroupBox(register_dialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 100, 510, 90));
        check_call = new QCheckBox(groupBox_2);
        check_call->setObjectName(QStringLiteral("check_call"));
        check_call->setGeometry(QRect(10, 30, 91, 19));
        check_presence = new QCheckBox(groupBox_2);
        check_presence->setObjectName(QStringLiteral("check_presence"));
        check_presence->setGeometry(QRect(10, 60, 91, 19));
        groupBox = new QGroupBox(register_dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 190, 510, 310));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 40, 10, 15));
        label_account = new QLabel(groupBox);
        label_account->setObjectName(QStringLiteral("label_account"));
        label_account->setGeometry(QRect(85, 40, 72, 15));
        label_account->setContextMenuPolicy(Qt::NoContextMenu);
        lineEdit_account = new QLineEdit(groupBox);
        lineEdit_account->setObjectName(QStringLiteral("lineEdit_account"));
        lineEdit_account->setGeometry(QRect(170, 34, 150, 30));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 90, 10, 15));
        label_domain = new QLabel(groupBox);
        label_domain->setObjectName(QStringLiteral("label_domain"));
        label_domain->setGeometry(QRect(85, 90, 72, 15));
        lineEdit_domain = new QLineEdit(groupBox);
        lineEdit_domain->setObjectName(QStringLiteral("lineEdit_domain"));
        lineEdit_domain->setGeometry(QRect(170, 90, 150, 30));
        label_passwd = new QLabel(groupBox);
        label_passwd->setObjectName(QStringLiteral("label_passwd"));
        label_passwd->setGeometry(QRect(85, 145, 72, 15));
        lineEdit_passwd = new QLineEdit(groupBox);
        lineEdit_passwd->setObjectName(QStringLiteral("lineEdit_passwd"));
        lineEdit_passwd->setGeometry(QRect(170, 140, 150, 30));
        label_display_name = new QLabel(groupBox);
        label_display_name->setObjectName(QStringLiteral("label_display_name"));
        label_display_name->setGeometry(QRect(85, 205, 72, 15));
        lineEdit_port = new QLineEdit(groupBox);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));
        lineEdit_port->setGeometry(QRect(170, 200, 150, 30));
        label_authorize = new QLabel(groupBox);
        label_authorize->setObjectName(QStringLiteral("label_authorize"));
        label_authorize->setGeometry(QRect(85, 270, 72, 15));
        lineEdit_authorize = new QLineEdit(groupBox);
        lineEdit_authorize->setObjectName(QStringLiteral("lineEdit_authorize"));
        lineEdit_authorize->setGeometry(QRect(170, 260, 150, 30));
        pushButton_ok = new QPushButton(register_dialog);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(280, 520, 93, 28));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        pushButton_ok->setFont(font);
        pushButton_ok->setStyleSheet(QLatin1String("QPushButton{\n"
"    background-color:rgb(233, 233, 233);\n"
"    background-repeat:no-repeat;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"    background-color:#CCCCCC\n"
"}\n"
"QPushButton:pressed{\n"
"    background-color:#888888\n"
"}"));
        pushButton_cancel = new QPushButton(register_dialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(400, 520, 93, 28));
        pushButton_cancel->setStyleSheet(QLatin1String("QPushButton{\n"
"    background-color:rgb(233, 233, 233);\n"
"    background-repeat:no-repeat;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"    background-color:#CCCCCC\n"
"}\n"
"QPushButton:pressed{\n"
"    background-color:#888888\n"
"}"));
        label_account_top = new QLabel(register_dialog);
        label_account_top->setObjectName(QStringLiteral("label_account_top"));
        label_account_top->setGeometry(QRect(40, 20, 72, 15));
        label_protol = new QLabel(register_dialog);
        label_protol->setObjectName(QStringLiteral("label_protol"));
        label_protol->setGeometry(QRect(40, 70, 72, 15));
        lineEdit_account_top = new QLineEdit(register_dialog);
        lineEdit_account_top->setObjectName(QStringLiteral("lineEdit_account_top"));
        lineEdit_account_top->setGeometry(QRect(130, 10, 150, 30));
        lineEdit_protol_top = new QLineEdit(register_dialog);
        lineEdit_protol_top->setObjectName(QStringLiteral("lineEdit_protol_top"));
        lineEdit_protol_top->setGeometry(QRect(130, 60, 150, 30));
        lineEdit_protol_top->setStyleSheet(QStringLiteral("color:rgb(172, 172, 172);"));
        lineEdit_protol_top->setReadOnly(true);

        retranslateUi(register_dialog);

        QMetaObject::connectSlotsByName(register_dialog);
    } // setupUi

    void retranslateUi(QWidget *register_dialog)
    {
        register_dialog->setWindowTitle(QApplication::translate("register_dialog", "register_dialog", 0));
        groupBox_2->setTitle(QApplication::translate("register_dialog", "\345\205\201\350\256\270\346\223\215\344\275\234", 0));
        check_call->setText(QApplication::translate("register_dialog", "\346\211\223\347\224\265\350\257\235", 0));
        check_presence->setText(QApplication::translate("register_dialog", "\345\221\210\347\216\260", 0));
        groupBox->setTitle(QApplication::translate("register_dialog", "\347\224\250\346\210\267\350\256\276\347\275\256", 0));
        label_2->setText(QApplication::translate("register_dialog", "*", 0));
        label_account->setText(QApplication::translate("register_dialog", "\350\264\246\346\210\267", 0));
        label_4->setText(QApplication::translate("register_dialog", "*", 0));
        label_domain->setText(QApplication::translate("register_dialog", "\345\237\237\345\220\215", 0));
        label_passwd->setText(QApplication::translate("register_dialog", "\345\257\206\347\240\201", 0));
        label_display_name->setText(QApplication::translate("register_dialog", "\347\253\257\345\217\243\345\217\267", 0));
        label_authorize->setText(QApplication::translate("register_dialog", "\351\211\264\346\235\203\345\220\215\347\247\260", 0));
        pushButton_ok->setText(QApplication::translate("register_dialog", "\347\241\256\345\256\232", 0));
        pushButton_cancel->setText(QApplication::translate("register_dialog", "\345\217\226\346\266\210", 0));
        label_account_top->setText(QApplication::translate("register_dialog", "\350\264\246\346\210\267", 0));
        label_protol->setText(QApplication::translate("register_dialog", "\345\215\217\350\256\256", 0));
        lineEdit_account_top->setText(QApplication::translate("register_dialog", "Account 1", 0));
        lineEdit_protol_top->setText(QApplication::translate("register_dialog", "SIP", 0));
    } // retranslateUi

};

namespace Ui {
    class register_dialog: public Ui_register_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_DIALOG_H
