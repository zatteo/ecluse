#ifndef PORTE_H
#define PORTE_H

#include <QObject>
#include <QTimer>

class Porte : public QObject
{
    Q_OBJECT

public:
     explicit Porte(QObject *parent = 0);

signals:
    int etatPorte(int);
    int positionPorte(int);

public slots:
    void ouverture();
    void fermeture();
    void arret();
    void urgence();
//    void extinctionAlarme();
    void deplacementPorte(int);

private:
    int etat; // 4 = ouvert, 3 = en ouverture, 2 = fermé, 1 = en fermeture, 0 = arrêtée
    bool panne; // 1 = en panne, 0 = en marche
    bool alarme; // 1 = alarme, 0 = pas d'alarme
    QTimer timer;

    int position;
};

#endif // PORTE_H
