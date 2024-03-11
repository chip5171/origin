#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->setStyleSheet("color:red");
    ui->dateEdit->setMinimumDate(QDate(2016, 8, 15));
    ui->dateEdit->setMaximumDate(QDate(2017, 9, 14));
    ui->dateEdit->setDisplayFormat("yyyy-MM-dd");

    dataBase = new DataBase(this);
    msg = new QMessageBox(this);
    stat = new Statistics(this);
    stat->setModal(true);


    dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);

    connectDb();

    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);
    connect(dataBase, &DataBase::sig_SendListModel, this, &MainWindow::screenListModel);
    connect(dataBase, &DataBase::sig_SendQueryModel, this, &MainWindow::screenQueryModel);
    connect(this, &MainWindow::sig_dataFromUser, dataBase, &DataBase::getDataFromUser);
    connect(this, &MainWindow::sig_airportName, stat, &Statistics::getAirportName);
    connect(dataBase, &DataBase::sig_SendBarSet, stat, &Statistics::createBarSeries);
    connect(dataBase, &DataBase::sig_SendDayCountMap, stat, &Statistics::createLineSeries);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dataBase;
    delete msg;
    delete stat;
}

void MainWindow::connectDb()
{

    auto conn = [&]{dataBase->ConnectToDataBase();};
    std::ignore = QtConcurrent::run(conn);

}

void MainWindow::screenListModel(QStringListModel *model)
{

    ui->cb_airports->setModel(model);

}

void MainWindow::screenQueryModel(QSqlQueryModel *model)
{

    ui->tv_result->setModel(model);
    ui->tv_result->setColumnWidth(0, 150);
    ui->tv_result->setColumnWidth(1, 250);
    ui->tv_result->setColumnWidth(2, 250);

}

void MainWindow::ReceiveStatusConnectionToDB(bool status)
{

    if(status){

        ui->statusbar->setStyleSheet("color:green");
        ui->statusbar->showMessage("Подключено к БД");

        dataBase->RequestToDB(airportRequest);

    }
    else{
        dataBase->DisconnectFromDataBase(DB_NAME);
        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->GetLastError().text());

        ui->statusbar->setStyleSheet("color:red");
        ui->statusbar->showMessage("Отключено");
        msg->exec();
    }

}

void MainWindow::getDataFromUser()
{

    QString date = ui->dateEdit->text();
    QString airportName = ui->cb_airports->currentText();

    emit sig_dataFromUser(airportName, date);
    emit sig_airportName(airportName);
}

void MainWindow::on_pb_getFlights_clicked()
{

    getDataFromUser();

    if(ui->rb_departure->isChecked() == true) {

        dataBase->RequestToDB(1);
    }
    if(ui->rb_arrival->isChecked() == true) {

        dataBase->RequestToDB(2);
    }

}

void MainWindow::on_pb_getWorkload_clicked()
{

    getDataFromUser();
    dataBase->RequestToDB(3);
    stat->show();

}

