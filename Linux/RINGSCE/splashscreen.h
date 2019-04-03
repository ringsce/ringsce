#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QApplication>
#include <QSplashScreen>
#include <qthread.h>

class I : public QThread
{
public:
    static void sleep(unsigned long secs) { QThread::sleep(secs); }
};
#endif // SPLASHSCREEN_H
