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

Vanne * Ecluse::getVanne(int i)
{
    if(i == AMONT)
    {
        return vanneAmont;
    }
    else if(i == AVAL)
    {
        return vanneAval;
    }

    return NULL;
}

Porte * Ecluse::getPorte(int i)
{
    if(i == AMONT)
    {
        return porteAmont;
    }
    else if(i == AVAL)
    {
        return porteAval;
    }

    return NULL;
}

SignalLumineux * Ecluse::getSignalLumineux(int i)
{
    if(i == AMONT)
    {
        return signalAmont;
    }
    else if(i == AVAL)
    {
        return signalAval;
    }

    return NULL;
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
    porteAval->ouverture();
}

void Ecluse::ouverturePorteAmont()
{
    porteAmont->ouverture();
}

void Ecluse::fermeturePorteAval()
{
    porteAval->fermeture();
}

void Ecluse::fermeturePorteAmont()
{
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

void Ecluse::avalVersAmont1()
{
    qDebug() << "Aval vers Amont 1";

    niveauEcluse = 1;

    if(niveauEau == 1)
    {
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

void Ecluse::avalVersAmont2()
{
    disconnect(vanneAval, SIGNAL(vanneOuverte()), this, SLOT(fermetureVanneAval()));
    disconnect(vanneAval, SIGNAL(vanneFermee()), this, SLOT(ouverturePorteAval()));
    disconnect(porteAval, SIGNAL(porteOuverte()), this, SLOT(avalVersAmont2()));

    qDebug() << "Aval vers Amont 1 terminé";

    niveauEcluse = 2;
}

void Ecluse::avalVersAmont2bis()
{
    qDebug() << "Aval vers Amont 2";

    connect(porteAval, SIGNAL(porteFermee()), this, SLOT(ouvertureVanneAmont()));
    connect(vanneAmont, SIGNAL(vanneOuverte()), this, SLOT(fermetureVanneAmont()));
    connect(vanneAmont, SIGNAL(vanneFermee()), this, SLOT(ouverturePorteAmont()));
    connect(porteAmont, SIGNAL(porteOuverte()), this, SLOT(avalVersAmont3()));
    fermeturePorteAval();
}

void Ecluse::avalVersAmont3()
{
    disconnect(porteAval, SIGNAL(porteFermee()), this, SLOT(ouvertureVanneAmont()));
    disconnect(vanneAmont, SIGNAL(vanneOuverte()), this, SLOT(fermetureVanneAmont()));
    disconnect(vanneAmont, SIGNAL(vanneFermee()), this, SLOT(ouverturePorteAmont()));
    disconnect(porteAmont, SIGNAL(porteOuverte()), this, SLOT(avalVersAmont3()));

    qDebug() << "Aval vers Amont 2 terminé";

    niveauEcluse = 3;
}

void Ecluse::avalVersAmont3bis()
{
    qDebug() << "Aval vers Amont 3";

    connect(porteAmont, SIGNAL(porteFermee()), this, SLOT(fin()));
    fermeturePorteAmont();
}

void Ecluse::amontVersAval1()
{
    qDebug() << "Aval vers Amont 1";

    niveauEcluse = 1;

    if(niveauEau == 1)
    {
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

void Ecluse::amontVersAval2()
{
    disconnect(vanneAval, SIGNAL(vanneOuverte()), this, SLOT(fermetureVanneAval()));
    disconnect(vanneAval, SIGNAL(vanneFermee()), this, SLOT(ouverturePorteAval()));
    disconnect(porteAval, SIGNAL(porteOuverte()), this, SLOT(avalVersAmont2()));

    qDebug() << "Aval vers Amont 1 terminé";

    niveauEcluse = 2;
}

void Ecluse::amontVersAval2bis()
{
    qDebug() << "Aval vers Amont 2";

    connect(porteAval, SIGNAL(porteFermee()), this, SLOT(ouvertureVanneAmont()));
    connect(vanneAmont, SIGNAL(vanneOuverte()), this, SLOT(fermetureVanneAmont()));
    connect(vanneAmont, SIGNAL(vanneFermee()), this, SLOT(ouverturePorteAmont()));
    connect(porteAmont, SIGNAL(porteOuverte()), this, SLOT(avalVersAmont3()));
    fermeturePorteAval();
}

void Ecluse::amontVersAval3()
{
    disconnect(porteAval, SIGNAL(porteFermee()), this, SLOT(ouvertureVanneAmont()));
    disconnect(vanneAmont, SIGNAL(vanneOuverte()), this, SLOT(fermetureVanneAmont()));
    disconnect(vanneAmont, SIGNAL(vanneFermee()), this, SLOT(ouverturePorteAmont()));
    disconnect(porteAmont, SIGNAL(porteOuverte()), this, SLOT(avalVersAmont3()));

    qDebug() << "Aval vers Amont 2 terminé";

    niveauEcluse = 3;
}

void Ecluse::amontVersAval3bis()
{
    qDebug() << "Aval vers Amont 3";

    connect(porteAmont, SIGNAL(porteFermee()), this, SLOT(fin()));
    fermeturePorteAmont();
}

void Ecluse::fin()
{
    // TODO reset de tout
}

