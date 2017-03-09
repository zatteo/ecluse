#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->Button_urgence1, SIGNAL(clicked(bool)), this, SLOT(on_urgence()));
    QObject::connect(ui->Button_urgence2, SIGNAL(clicked(bool)), this, SLOT(on_urgence()));
    QObject::connect(ui->Button_urgence3, SIGNAL(clicked(bool)), this, SLOT(on_urgence()));
    QObject::connect(ui->Button_urgence4, SIGNAL(clicked(bool)), this, SLOT(on_urgence()));

    QObject::connect(ui->Button_0, SIGNAL(clicked(bool)), this, SLOT(mdp()));
    QObject::connect(ui->Button_1, SIGNAL(clicked(bool)), this, SLOT(mdp()));
    QObject::connect(ui->Button_2, SIGNAL(clicked(bool)), this, SLOT(mdp()));
    QObject::connect(ui->Button_3, SIGNAL(clicked(bool)), this, SLOT(mdp()));
    QObject::connect(ui->Button_4, SIGNAL(clicked(bool)), this, SLOT(mdp()));
    QObject::connect(ui->Button_5, SIGNAL(clicked(bool)), this, SLOT(mdp()));
    QObject::connect(ui->Button_6, SIGNAL(clicked(bool)), this, SLOT(mdp()));
    QObject::connect(ui->Button_7, SIGNAL(clicked(bool)), this, SLOT(mdp()));
    QObject::connect(ui->Button_8, SIGNAL(clicked(bool)), this, SLOT(mdp()));
    QObject::connect(ui->Button_9, SIGNAL(clicked(bool)), this, SLOT(mdp()));
    QObject::connect(ui->Button_ok, SIGNAL(clicked(bool)), this, SLOT(mdp()));
    QObject::connect(ui->Button_rm, SIGNAL(clicked(bool)), this, SLOT(mdp()));

    QObject::connect(ui->Button_auth1, SIGNAL(clicked(bool)), this, SLOT(auth()));
    QObject::connect(ui->Button_auth2, SIGNAL(clicked(bool)), this, SLOT(auth()));
    QObject::connect(ui->Button_auth3, SIGNAL(clicked(bool)), this, SLOT(auth()));

    QObject::connect(e.porteAmont, SIGNAL(signalPortePlusUn()), this, SLOT(baisseporte1()));
    QObject::connect(e.porteAmont, SIGNAL(signalPorteMoinsUn()), this, SLOT(monteporte1()));
    QObject::connect(e.porteAval, SIGNAL(signalPortePlusUn()), this, SLOT(baisseporte2()));
    QObject::connect(e.porteAval, SIGNAL(signalPorteMoinsUn()), this, SLOT(monteporte2()));

    feu_amont();
    feu_aval();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rendu_ouvre_vanne1()
{
    ui->vanne1->setStyleSheet("background-color:rgb(114, 159, 207);");
    ui->vanne3->setStyleSheet("background-color:rgb(114, 159, 207);");
    ui->vanne2_2->setStyleSheet("background-color:rgb(114, 159, 207);");
    e.vanneAmont->etat = 1;

}
void MainWindow::rendu_ferme_vanne1()
{
    ui->vanne1->setStyleSheet("background-color:rgb(85, 87, 83);");
    ui->vanne3->setStyleSheet("background-color:rgb(85, 87, 83);");
    ui->vanne2_2->setStyleSheet("background-color:rgb(85, 87, 83);");
    e.vanneAmont->etat = 0;
}
void MainWindow::rendu_ouvre_vanne2()
{
    ui->vanne4->setStyleSheet("background-color:rgb(114, 159, 207);");
    ui->vanne2->setStyleSheet("background-color:rgb(114, 159, 207);");
    ui->vanne2_4->setStyleSheet("background-color:rgb(114, 159, 207);");
    e.vanneAval->etat = 1;
}
void MainWindow::rendu_ferme_vanne2()
{
    ui->vanne2->setStyleSheet("background-color:rgb(85, 87, 83);");
    ui->vanne4->setStyleSheet("background-color:rgb(85, 87, 83);");
    ui->vanne2_4->setStyleSheet("background-color:rgb(85, 87, 83);");
    e.vanneAval->etat = 0;
}

