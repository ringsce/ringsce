/********************************************************************************
** Form generated from reading UI file 'new_project.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_PROJECT_H
#define UI_NEW_PROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWizard>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_NewProject
{
public:
    QWizardPage *wizardPage1;
    QWizardPage *wizardPage2;
    QWizardPage *wizardPage4;
    QWizardPage *wizardPage3;

    void setupUi(QWizard *NewProject)
    {
        if (NewProject->objectName().isEmpty())
            NewProject->setObjectName(QStringLiteral("NewProject"));
        NewProject->resize(400, 300);
        wizardPage1 = new QWizardPage();
        wizardPage1->setObjectName(QStringLiteral("wizardPage1"));
        NewProject->addPage(wizardPage1);
        wizardPage2 = new QWizardPage();
        wizardPage2->setObjectName(QStringLiteral("wizardPage2"));
        NewProject->addPage(wizardPage2);
        wizardPage4 = new QWizardPage();
        wizardPage4->setObjectName(QStringLiteral("wizardPage4"));
        NewProject->addPage(wizardPage4);
        wizardPage3 = new QWizardPage();
        wizardPage3->setObjectName(QStringLiteral("wizardPage3"));
        NewProject->addPage(wizardPage3);

        retranslateUi(NewProject);

        QMetaObject::connectSlotsByName(NewProject);
    } // setupUi

    void retranslateUi(QWizard *NewProject)
    {
        NewProject->setWindowTitle(QApplication::translate("NewProject", "Wizard", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewProject: public Ui_NewProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_PROJECT_H
