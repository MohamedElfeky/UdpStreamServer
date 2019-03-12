#ifndef UDPTHREADWRAPPER_H
#define UDPTHREADWRAPPER_H
#include <QObject>
#include <QThread>
#include "udpclient.h"
#include "udpparser.h"

class UDPManager : public QObject
{
    Q_OBJECT
public:
    explicit UDPManager(QObject *parent = nullptr);

    void startUdp();

    void stopUDP();
signals:

public slots:
    void datagramReadyHandler(QByteArray packet);

private:
    UdpClient* m_udpClient;
    QThread* m_udpClientThread;

    UdpParser* m_parser;
    QThread* m_parserThread;
};




#endif // UDPTHREADWRAPPER_H
