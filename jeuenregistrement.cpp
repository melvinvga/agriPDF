#include "jeuenregistrement.h"
#include <QVariant>
#include <QDebug>

JeuEnregistrement::JeuEnregistrement()
{

}

JeuEnregistrement::JeuEnregistrement(QString chaineSql):QSqlQuery (chaineSql)
{
    //Ouvre la requête sur le premier enregistrement
    first();
}

void JeuEnregistrement::suivant()
{
    qDebug()<<"void JeuEnregistrement::suivant()";
    next();
}

bool JeuEnregistrement::fin()
{
    qDebug()<<"bool JeuEnregistrement::fin()";
    return isValid();
}

QVariant JeuEnregistrement::getValeur(QString nomChamp)
{
    qDebug()<<"QVariant JeuEnregistrement::getValeur(QString nomChamp)";
    return value(nomChamp);
}

void JeuEnregistrement::fermer()
{
    qDebug()<<"void JeuEnregistrement::fermer()";
    //fermeture de la requete
    //nothing to do
}
