#ifndef PORTE_H
#define PORTE_H

#include <QTimer>
#include <QThread>
#include <QDebug>
#include <QSignalMapper>

class Porte : public QThread
{
    Q_OBJECT

public:
    explicit Porte(int, QObject *parent = 0);

protected:
    void run();

signals:
    int porteOuverte();
    int porteFermee();
    int positionPorte(int);
    void alarmePorte(int);

public slots:
    void ouverture();
    void fermeture();
    void arret();
    void urgence();
    void portePlusUn();
    void porteMoinsUn();
    void mettreAlarme(int); // 1 = panne, 0 = urgence
    void enleverAlarme();
    void mettrePanne();
    void enleverPanne();
    bool estPanne();
    bool estAlarme();
    int getID();

private:
    int etat; // 4 = ouvert, 3 = en ouverture, 2 = fermé, 1 = en fermeture, 0 = arrêtée
    bool panne; // 1 = en panne, 0 = en marche
    bool alarme; // 1 = alarme, 0 = pas d'alarme
    QTimer timer;

    int position;
    int id;
};

#endif // PORTE_H
