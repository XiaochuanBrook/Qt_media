/***************************************************************
    mainform.cpp
****************************************************************
#include <QtCore>
#include "mainform.h"
#include "imagemainwindow.h"
#include "txtmainwindow.h"
#include "movieplayer.h"
Mainform::Mainform(QWidget *parent):QWidget(parent) 
{
    if (objectName().isEmpty())
        setObjectName(QString::fromUtf8("this"));
    resize(689, 565);
    setMaximumSize(QSize(1024, 768));

    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    font.setWeight(75);
    setFont(font);
    setMouseTracking(false);
    setContextMenuPolicy(Qt::NoContextMenu);
    imagebrowserbtn = new QPushButton(this);
    imagebrowserbtn->setObjectName(QString::fromUtf8("imagebrowserbtn"));
    imagebrowserbtn->setGeometry(QRect(110, 200, 60, 60));
    imagebrowserbtn->setMaximumSize(QSize(60, 60));

    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/icon/imagebrowser_icon.png")), QIcon::Normal, QIcon::Off);
    imagebrowserbtn->setIcon(icon);
    imagebrowserbtn->setIconSize(QSize(60, 60));
    zhbitlb = new QLabel(this);
    zhbitlb->setObjectName(QString::fromUtf8("zhbitlb"));
    zhbitlb->setGeometry(QRect(120, 30, 401, 111));
    zhbitlb->setPixmap(QPixmap(QString::fromUtf8(":/icon/zhbit.jpeg")));
    mp3playerbtn = new QPushButton(this);
    mp3playerbtn->setObjectName(QString::fromUtf8("mp3playerbtn"));
    mp3playerbtn->setGeometry(QRect(290, 200, 60, 60));
    mp3playerbtn->setMaximumSize(QSize(60, 60));

    QIcon icon1;
    icon1.addPixmap(QPixmap(QString::fromUtf8(":/icon/mp3_icon.png")), QIcon::Normal, QIcon::Off);
    mp3playerbtn->setIcon(icon1);
    mp3playerbtn->setIconSize(QSize(60, 60));
    aviplayerbtn = new QPushButton(this);
    aviplayerbtn->setObjectName(QString::fromUtf8("aviplayerbtn"));
    aviplayerbtn->setGeometry(QRect(460, 200, 60, 60));
    aviplayerbtn->setMaximumSize(QSize(60, 60));
    aviplayerbtn->setContextMenuPolicy(Qt::ActionsContextMenu);

    QIcon icon2;
    icon2.addPixmap(QPixmap(QString::fromUtf8(":/icon/avi_icon.png")), QIcon::Normal, QIcon::Off);
    aviplayerbtn->setIcon(icon2);
    aviplayerbtn->setIconSize(QSize(60, 60));
    textbrowserbtn = new QPushButton(this);
    textbrowserbtn->setObjectName(QString::fromUtf8("textbrowserbtn"));
    textbrowserbtn->setGeometry(QRect(110, 330, 60, 60));
    textbrowserbtn->setMaximumSize(QSize(60, 60));

    QIcon icon3;
    icon3.addPixmap(QPixmap(QString::fromUtf8(":/icon/text_icon.png")), QIcon::Normal, QIcon::Off);
    textbrowserbtn->setIcon(icon3);
    textbrowserbtn->setIconSize(QSize(60, 60));
    daytimebtn = new QPushButton(this);
    daytimebtn->setObjectName(QString::fromUtf8("daytimebtn"));
    daytimebtn->setGeometry(QRect(290, 330, 60, 60));
    daytimebtn->setMaximumSize(QSize(60, 60));

    QIcon icon4;
    icon4.addPixmap(QPixmap(QString::fromUtf8(":/icon/daytime.png")), QIcon::Normal, QIcon::Off);
    daytimebtn->setIcon(icon4);
    daytimebtn->setIconSize(QSize(60, 60));
    quitbtn = new QPushButton(this);
    quitbtn->setObjectName(QString::fromUtf8("quitbtn"));
    quitbtn->setGeometry(QRect(460, 330, 60, 60));
    quitbtn->setMaximumSize(QSize(60, 60));

    QIcon icon5;
    icon5.addPixmap(QPixmap(QString::fromUtf8(":/icon/quit_icon.png")), QIcon::Normal, QIcon::Off);
    quitbtn->setIcon(icon5);
    quitbtn->setIconSize(QSize(60, 60));
    imagelb = new QLabel(this);
    imagelb->setObjectName(QString::fromUtf8("imagelb"));
    imagelb->setGeometry(QRect(100, 270, 101, 16));

    QFont font1;
    font1.setFamily(QString::fromUtf8("Console"));
    font1.setPointSize(12);
    font1.setBold(true);
    font1.setItalic(false);
    font1.setUnderline(false);
    font1.setWeight(75);
    font1.setStrikeOut(false);
    font1.setKerning(true);
    font1.setStyleStrategy(QFont::PreferDefault);
    imagelb->setFont(font1);
    mp3lb = new QLabel(this);
    mp3lb->setObjectName(QString::fromUtf8("mp3lb"));
    mp3lb->setGeometry(QRect(290, 270, 71, 18));

    QFont font2;
    font2.setFamily(QString::fromUtf8("Console"));
    mp3lb->setFont(font2);
    mp3lb->setTextFormat(Qt::AutoText);

    avilb = new QLabel(this);
    avilb->setObjectName(QString::fromUtf8("avilb"));
    avilb->setGeometry(QRect(460, 270, 71, 18));
    avilb->setFont(font2);

    textlb = new QLabel(this);
    textlb->setObjectName(QString::fromUtf8("textlb"));
    textlb->setGeometry(QRect(100, 400, 91, 18));
    textlb->setFont(font2);

    timelb = new QLabel(this);
    timelb->setObjectName(QString::fromUtf8("timelb"));
    timelb->setGeometry(QRect(290, 400, 56, 18));
    timelb->setFont(font2);

    quitlb = new QLabel(this);
    quitlb->setObjectName(QString::fromUtf8("quitlb"));
    quitlb->setGeometry(QRect(480, 400, 56, 18));
    quitlb->setFont(font2);
    QWidget::setTabOrder(imagebrowserbtn, mp3playerbtn);
    QWidget::setTabOrder(mp3playerbtn, aviplayerbtn);
    QWidget::setTabOrder(aviplayerbtn, textbrowserbtn);
    QWidget::setTabOrder(textbrowserbtn, daytimebtn);
    QWidget::setTabOrder(daytimebtn, quitbtn);

    setWindowTitle(QApplication::translate("this", "zhbit", 0, QApplication::UnicodeUTF8));
    imagebrowserbtn->setText(QString());
    zhbitlb->setText(QString());
    mp3playerbtn->setText(QString());
    aviplayerbtn->setText(QString());
    textbrowserbtn->setText(QString());
    daytimebtn->setText(QString());
    quitbtn->setText(QString());
    imagelb->setText(QApplication::translate("this", "imagebrowser", 0, QApplication::UnicodeUTF8));
    mp3lb->setText(QApplication::translate("this", "mp3player", 0, QApplication::UnicodeUTF8));
    avilb->setText(QApplication::translate("this", "aviplayer", 0, QApplication::UnicodeUTF8));
    textlb->setText(QApplication::translate("this", "textbrowser", 0, QApplication::UnicodeUTF8));
    timelb->setText(QApplication::translate("this", "daytime", 0, QApplication::UnicodeUTF8));
    quitlb->setText(QApplication::translate("this", "quit", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(this);

    QObject::connect(imagebrowserbtn, SIGNAL(clicked()), this, SLOT(imagebrowser_clicked()));
    QObject::connect(mp3playerbtn, SIGNAL(clicked()), this, SLOT(mp3player_clicked()));
    QObject::connect(aviplayerbtn, SIGNAL(clicked()), this, SLOT(aviplayer_clicked()));
    QObject::connect(textbrowserbtn, SIGNAL(clicked()), this, SLOT(textbrowser_clicked()));
    QObject::connect(daytimebtn, SIGNAL(clicked()), this, SLOT(daytime_clicked()));
    QObject::connect(quitbtn, SIGNAL(clicked()), this, SLOT(close()));

    QMetaObject::connectSlotsByName(this);
} //MainMainform

void Mainform::imagebrowser_clicked()
{
    MainWindow *mf1 = new MainWindow;	
    //mainWin.showFullScreen();
    mf1->showMaximized();
}

void Mainform::mp3player_clicked()
{}

void Mainform::aviplayer_clicked()
{
    MoviePlayer *mp=new MoviePlayer;
    mp->showFullScreen();//showMxaimized();
}

void Mainform::textbrowser_clicked()
{
     Txtmaiwindow *tx1=new Txtmaiwindow;
     tx1->showMaximized();
}

void Mainform::daytime_clicked()
{}


