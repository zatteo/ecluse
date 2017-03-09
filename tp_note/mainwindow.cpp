#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>
#include <QGroupBox>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->Button_urgence1, SIGNAL(clicked(bool)), this, SLOT(on_urgence()));
    QObject::connect(ui->Button_urgence2, SIGNAL(clicked(bool)), this, SLOT(on_urgence()));
    QObject::connect(ui->Button_urgence3, SIGNAL(clicked(bool)), this, SLOT(on_urgence()));
    QObject::connect(ui->Button_urgence4, SIGNAL(clicked(bool)), this, SLOT(on_urgence()));

    // authentification
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

    // actualisation du niveau des portes
    QObject::connect(e.porteAmont, SIGNAL(signalPortePlusUn()), this, SLOT(baisseporte1()));
    QObject::connect(e.porteAmont, SIGNAL(signalPorteMoinsUn()), this, SLOT(monteporte1()));
    QObject::connect(e.porteAval, SIGNAL(signalPortePlusUn()), this, SLOT(baisseporte2()));
    QObject::connect(e.porteAval, SIGNAL(signalPorteMoinsUn()), this, SLOT(monteporte2()));

    // actualisation du niveau central de l'eau
    QObject::connect(e.vanneAmont, SIGNAL(signalVannePlusUn()), this, SLOT(monte_eau()));
    QObject::connect(e.vanneAval, SIGNAL(signalVannePlusUn()), this, SLOT(baisse_eau()));

    // actualisation de l'image des vannes
    QObject::connect(e.vanneAmont, SIGNAL(signalVanneFermee()), this, SLOT(rendu_ferme_vanne1()));
    QObject::connect(e.vanneAmont, SIGNAL(signalVanneOuverte()), this, SLOT(rendu_ouvre_vanne1()));
    QObject::connect(e.vanneAval, SIGNAL(signalVanneFermee()), this, SLOT(rendu_ferme_vanne2()));
    QObject::connect(e.vanneAval, SIGNAL(signalVanneOuverte()), this, SLOT(rendu_ouvre_vanne2()));

    // actualisation des feux
    QObject::connect(e.porteAmont, SIGNAL(signalPorteMoinsUn()), this, SLOT(feu_amont()));
    QObject::connect(e.porteAmont, SIGNAL(porteOuverte()), this, SLOT(feu_amont()));
    QObject::connect(e.porteAval, SIGNAL(signalPorteMoinsUn()), this, SLOT(feu_aval()));
    QObject::connect(e.porteAval, SIGNAL(porteOuverte()), this, SLOT(feu_aval()));

    QObject::connect(e.porteAmont, SIGNAL(porteOuverte()), this, SLOT(enable()));
    QObject::connect(e.porteAval, SIGNAL(porteOuverte()), this, SLOT(enable()));
    QObject::connect(e.porteAmont, SIGNAL(porteFermee()), this, SLOT(final_enable()));
    QObject::connect(e.porteAval, SIGNAL(porteFermee()), this, SLOT(final_enable()));

    // gestion des incidents
    QObject::connect(e.porteAmont, SIGNAL(alarmePorte()), this, SLOT(incident()));
    QObject::connect(e.porteAval, SIGNAL(alarmePorte()), this, SLOT(incident()));
    QObject::connect(e.vanneAmont, SIGNAL(alarmeVanne()), this, SLOT(incident()));
    QObject::connect(e.vanneAval, SIGNAL(alarmeVanne()), this, SLOT(incident()));

    feu_amont();
    feu_aval();

    failgen.resize(150, 200);

    vbox->addWidget(vanneAmontCK);
    vbox->addWidget(vanneAvalCK);
    vbox->addWidget(porteAmontCK);
    vbox->addWidget(porteAvalCK);
    vbox->addWidget(boutonCK);
    groupbox->setLayout(vbox);
    groupbox->move(5, 5);

    connect(boutonCK, SIGNAL(clicked(bool)), this, SLOT(random()));

    failgen.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::random()
{
    QList<QString> list;

    if(vanneAmontCK->isChecked())
    {
        list.append("vanneAmont");
    }
    if(vanneAvalCK->isChecked())
    {
        list.append("vanneAval");
    }
    if(porteAmontCK->isChecked())
    {
        list.append("porteAmont");
    }
    if(porteAvalCK->isChecked())
    {
        list.append("porteAval");
    }

    int randomValue = qrand() % 3;

    if(list.at(randomValue) == "vanneAmont")
    {
        e.vanneAmont->urgence();
    }
    else if(list.at(randomValue) == "vanneAval")
    {
        e.vanneAval->urgence();
    }
    else if(list.at(randomValue) == "porteAmont")
    {
        e.porteAmont->urgence();
    }
    else if(list.at(randomValue) == "porteAval")
    {
        e.porteAval->urgence();
    }
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
    qDebug() << "feu aval";
    if(!e.admin) // on actualise pas le feu si on est en administration (controle total)
    {
        if(e.signalAval->etat == 0)
        {
            qDebug() << "rouige";
            ui->feux2_3->setStyleSheet("background-color:rgb(239, 41, 41)");
            ui->feux2->setStyleSheet("background-color:rgb(239, 41, 41)");
            ui->feux4->setStyleSheet("background-color:rgb(239, 41, 41)");
        }
        else
        {
            qDebug() << "vert";
            ui->feux2_3->setStyleSheet("background-color: rgb(78, 154, 6);");
            ui->feux2->setStyleSheet("background-color: rgb(78, 154, 6);");
            ui->feux4->setStyleSheet("background-color: rgb(78, 154, 6);");
        }
    }
}
void MainWindow::feu_amont()
{
    qDebug() << "feu amont";
    if(!e.admin) // on actualise pas le feu si on est en administration (controle total)
    {
        if(e.signalAmont->etat == 0)
        {
            qDebug() << "rouge";
            ui->feux2_2->setStyleSheet("background-color:rgb(239, 41, 41)");
            ui->feux1->setStyleSheet("background-color:rgb(239, 41, 41)");
            ui->feux3->setStyleSheet("background-color:rgb(239, 41, 41)");
        }
        else
        {
            qDebug() << "vert";
            ui->feux2_2->setStyleSheet("background-color: rgb(78, 154, 6);");
            ui->feux1->setStyleSheet("background-color: rgb(78, 154, 6);");
            ui->feux3->setStyleSheet("background-color: rgb(78, 154, 6);");
        }
    }
}

