#include "tcpclient.h"

/*
 * Поскольку мы являемся клиентом, инициализацию сокета
 * проведем в конструкторе. Также необходимо соединить
 * сокет со всеми необходимыми нам сигналами.
*/
TCPclient::TCPclient(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);

    //Соединяемся с методом обработки входящих данных
    connect(socket, &QTcpSocket::readyRead, this, &TCPclient::ReadyReed);

    //Прокидываем сигналы статусов подключения
    connect(socket, &QTcpSocket::connected, this, [&]{
        emit sig_connectStatus(STATUS_SUCCES);
    });

    connect(socket, &QTcpSocket::errorOccurred, this, [&]{

        emit sig_connectStatus(ERR_CONNECT_TO_HOST);

    });

    //Прокидываем сигнал отключения
    connect(socket, &QTcpSocket::disconnected, this, &TCPclient::sig_Disconnected);
}

/* ServiceHeader
 * Для работы с потоками наши данные необходимо сериализовать.
 * Поскольку типы данных не стандартные перегрузим оператор << Для работы с ServiceHeader
*/
QDataStream &operator >>(QDataStream &out, ServiceHeader &data){

    out >> data.id;
    out >> data.idData;
    out >> data.status;
    out >> data.len;
    return out;
};
QDataStream &operator <<(QDataStream &in, ServiceHeader &data){

    in << data.id;
    in << data.idData;
    in << data.status;
    in << data.len;

    return in;
};
QDataStream &operator >>(QDataStream &out, StatServer &data){

    out >> data.incBytes;
    out >> data.sendBytes;
    out >> data.revPck;
    out >> data.sendPck;
    out >> data.workTime;
    out >> data.clients;
    return out;
};
QDataStream &operator <<(QDataStream &in, StatServer &data){

    in << data.incBytes;
    in << data.sendBytes;
    in << data.revPck;
    in << data.sendPck;
    in << data.workTime;
    in << data.clients;

    return in;
};
/* write
 * Метод отправляет запрос на сервер. Сериализировать будем
 * при помощи QDataStream
*/
void TCPclient::SendRequest(ServiceHeader head)
{
    //Сериализуем данные в массив байт
    QByteArray sendHdr;
    QDataStream outStream(&sendHdr, QIODevice::WriteOnly);
    outStream << head;

//   memcpy(sendHdr.data(), &head, sizeof(head));

    socket->write(sendHdr);

}

/* write
 * Такой же метод только передаем еще данные.
*/
void TCPclient::SendData(ServiceHeader head, QString str)
{
    QByteArray sendData;
    QDataStream outStream(&sendData, QIODevice::WriteOnly);

    outStream << head;
    outStream << str;

    socket->write(sendData);

}

/*
 * \brief Метод подключения к серверу
 */
void TCPclient::ConnectToHost(QHostAddress host, uint16_t port)
{
    socket->connectToHost(host, port);
}

/*
 * \brief Метод отключения от сервера
 */
void TCPclient::DisconnectFromHost()
{
    socket->disconnectFromHost();
}

void TCPclient::ReadyReed()
{

    QDataStream incStream(socket);

    if(incStream.status() != QDataStream::Ok){
        QMessageBox msg;
        msg.setIcon(QMessageBox::Warning);
        msg.setText("Ошибка открытия входящего потока для чтения данных!");
        msg.exec();
    }


    //Читаем до конца потока
    while(incStream.atEnd() == false){
        //Если мы обработали предыдущий пакет, мы скинули значение idData в 0
        if(servHeader.idData == 0){

            //Проверяем количество полученных байт. Если доступных байт меньше чем
            //заголовок, то выходим из обработчика и ждем новую посылку. Каждая новая
            //посылка дописывает данные в конец буфера
            if(socket->bytesAvailable() < sizeof(ServiceHeader)){
                return;
            }
            else{
                //Читаем заголовок
                incStream >> servHeader;
                //Проверяем на корректность данных. Принимаем решение по заранее известному ID
                //пакета. Если он "битый" отбрасываем все данные в поисках нового ID.
                if(servHeader.id != ID){
                    uint16_t hdr = 0;
                    while(incStream.atEnd()){
                        incStream >> hdr;
                        if(hdr == ID){
                            incStream >> servHeader.idData;
                            incStream >> servHeader.status;
                            incStream >> servHeader.len;
                            break;
                        }
                    }
                }
            }
        }
        //Если получены не все данные, то выходим из обработчика. Ждем новую посылку
        if(socket->bytesAvailable() < servHeader.len){
            return;
        }
        else{
            //Обработка данных
            ProcessingData(servHeader, incStream);
            servHeader.idData = 0;
            servHeader.status = 0;
            servHeader.len = 0;
        }
    }
}


/*
 * Остался метод обработки полученных данных. Согласно протоколу
 * мы должны прочитать данные из сообщения и вывести их в ПИ.
 * Поскольку все типы сообщений нам известны реализуем выбор через
 * switch. Реализуем получение времени.
*/

void TCPclient::ProcessingData(ServiceHeader header, QDataStream &stream)
{

    switch (header.idData){

    case GET_TIME: {
        QDateTime time;
        stream >> time;
        emit sig_sendTime(time);
        break;
    }
    case GET_SIZE:{
        uint32_t size;
        stream >> size;
        emit sig_sendFreeSize(size);
        break;
    }
    case GET_STAT: {
        StatServer stat;
        stream >> stat;
        emit sig_sendStat(stat);
        break;
    }
    case SET_DATA: {
        QString str;
        stream >> str;
        emit sig_SendReplyForSetData(str);
        break;
    }
    case CLEAR_DATA: {
        if (header.status == 1)
        emit sig_Success(201);
    }
    default:
        return;

    }

}
