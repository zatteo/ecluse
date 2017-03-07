#include "vanne.h"

void Vanne::run(){}

Vanne::Vanne(QObject *parent) : QThread(parent)
{

}

void Vanne::ouverture()
{
    if(alarme || etat == 1) // porte déjà ouverte
        return;

    sleep(2); // simulation d'ouverture de vanne
    etat = 1;
    emit etatVanne(etat);
}

void Vanne::fermeture()
{
    if(alarme || etat == 0) // porte déjà fermée
        return;

    sleep(2); // simulation de fermeture de vanne
    etat = 0;
    emit etatVanne(etat);
}

void Vanne::urgence()
{
    if(alarme)
        return;

    fermeture();
    mettreAlarme(0);
}

void Vanne::mettreAlarme(int i)
{
    alarme = true;
    emit alarmeVanne(i);
}

void Vanne::enleverAlarme()
{
    alarme = false;
}

void Vanne::mettrePanne()
{
    panne = true;
    mettreAlarme(1);
}

void Vanne::enleverPanne()
{
    panne = false;
}

bool Vanne::isPanne()
{
    return panne;
}

bool Vanne::isAlarme()
{
    return alarme;
}
