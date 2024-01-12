#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void sig_dbConnected(bool status);

private slots:
    void on_pb_ok_clicked();

    void on_pb_cansel_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
