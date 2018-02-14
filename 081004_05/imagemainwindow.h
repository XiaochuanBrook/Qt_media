/*********************************************
      imagemainwindow.h
*********************************************/

#ifndef IMAGEMAINWINDOW_H
#define IMAGEMAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QDir>
#include <QClipboard>

#include "imagewidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
  void keyPressEvent(QKeyEvent *event);
public slots:
    void selectDir();
    void next();
    void prev();
    void rotateLeft();
    void rotateRight();
    void zoomIn();
    void zoomOut();
    void sdcardir();
    void udiskdir();
    void present();
    void bluetooth();
//    void wireless();

protected:
    void resizeEvent(QResizeEvent *);
  

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();

    QScrollArea *scrollArea;
    ImageWidget *imageWidget;
    QToolBar *toolbar;

    QAction *dirAct;
    QAction *nextAct;
    QAction *prevAct;
    QAction *leftAct;
    QAction *rightAct;
    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *sdcardirAct;
    QAction *udiskdirAct;
    QAction *bluetoothAct;
  //  QAction *wirelessAct;
    QAction *presentAct;
    QAction *closeAct;

    QStringList imageList;
    int index;
    QDir imageDir;
    QClipboard *clipboard;
    bool mouseDouble_num;
    bool umFit,sdFit,bluetoothFit,wirelessFit;
};

#endif
