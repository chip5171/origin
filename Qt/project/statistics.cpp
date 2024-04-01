#include "statistics.h"
#include "ui_statistics.h"

Statistics::Statistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistics)


{
    ui->setupUi(this);

    months << "Январь" << "Февраль" << "Март" << "Апрель" << "Май" << "Июнь"
           << "Июль" << "Август" << "Сентябрь" << "Октябрь" << "Ноябрь" << "Декабрь";

    monthNumber = 1;

    setCbMonth();


    barSeries = new QBarSeries;
    barChart = new QChart();

    prepareBarChart();

    barChartView = new QChartView(barChart);
    barChartView->setParent(ui->hf_year);


    lineSeries = new QLineSeries;
    lineChart = new QChart();

    lineChartView = new QChartView(lineChart);
    lineChartView->setParent(ui->hf_month);

}

Statistics::~Statistics()
{

    delete ui;
    delete barChart;
    delete barSeries;
    delete barChartView;

    delete lineChart;
    delete lineSeries;
    delete lineChartView;
    delete flightsList;

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

void Statistics::prepareBarChart()
{

    barChart->addSeries(barSeries);
    barChart->setTitle("Загруженность за год");
    barChart->legend()->setVisible(false);
    barChart->setAnimationOptions(QChart::SeriesAnimations);

    auto *axisX = new QBarCategoryAxis();
    axisX->append(months);
    barChart->setAxisX(axisX, barSeries);

    auto *axisY = new QValueAxis;
    axisY->setRange(0, 3500);
    axisY->setTitleText(tr("Количесство рейсов"));
    axisY->setTitleVisible(true);
    axisY->setLabelsAngle(-90);
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

}

void Statistics::getFlightsList(QList<NumberOfFlights> *list)
{

    flightsList = new QList<NumberOfFlights>;

    for(int i = 0; i < list->size(); ++i) {
        flightsList->append(list->at(i));
    }

    createLineSeries(monthNumber);

}

void Statistics::createLineSeries(int mNumber)
{

    if(lineChart->isEmpty() == false) {
        clearLineChart(lineChart);
    }

    maxY = 0;

    for(int i = 0; i < flightsList->size(); i++) {

        QDate date = flightsList->at(i).date;

        int num = flightsList->at(i).num;

        int month = flightsList->at(i).date.month();

        if(month == mNumber) {
            QDateTime xValue;
            xValue.setDate((date));
            qreal yValue = num;

            if(num > maxY) {
                maxY = num;
            }

            lineSeries->append(xValue.toMSecsSinceEpoch(), yValue);

        }
    }

    emit sig_displayLineChart();

}

void Statistics::prepareLineChart()
{

    lineChart->addSeries(lineSeries);

    lineChart->setTitle("Загруженность за месяц");
    lineChart->legend()->setVisible(false);


    auto axisX = new QDateTimeAxis(this);
    axisX->setTickCount(15);
    axisX->setFormat("dd-MM-yyyy");
    axisX->setLabelsAngle(-90);
    axisX->setTitleText("Дата");

    lineChart->addAxis(axisX, Qt::AlignBottom);
    lineSeries->attachAxis(axisX);

    auto axisY = new QValueAxis(this);
    axisY->setRange(0, maxY*2);
    axisY->setLabelFormat("%i");
    axisY->setTitleVisible(true);
    axisY->setTitleText("Количесство рейсов");

    lineChart->addAxis(axisY, Qt::AlignLeft);
    lineSeries->attachAxis(axisY);

}

void Statistics::on_pb_close_clicked()
{

    barSeries->clear();

    clearLineChart(lineChart);

    ui->cb_month->setCurrentIndex(0);

    close();

}

void Statistics::clearLineChart(QChart *chart)
{

    int count = lineSeries->count();
    lineSeries->removePoints(0, count);

    lineSeries->clear();

    QList<QAbstractAxis*> list;

    list = lineSeries->attachedAxes();

    for(int i = 0; i < list.size(); i++) {

        lineSeries->detachAxis(list.at(i));
        chart->removeAxis(list.at(i));

    }

    chart->removeSeries(lineSeries);

}

void Statistics::on_cb_month_currentIndexChanged(int index)
{

    monthNumber = index+1;

    emit sig_monthNumberChanged(monthNumber);

}


