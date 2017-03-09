// SUTTER Nicolas et POIZAT Théo, L3 CMI ISR

#include <QDebug>
#include "ecluse.h"

Ecluse::Ecluse(QObject *parent) : QObject(parent)
{
    vanneAmont = new Vanne(AMONT); // vanne 0
    vanneAval = new Vanne(AVAL); // vanne 1

    porteAmont = new Porte(AMONT); // porte 0
    porteAval = new Porte(AVAL); // porte 1

    signalAmont = new SignalLumineux(AMONT); // signal 0
    signalAval = new SignalLumineux(AVAL); // signal 1

    admin = false;

    vanneAmont->start();
    vanneAval->start();
    porteAmont->start();
    porteAval->start();
    signalAmont->start();
    signalAval->start();
}

void Ecluse::ouvertureVanneAval()
{
    vanneAval->ouverture();
}

void Ecluse::ouvertureVanneAmont()
{
    vanneAmont->ouverture();
}

void Ecluse::fermetureVanneAval()
{
    vanneAval->fermeture();
}

void Ecluse::fermetureVanneAmont()
{
    vanneAmont->fermeture();
}

void Ecluse::ouverturePorteAval()
{
    signalAval->vert(); // ouverture d'une porte => le feu passera au vert (la mise à jour du feu sera effectué en temps voulu)
    porteAval->ouverture();
}

void Ecluse::ouverturePorteAmont()
{
    signalAmont->vert();
    porteAmont->ouverture();
}

void Ecluse::fermeturePorteAval()
{
    signalAval->rouge(); // fermeture d'une porte => le feu passera au rouge
    porteAval->fermeture();
}

void Ecluse::fermeturePorteAmont()
{
    signalAmont->rouge();
    porteAmont->fermeture();
}

void Ecluse::urgence()
{
    alarme = true;

    vanneAmont->urgence();
    vanneAval->urgence();
    porteAmont->urgence();
    porteAval->urgence();

    signalAmont->rouge();
    signalAval->rouge();
}

void Ecluse::enleverAlarme()
{
    alarme = false;

    vanneAmont->enleverAlarme();
    vanneAval->enleverAlarme();
    porteAmont->enleverAlarme();
    porteAval->enleverAlarme();
}

// 1ère étape du mode automatique, sens aval vers amont
void Ecluse::avalVersAmont1()
{
    qDebug() << "Aval vers Amont 1";

    niveauEcluse = 1;

    if(niveauEau == 2)
    {
        // connexion des signaux pour un déroulement cohérent
        qDebug() << "Niveau d'eau à 1";
        connect(vanneAval, SIGNAL(vanneOuverte()), this, SLOT(fermetureVanneAval()));
        connect(vanneAval, SIGNAL(vanneFermee()), this, SLOT(ouverturePorteAval()));
        connect(porteAval, SIGNAL(porteOuverte()), this, SLOT(avalVersAmont2()));
        ouvertureVanneAval();
    }
    else
    {
        qDebug() << "Niveau d'eau à 0";
        connect(porteAval, SIGNAL(porteOuverte()), this, SLOT(avalVersAmont2()));
        ouverturePorteAval();
    }
}

// 2ème étape
void Ecluse::avalVersAmont2()
{
    disconnect(vanneAval, SIGNAL(vanneOuverte()), this, SLOT(fermetureVanneAval()));
    disconnect(vanneAval, SIGNAL(vanneFermee()), this, SLOT(ouverturePorteAval()));
    disconnect(porteAval, SIGNAL(porteOuverte()), this, SLOT(avalVersAmont2()));

    qDebug() << "Aval vers Amont 1 terminé";

    niveauEcluse = 2;
}

// 2étape intermédiaire afin d'attendre le clic sur le bouton
void Ecluse::avalVersAmont2bis()
{
    qDebug() << "Aval vers Amont 2";

    connect(porteAval, SIGNAL(porteFermee()), this, SLOT(ouvertureVanneAmont()));
    connect(vanneAmont, SIGNAL(vanneOuverte()), this, SLOT(fermetureVanneAmont()));
    connect(vanneAmont, SIGNAL(vanneFermee()), this, SLOT(ouverturePorteAmont()));
    connect(porteAmont, SIGNAL(porteOuverte()), this, SLOT(avalVersAmont3()));
    fermeturePorteAval();
}

