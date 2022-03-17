#include "produit.h"
#include <QDebug>

//constructeur de la classe Produit
Produit::Produit(QString sonId, QString sonLibelle, QString sesInformations, QString sonImage, QString saQuantite, QString sonPrix)
{
    qDebug()<<"Produit::Produit(QString sonId, QString sonLibelle, QString sesInformations, QString sonImage, QString saQuantite, QString sonPrix)";
    numeroPorduit=sonId;
    nomProduit=sonLibelle;
    informationProduit=sesInformations;
    imageProduit=sonImage;
    quantiteProduit=saQuantite;
    prixUnitaire=sonPrix;
}

Produit::Produit()
{

}

//envoie la chaine de caractère pour la classe produit
QString Produit::versChaine()
{
    qDebug()<<"QString Produit::versChaine()";
    QString resultat;
    resultat+="<center><br>";
    resultat+="Nom du produit : "+nomProduit+"<br>Information du produit : "+informationProduit+"<br><img src='"+imageProduit+"'><br><br>Quantité : "+quantiteProduit+"<br>Prix du produit : "+prixUnitaire+"€<br></center>";

    qDebug()<<resultat;
    return resultat;
}

//recuperer l'image du produit
//QString Variete::getImageProd()
//{
    // on affiche le src de l'image
    //return imageProduit;
//}
