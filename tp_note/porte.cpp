#include "porte.h"

void Porte::run(){}

Porte::Porte(QObject *parent) : QThread(parent)
{
    etat = 2;
    panne = false;
    alarme = false;
}

void Porte::ouverture()
{
    if(alarme || etat == 3 || etat == 4)
        return;

    etat = 3; // on passe en ouverture
    connect(&timer, SIGNAL(timeout()), this, SLOT(deplacementPorte(1))); // ouverture
    timer.start(1000);
}

void Porte::fermeture()
{
    if(alarme || etat == 1 || etat == 2)
        return;

    etat = 1; // on passe en fermeture
    connect(&timer, SIGNAL(timeout()), this, SLOT(deplacementPorte(-1))); // fermeture
    timer.start(1000);
}

void Porte::arret()
{
    if(alarme)
        return;

    timer.stop();
    etat = 0;
}

void Porte::urgence()
{
    if(alarme)
        return;

    arret();
    mettreAlarme(0);
}

void Porte::deplacementPorte(int p)
{
    if(alarme)
        return;

    if(position == 10 && p == 1) // la porte est ouverte et l'objectif était de l'ouvrir
    {
        etat = 4;
    }
    else if(position == 0 && p == -1) // la porte est fermée et l'objectif était de la fermer
    {
        etat = 2;
    }
    else
    {
        position += p;
        emit etatPorte(etat);
        emit positionPorte(position);
    }
}

void Porte::mettreAlarme(int i)
{
    alarme = true;
    emit mettreAlarme(i);
}

void Porte::enleverAlarme()
{
    alarme = false;
}

void Porte::mettrePanne()
{
    panne = true;

    arret();
    mettreAlarme(1);
}

void Porte::enleverPanne()
{
    panne = false;
}

bool Porte::isPanne()
{
    return panne;
}

bool Porte::isAlarme()
{
    return alarme;
}
