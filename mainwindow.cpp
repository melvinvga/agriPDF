#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pdf.h"
#include "passerelle.h"
#include <QDebug>

MainWindow::MainWindow(char * numeroProducteur, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->numeroProducteur=numeroProducteur;
    brochurePDF();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::brochurePDF()
{
    qDebug()<<"void MainWindow::brochurePDF()";

    ui->monPDF->setName("AGRI.pdf");

    //vecteur de chargement des rayons et de ce qu'ils contiennent
    QVector <Rayon> collectionR;
    collectionR = Passerelle::chargerLesRayons(numeroProducteur);

    for(int compteur=0 ; compteur < collectionR.size() ; compteur++) {
        Rayon R=collectionR.at(compteur);
        QString texte;
        texte= R.versChaine();
        ui->monPDF->ecrireTexte(texte);
    }

    ui->monPDF->fermer();
}
