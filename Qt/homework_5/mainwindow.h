#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>

#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void rcv_updateTime();
    void on_pb_startStop_clicked();
    void on_pb_circle_clicked();
    void on_pb_clear_clicked();

private:

    Ui::MainWindow *ui;
    StopWatch *stopwatch;
    QTime curTime;
    QTime stopTime;
    int circleTime;
    int count;

};
#endif // MAINWINDOW_H
