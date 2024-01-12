#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void dbConnectionStatus(bool status);

private slots:
    void on_pb_connect_clicked();

    void on_pb_disconnect_clicked();



private:
    Ui::MainWindow *ui;
    Dialog *dialog;
};
#endif // MAINWINDOW_H
