#ifndef PASSERELLE_H
#define PASSERELLE_H
#include "rayon.h"
#include "variete.h"
#include "produit.h"
#include <QVector>

class Passerelle
{
public:
    Passerelle();
    static QVector<Rayon> chargerLesRayons(QString numeroProducteur);
    static QVector<Variete> chargerLesVarietes(int sonId, QString numeroProducteur);
    static QVector<Produit> chargerLesProduits(int lId, QString numeroProducteur);
};
#endif // PASSERELLE_H
