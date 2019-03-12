#include "udpclient.h"

UdpClient::UdpClient(QObject *parent): QObject (parent)
{
}

bool UdpClient::isStarted()
{
    return startFlag;
}

void UdpClient::start()
{
    qDebug() << "start udpManager";
    m_socket = new QUdpSocket(this);

    if(m_socket->bind(QHostAddress(hostAddress), m_port)){
        connect(m_socket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
        qDebug() << "Binding is OK";
    } else {
        qDebug() << "Binding is BAD";
    }
    this->startFlag = true;
}
/**
 * @brief UdpServer::processPendingDatagrams
 */
void UdpClient::processPendingDatagrams()
{
    while (m_socket->hasPendingDatagrams()) {
        //QHostAddress sender;
        //quint16 senderPort;
        //qint64 readCount = m_udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
        QNetworkDatagram datagram = m_socket->receiveDatagram(m_socket->pendingDatagramSize());
        processTheDatagram(datagram);
    }
}

void UdpClient::stop()
{
    m_socket->abort();
    disconnect(m_socket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
    this->startFlag = false;
    m_socket->deleteLater();
    emit finished();
}

void UdpClient::processTheDatagram(QNetworkDatagram datagram)
{
    buffer = datagram.data();
  //  qDebug() << buffer;
    emit datagramReceived(buffer);
}

const QUdpSocket &UdpClient::getSocket() const
{
    return *m_socket;
}

quint16 UdpClient::getPort() const
{
   return this->m_port;
}

void UdpClient::setPort(const quint16 &value)
{
    this->m_port = value;
}

/**
 * @brief UdpServer::~UdpServer
 */
UdpClient::~UdpClient()
{
}

QByteArray UdpClient::getUdpServerDatagram()
{
    return this->buffer;
}


