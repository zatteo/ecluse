#include <QDebug>
#include "ecluse.h"

Ecluse::Ecluse(QObject *parent) : QObject(parent)
{
    admin = false;

    vanneAmont.start();
    vanneAval.start();
    porteAmont.start();
    porteAval.start();
    signalAmont.start();
    signalAval.start();
}

Vanne Ecluse::getVanne(int i)
{
//    if(i == AMONT)
//    {
//        return vanneAmont;
//    }
//    else if(i == AVAL)
//    {
//        return vanneAval;
//    }
}

Porte Ecluse::getPorte(int i)
{
//    if(i == AMONT)
//    {
//        return porteAmont;
//    }
//    else if(i == AVAL)
//    {
//        return porteAval;
//    }
}

SignalLumineux Ecluse::getSignalLumineux(int i)
{
//    if(i == AMONT)
//    {
//        return signalAmont;
//    }
//    else if(i == AVAL)
//    {
//        return signalAval;
//    }
}

void Ecluse::ouvertureVannes(int i)
{
    if(i == -1)
    {
        vanneAmont.ouverture();
        vanneAval.ouverture();
    }
    else if(i == 0)
    {
        vanneAmont.ouverture();
    }
    else if(i == 1)
    {
        vanneAval.ouverture();
    }
}

void Ecluse::fermetureVannes(int i)
{
    if(i == -1)
    {
        vanneAmont.fermeture();
        vanneAval.fermeture();
    }
    else if(i == 0)
    {
        vanneAmont.fermeture();
    }
    else if(i == 1)
    {
        vanneAval.fermeture();
    }
}

void Ecluse::ouverturePortes(int i)
{
    if(i == -1)
    {
        porteAmont.ouverture();
        porteAval.ouverture();
    }
    else if(i == 0)
    {
        porteAmont.ouverture();
    }
    else if(i == 1)
    {
        porteAval.ouverture();
    }

}

void Ecluse::fermeturePortes(int i)
{
    if(i == -1)
    {
        porteAmont.fermeture();
        porteAval.fermeture();
    }
    else if(i == 0)
    {
        porteAmont.fermeture();
    }
    else if(i == 1)
    {
        porteAmont.fermeture();
    }
}

void Ecluse::urgence()
{
    alarme = true;

    vanneAmont.urgence();
    vanneAval.urgence();
    porteAmont.urgence();
    porteAval.urgence();

    signalAmont.rouge();
    signalAval.rouge();
}

void Ecluse::enleverAlarme()
{
    alarme = false;

    vanneAmont.enleverAlarme();
    vanneAval.enleverAlarme();
    porteAmont.enleverAlarme();
    porteAval.enleverAlarme();
}

void Ecluse::avalVersAmont()
{
//    QDebug() << "Aval vers Amont...";

//    ouvertureVannes(AVAL);

//    connect(getVanne(AVAL), this, SLOT(), this);

    // ouverture une des portes
}

void Ecluse::amontVersAval()
{
//    QDebug() << "Amont vers Aval...";
}

