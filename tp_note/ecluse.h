#ifndef ECLUSE_H
#define ECLUSE_H

#include <QObject>
#include "vanne.h"
#include "porte.h"
#include "signallumineux.h"

class Ecluse : public QObject
{
    Q_OBJECT

public:
    explicit Ecluse(QObject *parent = 0);
//    void avalVersAmont();
//    void amontVersAval();

signals:

public slots:
    void ouvertureVannes();
    void fermetureVannes();
    void ouverturePortes();
    void fermeturePortes();
    void urgence();
    void enleverAlarme();

private:
    Vanne vanneAmont;
    Vanne vanneAval;

    Porte porteAmont;
    Porte porteAval;

    SignalLumineux signalAmont;
    SignalLumineux signalAval;

    bool alarme;
    bool admin;
};

#endif // ECLUSE_H
