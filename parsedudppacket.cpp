#include "parsedudppacket.h"

ParsedUdpPacket::ParsedUdpPacket(quint64 packNo, PacketDateTime time, QVector<QByteArray> samples):
    packetNumber(packNo), timeStamp(time), data(samples)
{

}

ParsedUdpPacket::ParsedUdpPacket(ParsedUdpPacket &other)
{
    this->packetNumber = other.packetNumber;
    this->timeStamp = other.timeStamp;
    this->data = other.data;
}

ParsedUdpPacket &ParsedUdpPacket::operator=(ParsedUdpPacket &other)
{
    if (this != &other){
        this->packetNumber = other.packetNumber;
        this->timeStamp = other.timeStamp;
        this->data = other.data;
    }
    return *this;
}

ParsedUdpPacket::ParsedUdpPacket(ParsedUdpPacket &&other)
{
    this->packetNumber = std::move(other.packetNumber);
    this->timeStamp = std::move(other.timeStamp);
    this->data = std::move(other.data);
}

ParsedUdpPacket &ParsedUdpPacket::operator=(ParsedUdpPacket &&other)
{
    if (this != &other){
        this->packetNumber = std::move(other.packetNumber);
        this->timeStamp = std::move(other.timeStamp);
        this->data = std::move(other.data);
    }
    return *this;
}

ParsedUdpPacket::~ParsedUdpPacket()
{

}
