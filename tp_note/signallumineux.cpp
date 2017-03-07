#include "signallumineux.h"

void SignalLumineux::run(){}

SignalLumineux::SignalLumineux(QObject *parent) : QThread(parent){}

void SignalLumineux::rouge()
{
    etat = 0;
}

void SignalLumineux::vert()
{
    etat = 1;
}

int SignalLumineux::getEtat()
{
    return etat;
}
