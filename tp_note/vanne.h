#ifndef VANNE_H
#define VANNE_H

#include <QThread>

class Vanne : public QThread
{
    Q_OBJECT

public:
    explicit Vanne(QObject *parent = 0);

protected:
    void run();

signals:
    void etatVanne(int);
    void alarmeVanne(int);

public slots:
    void ouverture();
    void fermeture();
    void urgence();
    void mettreAlarme(int); // 1 = panne, 0 = urgence
    void enleverAlarme();
    void mettrePanne();
    void enleverPanne();
    bool isPanne();
    bool isAlarme();

private:
    int etat; // 1 = ouvert, 0 = fermé
    bool panne; // 1 = en panne, 0 = en marche
    bool alarme; // 1 = alarme, 0 = pas d'alarme
};

#endif // VANNE_H
