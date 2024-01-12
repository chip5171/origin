#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dialog = new Dialog(this);

    connect(dialog, &Dialog::sig_dbConnected, this, &MainWindow::dbConnectionStatus );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dbConnectionStatus(bool status)
{
    if(status)
    ui->lb_result->setText("База данных подключена");
    else
    ui->lb_result->setText("База данных не подключена");

}


void MainWindow::on_pb_connect_clicked()
{
    dialog->show();

    //dbConnectionStatus(bool status);
    //ui->lb_result->setText("База данных подключена");
}


void MainWindow::on_pb_disconnect_clicked()
{
    ui->lb_result->setText("База данных не подключена");
}

