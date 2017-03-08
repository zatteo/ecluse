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

private slots:
    void on_Button_Amont_Aval_3_clicked();
    void on_Button_Aval_Amont_3_clicked();
    void on_Button_Amont_Aval_4_clicked();

    void on_urgence();
    void mdp();
    void auth();

    void on_Button_retour_clicked();

    void on_Button_quit_clicked();

private:
    Ui::MainWindow *ui;
    Ecluse e;
    int code[4];
    int pos=0;
    int previous=0;
};

#endif // MAINWINDOW_H
