#ifndef STATISTICS_H
#define STATISTICS_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>

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

    void createLineSeries(QMap<QString, int> *map);

private slots:
    void prepareBarChart();
    void on_pb_close_clicked();

private:
    Ui::Statistics *ui;
    QStringList months;
    QString airportName;
    QBarSeries* barSeries;
    QLineSeries* lineSeries;
    QChart* barChart;
    QChart* lineChart;
};

#endif // STATISTICS_H
