#include "mainwindow.h"
#include <QApplication>
#include "highlighter.h"
#include <QDesktopWidget>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QtWidgets>
#include <QPushButton>
#include "splashscreen.h"

//Create Wizard
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

// Main Function
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    QCoreApplication::setOrganizationName("Kreatyve Project");
    QCoreApplication::setApplicationName("RINGSCEIDE");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("file", "The file to open.");
    parser.process(app);


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

    wizard.setWindowTitle("RINGSCE Wizard");
    wizard.show();

    QPixmap pixmap("RINGSCE_v2.png");
    QSplashScreen splash(pixmap);
    splash.show();


    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }

    I::sleep(20); // splash is shown for 5 seconds

    w.showMaximized();
    splash.finish(&w);



    w.show();

    return app.exec();
}
