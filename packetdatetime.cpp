#include "packetdatetime.h"

PacketDateTime::PacketDateTime()
{

}

PacketDateTime::PacketDateTime(PacketDateTime &other):
    QDateTime(other)
{
    microsec = other.getMicroSec();
}

PacketDateTime &PacketDateTime::operator=(PacketDateTime &other)
{
    if (this != &other){
        QDateTime::operator=(other);
        this->microsec = other.microsec;
    }
    return *this;
}

PacketDateTime::PacketDateTime(PacketDateTime &&other):
    QDateTime(std::move(other)), microsec(std::move(other.microsec))
{

}

PacketDateTime &PacketDateTime::operator=(PacketDateTime &&other)
{
    if (this != &other){
        QDateTime::operator=(std::move(other));
        microsec = std::move(other.microsec);
    }
    return *this;
}

PacketDateTime::~PacketDateTime()
{

}

void PacketDateTime::setMSecsSinceEpoch(unsigned long long msecs)
{
    QDateTime::setMSecsSinceEpoch(msecs / 10);    //standart Unix Time with millisec accuracy
    microsec = msecs % 10;
}

uint PacketDateTime::getMicroSec() const{
    return microsec;
}

