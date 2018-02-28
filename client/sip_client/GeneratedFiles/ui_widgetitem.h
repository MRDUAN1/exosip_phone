/********************************************************************************
** Form generated from reading UI file 'widgetitem.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETITEM_H
#define UI_WIDGETITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetitem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;

    void setupUi(QWidget *widgetitem)
    {
        if (widgetitem->objectName().isEmpty())
            widgetitem->setObjectName(QStringLiteral("widgetitem"));
        widgetitem->resize(400, 69);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetitem->sizePolicy().hasHeightForWidth());
        widgetitem->setSizePolicy(sizePolicy);
        widgetitem->setMinimumSize(QSize(100, 50));
        horizontalLayout = new QHBoxLayout(widgetitem);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widgetitem);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(widgetitem);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(120, 20));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widgetitem);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(120, 25));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_4 = new QLabel(widgetitem);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(0, 30));
        label_4->setMaximumSize(QSize(16777215, 35));

        horizontalLayout->addWidget(label_4);


        retranslateUi(widgetitem);

        QMetaObject::connectSlotsByName(widgetitem);
    } // setupUi

    void retranslateUi(QWidget *widgetitem)
    {
        widgetitem->setWindowTitle(QApplication::translate("widgetitem", "widgetitem", 0));
        label->setText(QApplication::translate("widgetitem", "TextLabel", 0));
        label_2->setText(QApplication::translate("widgetitem", "TextLabel", 0));
        label_3->setText(QApplication::translate("widgetitem", "TextLabel", 0));
        label_4->setText(QApplication::translate("widgetitem", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class widgetitem: public Ui_widgetitem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETITEM_H
