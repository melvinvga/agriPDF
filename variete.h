#ifndef VARIETE_H
#define VARIETE_H
#include "produit.h"
#include <QString>
#include <QVector>

class Variete
{
private:
    QString numeroVariete;
    QString nomVariete;
    QVector<Produit> lesProduits;
public:
    Variete(QString sonId, QString sonLibelle, QVector<Produit> uneCollProduit);
    Variete();
    QString versChaine();
};

#endif // VARIETE_H
