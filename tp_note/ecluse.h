// SUTTER Nicolas et POIZAT Théo, L3 CMI ISR

#ifndef ECLUSE_H
#define ECLUSE_H

#include <QObject>
#include <QDebug>
#include "vanne.h"
#include "porte.h"
#include "signallumineux.h"

#define AMONT 0
#define AVAL 1

/* l'écluse est un des éléments principals, elle comporte des portes, vannes et signaux luminaux*/
class Ecluse : public QObject
{
    Q_OBJECT

public:
    explicit Ecluse(QObject *parent = 0);

    int sens = 0; // 1 = aval vers amont, -1 = amont vers aval
    int niveauEcluse = 0; // représente l'avancement des étapes de l'interface automatique
    int niveauEau = 2; // représente le niveau actuel de l'eau, 2 = haut, 1 = moyen, 0 = bas
    bool admin; // écluse en mode administration ou non

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
    void urgence(); // active les fonctions urgences de tous les éléments de l'écluse
    void enleverAlarme();

    // fonctions des étapes automatiques en mode aval vers amont
    void avalVersAmont1();
    void avalVersAmont2();
    void avalVersAmont2bis();
    void avalVersAmont3();
    void avalVersAmont3bis();

    // fonction des étapes automatiques en mode amont vers amal
    void amontVersAval1();
    void amontVersAval2();
    void amontVersAval2bis();
    void amontVersAval3();
    void amontVersAval3bis();

    void fin();

private:
    bool alarme;
};

#endif // ECLUSE_H
