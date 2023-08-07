#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stopwatch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    stopwatch = new StopWatch(this);
    curTime.setHMS(0, 0, 0, 0);
    stopTime.setHMS(0, 0, 0, 0);
    circleTime = 0;
    count = 1;

    ui->setupUi(this);

    ui->pb_startStop->setCheckable(true);
    ui->pb_startStop->setText("CTAPT");
    ui->pb_circle->setText("КРУГ");
    ui->pb_clear->setText("ОЧИСТИТЬ");
    ui->pb_circle->setEnabled(false);

    connect(stopwatch, &StopWatch::sig_updateTime, this, &MainWindow::rcv_updateTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rcv_updateTime()
{
    curTime = curTime.addMSecs(100);
    QString time = curTime.toString("ss.zz");
    ui->l_time->setText(time.left(time.length()-1));
}

void MainWindow::on_pb_startStop_clicked()
{
    if(ui->pb_startStop->isChecked()) {

        stopwatch->startTimer();
        ui->pb_startStop->setText("CTOP");
        ui->pb_circle->setEnabled(true);
    }
    else
    {
        stopwatch->stopTimer();
        ui->pb_startStop->setText("CTAPT");
        ui->pb_circle->setEnabled(false);
    }
}

void MainWindow::on_pb_circle_clicked()
{
    circleTime = stopTime.secsTo(curTime);
    ui->tB_cirkles->append("Круг " + QString::number(count) + " , время: " + QString::number(circleTime) + " сек");
    stopTime = curTime;
    count++;
}

void MainWindow::on_pb_clear_clicked()
{
    ui->l_time->setText("00.0");
    count = 1;
    curTime.setHMS(0, 0, 0, 0);
    stopTime.setHMS(0, 0, 0, 0);
}