void MainWindow::baisse_eau()
{
        ui->eau1->move( ui->eau1->pos().x() , (ui->eau1->pos().y() + 5 ));
        ui->eau2->move( ui->eau2->pos().x() , (ui->eau2->pos().y() + 5 ));
        ui->eau3->move( ui->eau3->pos().x() , (ui->eau3->pos().y() + 5 ));
        QApplication::processEvents();
        e.niveauEau=0;
}

void MainWindow::baisseporte1()
{
    ui->porte1->move( ui->porte1->pos().x() , (ui->porte1->pos().y() + 7 ));
    ui->porte3->move( ui->porte3->pos().x() , (ui->porte3->pos().y() + 7 ));
    ui->porte1_2->move( ui->porte1_2->pos().x() , (ui->porte1_2->pos().y() + 7 ));
    QApplication::processEvents();
}

void MainWindow::baisseporte2()
{
    ui->porte2->move( ui->porte2->pos().x() , (ui->porte2->pos().y() + 7 ));
    ui->porte4->move( ui->porte4->pos().x() , (ui->porte4->pos().y() + 7 ));
    ui->porte1_3->move( ui->porte1_3->pos().x() , (ui->porte1_3->pos().y() + 7 ));
    QApplication::processEvents();
}


void MainWindow::monte_eau()
{
        ui->eau1->move( ui->eau1->pos().x() , (ui->eau1->pos().y() - 5 ));
        ui->eau2->move( ui->eau2->pos().x() , (ui->eau2->pos().y() - 5 ));
        ui->eau3->move( ui->eau3->pos().x() , (ui->eau3->pos().y() - 5 ));
        QApplication::processEvents();
        e.niveauEau=2;
}

