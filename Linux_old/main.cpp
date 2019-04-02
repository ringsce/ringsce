#include <QApplication>
#include <QDesktopWidget>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QtWidgets>

#include "mainwindow.h"
#include "dialog.h"
#include "highlighter.h"
QWizardPage *createIntroPage()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("Introduction");

    QLabel *label = new QLabel("This wizard will help you register your copy "
                               "of Super Product Two.");
    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    page->setLayout(layout);

    return page;
}

// createSetupPage
QWizardPage *createSetupPage()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("Setup");
    page->setSubTitle("Please fill both fields.");

    QLabel *nameLabel = new QLabel("Name:");
    QLineEdit *nameLineEdit = new QLineEdit;

    QLabel *emailLabel = new QLabel("Email address:");
    QLineEdit *emailLineEdit = new QLineEdit;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(nameLineEdit, 0, 1);
    layout->addWidget(emailLabel, 1, 0);
    layout->addWidget(emailLineEdit, 1, 1);
    page->setLayout(layout);

    return page;
}

// createRegistrationPage
QWizardPage *createRegistrationPage()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("Registration");
    page->setSubTitle("Please fill both fields.");

    QLabel *nameLabel = new QLabel("Name:");
    QLineEdit *nameLineEdit = new QLineEdit;

    QLabel *emailLabel = new QLabel("Email address:");
    QLineEdit *emailLineEdit = new QLineEdit;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(nameLineEdit, 0, 1);
    layout->addWidget(emailLabel, 1, 0);
    layout->addWidget(emailLineEdit, 1, 1);
    page->setLayout(layout);

    return page;
}


// createConclusionPage
QWizardPage *createConclusionPage()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("Conclusion");

    QLabel *label = new QLabel("You are now successfully registered. Have a "
                               "nice day!");
    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    page->setLayout(layout);

    return page;
}


int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Kreatyve Project");
    QCoreApplication::setApplicationName("OpenKrownIDE");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("file", "The file to open.");
    parser.process(app);


     /*TextEdit mw;

      const QRect availableGeometry = QApplication::desktop()->availableGeometry(&mw);
      mw.resize(availableGeometry.width() / 2, (availableGeometry.height() * 2) / 3);
      mw.move((availableGeometry.width() - mw.width()) / 2,
               (availableGeometry.height() - mw.height()) / 2);

      if (!mw.load(parser.positionalArguments().value(0, QLatin1String(":/example.html"))))
           mw.fileNew();*/

#ifndef QT_NO_TRANSLATION
    QString translatorFileName = QLatin1String("qt_");
    translatorFileName += QLocale::system().name();
    QTranslator *translator = new QTranslator(&app);
    if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        app.installTranslator(translator);
#endif

    QWizard wizard;
    wizard.addPage(createIntroPage());
    wizard.addPage(createSetupPage());
    wizard.addPage(createRegistrationPage());
    wizard.addPage(createConclusionPage());

    wizard.setWindowTitle("Trivial Wizard");
    wizard.show();


    MainWindow window;
    window.resize(640, 512);
    window.show();

    Dialog dialog;
    dialog.show();

    //mw.show();

    return app.exec();
}
