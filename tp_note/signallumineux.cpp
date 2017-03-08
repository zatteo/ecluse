#include "signallumineux.h"

void SignalLumineux::run(){}

SignalLumineux::SignalLumineux(QObject *parent) : QThread(parent){}

void SignalLumineux::rouge()
{
    qDebug() << "Signal rouge.";

    etat = 0;
}

void SignalLumineux::vert()
{
    qDebug() << "Signal vert.";

    etat = 1;
}

int SignalLumineux::getEtat()
{
    return etat;
}
