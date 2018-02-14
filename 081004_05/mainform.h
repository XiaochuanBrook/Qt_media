/**************************************************
 mainform.h
**************************************************/

#ifndef MAINFORM_H
#define MAINFORM_H

#include <QtGui>

class Mainform:public QWidget
{
    Q_OBJECT
public:
    Mainform (QWidget *parent = 0);

    QLabel *label;
    QPushButton *imagebrowserbtn;
    QPushButton *mp3playerbtn;
    QPushButton *aviplayerbtn;
    QPushButton *textbrowserbtn;
    QPushButton *daytimebtn;
    QPushButton *quitbtn;
    QLabel *imagelb;
    QLabel *mp3lb;
    QLabel *avilb;
    QLabel *textlb;
    QLabel *timelb;
    QLabel *quitlb;
protected:
    void keyPressEvent(QKeyEvent *event);



public slots:
    void imagebrowser_clicked();
    void mp3player_clicked();
    void aviplayer_clicked();
    void textbrowser_clicked();
    void daytime_clicked();

};



#endif 
