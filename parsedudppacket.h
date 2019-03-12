#ifndef PARSEDUDPPACKET_H
#define PARSEDUDPPACKET_H
#include <QVector>
#include "packetdatetime.h"

struct ParsedUdpPacket
{
    quint64 packetNumber = 0;
    PacketDateTime timeStamp;
    QVector<QByteArray> data;

    ParsedUdpPacket() = default;
    //costructor with parameters
    ParsedUdpPacket(quint64 packNo, PacketDateTime time, QVector<QByteArray> samples);

    //copy constructor
    ParsedUdpPacket(ParsedUdpPacket& other);
    //move constructor
    ParsedUdpPacket(ParsedUdpPacket&& other);
    //copy assigment
    ParsedUdpPacket &operator=(ParsedUdpPacket& other);
    //move assigment
    ParsedUdpPacket &operator=(ParsedUdpPacket&& other);

    ~ParsedUdpPacket();
};

#endif // PARSEDUDPPACKET_H
