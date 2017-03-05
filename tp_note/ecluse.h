#ifndef ECLUSE_H
#define ECLUSE_H

#include <QObject>
#include "vanne.h"
#include "porte.h"
#include "signallumineux.h"

class Ecluse
{
public:
    Ecluse();

private:
    Vanne vanneAmont;
    Vanne vanneAval;

    Porte porteAmont;
    Porte porteAval;

    SignalLumineux signalAmont;
    SignalLumineux signalAval;
};

#endif // ECLUSE_H
