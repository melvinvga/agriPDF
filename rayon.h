#ifndef RAYON_H
#define RAYON_H
#include "variete.h"
#include <QString>
#include <QVector>

class Rayon
{
private:
    QString numeroRayon;
    QString nomRayon;
    QVector<Variete> lesVarietes;
public:
    Rayon(QString unId,QString unNom, QVector<Variete> uneCollVariete);
    Rayon();
    QString versChaine();
};

#endif // RAYON_H
