/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *Button_Amont_Aval_3;
    QPushButton *Button_Aval_Amont_3;
    QLabel *label_4;
    QLabel *label;
    QProgressBar *progressBar;
    QPushButton *Button_urgence1;
    QPushButton *Button_auth1;
    QWidget *page_2;
    QLabel *label_2;
    QPushButton *Button_urgence2;
    QProgressBar *progressBar_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QPushButton *Button_Amont_Aval_4;
    QLabel *label_5;
    QPushButton *Button_auth2;
    QWidget *page_connection;
    QFrame *frame;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *Button_1;
    QPushButton *Button_2;
    QPushButton *Button_3;
    QPushButton *Button_8;
    QPushButton *Button_7;
    QPushButton *Button_4;
    QPushButton *Button_6;
    QPushButton *Button_5;
    QPushButton *Button_ok;
    QPushButton *Button_0;
    QPushButton *Button_9;
    QPushButton *Button_rm;
    QLineEdit *Champ_mdp;
    QLabel *label_6;
    QPushButton *Button_retour;
    QPushButton *Button_urgence3;
    QWidget *page_urgence;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLabel *label_18;
    QLabel *label_8;
    QPushButton *Button_auth3;
    QWidget *page_admin;
    QPushButton *Button_urgence4;
    QLabel *label_9;
    QPushButton *Button_quit;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_10;
    QGridLayout *gridLayout_4;
    QWidget *widget_6;
    QRadioButton *radioButton_11;
    QRadioButton *radioButton_12;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *pushButton_14;
    QWidget *widget_4;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_10;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *pushButton_13;
    QWidget *widget_5;
    QRadioButton *radioButton_13;
    QRadioButton *radioButton_14;
    QLabel *label_23;
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_9;
    QWidget *widget_2;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *pushButton_11;
    QWidget *widget_3;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QLabel *label_17;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1227, 669);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 10, 1221, 591));
        page_1 = new QWidget();
        page_1->setObjectName(QStringLiteral("page_1"));
        page_1->setEnabled(true);
        verticalLayoutWidget_2 = new QWidget(page_1);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(160, 130, 911, 401));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        Button_Amont_Aval_3 = new QPushButton(verticalLayoutWidget_2);
        Button_Amont_Aval_3->setObjectName(QStringLiteral("Button_Amont_Aval_3"));
        Button_Amont_Aval_3->setStyleSheet(QStringLiteral("font: 30pt \"Ubuntu\";"));

        verticalLayout_3->addWidget(Button_Amont_Aval_3);

        Button_Aval_Amont_3 = new QPushButton(verticalLayoutWidget_2);
        Button_Aval_Amont_3->setObjectName(QStringLiteral("Button_Aval_Amont_3"));
        Button_Aval_Amont_3->setStyleSheet(QStringLiteral("font: 30pt \"Ubuntu\";"));

        verticalLayout_3->addWidget(Button_Aval_Amont_3);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../build-tp_note-Desktop_Qt_5_8_0_GCC_64bit-Debug/ressources/Sch\303\251ma.gif")));
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        label = new QLabel(page_1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 40, 371, 41));
        label->setStyleSheet(QStringLiteral("font: 30pt \"Ubuntu\";"));
        progressBar = new QProgressBar(page_1);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(830, 40, 301, 51));
        progressBar->setValue(0);
        Button_urgence1 = new QPushButton(page_1);
        Button_urgence1->setObjectName(QStringLiteral("Button_urgence1"));
        Button_urgence1->setGeometry(QRect(540, 0, 131, 111));
        QIcon icon;
        icon.addFile(QStringLiteral("../build-tp_note-Desktop_Qt_5_8_0_GCC_64bit-Debug/ressources/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        Button_urgence1->setIcon(icon);
        Button_urgence1->setIconSize(QSize(100, 100));
        Button_auth1 = new QPushButton(page_1);
        Button_auth1->setObjectName(QStringLiteral("Button_auth1"));
        Button_auth1->setGeometry(QRect(1010, 540, 191, 41));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../build-tp_note-Desktop_Qt_5_8_0_GCC_64bit-Debug/ressources/lock.png"), QSize(), QIcon::Normal, QIcon::Off);
        Button_auth1->setIcon(icon1);
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 40, 371, 41));
        label_2->setStyleSheet(QStringLiteral("font: 30pt \"Ubuntu\";"));
        Button_urgence2 = new QPushButton(page_2);
        Button_urgence2->setObjectName(QStringLiteral("Button_urgence2"));
        Button_urgence2->setGeometry(QRect(540, 0, 131, 111));
        Button_urgence2->setIcon(icon);
        Button_urgence2->setIconSize(QSize(100, 100));
        progressBar_2 = new QProgressBar(page_2);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setGeometry(QRect(830, 40, 301, 51));
        progressBar_2->setValue(66);
        verticalLayoutWidget_3 = new QWidget(page_2);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(150, 130, 911, 401));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 100));
        label_3->setStyleSheet(QStringLiteral("font: 30pt \"Ubuntu\";"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        Button_Amont_Aval_4 = new QPushButton(verticalLayoutWidget_3);
        Button_Amont_Aval_4->setObjectName(QStringLiteral("Button_Amont_Aval_4"));
        Button_Amont_Aval_4->setStyleSheet(QStringLiteral("font: 30pt \"Ubuntu\";"));

        verticalLayout_4->addWidget(Button_Amont_Aval_4);

        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../build-tp_note-Desktop_Qt_5_8_0_GCC_64bit-Debug/ressources/Sch\303\251ma.gif")));
        label_5->setScaledContents(false);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        Button_auth2 = new QPushButton(page_2);
        Button_auth2->setObjectName(QStringLiteral("Button_auth2"));
        Button_auth2->setGeometry(QRect(1010, 540, 191, 41));
        Button_auth2->setIcon(icon1);
        stackedWidget->addWidget(page_2);
        page_connection = new QWidget();
        page_connection->setObjectName(QStringLiteral("page_connection"));
        frame = new QFrame(page_connection);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-1, -11, 1231, 611));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayoutWidget = new QWidget(frame);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(410, 260, 401, 340));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Button_1 = new QPushButton(gridLayoutWidget);
        Button_1->setObjectName(QStringLiteral("Button_1"));
        Button_1->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button_1, 0, 0, 1, 1);

        Button_2 = new QPushButton(gridLayoutWidget);
        Button_2->setObjectName(QStringLiteral("Button_2"));
        Button_2->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button_2, 0, 1, 1, 1);

        Button_3 = new QPushButton(gridLayoutWidget);
        Button_3->setObjectName(QStringLiteral("Button_3"));
        Button_3->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button_3, 0, 2, 1, 1);

        Button_8 = new QPushButton(gridLayoutWidget);
        Button_8->setObjectName(QStringLiteral("Button_8"));
        Button_8->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button_8, 2, 1, 1, 1);

        Button_7 = new QPushButton(gridLayoutWidget);
        Button_7->setObjectName(QStringLiteral("Button_7"));
        Button_7->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button_7, 2, 0, 1, 1);

        Button_4 = new QPushButton(gridLayoutWidget);
        Button_4->setObjectName(QStringLiteral("Button_4"));
        Button_4->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button_4, 1, 0, 1, 1);

        Button_6 = new QPushButton(gridLayoutWidget);
        Button_6->setObjectName(QStringLiteral("Button_6"));
        Button_6->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button_6, 1, 2, 1, 1);

        Button_5 = new QPushButton(gridLayoutWidget);
        Button_5->setObjectName(QStringLiteral("Button_5"));
        Button_5->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button_5, 1, 1, 1, 1);

        Button_ok = new QPushButton(gridLayoutWidget);
        Button_ok->setObjectName(QStringLiteral("Button_ok"));
        Button_ok->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button_ok, 3, 0, 1, 1);

        Button_0 = new QPushButton(gridLayoutWidget);
        Button_0->setObjectName(QStringLiteral("Button_0"));
        Button_0->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button_0, 3, 1, 1, 1);

        Button_9 = new QPushButton(gridLayoutWidget);
        Button_9->setObjectName(QStringLiteral("Button_9"));
        Button_9->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button_9, 2, 2, 1, 1);

        Button_rm = new QPushButton(gridLayoutWidget);
        Button_rm->setObjectName(QStringLiteral("Button_rm"));
        Button_rm->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button_rm, 3, 2, 1, 1);

        Champ_mdp = new QLineEdit(frame);
        Champ_mdp->setObjectName(QStringLiteral("Champ_mdp"));
        Champ_mdp->setGeometry(QRect(510, 180, 201, 61));
        Champ_mdp->setStyleSheet(QLatin1String("font: 30pt \"Ubuntu\";\n"
"text-align: center;"));
        Champ_mdp->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(160, 110, 901, 61));
        label_6->setStyleSheet(QLatin1String("font: 30pt \"Ubuntu\";\n"
"text-align: center;"));
        Button_retour = new QPushButton(frame);
        Button_retour->setObjectName(QStringLiteral("Button_retour"));
        Button_retour->setGeometry(QRect(1030, 30, 181, 81));
        Button_retour->setStyleSheet(QStringLiteral("font: 30pt \"Ubuntu\";"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../build-tp_note-Desktop_Qt_5_8_0_GCC_64bit-Debug/ressources/retour.png"), QSize(), QIcon::Normal, QIcon::Off);
        Button_retour->setIcon(icon2);
        Button_retour->setIconSize(QSize(32, 32));
        Button_urgence3 = new QPushButton(frame);
        Button_urgence3->setObjectName(QStringLiteral("Button_urgence3"));
        Button_urgence3->setGeometry(QRect(540, 10, 131, 111));
        Button_urgence3->setIcon(icon);
        Button_urgence3->setIconSize(QSize(100, 100));
        stackedWidget->addWidget(page_connection);
        page_urgence = new QWidget();
        page_urgence->setObjectName(QStringLiteral("page_urgence"));
        verticalLayoutWidget = new QWidget(page_urgence);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 1211, 591));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QLatin1String("font: 40pt \"Ubuntu\";\n"
"color: rgb(239, 41, 41);"));

        verticalLayout->addWidget(label_7, 0, Qt::AlignHCenter|Qt::AlignTop);

        label_18 = new QLabel(verticalLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setPixmap(QPixmap(QString::fromUtf8("../build-tp_note-Desktop_Qt_5_8_0_GCC_64bit-Debug/ressources/danger.png")));

        verticalLayout->addWidget(label_18, 0, Qt::AlignHCenter);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QStringLiteral("font: 30pt \"Ubuntu\";"));

        verticalLayout->addWidget(label_8, 0, Qt::AlignHCenter|Qt::AlignTop);

        Button_auth3 = new QPushButton(verticalLayoutWidget);
        Button_auth3->setObjectName(QStringLiteral("Button_auth3"));
        Button_auth3->setMinimumSize(QSize(0, 40));
        Button_auth3->setIcon(icon1);

        verticalLayout->addWidget(Button_auth3, 0, Qt::AlignHCenter);

        stackedWidget->addWidget(page_urgence);
        page_admin = new QWidget();
        page_admin->setObjectName(QStringLiteral("page_admin"));
        Button_urgence4 = new QPushButton(page_admin);
        Button_urgence4->setObjectName(QStringLiteral("Button_urgence4"));
        Button_urgence4->setGeometry(QRect(550, 0, 131, 111));
        Button_urgence4->setIcon(icon);
        Button_urgence4->setIconSize(QSize(100, 100));
        label_9 = new QLabel(page_admin);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(60, 40, 371, 41));
        label_9->setStyleSheet(QStringLiteral("font: 30pt \"Ubuntu\";"));
        Button_quit = new QPushButton(page_admin);
        Button_quit->setObjectName(QStringLiteral("Button_quit"));
        Button_quit->setGeometry(QRect(1030, 30, 181, 51));
        Button_quit->setStyleSheet(QStringLiteral("font: 30pt \"Ubuntu\";"));
        gridLayoutWidget_2 = new QWidget(page_admin);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 120, 1211, 461));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(gridLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setPixmap(QPixmap(QString::fromUtf8("../build-tp_note-Desktop_Qt_5_8_0_GCC_64bit-Debug/ressources/Sch\303\251ma.gif")));
        label_10->setScaledContents(false);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_10, 0, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        widget_6 = new QWidget(gridLayoutWidget_2);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        radioButton_11 = new QRadioButton(widget_6);
        radioButton_11->setObjectName(QStringLiteral("radioButton_11"));
        radioButton_11->setGeometry(QRect(200, 30, 112, 23));
        radioButton_12 = new QRadioButton(widget_6);
        radioButton_12->setObjectName(QStringLiteral("radioButton_12"));
        radioButton_12->setGeometry(QRect(200, 70, 121, 23));
        label_21 = new QLabel(widget_6);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 40, 121, 31));
        label_22 = new QLabel(widget_6);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(10, 110, 121, 31));
        label_22->setStyleSheet(QLatin1String("color: rgb(239, 41, 41);\n"
"font: 14pt \"Ubuntu\";"));
        pushButton_14 = new QPushButton(widget_6);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(130, 110, 101, 31));

        gridLayout_4->addWidget(widget_6, 1, 0, 1, 1);

        widget_4 = new QWidget(gridLayoutWidget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        radioButton_9 = new QRadioButton(widget_4);
        radioButton_9->setObjectName(QStringLiteral("radioButton_9"));
        radioButton_9->setGeometry(QRect(200, 30, 112, 23));
        radioButton_10 = new QRadioButton(widget_4);
        radioButton_10->setObjectName(QStringLiteral("radioButton_10"));
        radioButton_10->setGeometry(QRect(200, 70, 121, 23));
        label_19 = new QLabel(widget_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 40, 121, 31));
        label_20 = new QLabel(widget_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(10, 110, 121, 31));
        label_20->setStyleSheet(QLatin1String("color: rgb(239, 41, 41);\n"
"font: 14pt \"Ubuntu\";"));
        pushButton_13 = new QPushButton(widget_4);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(130, 110, 101, 31));

        gridLayout_4->addWidget(widget_4, 0, 0, 1, 1);

        widget_5 = new QWidget(gridLayoutWidget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        radioButton_13 = new QRadioButton(widget_5);
        radioButton_13->setObjectName(QStringLiteral("radioButton_13"));
        radioButton_13->setGeometry(QRect(200, 30, 112, 23));
        radioButton_14 = new QRadioButton(widget_5);
        radioButton_14->setObjectName(QStringLiteral("radioButton_14"));
        radioButton_14->setGeometry(QRect(200, 70, 121, 23));
        label_23 = new QLabel(widget_5);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 40, 171, 31));

        gridLayout_4->addWidget(widget_5, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 0, 2, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        widget = new QWidget(gridLayoutWidget_2);
        widget->setObjectName(QStringLiteral("widget"));
        radioButton = new QRadioButton(widget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(200, 30, 112, 23));
        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(200, 70, 121, 23));
        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 40, 121, 31));
        label_12 = new QLabel(widget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 110, 121, 31));
        label_12->setStyleSheet(QLatin1String("color: rgb(239, 41, 41);\n"
"font: 14pt \"Ubuntu\";"));
        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(130, 110, 101, 31));

        gridLayout_3->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(gridLayoutWidget_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        radioButton_5 = new QRadioButton(widget_2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(200, 30, 112, 23));
        radioButton_6 = new QRadioButton(widget_2);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(200, 70, 121, 23));
        label_15 = new QLabel(widget_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 40, 121, 31));
        label_16 = new QLabel(widget_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 110, 121, 31));
        label_16->setStyleSheet(QLatin1String("color: rgb(239, 41, 41);\n"
"font: 14pt \"Ubuntu\";"));
        pushButton_11 = new QPushButton(widget_2);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(130, 110, 101, 31));

        gridLayout_3->addWidget(widget_2, 1, 0, 1, 1);

        widget_3 = new QWidget(gridLayoutWidget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        radioButton_7 = new QRadioButton(widget_3);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));
        radioButton_7->setGeometry(QRect(200, 30, 112, 23));
        radioButton_8 = new QRadioButton(widget_3);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));
        radioButton_8->setGeometry(QRect(200, 70, 121, 23));
        label_17 = new QLabel(widget_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 40, 171, 31));

        gridLayout_3->addWidget(widget_3, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 0, 0, 1, 1);

        stackedWidget->addWidget(page_admin);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1227, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Button_Amont_Aval_3->setText(QApplication::translate("MainWindow", "--> Amont vers Aval -->", Q_NULLPTR));
        Button_Aval_Amont_3->setText(QApplication::translate("MainWindow", "<-- Aval vers Amont <--", Q_NULLPTR));
        label_4->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Mode: Automatique", Q_NULLPTR));
        Button_urgence1->setText(QString());
        Button_auth1->setText(QApplication::translate("MainWindow", " Authentification", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Mode: Automatique", Q_NULLPTR));
        Button_urgence2->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Lorsque vous \303\252tes dans le sas:", Q_NULLPTR));
        Button_Amont_Aval_4->setText(QApplication::translate("MainWindow", "Fermer la porte", Q_NULLPTR));
        label_5->setText(QString());
        Button_auth2->setText(QApplication::translate("MainWindow", " Authentification", Q_NULLPTR));
        Button_1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        Button_2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        Button_3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        Button_8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        Button_7->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        Button_4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        Button_6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        Button_5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        Button_ok->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
        Button_0->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        Button_9->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        Button_rm->setText(QApplication::translate("MainWindow", "<--", Q_NULLPTR));
        Champ_mdp->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Saisissez votre mot de passe pour vous connecter:", Q_NULLPTR));
        Button_retour->setText(QApplication::translate("MainWindow", " Retour", Q_NULLPTR));
        Button_urgence3->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "Arr\303\252t d'urgence", Q_NULLPTR));
        label_18->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "Veuillez attendre un op\303\251rateur va venir", Q_NULLPTR));
        Button_auth3->setText(QApplication::translate("MainWindow", " Authentification", Q_NULLPTR));
        Button_urgence4->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Mode: Manuel", Q_NULLPTR));
        Button_quit->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        label_10->setText(QString());
        radioButton_11->setText(QApplication::translate("MainWindow", "Ouvert", Q_NULLPTR));
        radioButton_12->setText(QApplication::translate("MainWindow", "Ferm\303\251", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "Porte aval", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "Alarme: ON", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("MainWindow", "Eteindre", Q_NULLPTR));
        radioButton_9->setText(QApplication::translate("MainWindow", "Ouvert", Q_NULLPTR));
        radioButton_10->setText(QApplication::translate("MainWindow", "Ferm\303\251", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "Vanne aval", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Alarme: ON", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", "Eteindre", Q_NULLPTR));
        radioButton_13->setText(QApplication::translate("MainWindow", "Rouge", Q_NULLPTR));
        radioButton_14->setText(QApplication::translate("MainWindow", "Vert", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "Signal lumineux aval", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "Ouvert", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "Ferm\303\251", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Vanne amont", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Alarme: ON", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "Eteindre", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("MainWindow", "Ouvert", Q_NULLPTR));
        radioButton_6->setText(QApplication::translate("MainWindow", "Ferm\303\251", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Porte amont", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Alarme: ON", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("MainWindow", "Eteindre", Q_NULLPTR));
        radioButton_7->setText(QApplication::translate("MainWindow", "Rouge", Q_NULLPTR));
        radioButton_8->setText(QApplication::translate("MainWindow", "Vert", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Signal lumineux amont", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
