#ifndef PACKETDATETIME_H
#define PACKETDATETIME_H
#include <QDateTime>

class PacketDateTime : public QDateTime
{
public:
    PacketDateTime();
    PacketDateTime(const PacketDateTime& other);
    PacketDateTime &operator=(const PacketDateTime& other);

    PacketDateTime(const PacketDateTime&& other);
    PacketDateTime &operator=(const PacketDateTime&& other);

    virtual ~PacketDateTime();

    void setMSecsSinceEpoch(unsigned long long msecs);
    uint getMicroSec() const;

protected:
    uint microsec = 0; //number of hundreds of microsec in time
};

#endif // PACKETDATETIME_H
