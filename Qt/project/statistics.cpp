#include "statistics.h"
#include "ui_statistics.h"

Statistics::Statistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistics)


{
    ui->setupUi(this);

    months << "Январь" << "Февраль" << "Март" << "Апрель" << "Май" << "Июнь"
           << "Июль" << "Август" << "Сентябрь" << "Октябрь" << "Ноябрь" << "Декабрь";

    setCbMonth();

    barSeries = new QBarSeries(this);
    barChart = new QChart();
    lineSeries = new QLineSeries(this);
    lineChart = new QChart();

    prepareBarChart();

    QChartView *barChartView = new QChartView(barChart);
    barChartView->setParent(ui->hf_year);

    QChartView *lineChartView = new QChartView(lineChart);
    lineChartView->setParent(ui->hf_month);

}

Statistics::~Statistics()
{
    delete ui;
    delete barChart;
    delete lineChart;
}

void Statistics::setCbMonth()
{
    QStringListModel* model = new QStringListModel;
    model->setStringList(months);
    ui->cb_month->setModel(model);
}

void Statistics::getAirportName(QString airportName)
{
    QString str = "Аэропорт: " + airportName;
    ui->lb_airport->setText(str);
}

void Statistics::createBarSeries(QBarSet *barSet)
{

    barSeries->append(barSet);

}

void Statistics::createLineSeries(QMap<QString, int> *map)
{
    ///..........................
}

void Statistics::prepareBarChart()
{
    barChart->addSeries(barSeries);
    barChart->setTitle("Загруженность за год");
    barChart->legend()->setVisible(false);
    barChart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(months);
    barChart->setAxisX(axisX, barSeries);

    auto axisY = new QValueAxis;
    axisY->setRange(0, 3500);
    axisY->setTitleText(tr("Количесство рейсов"));
    axisY->setTitleVisible(true);
    axisY->setLabelsAngle(-90);
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);
}

void Statistics::on_pb_close_clicked()
{
    barSeries->clear();
    //barChart->removeSeries(barSeries);
    close();
}

