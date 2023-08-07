#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QWidget>
#include <QTimer>

class StopWatch : public QObject
{
    Q_OBJECT
public:
    explicit StopWatch(QObject *parent = nullptr);
    ~StopWatch();

    void updateTime();
    void startTimer();
    void stopTimer();

signals:
    void sig_updateTime();

private:
    QTimer *timer;
};

#endif // STOPWATCH_H


