#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //connexion à la bdd
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("agri");
    db.setUserName("mviougea");
    db.setPassword("mviougea");

    //test si la bdd est ouverte
    bool ok=db.open();
    qDebug()<<ok;

    MainWindow w(argv[1]);
    w.show();
    return a.exec();
}
