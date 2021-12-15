#ifndef JEUENREGISTREMENT_H
#define JEUENREGISTREMENT_H
#include <QSqlQuery>

class JeuEnregistrement : public QSqlQuery
{
public:
    JeuEnregistrement(QString chaineSql);
    JeuEnregistrement();
    void suivant();
    bool fin();
    QVariant getValeur(QString nomChamp);
    void fermer();
};

#endif // JEUENREGISTREMENT_H
