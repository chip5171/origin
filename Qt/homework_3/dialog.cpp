#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_ok_clicked()
{
    emit sig_dbConnected(true);
    this->close();
}


void Dialog::on_pb_cansel_clicked()
{
    emit sig_dbConnected(false);
    this->close();
}

