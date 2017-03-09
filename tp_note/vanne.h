#ifndef VANNE_H
#define VANNE_H

#include <QThread>
#include <QDebug>
#include <QTimer>

#define AMONT 0
#define AVAL 1

class Vanne : public QThread
{
    Q_OBJECT

public:
    explicit Vanne(int, QObject *parent = 0);
    int etat; // 1 = ouvert, 0 = fermé

protected:
    void run();

signals:
    void vanneOuverte();
    void vanneFermee();
    void alarmeVanne(int);
    void signalVannePlusUn();
    void signalVanneOuverte();
    void signalVanneFermee();

public slots:
    void ouverture();
    void fermeture();
    void urgence();
    void mettreAlarme(int); // 1 = panne, 0 = urgence
    void enleverAlarme();
    void mettrePanne();
    void enleverPanne();
    bool estPanne();
    bool estAlarme();
    int getID();
//    void vanneMoinsUn();
    void vannePlusUn();

private:
    bool panne; // 1 = en panne, 0 = en marche
    bool alarme; // 1 = alarme, 0 = pas d'alarme
    int ouvertureVanne = 0;

    QTimer timer;
    int id;
};

#endif // VANNE_H
