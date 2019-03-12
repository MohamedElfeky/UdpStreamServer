#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QObject>
#include <QTime>
#include <QFile>

#include <boost/circular_buffer.hpp>

#include "udpmanager.h"
#include "udpclient.h"

void delay(int msec, QCoreApplication& a){
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < dieTime)
    {
        a.processEvents(QEventLoop::AllEvents);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    UDPManager m;
    m.startUdp();



    return a.exec();
}
