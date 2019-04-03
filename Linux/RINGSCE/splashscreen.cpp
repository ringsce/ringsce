#include <QApplication>
#include <QSplashScreen>
#include <qthread.h>

class I : public QThread
{
public:
    static void sleep(unsigned long secs) { QThread::sleep(secs); }
};
