// SUTTER Nicolas et POIZAT Théo, L3 CMI ISR

#ifndef SIGNALLUMINEUX_H
#define SIGNALLUMINEUX_H

#include <QThread>
#include <QDebug>

/* représente un feu d'une éclise, est un QThread à par entière*/
class SignalLumineux : public QThread
{
    Q_OBJECT

public:
    SignalLumineux(int, QObject *parent = 0);

    int etat = 0; // 1 = vert, 0 = rouge

protected:
    void run();

public slots:
    void rouge(); // passe le feu en rouge
    void vert(); // passe le feu en vert
    int getEtat();
    int getID();


private:
    int id;
};


#endif // SIGNALLUMINEUX_H
