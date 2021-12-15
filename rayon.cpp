#include "rayon.h"
#include "variete.h"
#include "produit.h"
#include <QDebug>

//constructeur de la classe Rayon
Rayon::Rayon(QString unId, QString unNom, QVector<Variete> uneCollVariete)
{
    qDebug()<<"Rayon::Rayon(QString unId, QString unNom, QVector<Variete> uneCollVariete)";
    numeroRayon = unId;
    nomRayon = unNom;
    lesVarietes = uneCollVariete;
}

Rayon::Rayon()
{
    //constructeur vide
}

//envoie la chaine de caractère pour la classe rayon
QString Rayon::versChaine()
{
    qDebug()<<"QString Rayon::versChaine()";
    QString resultat;
    resultat+="Nom du rayon : "+nomRayon+"<br>";
    resultat+="Liste des variétés du rayon : <br>";

    for(int compteur=0 ; compteur < lesVarietes.size() ; compteur ++) {
        resultat += lesVarietes[compteur].versChaine();
    }
    return resultat;
}
