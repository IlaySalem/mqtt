#pragma once
#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include <qmqtt.h>

const QHostAddress EXAMPLE_HOST  = QHostAddress::LocalHost;
const quint16      EXAMPLE_PORT  = 1893;
const QString      EXAMPLE_TOPIC = "qmqtt/exampletopic";

using namespace Qt;

class Publisher : public QMQTT::Client
{
    Q_OBJECT
public:
    explicit Publisher(const QHostAddress& host   = EXAMPLE_HOST,
                       const quint16       port   = EXAMPLE_PORT,
                       QObject*            parent = nullptr)
        : QMQTT::Client(host, port, parent)
        , _number(0)
    {
        connect(this, &Publisher::connected, this, &Publisher::onConnected);
        connect(&_timer, &QTimer::timeout, this, &Publisher::onTimeout);
        connect(this, &Publisher::disconnected, this, &Publisher::onDisconnected);
    }
    virtual ~Publisher() {}

    QTimer  _timer;
    quint16 _number;

public slots:
    void onConnected()
    {
        subscribe(EXAMPLE_TOPIC, 0);
        _timer.start(1000);
    }

    void onTimeout()
    {
        QMQTT::Message message(_number, EXAMPLE_TOPIC,
                               QString("Number is %1").arg(_number).toUtf8());
        publish(message);
        _number++;
        if (_number >= 10)
        {
            _timer.stop();
            disconnectFromHost();
        }
    }

    void onDisconnected()
    {
        QTimer::singleShot(0, qApp, &QCoreApplication::quit);
    }
};

class Subscriber : public QMQTT::Client
{
    Q_OBJECT
public:
    explicit Subscriber(const QHostAddress& host   = EXAMPLE_HOST,
                        const quint16       port   = EXAMPLE_PORT,
                        QObject*            parent = nullptr)
        : QMQTT::Client(host, port, parent)
    {
        connect(this, &Subscriber::connected, this, &Subscriber::onConnected);
        connect(this, &Subscriber::subscribed, this, &Subscriber::onSubscribed);
        connect(this, &Subscriber::received, this, &Subscriber::onReceived);
    }
    virtual ~Subscriber() {}

public slots:
    void onConnected()
    {
        qDebug() << "connected" << endl;
        subscribe(EXAMPLE_TOPIC, 0);
    }

    void onSubscribed(const QString& topic)
    {
        qDebug() << "subscribed " << topic << endl;
    }

    void onReceived(const QMQTT::Message& message)
    {
        qDebug() << "publish received: \"" << QString::fromUtf8(message.payload())
                 << "\"" << endl;
    }
};
