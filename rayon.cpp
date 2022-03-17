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
    resultat+="<center><h1><color:red>Nom du rayon : "+nomRayon+"</color></h1><br>";
    resultat+="<h2>Liste des variétés du rayon : </h2><br></center>";

    for(int compteur=0 ; compteur < lesVarietes.size() ; compteur ++) {
        resultat += lesVarietes[compteur].versChaine();
    }
    return resultat;
}
