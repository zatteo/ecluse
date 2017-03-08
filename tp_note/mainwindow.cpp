#include "mainwindow.h"
#include "ui_mainwindow.h"

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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_Amont_Aval_3_clicked()
{
    e.sens = -1; // 1 = aval vers amont, -1 = amont vers aval

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
    e.sens = 1; // 1 = aval vers amont, -1 = amont vers aval

    ui->stackedWidget->setCurrentIndex(1);
    ui->label_3->setText("Lorsque vous êtes sortit du sas:");
    ui->Button_Amont_Aval_4->setText("Fermer la porte");

    e.avalVersAmont1();

    for(int i=0; i< 34; i++)
    {
     ui->progressBar_2->setValue(i);
    }
}

void MainWindow::on_Button_Amont_Aval_4_clicked()
{
    if(ui->progressBar_2->value()  < 65)
    {
        for(int i=34; i< 67; i++)
        {
            ui->progressBar_2->setValue(i);
        }
        ui->label_3->setText("Lorsque vous êtes sortit du sas:");
        ui->Button_Amont_Aval_4->setText("J'ai fini");
    }
    else
    {
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
