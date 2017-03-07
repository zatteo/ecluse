#ifndef PORTE_H
#define PORTE_H

#include <QTimer>
#include <QThread>

class Porte : public QThread
{
    Q_OBJECT

public:
    explicit Porte(QObject *parent = 0);

protected:
    void run();

signals:
    int etatPorte(int);
    int positionPorte(int);
    void alarmePorte(int);

public slots:
    void ouverture();
    void fermeture();
    void arret();
    void urgence();
    void deplacementPorte(int);
    void mettreAlarme(int); // 1 = panne, 0 = urgence
    void enleverAlarme();
    void mettrePanne();
    void enleverPanne();
    bool isPanne();
    bool isAlarme();

private:
    int etat; // 4 = ouvert, 3 = en ouverture, 2 = fermé, 1 = en fermeture, 0 = arrêtée
    bool panne; // 1 = en panne, 0 = en marche
    bool alarme; // 1 = alarme, 0 = pas d'alarme
    QTimer timer;

    int position;
};

#endif // PORTE_H
