#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ecluse.h>

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

signals:

private slots:
    void on_Button_Amont_Aval_3_clicked();
    void on_Button_Aval_Amont_3_clicked();
    void on_Button_Amont_Aval_4_clicked();

    void on_urgence();
    void mdp();
    void auth();

    void on_Button_retour_clicked();
    void on_Button_quit_clicked();

    void rendu_ouvre_vanne1();
    void rendu_ouvre_vanne2();
    void rendu_ferme_vanne1();
    void rendu_ferme_vanne2();
    void monte_eau();
    void baisse_eau();

    void feu_aval();
    void feu_amont();

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

    void incident();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_11_clicked();

    void on_radioButton_12_clicked();

    void enable();
    void final_enable();

private:
    Ui::MainWindow *ui;
    Ecluse e;
    int code[4];
    int pos=0;
    int previous=0;
};

#endif // MAINWINDOW_H
