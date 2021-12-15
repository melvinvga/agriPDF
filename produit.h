#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>

class Produit
{
private:
    QString numeroPorduit;
    QString nomProduit;
    QString informationProduit;
    QString imageProduit;
    QString quantiteProduit;
    QString prixUnitaire;
public:
    Produit(QString sonId, QString sonLibelle, QString sesInformations, QString sonImage, QString saQuantite, QString sonPrix);
    Produit();
    QString getImageProd();
    QString versChaine();
};

#endif // PRODUIT_H