void MainWindow::monteporte1()
{
    ui->porte1->move( ui->porte1->pos().x() , (ui->porte1->pos().y() - 7 ));
    ui->porte3->move( ui->porte3->pos().x() , (ui->porte3->pos().y() - 7 ));
    ui->porte1_2->move( ui->porte1_2->pos().x() , (ui->porte1_2->pos().y() - 7 ));
    QApplication::processEvents();
}

void MainWindow::monteporte2()
{
    ui->porte2->move( ui->porte2->pos().x() , (ui->porte2->pos().y() - 7 ));
    ui->porte4->move( ui->porte4->pos().x() , (ui->porte4->pos().y() - 7 ));
    ui->porte1_3->move( ui->porte1_3->pos().x() , (ui->porte1_3->pos().y() - 7 ));

    QApplication::processEvents();
}

void MainWindow::enable()
{
    ui->Button_Amont_Aval_4->setDisabled(false);
    ui->Button_auth2->setDisabled(false);
}

void MainWindow::final_enable()
{
    ui->Button_Amont_Aval_3->setDisabled(false);
    ui->Button_Aval_Amont_3->setDisabled(false);
    ui->Button_auth1->setDisabled(false);
}

void MainWindow::on_Button_Amont_Aval_3_clicked()
{
    ui->Button_Amont_Aval_3->setDisabled(true);
    ui->Button_Aval_Amont_3->setDisabled(true);
    ui->Button_auth1->setDisabled(true);
    e.sens = -1;

    e.amontVersAval1();

    ui->stackedWidget->setCurrentIndex(1);
    ui->label_3->setText("Lorsque vous êtes dans le sas :");
    ui->Button_Amont_Aval_4->setText("Fermer la porte");
    ui->Button_Amont_Aval_4->setDisabled(true);
    ui->Button_auth2->setDisabled(true);

    for(int i=0; i< 34; i++)
    {
        ui->progressBar_2->setValue(i);
    }
}

void MainWindow::on_Button_Aval_Amont_3_clicked()
{   
    e.sens = 1;

    e.avalVersAmont1();

    ui->stackedWidget->setCurrentIndex(1);
    ui->label_3->setText("Lorsque vous êtes sorti du sas :");
    ui->Button_Amont_Aval_4->setText("Fermer la porte");
    ui->Button_Amont_Aval_4->setDisabled(true);
    ui->Button_auth2->setDisabled(true);
    for(int i=0; i< 34; i++)
    {
     ui->progressBar_2->setValue(i);
    }
}

void MainWindow::on_Button_Amont_Aval_4_clicked()
{
    ui->Button_Amont_Aval_4->setDisabled(true);
    ui->Button_Amont_Aval_3->setDisabled(true);
    ui->Button_auth2->setDisabled(true);
    if(ui->progressBar_2->value()  < 65)
    {
        // partie 2
        if(e.niveauEcluse == 2)
        {
            if(e.sens == 1)
            {
                e.avalVersAmont2bis();
            }
            else if(e.sens == -1)
            {
                e.amontVersAval2bis();
            }
        }

        for(int i=34; i< 67; i++)
        {
            ui->progressBar_2->setValue(i);
        }
        ui->label_3->setText("Lorsque vous êtes sorti du sas:");
        ui->Button_Amont_Aval_4->setText("J'ai fini");
    }
    else
    {
        ui->Button_Amont_Aval_4->setDisabled(true);
        ui->Button_Amont_Aval_3->setDisabled(true);
        ui->Button_auth2->setDisabled(true);
        ui->Button_Aval_Amont_3->setDisabled(true);
        ui->Button_auth1->setDisabled(true);
        // partie 3
        if(e.niveauEcluse == 3)
        {
            if(e.sens == 1)
            {
                e.avalVersAmont3bis();
            }
            else if(e.sens == -1)
            {
                e.amontVersAval3bis();
            }
        }

        ui->stackedWidget->setCurrentIndex(0);
    }
}

