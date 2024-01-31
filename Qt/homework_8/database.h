#ifndef DATABASE_H
#define DATABASE_H

#include <QTableWidget>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlQueryModel>

#define POSTGRE_DRIVER "QPSQL"
#define DB_NAME "MyDB"

//Количество полей данных необходимых для подключения к БД
#define NUM_DATA_FOR_CONNECT_TO_DB 5

//Перечисление полей данных
enum fieldsForConnect{
    hostName = 0,
    dbName = 1,
    login = 2,
    pass = 3,
    port = 4
};

//Типы запросов
enum requestType{

    requestAllFilms = 1,
    requestComedy   = 2,
    requestHorrors  = 3

};



class DataBase : public QObject
{
    Q_OBJECT

public:
    QSqlTableModel  *tableModel;
    QSqlQueryModel  *queryModel;


    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();

    void AddDataBase(QString driver, QString nameDB = "");
    void DisconnectFromDataBase(QString nameDb = "");
    void RequestToDB(QString request);
    QSqlError GetLastError(void);
    void ConnectToDataBase(QVector<QString> dataForConnect);

    void initializeTableModel(QSqlTableModel *model);
    void initializeQueryModel(QSqlQueryModel *model, QString request);
    void clearModel(QSqlTableModel *model);

signals:
   void sig_SendTableModel(QSqlTableModel *tableModel);
   void sig_SendQueryModel(QSqlQueryModel *QueryModel);

   void sig_SendStatusConnection(bool);



private:
    QSqlDatabase* dataBase;
};

#endif // DATABASE_H
