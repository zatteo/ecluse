#ifndef VANNE_H
#define VANNE_H

#include <QObject>

class Vanne
{
public:
    Vanne();

signals:
    bool etatVanne();

public slots:
    void ouverture();
    void fermeture();
    void urgence();
    void extinctionAlarme();

private:
    bool etat; // 1 = ouvert, 0 = fermé
    bool panne; // 1 = en panne, 0 = en marche
    bool alarme; // 1 = alarme, 0 = pas d'alarme
};

#endif // VANNE_H
