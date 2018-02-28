/********************************************************************************
** Form generated from reading UI file 'sip_client.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIP_CLIENT_H
#define UI_SIP_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sip_clientClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QLabel *label;
    QFrame *frame_2;
    QPushButton *pushbutton_setting;
    QPushButton *pushButton_view;
    QPushButton *pushButton_contact;
    QPushButton *pushbutton_help;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_state;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushbutton_message;
    QPushButton *pushbutton_voice;
    QVBoxLayout *verticalLayout;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox;
    QPushButton *pushButton_delete;
    QPushButton *pushbutton_call;
    QPushButton *pushButton_call_menu;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QPushButton *four;
    QPushButton *three;
    QPushButton *two;
    QPushButton *one;
    QPushButton *mi;
    QPushButton *jing;
    QPushButton *zero;
    QPushButton *nine;
    QPushButton *six;
    QPushButton *five;
    QPushButton *eight;
    QPushButton *seven;
    QSpacerItem *horizontalSpacer_2;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *listWidget;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_5;
    QListWidget *listWidget_2;
    QWidget *page_4;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *listWidget_3;
    QFrame *frame_4;
    QPushButton *stack_dialog;
    QPushButton *statk_list;
    QPushButton *stack_favorite;
    QPushButton *stack_record;
    QFrame *frame_5;

    void setupUi(QWidget *sip_clientClass)
    {
        if (sip_clientClass->objectName().isEmpty())
            sip_clientClass->setObjectName(QStringLiteral("sip_clientClass"));
        sip_clientClass->resize(380, 620);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sip_clientClass->sizePolicy().hasHeightForWidth());
        sip_clientClass->setSizePolicy(sizePolicy);
        sip_clientClass->setMinimumSize(QSize(380, 620));
        verticalLayout_2 = new QVBoxLayout(sip_clientClass);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(sip_clientClass);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(380, 30));
        frame->setStyleSheet(QStringLiteral("background-color:rgb(43, 43, 43);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 301, 16));
        label->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(frame);

        frame_2 = new QFrame(sip_clientClass);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(380, 30));
        frame_2->setStyleSheet(QStringLiteral("background-color:rgb(244, 244, 244);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        pushbutton_setting = new QPushButton(frame_2);
        pushbutton_setting->setObjectName(QStringLiteral("pushbutton_setting"));
        pushbutton_setting->setGeometry(QRect(1, 1, 77, 28));
        sizePolicy.setHeightForWidth(pushbutton_setting->sizePolicy().hasHeightForWidth());
        pushbutton_setting->setSizePolicy(sizePolicy);
        pushbutton_setting->setMinimumSize(QSize(60, 28));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferAntialias);
        pushbutton_setting->setFont(font);
        pushbutton_setting->setStyleSheet(QLatin1String("QPushButton{\n"
"    background-color:rgb(244, 244, 244);\n"
"    background-repeat:no-repeat;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"    background-color:rgb(191, 191, 191);\n"
"}\n"
"QPushButton:pressed{\n"
"    background-color:rgb(191, 191, 191);\n"
"}"));
        pushButton_view = new QPushButton(frame_2);
        pushButton_view->setObjectName(QStringLiteral("pushButton_view"));
        pushButton_view->setGeometry(QRect(101, 1, 77, 28));
        pushButton_view->setMinimumSize(QSize(60, 28));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_view->setFont(font1);
        pushButton_view->setStyleSheet(QLatin1String("QPushButton{\n"
"    background-color:rgb(244, 244, 244);\n"
"    background-repeat:no-repeat;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"    background-color:rgb(191, 191, 191);\n"
"}\n"
"QPushButton:pressed{\n"
"    background-color:rgb(191, 191, 191);\n"
"}"));
        pushButton_contact = new QPushButton(frame_2);
        pushButton_contact->setObjectName(QStringLiteral("pushButton_contact"));
        pushButton_contact->setGeometry(QRect(202, 1, 77, 28));
        sizePolicy.setHeightForWidth(pushButton_contact->sizePolicy().hasHeightForWidth());
        pushButton_contact->setSizePolicy(sizePolicy);
        pushButton_contact->setMinimumSize(QSize(60, 28));
        pushButton_contact->setFont(font1);
        pushButton_contact->setStyleSheet(QLatin1String("QPushButton{\n"
"    background-color:rgb(244, 244, 244);\n"
"    background-repeat:no-repeat;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"    background-color:rgb(191, 191, 191);\n"
"}\n"
"QPushButton:pressed{\n"
"    background-color:rgb(191, 191, 191);\n"
"}"));
        pushbutton_help = new QPushButton(frame_2);
        pushbutton_help->setObjectName(QStringLiteral("pushbutton_help"));
        pushbutton_help->setGeometry(QRect(302, 1, 77, 28));
        pushbutton_help->setMinimumSize(QSize(60, 28));
        pushbutton_help->setFont(font1);
        pushbutton_help->setStyleSheet(QLatin1String("QPushButton{\n"
"    background-color:rgb(244, 244, 244);\n"
"    background-repeat:no-repeat;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"    background-color:rgb(191, 191, 191);\n"
"}\n"
"QPushButton:pressed{\n"
"    background-color:rgb(191, 191, 191);\n"
"}"));

        verticalLayout_2->addWidget(frame_2);

        frame_6 = new QFrame(sip_clientClass);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        sizePolicy.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy);
        frame_6->setMinimumSize(QSize(380, 60));
        frame_6->setStyleSheet(QStringLiteral("background-color:rgb(244, 244, 244);"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_6);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_state = new QPushButton(frame_6);
        pushButton_state->setObjectName(QStringLiteral("pushButton_state"));
        sizePolicy.setHeightForWidth(pushButton_state->sizePolicy().hasHeightForWidth());
        pushButton_state->setSizePolicy(sizePolicy);
        pushButton_state->setMinimumSize(QSize(110, 50));

        horizontalLayout_2->addWidget(pushButton_state);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushbutton_message = new QPushButton(frame_6);
        pushbutton_message->setObjectName(QStringLiteral("pushbutton_message"));
        pushbutton_message->setMinimumSize(QSize(50, 40));
        pushbutton_message->setFlat(true);

        horizontalLayout_2->addWidget(pushbutton_message);

        pushbutton_voice = new QPushButton(frame_6);
        pushbutton_voice->setObjectName(QStringLiteral("pushbutton_voice"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushbutton_voice->sizePolicy().hasHeightForWidth());
        pushbutton_voice->setSizePolicy(sizePolicy1);
        pushbutton_voice->setMinimumSize(QSize(50, 40));
        pushbutton_voice->setFlat(true);

        horizontalLayout_2->addWidget(pushbutton_voice);


        verticalLayout_2->addWidget(frame_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_3 = new QFrame(sip_clientClass);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(380, 60));
        frame_3->setStyleSheet(QStringLiteral("background-color:rgb(244, 244, 244);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(frame_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(250, 40));
        comboBox->setEditable(true);

        horizontalLayout_3->addWidget(comboBox);

        pushButton_delete = new QPushButton(frame_3);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));
        pushButton_delete->setMinimumSize(QSize(40, 40));
        pushButton_delete->setStyleSheet(QStringLiteral("background-image:"));
        pushButton_delete->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_delete);

        pushbutton_call = new QPushButton(frame_3);
        pushbutton_call->setObjectName(QStringLiteral("pushbutton_call"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushbutton_call->sizePolicy().hasHeightForWidth());
        pushbutton_call->setSizePolicy(sizePolicy2);
        pushbutton_call->setMinimumSize(QSize(40, 40));
        pushbutton_call->setStyleSheet(QStringLiteral(""));
        pushbutton_call->setFlat(true);

        horizontalLayout_3->addWidget(pushbutton_call);

        pushButton_call_menu = new QPushButton(frame_3);
        pushButton_call_menu->setObjectName(QStringLiteral("pushButton_call_menu"));
        sizePolicy2.setHeightForWidth(pushButton_call_menu->sizePolicy().hasHeightForWidth());
        pushButton_call_menu->setSizePolicy(sizePolicy2);
        pushButton_call_menu->setMinimumSize(QSize(40, 40));
        pushButton_call_menu->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_call_menu);


        verticalLayout->addWidget(frame_3);

        stackedWidget = new QStackedWidget(sip_clientClass);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMinimumSize(QSize(380, 350));
        stackedWidget->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayout = new QHBoxLayout(page);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        four = new QPushButton(page);
        four->setObjectName(QStringLiteral("four"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(four->sizePolicy().hasHeightForWidth());
        four->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \344\273\277\345\256\213 Std R"));
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        four->setFont(font2);
        four->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"    background-color: rgb(201, 201, 201);\n"
"}"));

        gridLayout->addWidget(four, 1, 0, 1, 1);

        three = new QPushButton(page);
        three->setObjectName(QStringLiteral("three"));
        sizePolicy3.setHeightForWidth(three->sizePolicy().hasHeightForWidth());
        three->setSizePolicy(sizePolicy3);
        three->setFont(font2);
        three->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"    background-color: rgb(201, 201, 201);\n"
"}"));

        gridLayout->addWidget(three, 0, 2, 1, 1);

        two = new QPushButton(page);
        two->setObjectName(QStringLiteral("two"));
        sizePolicy3.setHeightForWidth(two->sizePolicy().hasHeightForWidth());
        two->setSizePolicy(sizePolicy3);
        two->setFont(font2);
        two->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"    background-color: rgb(201, 201, 201);\n"
"}"));

        gridLayout->addWidget(two, 0, 1, 1, 1);

        one = new QPushButton(page);
        one->setObjectName(QStringLiteral("one"));
        sizePolicy3.setHeightForWidth(one->sizePolicy().hasHeightForWidth());
        one->setSizePolicy(sizePolicy3);
        one->setFont(font2);
        one->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"    background-color: rgb(201, 201, 201);\n"
"}"));

        gridLayout->addWidget(one, 0, 0, 1, 1);

        mi = new QPushButton(page);
        mi->setObjectName(QStringLiteral("mi"));
        sizePolicy3.setHeightForWidth(mi->sizePolicy().hasHeightForWidth());
        mi->setSizePolicy(sizePolicy3);
        mi->setFont(font2);
        mi->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"    background-color: rgb(201, 201, 201);\n"
"}"));

        gridLayout->addWidget(mi, 3, 0, 1, 1);

        jing = new QPushButton(page);
        jing->setObjectName(QStringLiteral("jing"));
        sizePolicy3.setHeightForWidth(jing->sizePolicy().hasHeightForWidth());
        jing->setSizePolicy(sizePolicy3);
        jing->setFont(font2);
        jing->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"    background-color: rgb(201, 201, 201);\n"
"}"));

        gridLayout->addWidget(jing, 3, 2, 1, 1);

        zero = new QPushButton(page);
        zero->setObjectName(QStringLiteral("zero"));
        sizePolicy3.setHeightForWidth(zero->sizePolicy().hasHeightForWidth());
        zero->setSizePolicy(sizePolicy3);
        zero->setFont(font2);
        zero->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"    background-color: rgb(201, 201, 201);\n"
"}"));

        gridLayout->addWidget(zero, 3, 1, 1, 1);

        nine = new QPushButton(page);
        nine->setObjectName(QStringLiteral("nine"));
        sizePolicy3.setHeightForWidth(nine->sizePolicy().hasHeightForWidth());
        nine->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        nine->setFont(font3);
        nine->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"    background-color: rgb(201, 201, 201);\n"
"}"));

        gridLayout->addWidget(nine, 2, 2, 1, 1);

        six = new QPushButton(page);
        six->setObjectName(QStringLiteral("six"));
        sizePolicy3.setHeightForWidth(six->sizePolicy().hasHeightForWidth());
        six->setSizePolicy(sizePolicy3);
        six->setFont(font2);
        six->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"    background-color: rgb(201, 201, 201);\n"
"}"));

        gridLayout->addWidget(six, 1, 2, 1, 1);

        five = new QPushButton(page);
        five->setObjectName(QStringLiteral("five"));
        sizePolicy3.setHeightForWidth(five->sizePolicy().hasHeightForWidth());
        five->setSizePolicy(sizePolicy3);
        five->setFont(font2);
        five->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"    background-color: rgb(201, 201, 201);\n"
"}"));

        gridLayout->addWidget(five, 1, 1, 1, 1);

        eight = new QPushButton(page);
        eight->setObjectName(QStringLiteral("eight"));
        sizePolicy3.setHeightForWidth(eight->sizePolicy().hasHeightForWidth());
        eight->setSizePolicy(sizePolicy3);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Adobe \344\273\277\345\256\213 Std R"));
        font4.setPointSize(13);
        font4.setBold(true);
        font4.setWeight(75);
        font4.setStrikeOut(false);
        eight->setFont(font4);
        eight->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"    background-color: rgb(201, 201, 201);\n"
"}"));

        gridLayout->addWidget(eight, 2, 1, 1, 1);

        seven = new QPushButton(page);
        seven->setObjectName(QStringLiteral("seven"));
        sizePolicy3.setHeightForWidth(seven->sizePolicy().hasHeightForWidth());
        seven->setSizePolicy(sizePolicy3);
        seven->setFont(font2);
        seven->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"    background-color: rgb(201, 201, 201);\n"
"}"));

        gridLayout->addWidget(seven, 2, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        horizontalLayout_4 = new QHBoxLayout(page_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        listWidget = new QListWidget(page_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
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

        horizontalLayout_4->addWidget(listWidget);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        horizontalLayout_5 = new QHBoxLayout(page_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        listWidget_2 = new QListWidget(page_3);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));

        horizontalLayout_5->addWidget(listWidget_2);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        horizontalLayout_6 = new QHBoxLayout(page_4);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        listWidget_3 = new QListWidget(page_4);
        listWidget_3->setObjectName(QStringLiteral("listWidget_3"));
        listWidget_3->setStyleSheet(QLatin1String("\n"
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

        horizontalLayout_6->addWidget(listWidget_3);

        stackedWidget->addWidget(page_4);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_2->addLayout(verticalLayout);

        frame_4 = new QFrame(sip_clientClass);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setMinimumSize(QSize(380, 60));
        frame_4->setStyleSheet(QStringLiteral("background-color:rgb(244, 244, 244);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        stack_dialog = new QPushButton(frame_4);
        stack_dialog->setObjectName(QStringLiteral("stack_dialog"));
        stack_dialog->setGeometry(QRect(10, 10, 70, 40));
        sizePolicy2.setHeightForWidth(stack_dialog->sizePolicy().hasHeightForWidth());
        stack_dialog->setSizePolicy(sizePolicy2);
        stack_dialog->setFlat(true);
        statk_list = new QPushButton(frame_4);
        statk_list->setObjectName(QStringLiteral("statk_list"));
        statk_list->setGeometry(QRect(100, 10, 70, 40));
        sizePolicy2.setHeightForWidth(statk_list->sizePolicy().hasHeightForWidth());
        statk_list->setSizePolicy(sizePolicy2);
        statk_list->setFlat(true);
        stack_favorite = new QPushButton(frame_4);
        stack_favorite->setObjectName(QStringLiteral("stack_favorite"));
        stack_favorite->setGeometry(QRect(190, 10, 70, 40));
        sizePolicy2.setHeightForWidth(stack_favorite->sizePolicy().hasHeightForWidth());
        stack_favorite->setSizePolicy(sizePolicy2);
        stack_favorite->setFlat(true);
        stack_record = new QPushButton(frame_4);
        stack_record->setObjectName(QStringLiteral("stack_record"));
        stack_record->setGeometry(QRect(280, 10, 70, 40));
        sizePolicy2.setHeightForWidth(stack_record->sizePolicy().hasHeightForWidth());
        stack_record->setSizePolicy(sizePolicy2);
        stack_record->setFlat(true);

        verticalLayout_2->addWidget(frame_4);

        frame_5 = new QFrame(sip_clientClass);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setMinimumSize(QSize(380, 30));
        frame_5->setStyleSheet(QStringLiteral("background-color:rgb(43, 43, 43)"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(frame_5);


        retranslateUi(sip_clientClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(sip_clientClass);
    } // setupUi

    void retranslateUi(QWidget *sip_clientClass)
    {
        sip_clientClass->setWindowTitle(QApplication::translate("sip_clientClass", "sip_client", 0));
        label->setText(QApplication::translate("sip_clientClass", "X_LITE", 0));
        pushbutton_setting->setText(QApplication::translate("sip_clientClass", "\350\256\276\347\275\256", 0));
        pushButton_view->setText(QApplication::translate("sip_clientClass", "\350\247\206\345\233\276", 0));
        pushButton_contact->setText(QApplication::translate("sip_clientClass", "\350\277\236\346\216\245", 0));
        pushbutton_help->setText(QApplication::translate("sip_clientClass", "\345\270\256\345\212\251", 0));
        pushButton_state->setText(QString());
        pushbutton_message->setText(QString());
        pushbutton_voice->setText(QString());
        pushButton_delete->setText(QString());
        pushbutton_call->setText(QString());
        pushButton_call_menu->setText(QString());
        four->setText(QApplication::translate("sip_clientClass", "4", 0));
        three->setText(QApplication::translate("sip_clientClass", "3", 0));
        two->setText(QApplication::translate("sip_clientClass", "2", 0));
        one->setText(QApplication::translate("sip_clientClass", "1", 0));
        mi->setText(QApplication::translate("sip_clientClass", "*", 0));
        jing->setText(QApplication::translate("sip_clientClass", "#", 0));
        zero->setText(QApplication::translate("sip_clientClass", "0", 0));
        nine->setText(QApplication::translate("sip_clientClass", "9", 0));
        six->setText(QApplication::translate("sip_clientClass", "6", 0));
        five->setText(QApplication::translate("sip_clientClass", "5", 0));
        eight->setText(QApplication::translate("sip_clientClass", "8", 0));
        seven->setText(QApplication::translate("sip_clientClass", "7", 0));
        stack_dialog->setText(QString());
        statk_list->setText(QString());
        stack_favorite->setText(QString());
        stack_record->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class sip_clientClass: public Ui_sip_clientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIP_CLIENT_H
