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
    ui->pb_getFlights->setEnabled(false);
    ui->pb_getWorkload->setEnabled(false);



    dataBase = new DataBase(this);
    msg = new QMessageBox(this);
    stat = new Statistics(this);
    stat->setModal(true);
    timer = new QTimer(this);


    dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);

    connectDb();

    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);
    connect(dataBase, &DataBase::sig_SendListModel, this, &MainWindow::screenListModel);
    connect(dataBase, &DataBase::sig_SendQueryModel, this, &MainWindow::screenQueryModel);
    connect(dataBase, &DataBase::sig_SendBarSet, stat, &Statistics::createBarSeries);
    connect(dataBase, &DataBase::sig_SendDayCountList, stat, &Statistics::getFlightsList);
    connect(stat, &Statistics::sig_displayLineChart, stat, &Statistics::prepareLineChart);
    connect(stat, &Statistics::sig_monthNumberChanged, stat, &Statistics::createLineSeries);
    connect(timer, &QTimer::timeout, this, &MainWindow::connectDb);

}

MainWindow::~MainWindow()
{

    delete ui;
    delete dataBase;
    delete msg;
    delete stat;
    delete timer;

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
        ui->pb_getFlights->setEnabled(true);
        ui->pb_getWorkload->setEnabled(true);

        dataBase->RequestToDB(airportRequest);

    }
    else{

        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->GetLastError().text());

        ui->statusbar->setStyleSheet("color:red");
        ui->statusbar->showMessage("Отключено");
        msg->exec();

        timer->start(5000);

    }

}

void MainWindow::getDataFromUser()
{

    QString date = ui->dateEdit->text();
    QString airportName = ui->cb_airports->currentText();

    dataBase->getDataFromUser(airportName, date);
    stat->getAirportName(airportName);

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
    dataBase->RequestToDB(4);
    stat->show();

}

