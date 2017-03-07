#ifndef SIGNALLUMINEUX_H
#define SIGNALLUMINEUX_H

#include <QThread>

class SignalLumineux : public QThread
{
    Q_OBJECT

public:
    SignalLumineux(QObject *parent = 0);

protected:
    void run();

public slots:
    void rouge();
    void vert();
    int getEtat();

private:
    int etat; // 1 = vert, 0 = rouge
};


#endif // SIGNALLUMINEUX_H
