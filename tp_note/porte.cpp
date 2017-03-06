#include "porte.h"

Porte::Porte(QObject *parent) : QObject(parent)
{
    etat = 2;
    panne = 0;
    alarme = 0;
}

void Porte::ouverture()
{
    etat = 3; // on passe en ouverture
    connect(&timer, SIGNAL(timeout()), this, SLOT(deplacementPorte(1))); // ouverture
    timer.start(1000);
}

void Porte::fermeture()
{
    etat = 1; // on passe en fermeture
    connect(&timer, SIGNAL(timeout()), this, SLOT(deplacementPorte(-1))); // fermeture
    timer.start(1000);
}

void Porte::deplacementPorte(int p)
{
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

void Porte::arret()
{
    timer.stop();
    etat = 0;
}

void Porte::urgence()
{
    etat = 0;
}
