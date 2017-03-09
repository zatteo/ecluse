#include "porte.h"

void Porte::run(){}

Porte::Porte(int id1, QObject *parent) : QThread(parent)
{
    id = id1;
    etat = 2;
    position = 0; // 0 = fermée .. 10 = ouverte
    alarme = false;
}

void Porte::ouverture()
{
    qDebug() << "Ouverture de la porte" << getID();

    if(alarme || etat == 3 || etat == 4)
        return;

    etat = 3; // on passe en ouverture

    connect(&timer, SIGNAL(timeout()), this, SLOT(portePlusUn())); // ouverture
    timer.start(1000);
}

void Porte::fermeture()
{
    qDebug() << "Fermeture de la porte" << getID();

    if(alarme || etat == 1 || etat == 2)
        return;

    etat = 1; // on passe en fermeture

    connect(&timer, SIGNAL(timeout()), this, SLOT(porteMoinsUn())); // fermeture
    timer.start(1000);
}

void Porte::arret()
{
    qDebug() << "Arrêt de la porte" << getID();

    if(alarme)
        return;

    timer.stop();
    etat = 0;
}

void Porte::urgence()
{
    qDebug() << "Urgence sur la porte" << getID();

    if(alarme)
        return;

    arret();
    mettreAlarme(0);
}

void Porte::portePlusUn()
{
    if(alarme)
        return;

    qDebug() << "position++";

    if(position == 10) // la porte est ouverte et l'objectif était de l'ouvrir
    {
        etat = 4;
        timer.stop();
        disconnect(&timer, SIGNAL(timeout()), this, SLOT(portePlusUn()));
        emit porteOuverte();
    }
    else
    {
        position++;
        emit signalPortePlusUn();
    }
}

void Porte::porteMoinsUn()
{
    if(alarme)
        return;

    qDebug() << "position--";

    if(position == 0) // la porte est ouverte et l'objectif était de l'ouvrir
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

void Porte::mettreAlarme(int i)
{
    qDebug() << "Alarme ON sur la porte" << getID();

    alarme = true;
    emit mettreAlarme(i);
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
