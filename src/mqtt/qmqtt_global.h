#pragma once

#include <QtCore/qglobal.h>

#if defined(QMQTT_LIBRARY)
#define Q_MQTT_EXPORT Q_DECL_EXPORT
#else
#define Q_MQTT_EXPORT Q_DECL_IMPORT
#endif
