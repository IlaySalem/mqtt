TEMPLATE = app

CONFIG += c++17 cmdline
CONFIG -= app_bundle

QT = core network
QT -= gui

HEADERS += \
    example.h

SOURCES += \
    main.cpp
	
LIBS += -lqmqtt

include($$ROOT_QMQTT/qmqtt_include.pri)
include($$ROOT_PROJECT/build.pri)
