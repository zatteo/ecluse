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
    Vanne *getVanne(int);
    Porte *getPorte(int);
    SignalLumineux *getSignalLumineux(int);
    int sens = 0; // 1 = aval vers amont, -1 = amont vers aval
    int niveauEcluse = 0;
    int niveauEau = 1;

    Vanne * vanneAmont; // vanne 0
    Vanne * vanneAval; // vanne 1

    Porte * porteAmont; // porte 0
    Porte * porteAval; // porte 1

    SignalLumineux * signalAmont; // signal 0
    SignalLumineux * signalAval; // signal 1

signals:

public slots:
    void ouvertureVanneAval();
    void ouvertureVanneAmont();
    void fermetureVanneAval();
    void fermetureVanneAmont();
    void ouverturePorteAval();
    void ouverturePorteAmont();
    void fermeturePorteAval();
    void fermeturePorteAmont();
    void urgence();
    void enleverAlarme();

    void avalVersAmont1();
    void avalVersAmont2();
    void avalVersAmont2bis();
    void avalVersAmont3();
    void avalVersAmont3bis();

    void amontVersAval1();
    void amontVersAval2();
    void amontVersAval2bis();
    void amontVersAval3();
    void amontVersAval3bis();

    void fin();

private:

    bool alarme;
    bool admin;
};

#endif // ECLUSE_H
