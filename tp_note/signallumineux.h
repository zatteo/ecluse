#ifndef SIGNALLUMINEUX_H
#define SIGNALLUMINEUX_H

#include <QThread>
#include <QDebug>

class SignalLumineux : public QThread
{
    Q_OBJECT

public:
    SignalLumineux(int, QObject *parent = 0);
    int etat= 0; // 1 = vert, 0 = rouge

protected:
    void run();

public slots:
    void rouge();
    void vert();
    int getEtat();
    int getID();


private:
    int id;
};


#endif // SIGNALLUMINEUX_H
