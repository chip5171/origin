#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpWorker = new UDPworker(this);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, [&]{
        static uint32_t counter = 0;

        QDateTime dateTime = QDateTime::currentDateTime();
        QByteArray sendData;

        QDataStream inputStream(&sendData, QIODevice::WriteOnly);
        inputStream << dateTime;
        inputStream << counter;

        udpWorker->SendDatagram(sendData, udpWorker->serviceUdpSocket, BIND_PORT);
        ++counter;
    });

    connect(udpWorker, &UDPworker::sig_sendTimeToGUI, this, &MainWindow::DisplayRcvTime);
    connect(udpWorker, &UDPworker::sig_sendDataToGUI, this, &MainWindow::DisplayRcvData);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_start_clicked()
{

    timer->start(TIMER_DELAY);

}

void MainWindow::DisplayRcvData(QString data)
{

    counterPck++;

    if(counterPck % 20 == 0){
        ui->te_result->clear();
    }

    ui->te_result->append("Принято сообщение от " + (udpWorker->senderIpAddress).toString() + " , размер сообщения(байт) " + QString::number(udpWorker->messageSize));

}

void MainWindow::DisplayRcvTime(QDateTime data)
{

    counterPck++;

    if(counterPck % 20 == 0){
        ui->te_result->clear();
    }

    ui->te_result->append(QString("Текущее время: %1. Принято пакетов: %2").arg(data.toString()).arg(counterPck));

}

void MainWindow::on_pb_stop_clicked()
{

    timer->stop();

}

void MainWindow::on_pb_sendData_clicked()
{

    QString userData = ui->ln_sendData->text();

    QByteArray dataToSend;
    QDataStream outStr(&dataToSend, QIODevice::WriteOnly);

    outStr << userData;
    udpWorker->SendDatagram(dataToSend, udpWorker->userUdpSocket, USER_PORT);
}