// 3ème étape
void Ecluse::avalVersAmont3()
{
    disconnect(porteAval, SIGNAL(porteFermee()), this, SLOT(ouvertureVanneAmont()));
    disconnect(vanneAmont, SIGNAL(vanneOuverte()), this, SLOT(fermetureVanneAmont()));
    disconnect(vanneAmont, SIGNAL(vanneFermee()), this, SLOT(ouverturePorteAmont()));
    disconnect(porteAmont, SIGNAL(porteOuverte()), this, SLOT(avalVersAmont3()));

    qDebug() << "Aval vers Amont 2 terminé";

    niveauEcluse = 3;
}

// 3ème étape intermediaire
void Ecluse::avalVersAmont3bis()
{
    qDebug() << "Aval vers Amont 3";

    connect(porteAmont, SIGNAL(porteFermee()), this, SLOT(fin()));
    fermeturePorteAmont();
}

// 1ère étape du mode automatique, sens amont vers aval, similaire à l'autre sens
void Ecluse::amontVersAval1()
{
    qDebug() << "Amont vers Aval 1";

    niveauEcluse = 1;

    if(niveauEau == 0)
    {
        qDebug() << "Niveau d'eau à 0";
        connect(vanneAmont, SIGNAL(vanneOuverte()), this, SLOT(fermetureVanneAmont()));
        connect(vanneAmont, SIGNAL(vanneFermee()), this, SLOT(ouverturePorteAmont()));
        connect(porteAmont, SIGNAL(porteOuverte()), this, SLOT(amontVersAval2()));
        ouvertureVanneAmont();
    }
    else
    {
        qDebug() << "Niveau d'eau à 1";
        connect(porteAmont, SIGNAL(porteOuverte()), this, SLOT(amontVersAval2()));
        ouverturePorteAmont();
    }
}

void Ecluse::amontVersAval2()
{
    disconnect(vanneAmont, SIGNAL(vanneOuverte()), this, SLOT(fermetureVanneAmont()));
    disconnect(vanneAmont, SIGNAL(vanneFermee()), this, SLOT(ouverturePorteAmont()));
    disconnect(porteAmont, SIGNAL(porteOuverte()), this, SLOT(amontVersAval2bis()));
    qDebug() << "Amont vers Aval 1 terminé";

    niveauEcluse = 2;
}

void Ecluse::amontVersAval2bis()
{
    qDebug() << "Amont vers Aval 2";

    connect(porteAmont, SIGNAL(porteFermee()), this, SLOT(ouvertureVanneAval()));
    connect(vanneAval, SIGNAL(vanneOuverte()), this, SLOT(fermetureVanneAval()));
    connect(vanneAval, SIGNAL(vanneFermee()), this, SLOT(ouverturePorteAval()));
    connect(porteAval, SIGNAL(porteOuverte()), this, SLOT(amontVersAval3()));
    fermeturePorteAmont();
}

void Ecluse::amontVersAval3()
{
    disconnect(porteAmont, SIGNAL(porteFermee()), this, SLOT(ouvertureVanneAval()));
    disconnect(vanneAval, SIGNAL(vanneOuverte()), this, SLOT(fermetureVanneAval()));
    disconnect(vanneAval, SIGNAL(vanneFermee()), this, SLOT(ouverturePorteAval()));
    disconnect(porteAval, SIGNAL(porteOuverte()), this, SLOT(amontVersAval3bis()));

    qDebug() << "Amont vers Aval 2 terminé";

    niveauEcluse = 3;
}

void Ecluse::amontVersAval3bis()
{
    qDebug() << "Amont vers Aval 3";

    connect(porteAval, SIGNAL(porteFermee()), this, SLOT(fin()));
    fermeturePorteAval();
}

void Ecluse::fin()
{
    // TODO reset de tout
    niveauEcluse = 0;
}
