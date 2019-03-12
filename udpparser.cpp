#include "udpparser.h"
#include <QTime>
#include <QDataStream>

UdpParser::UdpParser(QObject *parent) : QObject(parent)
{
    ringBuffer = std::make_shared<RingBuffer>(65536);  //the whole cycle of data numbers 0..65535
}

void UdpParser::setFree()
{
    this->isParserFree = true;
}

void UdpParser::setBusy()
{
    this->isParserFree = false;
}

bool UdpParser::isFree()
{
    return this->isParserFree;
}

quint64 UdpParser::lostPacket(const ParsedUdpPacket &pack)
{
    static quint64 previousPacketNo = 0;
    //qDebug() << "previousPacket = " << previousPacketNo;
    bool delta = (pack.packetNumber - previousPacketNo) > 2;
    //auto delta = pack.packetNumber /*- previousPacketNo*/;
    previousPacketNo = pack.packetNumber;
   // if(pack.)
    return delta;
}

void UdpParser::parseReceivedDatagram(QByteArray received_packet)
{
    setBusy();
    auto mssec = received_packet.mid(8,8).toHex();
    auto parsedTime =  strtoull(mssec.data(), nullptr, 16); //extract packet unix time

    PacketDateTime packetTime;
    packetTime.setMSecsSinceEpoch(parsedTime);

    quint64 packetNo = strtoull(received_packet.mid(2,2).toHex().data(), nullptr, 16); //extract packet number

    QVector<QByteArray>  channelsData;
    channelsData.reserve(CHANNEL_NUMBERS);

    for (int i = 1; i <= CHANNEL_NUMBERS; ++i) {   //extract 4 bytes for each channel
        channelsData.push_back(received_packet.mid(16 + (i - 1) * 4, 4));
    }

    ringBuffer->push_back({packetNo, packetTime, channelsData});
    //qDebug() << ringBuffer->front().timeStamp;
}
