//arret d'urgence
void MainWindow::on_urgence()
{
    e.urgence();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::incident()
{
    ui->stackedWidget->setCurrentIndex(3);
}


//connection
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
        //si le mot de passe est le bon
        if(pos == 4 && code[0] == 1 && code[1] == 2 && code[2] == 3 && code[3]== 1)
        {
            ui->Champ_mdp->clear();
            for(int i=0; i<pos; i++)
                code[i]= -1;
            pos = 0;
            ui->stackedWidget->setCurrentIndex(4);
            e.admin = true;
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

            if(e.niveauEau == 2)
            {
                ui->radioButton_11->setEnabled(false);
                ui->radioButton_12->setEnabled(false);
            }
            else if(e.niveauEau == 1)
            {
                ui->radioButton_11->setEnabled(false);
                ui->radioButton_12->setEnabled(false);
                ui->radioButton_5->setEnabled(false);
                ui->radioButton_6->setEnabled(false);
            }
            else if(e.niveauEau == 0)
            {
                ui->radioButton_5->setEnabled(false);
                ui->radioButton_6->setEnabled(false);
            }

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

//click sur le bouton pour se connecter
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

//annulation ecran connection
void MainWindow::on_Button_retour_clicked()
{
    for(int i=0; i<pos; i++)
        code[i]= -1;
    pos = 0;
    ui->Champ_mdp->clear();
    ui->stackedWidget->setCurrentIndex(previous);
}

//deconnexion du panneau manuel
void MainWindow::on_Button_quit_clicked()
{
    e.admin = false;
    ui->stackedWidget->setCurrentIndex(0);
}

//changement feu amont
void MainWindow::on_radioButton_7_clicked()
{
    e.signalAmont->rouge();
    feu_amont();
}

//changement feu amont
void MainWindow::on_radioButton_8_clicked()
{
    e.signalAmont->vert();
    feu_amont();
}

//changement feu aval
void MainWindow::on_radioButton_13_clicked()
{
    e.signalAval->rouge();
    feu_aval();
}

//changement feu aval
void MainWindow::on_radioButton_14_clicked()
{
    e.signalAval->vert();
    feu_aval();
}

//aligne le niveau de l'eau en fonctione des vannes
void MainWindow::aligne_eau()
{
    int k=0, l=0;
    if(e.niveauEau == 1 && e.vanneAmont->etat == 1 && e.vanneAval->etat == 0) {k= 5; e.niveauEau=2;}
    else if(e.niveauEau == 0 && e.vanneAmont->etat == 1 && e.vanneAval->etat == 0) {k = 10; e.niveauEau=2;}
    else if(e.niveauEau == 2 && e.vanneAmont->etat == 0 && e.vanneAval->etat == 1) {l = 10; e.niveauEau=0;}
    else if(e.niveauEau == 1 && e.vanneAmont->etat == 0 && e.vanneAval->etat == 1) {l = 5; e.niveauEau=0;}
    else if(e.niveauEau == 0 && e.vanneAmont->etat == 1 && e.vanneAval->etat == 1) {k = 5; e.niveauEau=1;}
    else if(e.niveauEau == 2 && e.vanneAmont->etat == 1 && e.vanneAval->etat == 1) {l = 5; e.niveauEau=1;}
    for(int i=1; i<k; i++)
    {
        ui->eau1->move( ui->eau1->pos().x() , (ui->eau1->pos().y() - 5 ));
        ui->eau2->move( ui->eau2->pos().x() , (ui->eau2->pos().y() - 5 ));
        ui->eau3->move( ui->eau3->pos().x() , (ui->eau3->pos().y() - 5 ));
        QApplication::processEvents();
        sleep(0.5);
    }
    for(int i=1; i<l; i++)
    {
        ui->eau1->move( ui->eau1->pos().x() , (ui->eau1->pos().y() + 5 ));
        ui->eau2->move( ui->eau2->pos().x() , (ui->eau2->pos().y() + 5 ));
        ui->eau3->move( ui->eau3->pos().x() , (ui->eau3->pos().y() + 5 ));

        QApplication::processEvents();
        sleep(0.5);
    }
}

//ouverture manuelle vanne amont
void MainWindow::on_radioButton_clicked()
{
    ui->radioButton_5->setEnabled(false);
    ui->radioButton_6->setEnabled(false);
    ui->radioButton_11->setEnabled(false);
    ui->radioButton_12->setEnabled(false);
    rendu_ouvre_vanne1();
    aligne_eau();
}

//fermeture manuelle vanne amont
void MainWindow::on_radioButton_2_clicked()
{
    rendu_ferme_vanne1();
    aligne_eau();
    if(e.vanneAval->etat == 0)
    {
        ui->radioButton_5->setEnabled(true);
        ui->radioButton_6->setEnabled(true);
    }
}

//ouverture vanne manuelle aval
void MainWindow::on_radioButton_9_clicked()
{
    ui->radioButton_5->setEnabled(false);
    ui->radioButton_6->setEnabled(false);
    ui->radioButton_11->setEnabled(false);
    ui->radioButton_12->setEnabled(false);
    rendu_ouvre_vanne2();
    aligne_eau();
}

//fermeture manuelle vanne aval
void MainWindow::on_radioButton_10_clicked()
{
    rendu_ferme_vanne2();
    aligne_eau();
    if(e.vanneAmont->etat == 0)
    {
        ui->radioButton_11->setEnabled(true);
        ui->radioButton_12->setEnabled(true);
    }
}

//ouverture manuelle porte amont
void MainWindow::on_radioButton_5_clicked()
{
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    ui->radioButton_9->setEnabled(false);
    ui->radioButton_10->setEnabled(false);
    ui->radioButton_11->setEnabled(false);
    ui->radioButton_12->setEnabled(false);
    e.ouverturePorteAmont();
}

//fermeture manuelle porte amont
void MainWindow::on_radioButton_6_clicked()
{
    e.fermeturePorteAmont();
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
    ui->radioButton_9->setEnabled(true);
    ui->radioButton_10->setEnabled(true);
}

//ouverture manuelle porte aval
void MainWindow::on_radioButton_11_clicked()
{
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    ui->radioButton_9->setEnabled(false);
    ui->radioButton_10->setEnabled(false);
    ui->radioButton_5->setEnabled(false);
    ui->radioButton_6->setEnabled(false);
    e.ouverturePorteAval();
}

//fermeture manuelle porte aval
void MainWindow::on_radioButton_12_clicked()
{
    e.fermeturePorteAval();
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
    ui->radioButton_9->setEnabled(true);
    ui->radioButton_10->setEnabled(true);
}

void MainWindow::on_pushButton_9_clicked()
{
    e.vanneAmont->enleverAlarme();
    if(e.vanneAmont->alarme) {ui->label_12->show(); ui->pushButton_9->show();}
    else {ui->label_12->hide(); ui->pushButton_9->hide();}
}

void MainWindow::on_pushButton_11_clicked()
{
    e.porteAmont->enleverAlarme();
    if(e.porteAmont->alarme) {ui->label_16->show(); ui->pushButton_11->show();}
    else {ui->label_16->hide(); ui->pushButton_11->hide();}
}

void MainWindow::on_pushButton_13_clicked()
{
    e.vanneAval->enleverAlarme();
    if(e.vanneAval->alarme) {ui->label_20->show(); ui->pushButton_13->show();}
    else {ui->label_20->hide(); ui->pushButton_13->hide();}
}

void MainWindow::on_pushButton_14_clicked()
{
    e.porteAval->enleverAlarme();
    if(e.porteAval->alarme) {ui->label_22->show(); ui->pushButton_14->show();}
    else {ui->label_22->hide(); ui->pushButton_14->hide();}
}
