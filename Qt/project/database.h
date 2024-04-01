#ifndef DATABASE_H
#define DATABASE_H

#include <QTableWidget>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringList>
#include <QList>
#include <QSqlQueryModel>
#include <QStringListModel>
#include <QBarSet>
#include <QDate>
#include <QMessageBox>
#include <QTimer>

#define POSTGRE_DRIVER "QPSQL"
#define DB_NAME "MyDB"

enum requestType{

    airportRequest = 0,
    departureRequest = 1,
    arrivalRequest = 2,
    yearLoadRequest = 3,
    monthLoadRequest = 4

};

enum direction{

    departure = 0,
    arrival = 1

};

struct NumberOfFlights {
    QDate date;
    int num;
};


class DataBase : public QObject
{
    Q_OBJECT

public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();

    void AddDataBase(QString driver, QString nameDB = "");
    void DisconnectFromDataBase(QString nameDb = "");
    void RequestToDB(int requestType);
    QSqlError GetLastError(void);
    void ConnectToDataBase();
    QStringList createStringList(QString request);
    void initializeQueryModel(QSqlQueryModel *model, QString request, int requestType);
    void initializeListModel(QStringListModel *model, QString request);
    void createAirportsMap(QString request);
    void createDayCountList(QString request);
    void createBarSet(QString request);

public slots:
    void getDataFromUser(QString code, QString date);

signals:
   void sig_SendListModel(QStringListModel *model);
   void sig_SendQueryModel(QSqlQueryModel *model);
   void sig_SendStatusConnection(bool);
   void sig_SendStatusRequest(QSqlError err);
   void sig_SendBarSet(QBarSet *set);
   void sig_SendDayCountList(QList<NumberOfFlights> *list);

private:
    QSqlDatabase* dataBase;
    QSqlQuery* query;
    QSqlQueryModel *queryModel;
    QStringListModel *listModel;
    QString airportCode;
    QString dateOfFlight;

    QMap<QString, QString> *airportsMap;
    QList<NumberOfFlights> *dayCountList;
    QStringList* airportsList;

};

#endif // DATABASE_H
