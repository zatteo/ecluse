// SUTTER Nicolas et POIZAT Théo, L3 CMI ISR

#include "signallumineux.h"

void SignalLumineux::run(){}

SignalLumineux::SignalLumineux(int id1, QObject *parent) : QThread(parent){id = id1;}

void SignalLumineux::rouge()
{
    qDebug() << "Signal rouge sur le feu" << getID();

    etat = 0;
}

void SignalLumineux::vert()
{
    qDebug() << "Signal vert sur le feu" << getID();

    etat = 1;
}

int SignalLumineux::getEtat()
{
    return etat;
}

int SignalLumineux::getID()
{
    return id;
}
