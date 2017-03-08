#ifndef ECLUSE_H
#define ECLUSE_H

#include <QObject>
#include <QDebug>
#include "vanne.h"
#include "porte.h"
#include "signallumineux.h"

#define AMONT 0
#define AVAL 1

class Ecluse : public QObject
{
    Q_OBJECT

public:
    explicit Ecluse(QObject *parent = 0);
    void avalVersAmont();
    void amontVersAval();
    Vanne getVanne(int);
    Porte getPorte(int);
    SignalLumineux getSignalLumineux(int);

signals:

public slots:
    void ouvertureVannes(int);
    void fermetureVannes(int);
    void ouverturePortes(int);
    void fermeturePortes(int);
    void urgence();
    void enleverAlarme();

private:
    Vanne vanneAmont; // vanne 0
    Vanne vanneAval; // vanne 1

    Porte porteAmont; // porte 0
    Porte porteAval; // porte 1

    SignalLumineux signalAmont; // signal 0
    SignalLumineux signalAval; // signal 1

    bool alarme;
    bool admin;
};

#endif // ECLUSE_H
