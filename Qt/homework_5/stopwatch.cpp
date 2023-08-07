#include "stopwatch.h"
//#include <QTimer>

StopWatch::StopWatch(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, &QTimer::timeout, this, &StopWatch::updateTime);
}

StopWatch::~StopWatch(){}

void StopWatch::updateTime()
{
    emit sig_updateTime();
}

void StopWatch::startTimer()
{
    timer->start();
    updateTime();
}

void StopWatch::stopTimer()
{
    timer->stop();
}


