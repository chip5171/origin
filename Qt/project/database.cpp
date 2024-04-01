#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{

    dataBase = new QSqlDatabase();
    query = new QSqlQuery();
    queryModel = new QSqlQueryModel();
    listModel = new QStringListModel();
    airportsMap = new QMap<QString, QString>();
    dayCountList = new QList<NumberOfFlights>();

    ConnectToDataBase();

}

DataBase::~DataBase()
{

    delete dataBase;
    delete query;
    delete queryModel;
    delete listModel;
    delete airportsMap;
    delete dayCountList;

}

void DataBase::AddDataBase(QString driver, QString nameDB)
{

    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);

}

void DataBase::ConnectToDataBase()
{

    dataBase->setHostName("981757-ca08998.tmweb.ru");
    dataBase->setDatabaseName("demo");
    dataBase->setUserName("netology_usr_cpp");
    dataBase->setPassword("CppNeto3");
    dataBase->setPort(5432);

    bool status;

    status = dataBase->open( );

    emit sig_SendStatusConnection(status);

}

void DataBase::DisconnectFromDataBase(QString nameDb)
{

    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();

}

void DataBase::RequestToDB(int requestType)
{
    switch(requestType) {
        case(airportRequest):{

            QString request = "SELECT airport_name->> 'ru' as \"airportName\", airport_code FROM bookings.airports_data";

            initializeListModel(listModel, request);
            createAirportsMap(request);

            break;
        }
        case(departureRequest): {

            QString request = "SELECT flight_no, scheduled_departure, ad.airport_name->>'ru' as \"Name\" FROM bookings.flights f "
                              "JOIN bookings.airports_data ad on ad.airport_code = f.arrival_airport "
                              "WHERE f.departure_airport = '" + airportCode + "' AND f.scheduled_departure::date = date('" + dateOfFlight + "')";

            initializeQueryModel(queryModel, request, departureRequest);

            break;
        }
        case(arrivalRequest):{

            QString request = "SELECT flight_no, scheduled_arrival, ad.airport_name->>'ru' as \"Name\" FROM bookings.flights f "
                              "JOIN bookings.airports_data ad on ad.airport_code = f.departure_airport "
                              "WHERE f.arrival_airport = '" + airportCode + "' AND f.scheduled_departure::date = date('" + dateOfFlight + "')";

            initializeQueryModel(queryModel, request, arrivalRequest);

            break;
        }
        case(yearLoadRequest):{

            QString request = "SELECT count(flight_no), date_trunc('month', scheduled_departure) as \"Month\" FROM bookings.flights f "
                              "WHERE (scheduled_departure::date > date('2016-08-31') AND scheduled_departure::date <= date('2017-08-31')) "
                              "AND ( departure_airport = '" + airportCode + "' or arrival_airport = '" + airportCode + "') group by \"Month\"";

            createBarSet(request);

            break;
        }
        case(monthLoadRequest):{

            QString request = "SELECT count(flight_no), date_trunc('day', scheduled_departure) as \"Day\" FROM bookings.flights f "
                              "WHERE (scheduled_departure::date > date('2016-08-31') AND scheduled_departure::date <= date('2017-08-31')) "
                              "AND ( departure_airport = '" + airportCode + "' or arrival_airport = '" + airportCode + "') group by \"Day\"";

            createDayCountList(request);

            break;
        }
        default:

            break;
    }
}

QStringList DataBase::createStringList(QString request)
{

    QStringList list;
    *query = QSqlQuery(*dataBase);

    if(query->exec(request)){
        while(query->next()) {
            list.append(query->value(0).toStringList());
        }
    }

    list.sort(Qt::CaseInsensitive);
    return list;

}

void DataBase::createAirportsMap(QString request)
{

    *query = QSqlQuery(*dataBase);

    if(query->exec(request)){
        while(query->next()) {
            airportsMap->insert(query->value(0).toString(), query->value(1).toString());
        }
    }

}

void DataBase::createDayCountList(QString request)
{

    *query = QSqlQuery(*dataBase);

    if(query->exec(request)){
        while(query->next()) {

            NumberOfFlights str;
            QString dateTime = query->value(1).toString();
            QDateTime dt = QDateTime::fromString(dateTime, "yyyy-MM-ddTHH:mm:ss.zzz");
            str.date = dt.date();
            str.num = query->value(0).toInt();

            dayCountList->append(str);

        }
    }

    emit sig_SendDayCountList(dayCountList);

    dayCountList->clear();

}

void DataBase::createBarSet(QString request)
{

    QBarSet* barSet = new QBarSet("");
    *query = QSqlQuery(*dataBase);

    if(query->exec(request)){
        while(query->next()) {
            barSet->append(query->value(0).toInt());
        }
    }

    emit sig_SendBarSet(barSet);

}

void DataBase::getDataFromUser(QString name, QString date)
{

    airportCode = airportsMap->value(name);
    dateOfFlight = date;

}

void DataBase::initializeQueryModel(QSqlQueryModel *model, QString request, int requestType)
{

    model->setQuery(request, *dataBase);
    model->setHeaderData(0, Qt::Horizontal, tr("Номер рейса"));
    if (requestType == departureRequest) {
    model->setHeaderData(1, Qt::Horizontal, tr("Время вылета"));
    model->setHeaderData(2, Qt::Horizontal, tr("Аэропорт назначения"));
    }
    if (requestType == arrivalRequest) {
    model->setHeaderData(1, Qt::Horizontal, tr("Время прибытия"));
    model->setHeaderData(2, Qt::Horizontal, tr("Аэропорт отправления"));
    }

    emit sig_SendQueryModel(model);

}

void DataBase::initializeListModel(QStringListModel *model, QString request)
{

    QStringList list;
    list = createStringList(request);
    model->setStringList(list);

    emit sig_SendListModel(model);

}

QSqlError DataBase::GetLastError()
{

    return dataBase->lastError();

}
