#include "pdf.h"
#include <QPagedPaintDevice>
#include <QPdfWriter>
#include <QDebug>

PDF::PDF(QWidget * parent):QTextBrowser(parent)
{

}

void PDF::ecrireTexte(QString leTexte)
{
    //écrit le texte
    setHtml(toHtml()+"<p>"+leTexte+"</p>");
}

void PDF::chargerImage(QString chemin)
{
    //écrit l'image
    setHtml(toHtml()+"<img src=""+chemin+""/>");
}

void PDF::fermer()
{
    qDebug()<<"void PDF::fermer()";
    //fermer le pdf en l'enregistrant
    QPdfWriter* printer = new QPdfWriter(nomDoc);
    printer->newPage();
    printer->setTitle("AGRIC: Catalogue des articles d'agriculteurs");
    printer->setPageSize(QPageSize::A4);

    print(printer);
}

void PDF::setName(QString nomDocument)
{
    qDebug()<<"void PDF::setName(QString nomDocument)";
    nomDoc=nomDocument;
}
