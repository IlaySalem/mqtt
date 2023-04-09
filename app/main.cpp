
#include "example.h"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    /*
    QMQTT::Client* client = new QMQTT::Client(QHostAddress::LocalHost, 1893);
    client->setClientId("clientId");
    client->setUsername("user");
    client->setPassword("password");
    client->connectToHost();

     QObject::connect(client, &QMQTT::Client::connected, [=]() {
         qDebug() << "connected";
     });
     QObject::connect(client, &QMQTT::Client::subscribed, [=](const QString& topic, const quint8 qos = 0) {
         qDebug() << "subscribed" << topic << qos;
     });
     QObject::connect(client, &QMQTT::Client::unsubscribed, [=](const QString& topic) {
         qDebug() << "unsubscribed" << topic;
     });
     QObject::connect(client, &QMQTT::Client::published, [=](const QMQTT::Message& message, quint16 msgid = 0) {
         qDebug() << "published" << message.topic() << msgid;
     });
     QObject::connect(client, &QMQTT::Client::received, [=](const QMQTT::Message& message) {
         qDebug() << "message:" << message.topic();
     });
     */
    Subscriber subscriber;
    subscriber.connectToHost();
    Publisher publisher;
    publisher.connectToHost();

    return app.exec();
}
