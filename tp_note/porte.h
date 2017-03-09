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
    int etat = 2; // 4 = ouvert, 3 = en ouverture, 2 = fermé, 1 = en fermeture, 0 = arrêtée
    bool alarme = 0; // 1 = alarme, 0 = pas d'alarme

protected:
    void run();

signals:
    int porteOuverte();
    int porteFermee();
    void alarmePorte();
    void signalPorteMoinsUn();
    void signalPortePlusUn();


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

    int position;
    int id;
};

#endif // PORTE_H
