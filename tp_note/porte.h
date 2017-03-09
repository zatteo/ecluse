// SUTTER Nicolas et POIZAT Théo, L3 CMI ISR

#ifndef PORTE_H
#define PORTE_H

#include <QTimer>
#include <QThread>
#include <QDebug>
#include <QSignalMapper>

/* représente une porte d'une écluse, est un QThread à par entière*/
class Porte : public QThread
{
    Q_OBJECT

public:
    explicit Porte(int, QObject *parent = 0);

    int etat = 2; // 4 = ouvert, 3 = en ouverture, 2 = fermé, 1 = en fermeture, 0 = arrêtée
    bool alarme = 0; // 1 = alarme, 0 = pas d'alarme

protected:
    void run();

signals:
    int porteOuverte(); // indique que la porte vient d'être ouverte
    int porteFermee(); // indique que la porte vient d'être fermée
    void alarmePorte();
    void signalPorteMoinsUn(); // indique que la porte est en train d'être fermée
    void signalPortePlusUn(); // indique que la porte est en train d'être ouverte


public slots:
    void ouverture();
    void fermeture();
    void arret();
    void urgence();
    void portePlusUn();
    void porteMoinsUn();
    void mettreAlarme();
    void enleverAlarme();
    bool estAlarme();
    int getID();

private:
    QTimer timer;

    int position; // degré d'ouverture de la porte
    int id;
};

#endif // PORTE_H
