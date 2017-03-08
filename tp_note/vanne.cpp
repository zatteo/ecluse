#include "vanne.h"

void Vanne::run(){}

Vanne::Vanne(QObject *parent) : QThread(parent)
{

}

void Vanne::ouverture()
{
    qDebug() << "Ouverture de la vanne...";

    if(alarme || etat == 1) // porte déjà ouverte
        return;

    sleep(2); // simulation d'ouverture de vanne
    etat = 1;
    emit etatVanne(etat);
}

void Vanne::fermeture()
{
    qDebug() << "Fermeture de la vanne...";

    if(alarme || etat == 0) // porte déjà fermée
        return;

    sleep(2); // simulation de fermeture de vanne
    etat = 0;
    emit etatVanne(etat);
}

void Vanne::urgence()
{
    qDebug() << "Urgence.";

    if(alarme)
        return;

    fermeture();
    mettreAlarme(0);
}

void Vanne::mettreAlarme(int i)
{
    qDebug() << "Alarme ON.";

    alarme = true;
    emit alarmeVanne(i);
}

void Vanne::enleverAlarme()
{
    qDebug() << "Alarme OFF.";

    alarme = false;
}

void Vanne::mettrePanne()
{
    qDebug() << "Panne ON.";

    panne = true;
    mettreAlarme(1);
}

void Vanne::enleverPanne()
{
    qDebug() << "Panne OFF.";

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
