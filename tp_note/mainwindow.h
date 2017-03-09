// SUTTER Nicolas et POIZAT Théo, L3 CMI ISR

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ecluse.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>
#include <QGroupBox>
#include <QCheckBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void authentification();
    // fenêtre du générateur de pannes
    QWidget failgen;
    QGroupBox *groupbox = new QGroupBox("F41LG3N 1.0", &failgen);
    QCheckBox *vanneAmontCK = new QCheckBox("Vanne Amont");
    QCheckBox *vanneAvalCK = new QCheckBox("Vanne Aval");
    QCheckBox *porteAmontCK = new QCheckBox("Porte Amont");
    QCheckBox *porteAvalCK = new QCheckBox("Porte Aval");
    QPushButton *boutonCK = new QPushButton("GO !");
    QVBoxLayout *vbox = new QVBoxLayout;

signals:

private slots:
    void on_Button_Amont_Aval_3_clicked();
    void on_Button_Aval_Amont_3_clicked();
    void on_Button_Amont_Aval_4_clicked();

    void random(); // fonction de génération d'une panne

    void on_urgence();
    void mdp();
    void auth();

    void on_Button_retour_clicked();
    void on_Button_quit_clicked();

    void rendu_ouvre_vanne1();
    void rendu_ouvre_vanne2();
    void rendu_ferme_vanne1();
    void rendu_ferme_vanne2();
    void monte_eau(); // augmente visuellement le niveau de l'eau
    void baisse_eau(); // diminue visuellement le niveau de l'eau

    void feu_aval(); // mise à jour visuelle du feu aval en fonction de son état
    void feu_amont(); // mise à jour visuelle du feu amont en fonction de son état
    void feu_aval_admin(); // idem en mode administrateur
    void feu_amont_admin(); // idem en mode administrateur

    // mouvement des portes
    void baisseporte1();
    void baisseporte2();
    void monteporte1();
    void monteporte2();

    void aligne_eau();

    void on_radioButton_7_clicked();

    void on_radioButton_8_clicked();

    void on_radioButton_13_clicked();

    void on_radioButton_14_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_9_clicked();

    void on_radioButton_10_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_11_clicked();

    void on_radioButton_12_clicked();

    void incident(); // gestion d'une panne

    void enable();
    void final_enable();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::MainWindow *ui;
    Ecluse e;

    int code[4]; // mot de passe stocké dans la fenêtre
    int pos = 0;
    int previous = 0;
};

#endif // MAINWINDOW_H
