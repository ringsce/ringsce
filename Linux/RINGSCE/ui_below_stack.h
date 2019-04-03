/********************************************************************************
** Form generated from reading UI file 'below_stack.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BELOW_STACK_H
#define UI_BELOW_STACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StackedWidget
{
public:
    QWidget *page;
    QWidget *page1;

    void setupUi(QStackedWidget *StackedWidget)
    {
        if (StackedWidget->objectName().isEmpty())
            StackedWidget->setObjectName(QStringLiteral("StackedWidget"));
        StackedWidget->resize(400, 300);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        StackedWidget->addWidget(page);
        page1 = new QWidget();
        page1->setObjectName(QStringLiteral("page1"));
        StackedWidget->addWidget(page1);

        retranslateUi(StackedWidget);

        StackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StackedWidget);
    } // setupUi

    void retranslateUi(QStackedWidget *StackedWidget)
    {
        StackedWidget->setWindowTitle(QApplication::translate("StackedWidget", "StackedWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StackedWidget: public Ui_StackedWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BELOW_STACK_H