void MainWindow::feu_aval()
{
    if(e.signalAval->etat == 0)
    {
        ui->feux2_3->setStyleSheet("background-color:rgb(239, 41, 41)");
        ui->feux2->setStyleSheet("background-color:rgb(239, 41, 41)");
        ui->feux4->setStyleSheet("background-color:rgb(239, 41, 41)");
    }
    else
    {
        ui->feux2_3->setStyleSheet("background-color: rgb(78, 154, 6);");
        ui->feux2->setStyleSheet("background-color: rgb(78, 154, 6);");
        ui->feux4->setStyleSheet("background-color: rgb(78, 154, 6);");
    }
}
void MainWindow::feu_amont()
{
    if(e.signalAmont->etat == 0)
    {
        ui->feux2_2->setStyleSheet("background-color:rgb(239, 41, 41)");
        ui->feux1->setStyleSheet("background-color:rgb(239, 41, 41)");
        ui->feux3->setStyleSheet("background-color:rgb(239, 41, 41)");
    }
    else
    {
        ui->feux2_2->setStyleSheet("background-color: rgb(78, 154, 6);");
        ui->feux1->setStyleSheet("background-color: rgb(78, 154, 6);");
        ui->feux3->setStyleSheet("background-color: rgb(78, 154, 6);");
    }
}

void MainWindow::baisse_eau()
{
    for(int i=0; i< 10; i++)
    {
        ui->eau1->move( ui->eau1->pos().x() , (ui->eau1->pos().y() + 5 ));
        ui->eau2->move( ui->eau1->pos().x() , (ui->eau2->pos().y() + 5 ));
        QApplication::processEvents();
        QThread::msleep(300);
    }
}

void MainWindow::baisseporte1()
{
    ui->porte1->move( ui->porte1->pos().x() , (ui->porte1->pos().y() + 7 ));
    ui->porte3->move( ui->porte3->pos().x() , (ui->porte3->pos().y() + 7 ));
    QApplication::processEvents();
}

void MainWindow::baisseporte2()
{
    ui->porte2->move( ui->porte2->pos().x() , (ui->porte2->pos().y() + 7 ));
    ui->porte4->move( ui->porte4->pos().x() , (ui->porte4->pos().y() + 7 ));
    QApplication::processEvents();
}


void MainWindow::monte_eau()
{
    for(int i=0; i< 10; i++)
    {
        ui->eau1->move( ui->eau1->pos().x() , (ui->eau1->pos().y() - 5 ));
        ui->eau2->move( ui->eau1->pos().x() , (ui->eau2->pos().y() - 5 ));
        QApplication::processEvents();
        QThread::msleep(300);
    }
}

void MainWindow::monteporte1()
{
    ui->porte1->move( ui->porte1->pos().x() , (ui->porte1->pos().y() - 7 ));
    ui->porte3->move( ui->porte3->pos().x() , (ui->porte3->pos().y() - 7 ));
    QApplication::processEvents();
}

void MainWindow::monteporte2()
{
    ui->porte2->move( ui->porte2->pos().x() , (ui->porte2->pos().y() - 7 ));
    ui->porte4->move( ui->porte4->pos().x() , (ui->porte4->pos().y() - 7 ));
    QApplication::processEvents();
}

void MainWindow::on_Button_Amont_Aval_3_clicked()
{
    e.sens = -1;

    if(e.niveauEau == 0)
    {
        rendu_ouvre_vanne1();
        monte_eau();
        rendu_ferme_vanne1();
    }

    ui->stackedWidget->setCurrentIndex(1);
    ui->label_3->setText("Lorsque vous êtes dans le sas:");
    ui->Button_Amont_Aval_4->setText("Fermer la porte");
    for(int i=0; i< 34; i++)
    {
        ui->progressBar_2->setValue(i);
    }
}

void MainWindow::on_Button_Aval_Amont_3_clicked()
{
    e.sens = 1;

    if(e.niveauEau == 1)
    {
        rendu_ouvre_vanne2();
        baisse_eau();
        rendu_ferme_vanne2();
    }

    e.avalVersAmont1();

    ui->stackedWidget->setCurrentIndex(1);
    ui->label_3->setText("Lorsque vous êtes sortit du sas:");
    ui->Button_Amont_Aval_4->setText("Fermer la porte");
    for(int i=0; i< 34; i++)
    {
     ui->progressBar_2->setValue(i);
    }
}

