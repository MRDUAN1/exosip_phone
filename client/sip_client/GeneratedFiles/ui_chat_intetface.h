/********************************************************************************
** Form generated from reading UI file 'chat_intetface.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_INTETFACE_H
#define UI_CHAT_INTETFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat_intetface
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_call;
    QPushButton *pushButton_video;
    QPushButton *pushButton_menu;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QTextEdit *textEdit_input;
    QPushButton *pushButton_4;

    void setupUi(QWidget *chat_intetface)
    {
        if (chat_intetface->objectName().isEmpty())
            chat_intetface->setObjectName(QStringLiteral("chat_intetface"));
        chat_intetface->resize(800, 864);
        verticalLayout_4 = new QVBoxLayout(chat_intetface);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        verticalLayout_4->addLayout(verticalLayout_3);

        frame_3 = new QFrame(chat_intetface);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(0, 40));
        frame_3->setStyleSheet(QStringLiteral("background-color:rgb(43, 43, 43);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 401, 16));
        label->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255);"));

        verticalLayout_4->addWidget(frame_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listWidget = new QListWidget(chat_intetface);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMinimumSize(QSize(250, 820));
        listWidget->setStyleSheet(QLatin1String("\n"
"\n"
"QListView::item {\n"
"    background: rgb(201, 201, 201);\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"    border: 1px solid #6a6ea9;\n"
"}\n"
"\n"
"QListView::item:selected:!active {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ABAFE5, stop: 1 #8588B2);\n"
"}\n"
"\n"
"QListView::item:selected:active {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #6a6ea9, stop: 1 #888dd9);\n"
"}\n"
"\n"
"QListView::item:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #FAFBFE, stop: 1 #DCDEF1);\n"
"}"));

        horizontalLayout_2->addWidget(listWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(chat_intetface);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_call = new QPushButton(chat_intetface);
        pushButton_call->setObjectName(QStringLiteral("pushButton_call"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_call->sizePolicy().hasHeightForWidth());
        pushButton_call->setSizePolicy(sizePolicy1);
        pushButton_call->setMinimumSize(QSize(50, 40));
        pushButton_call->setMaximumSize(QSize(50, 40));
        pushButton_call->setFlat(true);

        horizontalLayout->addWidget(pushButton_call);

        pushButton_video = new QPushButton(chat_intetface);
        pushButton_video->setObjectName(QStringLiteral("pushButton_video"));
        sizePolicy1.setHeightForWidth(pushButton_video->sizePolicy().hasHeightForWidth());
        pushButton_video->setSizePolicy(sizePolicy1);
        pushButton_video->setMinimumSize(QSize(50, 40));
        pushButton_video->setMaximumSize(QSize(50, 40));
        pushButton_video->setFlat(true);

        horizontalLayout->addWidget(pushButton_video);

        pushButton_menu = new QPushButton(chat_intetface);
        pushButton_menu->setObjectName(QStringLiteral("pushButton_menu"));
        sizePolicy1.setHeightForWidth(pushButton_menu->sizePolicy().hasHeightForWidth());
        pushButton_menu->setSizePolicy(sizePolicy1);
        pushButton_menu->setMinimumSize(QSize(0, 40));
        pushButton_menu->setMaximumSize(QSize(50, 40));
        pushButton_menu->setFlat(true);

        horizontalLayout->addWidget(pushButton_menu);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(chat_intetface);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMinimumSize(QSize(0, 600));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        textEdit_input = new QTextEdit(chat_intetface);
        textEdit_input->setObjectName(QStringLiteral("textEdit_input"));

        verticalLayout->addWidget(textEdit_input);

        pushButton_4 = new QPushButton(chat_intetface);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_2);


        retranslateUi(chat_intetface);

        QMetaObject::connectSlotsByName(chat_intetface);
    } // setupUi

    void retranslateUi(QWidget *chat_intetface)
    {
        chat_intetface->setWindowTitle(QApplication::translate("chat_intetface", "chat_intetface", 0));
        label->setText(QApplication::translate("chat_intetface", "\350\201\212\345\244\251", 0));
        label_2->setText(QApplication::translate("chat_intetface", "TextLabel", 0));
        pushButton_call->setText(QString());
        pushButton_video->setText(QString());
        pushButton_menu->setText(QString());
        pushButton_4->setText(QApplication::translate("chat_intetface", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class chat_intetface: public Ui_chat_intetface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_INTETFACE_H
