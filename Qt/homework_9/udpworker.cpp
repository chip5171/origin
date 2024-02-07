#include "udpworker.h"

UDPworker::UDPworker(QObject *parent) : QObject(parent)
{

    serviceUdpSocket = new QUdpSocket( this );
    userUdpSocket = new QUdpSocket( this );

    serviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT);
    connect(serviceUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::ReadServicePendingDatagrams);

    userUdpSocket->bind(QHostAddress::LocalHost, USER_PORT);
    connect(userUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::ReadUserPendingDatagrams);

}


void UDPworker::ReadUserDatagram(QNetworkDatagram datagram)
{

    QByteArray inputData;
    inputData = datagram.data( );

    senderIpAddress = datagram.senderAddress();

    QDataStream inputStream(&inputData, QIODevice::ReadOnly);

    QString data;
    inputStream >> data;

    emit sig_sendDataToGUI(data);

}

void UDPworker::ReadServiceDatagram(QNetworkDatagram datagram)
{

    QByteArray inputData;
    inputData = datagram.data( );

    QDataStream inputStream(&inputData, QIODevice::ReadOnly);

    QDateTime dateTime;
    inputStream >> dateTime;

    emit sig_sendTimeToGUI(dateTime);

}

void UDPworker::SendDatagram(const QByteArray &data, QUdpSocket *socket, qint16 port)
{

    QNetworkDatagram sendDatagram;

    sendDatagram.setDestination(QHostAddress::LocalHost, port);
    sendDatagram.setData(data);

    messageSize = socket->writeDatagram(sendDatagram);

//    qDebug() << ip4String;

}

//QHostAddress getSenderIpAddress()
//{

//    QNetworkDatagram sendDatagram;
//    sendDatagram

//}
void UDPworker::ReadServicePendingDatagrams( void )
{

    while( serviceUdpSocket->hasPendingDatagrams( ) ){

        QNetworkDatagram datagram = serviceUdpSocket->receiveDatagram();
        ReadServiceDatagram(datagram);
    }

}

void UDPworker::ReadUserPendingDatagrams( void )
{

    while( userUdpSocket->hasPendingDatagrams( ) ){

        QNetworkDatagram datagram = userUdpSocket->receiveDatagram();
        ReadUserDatagram(datagram);

    }

}
