#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtConcurrent>

#include "database.h"
#include "statistics.h"


QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void connectDb();

public slots:
    void ReceiveStatusConnectionToDB(bool status);
    void screenQueryModel(QSqlQueryModel *model);
    void screenListModel(QStringListModel *model);

private slots:
    void on_pb_getFlights_clicked();
    void getDataFromUser();
    void on_pb_getWorkload_clicked();

signals:
    void sig_RequestToDb(QString request);

private:
    Ui::MainWindow *ui;
    Statistics* stat;
    DataBase* dataBase;
    QMessageBox* msg;
    QTimer* timer;

};

#endif // MAINWINDOW_H
