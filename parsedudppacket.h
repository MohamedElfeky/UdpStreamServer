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
    ParsedUdpPacket(const ParsedUdpPacket& other);
    //move constructor
    ParsedUdpPacket(const ParsedUdpPacket&& other);
    //copy assigment
    ParsedUdpPacket &operator=(const ParsedUdpPacket& other);
    //move assigment
    ParsedUdpPacket &operator=(const ParsedUdpPacket&& other);

    ~ParsedUdpPacket();
};

#endif // PARSEDUDPPACKET_H
