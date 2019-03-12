QT       += core network
QT       -= gui

CONFIG += c++14 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    udpparser.cpp \
    udpclient.cpp \
    udpmanager.cpp \
    databasemanager.cpp \
    packetdatetime.cpp \
    parsedudppacket.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    udpparser.h \
    udpclient.h \
    udpmanager.h \
    databasemanager.h \
    packetdatetime.h \
    parsedudppacket.h

# remove possible other optimization flags
QMAKE_CXXFLAGS -= -O
QMAKE_CXXFLAGS -= -O1
QMAKE_CXXFLAGS -= -O2

# add the desired -O3 if not present
QMAKE_CXXFLAGS += -O3

QMAKE_CXXFLAGS_RELEASE += -finline-small-functions

LIBS += \
       -lboost_system\
#sudo aptitude install libboost-all-dev

QMAKE_CFLAGS_DEBUG +=  -DBOOST_CB_DISABLE_DEBUG -DNDEBUG