void MainWindow::on_Button_Amont_Aval_4_clicked()
{
    if(ui->progressBar_2->value()  < 65)
    {
        // partie 2
        if(e.niveauEcluse == 2)
        {
            if(e.sens == 1)
            {
                e.avalVersAmont2bis();
            }
        }

        for(int i=34; i< 67; i++)
        {
            ui->progressBar_2->setValue(i);
        }
        ui->label_3->setText("Lorsque vous êtes sortit du sas:");
        ui->Button_Amont_Aval_4->setText("J'ai fini");
    }
    else
    {
        // partie 3
        if(e.niveauEcluse == 3)
        {
            if(e.sens == 1)
            {
                e.avalVersAmont3bis();
            }
        }

        ui->stackedWidget->setCurrentIndex(0);
    }
}

void MainWindow::on_urgence()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::mdp()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString text = button->text();
    if(text != "OK" && text != "<--" && pos<5)
    {
       code[pos] = text.toInt();
       pos= pos + 1;
       ui->Champ_mdp->insert("*");
    }
    if(text == "<--" && pos > 0)
    {
        pos= pos - 1;
        code[pos]=-1;
        ui->Champ_mdp->clear();
        for(int i=0; i<pos; i++)
        {
            ui->Champ_mdp->insert("*");
        }
    }
    if(text == "OK")
    {
        if(pos == 4 && code[0] == 1 && code[1] == 2 && code[2] == 3 && code[3]== 1)
        {
            ui->Champ_mdp->clear();
            for(int i=0; i<pos; i++)
                code[i]= -1;
            pos = 0;
            ui->stackedWidget->setCurrentIndex(4);
            if(e.vanneAmont->etat == 1) ui->radioButton->setChecked(true);
            else ui->radioButton_2->setChecked(true);
            if(e.vanneAval->etat == 1) ui->radioButton_9->setChecked(true);
            else ui->radioButton_10->setChecked(true);
            if(e.vanneAmont->alarme) {ui->label_12->show(); ui->pushButton_9->show();}
            else {ui->label_12->hide(); ui->pushButton_9->hide();}
            if(e.vanneAval->alarme) {ui->label_20->show(); ui->pushButton_13->show();}
            else {ui->label_20->hide(); ui->pushButton_13->hide();}

            if(e.porteAmont->etat == 4) ui->radioButton_5->setChecked(true);
            else ui->radioButton_6->setChecked(true);
            if(e.porteAval->etat == 4) ui->radioButton_11->setChecked(true);
            else ui->radioButton_12->setChecked(true);
            if(e.porteAmont->alarme) {ui->label_16->show(); ui->pushButton_11->show();}
            else {ui->label_16->hide(); ui->pushButton_11->hide();}
            if(e.porteAval->alarme) {ui->label_22->show(); ui->pushButton_14->show();}
            else {ui->label_22->hide(); ui->pushButton_14->hide();}

            if(e.signalAmont->etat == 0) ui->radioButton_7->setChecked(true);
            else ui->radioButton_8->setChecked(true);
            if(e.signalAval->etat == 0) ui->radioButton_13->setChecked(true);
            else ui->radioButton_14->setChecked(true);

        }
        else
        {
            ui->Champ_mdp->clear();
            for(int i=0; i<pos; i++)
                code[i]= -1;
            pos = 0;
        }
    }
}

void MainWindow::auth()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString text = button->objectName();
    if(text == "Button_auth3")
        previous= 3;
    else if(text == "Button_auth2")
        previous= 1;
    else
        previous= 0;
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Button_retour_clicked()
{
    for(int i=0; i<pos; i++)
        code[i]= -1;
    pos = 0;
    ui->Champ_mdp->clear();
    ui->stackedWidget->setCurrentIndex(previous);
}

void MainWindow::on_Button_quit_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_radioButton_7_clicked()
{
    e.signalAmont->etat= 0;
    feu_amont();
}

void MainWindow::on_radioButton_8_clicked()
{
    e.signalAmont->etat= 1;
    feu_amont();
}

void MainWindow::on_radioButton_13_clicked()
{
    e.signalAval->etat= 0;
    feu_aval();
}

void MainWindow::on_radioButton_14_clicked()
{
    e.signalAval->etat= 1;
    feu_aval();
}

void MainWindow::on_radioButton_clicked()
{
    rendu_ouvre_vanne1();
}

void MainWindow::on_radioButton_2_clicked()
{
    rendu_ferme_vanne1();
}

void MainWindow::on_radioButton_9_clicked()
{
    rendu_ouvre_vanne2();
}

void MainWindow::on_radioButton_10_clicked()
{
    rendu_ferme_vanne2();
}
