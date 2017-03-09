#include "vanne.h"

void Vanne::run(){}

Vanne::Vanne(int id1, QObject *parent) : QThread(parent){id = id1;}

void Vanne::ouverture()
{
    qDebug() << "Ouverture de la vanne" << getID();

    if(alarme || etat == 1) // vanne déjà ouverte
    {
        return;
    }

    emit signalVanneOuverte();

    connect(&timer, SIGNAL(timeout()), this, SLOT(vannePlusUn())); // ouverture de la vanne
    timer.start(500);
}

void Vanne::fermeture()
{
    qDebug() << "Fermeture de la vanne" << getID();

    if(alarme || etat == 0) // porte déjà fermée
    {
        return;
    }

    etat = 0;
    ouvertureVanne = 0;

    emit signalVanneFermee();
    emit vanneFermee();
}

void Vanne::vannePlusUn()
{
    if(alarme)
        return;

    qDebug() << "ouvertureVanne++" ;

    if(ouvertureVanne == 10) // la vanne est ouverte et l'objectif était de l'ouvrir
    {
        etat = 1;
        timer.stop();
        disconnect(&timer, SIGNAL(timeout()), this, SLOT(vannePlusUn()));
        emit vanneOuverte();
    }
    else
    {
        ouvertureVanne++;
        emit signalVannePlusUn();
    }
}

void Vanne::urgence()
{
    qDebug() << "Urgence sur la vanne" << getID();

    if(alarme)
        return;

    fermeture();
    mettreAlarme(0);
}

void Vanne::mettreAlarme(int i)
{
    qDebug() << "Alarme ON sur la vanne" << getID();

    alarme = true;
    emit alarmeVanne(i);
}

void Vanne::enleverAlarme()
{
    qDebug() << "Alarme OFF sur la vanne" << getID();

    alarme = false;
}

bool Vanne::estAlarme()
{
    return alarme;
}

int Vanne::getID()
{
    return id;
}
