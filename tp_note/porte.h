#ifndef PORTE_H
#define PORTE_H

#include <QObject>
#include <QTimer>

class Porte
{
public:
    Porte();

signals:
    int etatPorte();
    int position();

public slots:
    void ouverture();
    void fermeture();
    void urgence();
    void extinctionAlarme();

private:
    int etat; // 4 = ouvert, 3 = en ouverture, 2 = fermé, 1 = en fermeture, 0 = arrêtée
    bool panne; // 1 = en panne, 0 = en marche
    bool alarme; // 1 = alarme, 0 = pas d'alarme
    QTimer timer;
};

#endif // PORTE_H
