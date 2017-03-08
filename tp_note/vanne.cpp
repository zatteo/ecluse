#include "vanne.h"

void Vanne::run(){}

Vanne::Vanne(int id1, QObject *parent) : QThread(parent){id = id1;}

void Vanne::ouverture()
{
    qDebug() << "Ouverture de la vanne" << getID();

    if(alarme || etat == 1) // porte déjà ouverte
    {
        emit vanneOuverte();
        return;
    }

    QThread::sleep(2); // simulation d'ouverture de vanne
    etat = 1;
    emit vanneOuverte();
}

void Vanne::fermeture()
{
    qDebug() << "Fermeture de la vanne" << getID();

    if(alarme || etat == 0) // porte déjà fermée
    {
        emit vanneFermee();
        return;
    }

    //    sleep(2); // simulation de fermeture de vanne
    etat = 0;
    emit vanneFermee();
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

void Vanne::mettrePanne()
{
    qDebug() << "Panne ON sur la vanne" << getID();

    panne = true;
    mettreAlarme(1);
}

void Vanne::enleverPanne()
{
    qDebug() << "Panne OFF sur la vanne" << getID();

    panne = false;
}

bool Vanne::estPanne()
{
    return panne;
}

bool Vanne::estAlarme()
{
    return alarme;
}

int Vanne::getID()
{
    return id;
}
