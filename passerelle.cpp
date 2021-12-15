#include "passerelle.h"
#include "jeuenregistrement.h"
#include "rayon.h"
#include "variete.h"
#include "produit.h"
#include <QVector>
#include <QVariant>
#include <QDebug>

QVector<Rayon> Passerelle::chargerLesRayons(QString numeroProducteur)
{
    qDebug()<<"QVector<Rayon> Passerelle::chargerLesRayons()";
    //on déclare la collection
    QVector<Rayon> resultat;

    //on remplit le vecteur
    JeuEnregistrement monJeu("SELECT DISTINCT Rayon.numeroRayon, nomRayon  FROM Rayon  INNER JOIN Variete ON Variete.numeroRayon = Rayon.numeroRayon  INNER JOIN Produit ON Produit.numeroVariete = Variete.numeroVariete  INNER JOIN LDC ON LDC.numeroProduit = Produit.numeroProduit  WHERE numeroProducteur ="+numeroProducteur);

    while(monJeu.fin())
    {
        int sonId=monJeu.getValeur("numeroRayon").toInt();
        QString sonNom = monJeu.getValeur("nomRayon").toString();

        //j'obtiens ses variétés
        QVector <Variete> sesVarietes=chargerLesVarietes(sonId, numeroProducteur    );

        //on ajoute le rayon
        resultat.push_back(Rayon(QString::number(sonId),sonNom,sesVarietes));
        monJeu.suivant();
    }
    return resultat;
}

Passerelle::Passerelle()
{

}

QVector<Variete> Passerelle::chargerLesVarietes(int unIdRayon, QString numeroProducteur)
{
    qDebug()<<"QVector<Variete> Passerelle::chargerLesVarietes(int unIdRayon)";
    //je déclare le vecteur
    QVector<Variete> resultat;

    //je vais chercher les infos dans la bdd
    QString reqVariete="SELECT Variete.numeroVariete, Variete.nomVariete FROM Variete INNER JOIN Produit ON Produit.numeroVariete = Variete.numeroVariete  INNER JOIN LDC ON LDC.numeroProduit = Produit.numeroProduit  WHERE numeroProducteur ="+numeroProducteur+" AND numeroRayon="+QString::number(unIdRayon);
    JeuEnregistrement monJeuVariete(reqVariete);
    qDebug()<<reqVariete;

    //boucle chargement des variétés
    while(monJeuVariete.fin())
    {
        QString lId = monJeuVariete.getValeur("numeroVariete").toString();
        QString leNom = monJeuVariete.getValeur("nomVariete").toString();

        // j'obtiens ses produits
        QVector<Produit> sesProduits=chargerLesProduits(lId.toInt(), numeroProducteur);

        // on l'ajoute au vecteur
        resultat.push_back(Variete(lId,leNom,sesProduits));
        monJeuVariete.suivant();
    }

    return resultat;
}

QVector<Produit> Passerelle::chargerLesProduits(int unIdVariete, QString numeroProducteur)
{
    qDebug()<<"QVector<Produit> Passerelle::chargerLesProduits(int unIdVariete)";
    // je déclare le vecteur
    QVector<Produit> resultat;

    // je vais chercher les infos dans la bdd
    QString reqProduit="SELECT Produit.numeroProduit, Produit.nomProduit, Produit.informationProduit, Produit.imageProduit, Produit.quantiteProduit, prixUnitaire "
                       "FROM Produit INNER JOIN produire ON produire.numeroProduit=Produit.numeroProduit "
                       "INNER JOIN LDC ON LDC.numeroProduit = Produit.numeroProduit  "
                       "WHERE LDC.numeroProducteur ="+numeroProducteur+" AND numeroVariete="+QString::number(unIdVariete);
    JeuEnregistrement monJeuProduit(reqProduit);
    qDebug()<<reqProduit;

    // boucle
    while(monJeuProduit.fin())
    {
        QString lId = monJeuProduit.getValeur("numeroProduit").toString();
        QString leNom = monJeuProduit.getValeur("nomProduit").toString();
        QString lInfo = monJeuProduit.getValeur("informationProduit").toString();
        QString lImage = monJeuProduit.getValeur("imageProduit").toString();
        QString laQuant = monJeuProduit.getValeur("quantiteProduit").toString();
        QString lePrix = monJeuProduit.getValeur("prixUnitaire").toString();
        // on l'ajoute au vecteur
        resultat.push_back(Produit(lId,leNom,lInfo,lImage,laQuant,lePrix));
        monJeuProduit.suivant();
    }

    return resultat;
}
