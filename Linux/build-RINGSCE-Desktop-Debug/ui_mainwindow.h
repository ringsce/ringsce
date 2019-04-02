/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewProject;
    QAction *actionNewFile;
    QAction *actionEdit;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionSaveAll;
    QAction *actionClose;
    QAction *actionCloseAll;
    QAction *actionExit;
    QAction *actionBuild;
    QAction *actionBuildAll;
    QAction *actionClean;
    QAction *actionCleanAll;
    QAction *actionCLang;
    QAction *actionSettings;
    QAction *actionCompilers;
    QAction *actionUpdate;
    QAction *actionAbout;
    QAction *actionCVS;
    QAction *actionChat;
    QAction *actionGithub;
    QAction *actionSubversion;
    QAction *actionMercurial;
    QAction *actionBazaar;
    QAction *actionCompilers_2;
    QAction *actionSdks;
    QAction *actionIncludes;
    QAction *actionPlugins;
    QAction *actionAddIns;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionPaste;
    QAction *actionSelect;
    QAction *actionSelectAll;
    QAction *actionFind;
    QAction *actionFindReplace;
    QAction *actionSearch;
    QAction *actionGDB_2;
    QAction *actionDeploy;
    QAction *actionDepoyWithoutDebugging;
    QAction *actionRun;
    QAction *actionRunWithoutDeployment;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuPreferences;
    QMenu *menuEdit;
    QMenu *menuBuild;
    QMenu *menuAnalyze;
    QMenu *menuDebug;
    QMenu *menuDebug_2;
    QMenu *menuAbout;
    QMenu *menuTools;
    QMenu *menuTeam;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RINGS_CE___Community_Edition)
    {
        if (RINGS_CE___Community_Edition->objectName().isEmpty())
            RINGS_CE___Community_Edition->setObjectName(QStringLiteral("RINGS_CE___Community_Edition"));
        RINGS_CE___Community_Edition->resize(800, 600);
        actionNewProject = new QAction(RINGS_CE___Community_Edition);
        actionNewProject->setObjectName(QStringLiteral("actionNewProject"));
        actionNewFile = new QAction(RINGS_CE___Community_Edition);
        actionNewFile->setObjectName(QStringLiteral("actionNewFile"));
        actionEdit = new QAction(RINGS_CE___Community_Edition);
        actionEdit->setObjectName(QStringLiteral("actionEdit"));
        actionSave = new QAction(RINGS_CE___Community_Edition);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSaveAs = new QAction(RINGS_CE___Community_Edition);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionSaveAll = new QAction(RINGS_CE___Community_Edition);
        actionSaveAll->setObjectName(QStringLiteral("actionSaveAll"));
        actionClose = new QAction(RINGS_CE___Community_Edition);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionCloseAll = new QAction(RINGS_CE___Community_Edition);
        actionCloseAll->setObjectName(QStringLiteral("actionCloseAll"));
        actionExit = new QAction(RINGS_CE___Community_Edition);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionBuild = new QAction(RINGS_CE___Community_Edition);
        actionBuild->setObjectName(QStringLiteral("actionBuild"));
        actionBuildAll = new QAction(RINGS_CE___Community_Edition);
        actionBuildAll->setObjectName(QStringLiteral("actionBuildAll"));
        actionClean = new QAction(RINGS_CE___Community_Edition);
        actionClean->setObjectName(QStringLiteral("actionClean"));
        actionCleanAll = new QAction(RINGS_CE___Community_Edition);
        actionCleanAll->setObjectName(QStringLiteral("actionCleanAll"));
        actionCLang = new QAction(RINGS_CE___Community_Edition);
        actionCLang->setObjectName(QStringLiteral("actionCLang"));
        actionSettings = new QAction(RINGS_CE___Community_Edition);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionCompilers = new QAction(RINGS_CE___Community_Edition);
        actionCompilers->setObjectName(QStringLiteral("actionCompilers"));
        actionUpdate = new QAction(RINGS_CE___Community_Edition);
        actionUpdate->setObjectName(QStringLiteral("actionUpdate"));
        actionAbout = new QAction(RINGS_CE___Community_Edition);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionCVS = new QAction(RINGS_CE___Community_Edition);
        actionCVS->setObjectName(QStringLiteral("actionCVS"));
        actionChat = new QAction(RINGS_CE___Community_Edition);
        actionChat->setObjectName(QStringLiteral("actionChat"));
        actionGithub = new QAction(RINGS_CE___Community_Edition);
        actionGithub->setObjectName(QStringLiteral("actionGithub"));
        actionSubversion = new QAction(RINGS_CE___Community_Edition);
        actionSubversion->setObjectName(QStringLiteral("actionSubversion"));
        actionMercurial = new QAction(RINGS_CE___Community_Edition);
        actionMercurial->setObjectName(QStringLiteral("actionMercurial"));
        actionBazaar = new QAction(RINGS_CE___Community_Edition);
        actionBazaar->setObjectName(QStringLiteral("actionBazaar"));
        actionCompilers_2 = new QAction(RINGS_CE___Community_Edition);
        actionCompilers_2->setObjectName(QStringLiteral("actionCompilers_2"));
        actionSdks = new QAction(RINGS_CE___Community_Edition);
        actionSdks->setObjectName(QStringLiteral("actionSdks"));
        actionIncludes = new QAction(RINGS_CE___Community_Edition);
        actionIncludes->setObjectName(QStringLiteral("actionIncludes"));
        actionPlugins = new QAction(RINGS_CE___Community_Edition);
        actionPlugins->setObjectName(QStringLiteral("actionPlugins"));
        actionAddIns = new QAction(RINGS_CE___Community_Edition);
        actionAddIns->setObjectName(QStringLiteral("actionAddIns"));
        actionUndo = new QAction(RINGS_CE___Community_Edition);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(RINGS_CE___Community_Edition);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionCut = new QAction(RINGS_CE___Community_Edition);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionPaste = new QAction(RINGS_CE___Community_Edition);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionSelect = new QAction(RINGS_CE___Community_Edition);
        actionSelect->setObjectName(QStringLiteral("actionSelect"));
        actionSelectAll = new QAction(RINGS_CE___Community_Edition);
        actionSelectAll->setObjectName(QStringLiteral("actionSelectAll"));
        actionFind = new QAction(RINGS_CE___Community_Edition);
        actionFind->setObjectName(QStringLiteral("actionFind"));
        actionFindReplace = new QAction(RINGS_CE___Community_Edition);
        actionFindReplace->setObjectName(QStringLiteral("actionFindReplace"));
        actionSearch = new QAction(RINGS_CE___Community_Edition);
        actionSearch->setObjectName(QStringLiteral("actionSearch"));
        actionGDB_2 = new QAction(RINGS_CE___Community_Edition);
        actionGDB_2->setObjectName(QStringLiteral("actionGDB_2"));
        actionDeploy = new QAction(RINGS_CE___Community_Edition);
        actionDeploy->setObjectName(QStringLiteral("actionDeploy"));
        actionDepoyWithoutDebugging = new QAction(RINGS_CE___Community_Edition);
        actionDepoyWithoutDebugging->setObjectName(QStringLiteral("actionDepoyWithoutDebugging"));
        actionRun = new QAction(RINGS_CE___Community_Edition);
        actionRun->setObjectName(QStringLiteral("actionRun"));
        actionRunWithoutDeployment = new QAction(RINGS_CE___Community_Edition);
        actionRunWithoutDeployment->setObjectName(QStringLiteral("actionRunWithoutDeployment"));
        centralwidget = new QWidget(RINGS_CE___Community_Edition);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        RINGS_CE___Community_Edition->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RINGS_CE___Community_Edition);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuPreferences = new QMenu(menuFile);
        menuPreferences->setObjectName(QStringLiteral("menuPreferences"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuBuild = new QMenu(menubar);
        menuBuild->setObjectName(QStringLiteral("menuBuild"));
        menuAnalyze = new QMenu(menubar);
        menuAnalyze->setObjectName(QStringLiteral("menuAnalyze"));
        menuDebug = new QMenu(menubar);
        menuDebug->setObjectName(QStringLiteral("menuDebug"));
        menuDebug_2 = new QMenu(menuDebug);
        menuDebug_2->setObjectName(QStringLiteral("menuDebug_2"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuTeam = new QMenu(menubar);
        menuTeam->setObjectName(QStringLiteral("menuTeam"));
        RINGS_CE___Community_Edition->setMenuBar(menubar);
        statusbar = new QStatusBar(RINGS_CE___Community_Edition);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        RINGS_CE___Community_Edition->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuBuild->menuAction());
        menubar->addAction(menuAnalyze->menuAction());
        menubar->addAction(menuDebug->menuAction());
        menubar->addAction(menuTeam->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNewProject);
        menuFile->addAction(actionNewFile);
        menuFile->addAction(actionEdit);
        menuFile->addAction(menuPreferences->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addAction(actionSaveAll);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionCloseAll);
        menuFile->addAction(actionExit);
        menuPreferences->addAction(actionSettings);
        menuPreferences->addAction(actionCompilers);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionSelect);
        menuEdit->addAction(actionSelectAll);
        menuEdit->addAction(actionFind);
        menuEdit->addAction(actionFindReplace);
        menuEdit->addAction(actionSearch);
        menuBuild->addAction(actionBuild);
        menuBuild->addAction(actionBuildAll);
        menuBuild->addAction(actionClean);
        menuBuild->addAction(actionCleanAll);
        menuBuild->addAction(actionRun);
        menuBuild->addAction(actionRunWithoutDeployment);
        menuAnalyze->addAction(actionCLang);
        menuAnalyze->addAction(actionGDB_2);
        menuDebug->addAction(menuDebug_2->menuAction());
        menuDebug_2->addAction(actionDeploy);
        menuDebug_2->addAction(actionDepoyWithoutDebugging);
        menuAbout->addAction(actionUpdate);
        menuAbout->addAction(actionAbout);
        menuTools->addAction(actionCompilers_2);
        menuTools->addAction(actionSdks);
        menuTools->addAction(actionIncludes);
        menuTools->addAction(actionPlugins);
        menuTools->addAction(actionAddIns);
        menuTeam->addAction(actionChat);
        menuTeam->addAction(actionCVS);
        menuTeam->addAction(actionGithub);
        menuTeam->addAction(actionSubversion);
        menuTeam->addAction(actionMercurial);
        menuTeam->addAction(actionBazaar);

        retranslateUi(RINGS_CE___Community_Edition);

        QMetaObject::connectSlotsByName(RINGS_CE___Community_Edition);
    } // setupUi

    void retranslateUi(QMainWindow *RINGS_CE___Community_Edition)
    {
        RINGS_CE___Community_Edition->setWindowTitle(QApplication::translate("MainWindow", "RINGSCE - Community Edition", Q_NULLPTR));
        actionNewProject->setText(QApplication::translate("MainWindow", "New Project", Q_NULLPTR));
        actionNewFile->setText(QApplication::translate("MainWindow", "New File", Q_NULLPTR));
        actionEdit->setText(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionSaveAs->setText(QApplication::translate("MainWindow", "Save As", Q_NULLPTR));
        actionSaveAll->setText(QApplication::translate("MainWindow", "Save All", Q_NULLPTR));
        actionClose->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        actionCloseAll->setText(QApplication::translate("MainWindow", "Close All", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionBuild->setText(QApplication::translate("MainWindow", "Build", Q_NULLPTR));
        actionBuildAll->setText(QApplication::translate("MainWindow", "Build All", Q_NULLPTR));
        actionClean->setText(QApplication::translate("MainWindow", "Clean", Q_NULLPTR));
        actionCleanAll->setText(QApplication::translate("MainWindow", "Clean All", Q_NULLPTR));
        actionCLang->setText(QApplication::translate("MainWindow", "CLang", Q_NULLPTR));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        actionCompilers->setText(QApplication::translate("MainWindow", "Compilers", Q_NULLPTR));
        actionUpdate->setText(QApplication::translate("MainWindow", "Update", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionCVS->setText(QApplication::translate("MainWindow", "CVS", Q_NULLPTR));
        actionChat->setText(QApplication::translate("MainWindow", "Team Chat", Q_NULLPTR));
        actionGithub->setText(QApplication::translate("MainWindow", "Github", Q_NULLPTR));
        actionSubversion->setText(QApplication::translate("MainWindow", "Subversion", Q_NULLPTR));
        actionMercurial->setText(QApplication::translate("MainWindow", "Mercurial", Q_NULLPTR));
        actionBazaar->setText(QApplication::translate("MainWindow", "Bazaar", Q_NULLPTR));
        actionCompilers_2->setText(QApplication::translate("MainWindow", "Compilers", Q_NULLPTR));
        actionSdks->setText(QApplication::translate("MainWindow", "Sdks", Q_NULLPTR));
        actionIncludes->setText(QApplication::translate("MainWindow", "Includes", Q_NULLPTR));
        actionPlugins->setText(QApplication::translate("MainWindow", "Plugins", Q_NULLPTR));
        actionAddIns->setText(QApplication::translate("MainWindow", "Add-Ins", Q_NULLPTR));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", Q_NULLPTR));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", Q_NULLPTR));
        actionSelect->setText(QApplication::translate("MainWindow", "Select", Q_NULLPTR));
        actionSelectAll->setText(QApplication::translate("MainWindow", "Select All", Q_NULLPTR));
        actionFind->setText(QApplication::translate("MainWindow", "Find ", Q_NULLPTR));
        actionFindReplace->setText(QApplication::translate("MainWindow", "Find & Replace", Q_NULLPTR));
        actionSearch->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        actionGDB_2->setText(QApplication::translate("MainWindow", "GDB", Q_NULLPTR));
        actionDeploy->setText(QApplication::translate("MainWindow", "Deploy", Q_NULLPTR));
        actionDepoyWithoutDebugging->setText(QApplication::translate("MainWindow", "Depoy without Debugging", Q_NULLPTR));
        actionRun->setText(QApplication::translate("MainWindow", "Run", Q_NULLPTR));
        actionRunWithoutDeployment->setText(QApplication::translate("MainWindow", "Run without Deployment", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuPreferences->setTitle(QApplication::translate("MainWindow", "Preferences", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuBuild->setTitle(QApplication::translate("MainWindow", "Build", Q_NULLPTR));
        menuAnalyze->setTitle(QApplication::translate("MainWindow", "Analyze", Q_NULLPTR));
        menuDebug->setTitle(QApplication::translate("MainWindow", "Debug", Q_NULLPTR));
        menuDebug_2->setTitle(QApplication::translate("MainWindow", "Debug", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuTeam->setTitle(QApplication::translate("MainWindow", "Team", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
