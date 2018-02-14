/***************************************************************
    mainform.cpp
***************************************************************/
#include <QtCore>
#include "mainform.h"
#include "imagemainwindow.h"
#include "txtmainwindow.h"
#include "movieplayer.h"
#include "daytime2.h"
#include "mediaplay.h"
#include <QGraphicsView>
#include <QListView>
Mainform::Mainform(QWidget *parent):QWidget(parent) 
{
    if (objectName().isEmpty())
        setObjectName(QString::fromUtf8("this"));
    label = new QLabel(this);   
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(0, 0, 640, 480));
    label->setPixmap(QPixmap(QString::fromUtf8(":/icon/background.jpg")));
    resize(689, 565);
    setStyleSheet(QString::fromUtf8("background-image:url:/icon/background.jpg;")); 
    setMaximumSize(QSize(1024, 768)); 
    setMouseTracking(false);
    setContextMenuPolicy(Qt::NoContextMenu);

   imagebrowserbtn = new QPushButton(this);
    imagebrowserbtn->setObjectName(QString::fromUtf8("imagebrowserbtn"));
    imagebrowserbtn->setGeometry(QRect(50, 119, 80, 80));
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/icon/imagebrowser_icon.png")), QIcon::Normal, QIcon::Off);
    icon.addPixmap(QPixmap(QString::fromUtf8(":/icon/imagebrowser_icon2.png")), QIcon::Active, QIcon::Off);
    imagebrowserbtn->setIcon(icon);
    imagebrowserbtn->setIconSize(QSize(80, 80));

    mp3playerbtn = new QPushButton(this);
    mp3playerbtn->setObjectName(QString::fromUtf8("mp3playerbtn"));
    mp3playerbtn->setGeometry(QRect(50, 280, 80, 80));
    QIcon icon1;
    icon1.addPixmap(QPixmap(QString::fromUtf8(":/icon/mp3_icon.png")), QIcon::Normal, QIcon::Off);
    icon1.addPixmap(QPixmap(QString::fromUtf8(":/icon/mp3_icon2.png")), QIcon::Active, QIcon::Off);
    mp3playerbtn->setIcon(icon1);
    mp3playerbtn->setIconSize(QSize(80, 80));
    
    aviplayerbtn = new QPushButton(this);
    aviplayerbtn->setObjectName(QString::fromUtf8("aviplayerbtn"));
    aviplayerbtn->setGeometry(QRect(280, 29, 80, 80));
    QIcon icon2;
    icon2.addPixmap(QPixmap(QString::fromUtf8(":/icon/avi_icon.png")), QIcon::Normal, QIcon::Off);
    icon2.addPixmap(QPixmap(QString::fromUtf8(":/icon/avi_icon2.png")), QIcon::Active, QIcon::Off);

    aviplayerbtn->setIcon(icon2);
    aviplayerbtn->setIconSize(QSize(80, 80));
    
    textbrowserbtn = new QPushButton(this);
    textbrowserbtn->setObjectName(QString::fromUtf8("textbrowserbtn"));
    textbrowserbtn->setGeometry(QRect(280, 370, 80, 80));
    QIcon icon3;
    icon3.addPixmap(QPixmap(QString::fromUtf8(":/icon/text_icon.png")), QIcon::Normal, QIcon::Off);
    icon3.addPixmap(QPixmap(QString::fromUtf8(":/icon/text_icon2.png")), QIcon::Active, QIcon::Off);
    textbrowserbtn->setIcon(icon3);
    textbrowserbtn->setIconSize(QSize(80, 80));
    
    daytimebtn = new QPushButton(this);
    daytimebtn->setObjectName(QString::fromUtf8("daytimebtn"));
    daytimebtn->setGeometry(QRect(500, 120, 80, 80));
    QIcon icon4;
    icon4.addPixmap(QPixmap(QString::fromUtf8(":/icon/daytime.png")), QIcon::Normal, QIcon::Off);
    icon4.addPixmap(QPixmap(QString::fromUtf8(":/icon/daytime2.png")), QIcon::Active, QIcon::Off);
    daytimebtn->setIcon(icon4);
    daytimebtn->setIconSize(QSize(80, 80));

    quitbtn = new QPushButton(this);
    quitbtn->setObjectName(QString::fromUtf8("quitbtn"));
    quitbtn->setGeometry(QRect(500, 280, 80, 80));
    QIcon icon5;
    icon5.addPixmap(QPixmap(QString::fromUtf8(":/icon/quit_icon.png")), QIcon::Normal, QIcon::Off);
    icon5.addPixmap(QPixmap(QString::fromUtf8(":/icon/quit_icon2.png")), QIcon::Active, QIcon::Off);
    quitbtn->setIcon(icon5);
    quitbtn->setIconSize(QSize(80, 80));



    QWidget::setTabOrder(imagebrowserbtn, aviplayerbtn);
    QWidget::setTabOrder(quitbtn, textbrowserbtn);
    QWidget::setTabOrder(aviplayerbtn, daytimebtn);
    QWidget::setTabOrder(textbrowserbtn,mp3playerbtn);
    QWidget::setTabOrder(daytimebtn,quitbtn);

    setWindowTitle(QApplication::translate("this", "zhbit", 0, QApplication::UnicodeUTF8));
    imagebrowserbtn->setText(QString());

    mp3playerbtn->setText(QString());
    aviplayerbtn->setText(QString());
    textbrowserbtn->setText(QString());
    daytimebtn->setText(QString());
    quitbtn->setText(QString());
//����ͼ������
 
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
    mf1->showFullScreen();
}

void Mainform::mp3player_clicked()
{PlayerWidget *mymedia=new PlayerWidget;
 mymedia->showFullScreen();}

void Mainform::aviplayer_clicked()
{
    MoviePlayer *mp=new MoviePlayer;
    mp->showFullScreen();//showMxaimized();
}

void Mainform::textbrowser_clicked()
{
     Txtmaiwindow *tx1=new Txtmaiwindow;
     tx1->showFullScreen();
}

void Mainform::daytime_clicked()
{
	DayTime *dt=new DayTime;
	dt->showFullScreen();
}

/*void Mainform::keyPressEvent(QKeyEvent *event)
{
 if(event->key()==Qt::Key_0)
{focusNextChild();}
}*/
void Mainform::keyPressEvent(QKeyEvent *event)
{      if(event->key() == Qt::Key_0)
      {
              QKeyEvent *event1 = new QKeyEvent(QKeyEvent::KeyPress,Qt::Key_Tab,Qt::NoModifier);
              QApplication::sendEvent(this,event1);
      }
      if(event->key() == Qt::Key_7)
      {
               MainWindow *mf1 = new MainWindow;	
               mf1->showFullScreen();
      }
      else if(event->key() == Qt::Key_8)
             { MoviePlayer *mp=new MoviePlayer;
    mp->showFullScreen();}
          else if(event->key() == Qt::Key_9)
             {DayTime *dt=new DayTime;
	dt->showFullScreen();}
          else if(event->key() == Qt::Key_4)
            {PlayerWidget *mymedia=new PlayerWidget;
 mymedia->showFullScreen();}
            else if(event->key() == Qt::Key_5)
              {Txtmaiwindow *tx1=new Txtmaiwindow;
     tx1->showFullScreen();}
               else if(event->key() == Qt::Key_6)
               {close();}
      else
                QWidget::keyPressEvent(event);
}

