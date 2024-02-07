#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>

#define BIND_PORT 12345
#define USER_PORT 54321
class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void ReadServiceDatagram( QNetworkDatagram datagram);
    void ReadUserDatagram(QNetworkDatagram datagram);
    void SendDatagram(const QByteArray &data, QUdpSocket* socket, qint16 port);

private slots:
    void ReadServicePendingDatagrams(void);
    void ReadUserPendingDatagrams(void);

public:
    QUdpSocket* serviceUdpSocket;
    QUdpSocket* userUdpSocket;
    qint64 messageSize;

signals:
    void sig_sendTimeToGUI(QDateTime data);
    void sig_sendDataToGUI(QString data);
};

#endif // UDPWORKER_H
