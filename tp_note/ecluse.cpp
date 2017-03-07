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

void Ecluse::ouvertureVannes()
{
    vanneAmont.ouverture();
    vanneAval.ouverture();
}

void Ecluse::fermetureVannes()
{
    vanneAmont.fermeture();
    vanneAval.fermeture();
}

void Ecluse::ouverturePortes()
{
    porteAmont.ouverture();
    porteAval.ouverture();
}

void Ecluse::fermeturePortes()
{
    porteAmont.fermeture();
    porteAval.fermeture();
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

