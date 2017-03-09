// SUTTER Nicolas et POIZAT Théo, L3 CMI ISR

#ifndef VANNE_H
#define VANNE_H

#include <QThread>
#include <QDebug>
#include <QTimer>

#define AMONT 0
#define AVAL 1

/* représente une vanne d'une éclise, est un QThread à par entière*/
class Vanne : public QThread
{
    Q_OBJECT

public:
    explicit Vanne(int, QObject *parent = 0);

    int etat = 0; // 1 = ouvert, 0 = fermé
    bool alarme = false; // 1 = alarme, 0 = pas d'alarme


protected:
    void run();

signals:
    void vanneOuverte(); // indique qu'une vanne vient d'être ouverte
    void vanneFermee(); // indique qu'une vanne vient d'être fermée
    void alarmeVanne();
    void signalVannePlusUn(); // indique implicitement l'écoulement de l'eau
    void signalVanneOuverte();
    void signalVanneFermee();

public slots:
    void ouverture();
    void fermeture();
    void urgence();
    void mettreAlarme();
    void enleverAlarme();
    bool estAlarme();
    int getID();
    void vannePlusUn();

private:
    int ouvertureVanne = 0; // degré d'écoulement de l'eau

    QTimer timer;
    int id;
};

#endif // VANNE_H
