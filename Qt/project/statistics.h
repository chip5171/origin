#ifndef STATISTICS_H
#define STATISTICS_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QValueAxis>
#include "database.h"

namespace Ui {

class Statistics;

}

class Statistics : public QDialog
{
    Q_OBJECT

public:
    explicit Statistics(QWidget *parent = nullptr);
    ~Statistics();

    void setCbMonth();


public slots:
    void getAirportName(QString airportName);
    void createBarSeries(QBarSet *barSet);
    void createLineSeries(int mNumber);
    void getFlightsList(QList<NumberOfFlights> *list);
    void prepareLineChart();


signals:
    void sig_displayLineChart();
    void sig_monthNumberChanged(int numder);

private slots:
    void prepareBarChart();
    void on_pb_close_clicked();
    void clearLineChart(QChart *chart);
    void on_cb_month_currentIndexChanged(int index);

private:
    Ui::Statistics *ui;
    QList<NumberOfFlights> *flightsList;
    QBarSeries *barSeries;
    QLineSeries *lineSeries;
    QChart *barChart;
    QChart *lineChart;
    QChartView *barChartView;
    QChartView *lineChartView;

    QString airportName;
    QStringList months;
    int monthNumber;
    int maxY;

};

#endif // STATISTICS_H
