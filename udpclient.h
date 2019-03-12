#ifndef UDPMANAGER_H
#define UDPMANAGER_H
#include <QUdpSocket>
#include <QNetworkDatagram>

//sudo ip address add 192.168.1.1/24 dev enp0s8
//pgAdmin4    http://127.0.0.1:40251/

class UdpClient : public QObject
{
    Q_OBJECT

public:
    explicit UdpClient(QObject *parent = nullptr);
    virtual ~UdpClient();

    QByteArray getUdpServerDatagram();
    quint16 getPort() const;
    void setPort(const quint16 &value);
    bool isStarted();
    void stop();
    void processTheDatagram(QNetworkDatagram datagram);
    const QUdpSocket& getSocket() const;

signals:
    void datagramReceived(QByteArray receivedData);
    void finished();
public slots:
    void start();

private slots:
    void processPendingDatagrams();

private:
    QUdpSocket *m_socket;
    QByteArray buffer;
    bool startFlag = false;
    quint16 m_port = 32768;
    QString hostAddress = "192.168.1.1";
};


#endif // UDPMANAGER_H
