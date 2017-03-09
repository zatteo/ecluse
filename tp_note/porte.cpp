// SUTTER Nicolas et POIZAT Théo, L3 CMI ISR

#include "porte.h"

void Porte::run(){}

Porte::Porte(int id1, QObject *parent) : QThread(parent)
{
    id = id1;
    etat = 2; // initialisation fermée
    position = 0; // 0 = fermée .. 10 = ouverte, initalisation fermée
    alarme = false;
}

void Porte::ouverture()
{
    qDebug() << "Ouverture de la porte" << getID();

    if(alarme || etat == 4) // si alarme ou déjà ouvert, on n'ouvre pas plus
        return;

    etat = 3; // on passe en ouverture

    // envoi d'un signal toutes les secondes pendant 10 secondes (voir SLOT), qui implique les changements visuels sur l'interface
    connect(&timer, SIGNAL(timeout()), this, SLOT(portePlusUn()));
    timer.start(1000);
}

void Porte::fermeture()
{
    qDebug() << "Fermeture de la porte" << getID();

    if(alarme || etat == 2) // si alarme ou déjà fermée, on ne ferme pas plus
        return;

    etat = 1; // on passe en fermeture

    connect(&timer, SIGNAL(timeout()), this, SLOT(porteMoinsUn()));
    timer.start(1000);
}

void Porte::arret()
{
    qDebug() << "Arrêt de la porte" << getID();

    if(alarme)
        return;

    timer.stop(); // arrêt brutal = on stoppe le timer d'ouverture/fermeture
    etat = 0;
}

void Porte::urgence()
{
    qDebug() << "Urgence sur la porte" << getID();

    if(alarme)
        return;

    arret();
    mettreAlarme();
}

void Porte::portePlusUn()
{
    if(alarme)
        return;

    qDebug() << "position++";

    if(position == 10) // la porte est ouverte et l'objectif était de l'ouvrir
    {
        etat = 4; // on passe en mode ouvert
        timer.stop();
        disconnect(&timer, SIGNAL(timeout()), this, SLOT(portePlusUn()));
        emit porteOuverte(); // on indique qu'elle est ouverte
    }
    else
    {
        position++; // on augmente la position de la porte
        emit signalPortePlusUn(); // on indique qu'elle s'ouvre (10x)
    }
}

void Porte::porteMoinsUn()
{
    if(alarme)
        return;

    qDebug() << "position--";

    if(position == 0) // la porte est fermée et l'objectif était de la fermer
    {
        etat = 2;
        timer.stop();
        disconnect(&timer, SIGNAL(timeout()), this, SLOT(porteMoinsUn()));
        emit porteFermee();
    }
    else
    {
        position--;
        emit signalPorteMoinsUn();
    }
}

void Porte::mettreAlarme()
{
    qDebug() << "Alarme ON sur la porte" << getID();

    alarme = true;
    emit alarmePorte();
}

void Porte::enleverAlarme()
{
    qDebug() << "Alarme OFF sur la porte" << getID();

    alarme = false;
}

bool Porte::estAlarme()
{
    return alarme;
}

int Porte::getID()
{
    return id;
}
