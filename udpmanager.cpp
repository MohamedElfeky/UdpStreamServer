#include "udpmanager.h"

UDPManager::UDPManager(QObject *parent): QObject(parent)
{
    m_udpClient = new UdpClient;
    m_udpClientThread = new QThread;
    m_udpClient->moveToThread(m_udpClientThread);

    connect(m_udpClientThread, SIGNAL(started()), m_udpClient, SLOT(start()));
    connect(m_udpClient, SIGNAL(finished()), m_udpClientThread, SLOT(quit()));
    connect(m_udpClient, SIGNAL(finished()), m_udpClient, SLOT(deleteLater()));
    connect(m_udpClientThread, SIGNAL(finished()), m_udpClientThread, SLOT(deleteLater()));

    m_parser = new UdpParser;
    m_parserThread = new QThread;
    connect(m_udpClient, SIGNAL(datagramReceived(QByteArray)), this, SLOT(datagramReadyHandler(QByteArray)));
}

void UDPManager::startUdp()
{
    m_udpClientThread->start();
}

void UDPManager::stopUDP()
{
    m_udpClient->stop();
}

void UDPManager::datagramReadyHandler(QByteArray packet)
{
    this->m_parser->parseReceivedDatagram(packet);
}
