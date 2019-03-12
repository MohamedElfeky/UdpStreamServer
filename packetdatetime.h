#ifndef PACKETDATETIME_H
#define PACKETDATETIME_H
#include <QDateTime>

class PacketDateTime : public QDateTime
{
public:
    PacketDateTime();
    PacketDateTime(PacketDateTime& other);
    PacketDateTime &operator=(PacketDateTime& other);

    PacketDateTime(PacketDateTime&& other);
    PacketDateTime &operator=(PacketDateTime&& other);

    virtual ~PacketDateTime();

    void setMSecsSinceEpoch(unsigned long long msecs);
    uint getMicroSec() const;

protected:
    uint microsec = 0; //number of hundreds of microsec in time
};

#endif // PACKETDATETIME_H
