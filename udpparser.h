#ifndef UDPPARSER_H
#define UDPPARSER_H

#include <QObject>
#include <QVector>
#include <QDebug>
#include <QFile>

#include <boost/circular_buffer.hpp>
#include <memory>

#include "packetdatetime.h"
#include "parsedudppacket.h"

class UdpParser : public QObject
{
    Q_OBJECT

private:
    quint64 lostPacket(const ParsedUdpPacket& pack);

private:
    static const int CHANNEL_NUMBERS = 96;
    bool isParserFree = true;
    using  RingBuffer = boost::circular_buffer<ParsedUdpPacket>;
    std::shared_ptr<RingBuffer> ringBuffer;

public:
     explicit UdpParser(QObject *parent = nullptr);
     void setFree();
     void setBusy();
     bool isFree();

signals:


public slots:
    void parseReceivedDatagram(QByteArray received_packet);
};

#endif // UDPPARSER_H
