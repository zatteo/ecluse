#ifndef SIGNALLUMINEUX_H
#define SIGNALLUMINEUX_H

#include <QObject>

class SignalLumineux : public QObject
{
    Q_OBJECT

public:
    SignalLumineux();

private:
    int etat; // 1 = vert, 0 = rouge
};


#endif // SIGNALLUMINEUX_H
