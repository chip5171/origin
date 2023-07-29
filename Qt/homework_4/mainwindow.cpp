#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rb_enableList->setText("Список включен");
    ui->rb_enableList->setChecked(true);
    ui->rb_disableList->setText("Список выключен");

    for(int i=1; i<=10; ++i) {
        ui->cb_dropdownList->addItem("Элемент " + QString::number(i));
    }

    ui->pb_controlProgressBar->setText("Управлять прогрессом");
    ui->pb_controlProgressBar->toggle();

    ui->pB_progressBar->setMinimum(0);
    ui->pB_progressBar->setMaximum(100);
    ui->pB_progressBar->setValue(20);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rb_enableList_clicked(bool checked)
{
    if (true )
        ui->cb_dropdownList->setEnabled(true);
}
void MainWindow::on_rb_disableList_clicked(bool checked)
{
    if (true )
        ui->cb_dropdownList->setEnabled(false);
}


void MainWindow::on_pb_controlProgressBar_clicked()
{
    uint val = ui->pB_progressBar->value();
    if (val<100) {
        ui->pB_progressBar->setValue(val+10);
    } else
        ui->pB_progressBar->setValue(0);
}

