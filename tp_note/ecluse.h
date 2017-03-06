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
    void avalVersAmont();
    void amontVersAval();
    void ouvertureVanne(Vanne v);
    void fermetureVanne(Vanne v);
    void ouverturePorte(Porte p);
    void fermeturePorte(Porte p);
    void signalLumineux(SignalLumineux sl, bool etat);

signals:

public slots:
    void urgence();
    void extinctionAlarme();

private:
    Vanne vanneAmont;
    Vanne vanneAval;

    Porte porteAmont;
    Porte porteAval;

    SignalLumineux signalAmont;
    SignalLumineux signalAval;

    bool alarme; // 1 = alarme, 0 = pas d'alarme
};

#endif // ECLUSE_H
