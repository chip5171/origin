//homework_2

#include <QCoreApplication>
#include <QTcpServer>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpServer s;
    QSqlError er;

      return a.exec();
}
