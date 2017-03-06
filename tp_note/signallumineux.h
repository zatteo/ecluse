#ifndef SIGNALLUMINEUX_H
#define SIGNALLUMINEUX_H

#include <QObject>

class SignalLumineux
{
public:
    SignalLumineux();

signals:

public slots:
    void signalLumineux(SignalLumineux sl, bool etat);

private:
    int etat; // 1 = vert, 0 = rouge
};


#endif // SIGNALLUMINEUX_H
