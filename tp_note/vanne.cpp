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

bool Vanne::estAlarme()
{
    return alarme;
}

int Vanne::getID()
{
    return id;
}
