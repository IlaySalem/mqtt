TARGET = qmqtt
TEMPLATE = lib
QT += core network
#qtHaveModule(websockets): QMQTT_WEBSOCKETS: QT += websockets

DEFINES += QMQTT_LIBRARY \
           QT_NO_CAST_TO_ASCII \
           QT_NO_CAST_FROM_ASCII \
           QT_NO_SSL
           #QT_WEBSOCKETS_LIB

CONFIG += NO_UNIT_TESTS QMQTT_NO_SSL dll


HEADERS += \
    qmqtt_global.h \
    qmqtt.h

include(qmqtt.pri)
include($$ROOT_PROJECT/build.pri)

HEADERS += $$PUBLIC_HEADERS $$PRIVATE_HEADERS

DISTFILES += \
    qmqtt_include.pri
