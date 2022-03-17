#include "variete.h"
#include <QDebug>

//constructeur de la classe Variete
Variete::Variete(QString sonId, QString sonLibelle, QVector<Produit> uneCollProduit)
{
    qDebug()<<"Variete::Variete(QString sonId, QString sonLibelle, QVector<Produit> uneCollProduit)";
    numeroVariete=sonId;
    nomVariete=sonLibelle;
    lesProduits=uneCollProduit;
}

Variete::Variete()
{

}

//envoie la chaine de caractère pour la classe variete
QString Variete::versChaine()
{
    qDebug()<<"QString Variete::versChaine()";
    QString resultat;
    resultat+="<center><h3>Nom de la variété : "+nomVariete+"</h3><br>";
    resultat+="<h3>Liste des produits de la variété : </h3><br><center>";

    for(int compteur=0 ; compteur < lesProduits.size() ; compteur ++) {
        resultat += lesProduits[compteur].versChaine();
    }
    return resultat;
}

