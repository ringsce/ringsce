/********************************************************************************
** Form generated from reading UI file 'new_file.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_FILE_H
#define UI_NEW_FILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWizard>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_NewFile
{
public:
    QWizardPage *Default;
    QWizardPage *wizardPage2;
    QWizardPage *wizardPage4;
    QWizardPage *EndPage;

    void setupUi(QWizard *NewFile)
    {
        if (NewFile->objectName().isEmpty())
            NewFile->setObjectName(QStringLiteral("NewFile"));
        NewFile->resize(400, 300);
        Default = new QWizardPage();
        Default->setObjectName(QStringLiteral("Default"));
        NewFile->addPage(Default);
        wizardPage2 = new QWizardPage();
        wizardPage2->setObjectName(QStringLiteral("wizardPage2"));
        NewFile->addPage(wizardPage2);
        wizardPage4 = new QWizardPage();
        wizardPage4->setObjectName(QStringLiteral("wizardPage4"));
        NewFile->addPage(wizardPage4);
        EndPage = new QWizardPage();
        EndPage->setObjectName(QStringLiteral("EndPage"));
        NewFile->addPage(EndPage);

        retranslateUi(NewFile);

        QMetaObject::connectSlotsByName(NewFile);
    } // setupUi

    void retranslateUi(QWizard *NewFile)
    {
        NewFile->setWindowTitle(QApplication::translate("NewFile", "Wizard", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewFile: public Ui_NewFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_FILE_H
