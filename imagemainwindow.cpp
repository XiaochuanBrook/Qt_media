/***************************************************
      imagemainwindow.cpp
***************************************************/
#include <QtGui>
#include <sys/mount.h>
#include "imagemainwindow.h"
//imageList:当前浏览图片列表
//index：当前浏览图片序号
//imageDir：QDir类的实例，代表浏览目录
MainWindow::MainWindow()
{
    clipboard = QApplication::clipboard();
    imageWidget = new ImageWidget;
    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    imageWidget->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    scrollArea->setWidget(imageWidget);
    scrollArea->widget()->setMinimumSize(480, 475);	
    setCentralWidget(scrollArea);

    createActions();
    createToolBars();
    createStatusBar();
    setWindowTitle(tr("zhbit"));
    setFocusPolicy(Qt::StrongFocus);
    index = -1;
    umFit = true;//u盘启动许可标志
    sdFit = true;//sd卡启动许可标志
    bluetoothfit=true;//蓝牙启动许可标志
    imageDir.setPath("/mnt/yaffs/pic");
    QStringList filter;
    filter << "*.jpg" << "*.bmp" << "*.jpeg" << "*.png" <<"*.JPG"<<"*.JPEG"<<"*.PNG";
    imageList = imageDir.entryList ( filter, QDir::Files );
    next();
}

void MainWindow::resizeEvent(QResizeEvent *)//？
{
     QRect childRect = scrollArea->childrenRect();
     imageWidget->resize(childRect.size());
}

void MainWindow::createActions()
{
    dirAct = new QAction(QIcon(":/images/open.png"), tr("Open"), this);
    dirAct->setShortcut(Qt::Key_Asterisk);
    connect(dirAct, SIGNAL(triggered()), this, SLOT(selectDir() ));

    prevAct = new QAction(QIcon(":/images/previous.png"), tr("Previous"), this);
    prevAct->setShortcut(Qt::Key_4);
    connect(prevAct, SIGNAL(triggered()), this, SLOT(prev() ));

    nextAct = new QAction(QIcon(":/images/next.png"), tr("Next"), this);
    nextAct->setShortcut(Qt::Key_6);
    connect(nextAct, SIGNAL(triggered()), this, SLOT(next() ));

    leftAct = new QAction(QIcon(":/images/rotate_left.png"), tr("Left"), this);
    leftAct->setShortcut(Qt::Key_1);
    connect(leftAct, SIGNAL(triggered()), this, SLOT(rotateLeft() ));

    rightAct = new QAction(QIcon(":/images/rotate_right.png"), tr("Right"), this);
    rightAct->setShortcut(Qt::Key_3);
    connect(rightAct, SIGNAL(triggered()), this, SLOT(rotateRight() ));

    zoomInAct = new QAction(QIcon(":/images/zoomin.png"), tr("ZoomIn"), this);
    zoomInAct->setShortcut(Qt::Key_Plus);
    connect(zoomInAct, SIGNAL(triggered()), this, SLOT(zoomIn() ));

    zoomOutAct = new QAction(QIcon(":/images/zoomout.png"), tr("ZoomOut"), this);
    zoomOutAct->setShortcut(Qt::Key_Minus);
    connect(zoomOutAct, SIGNAL(triggered()), this, SLOT(zoomOut() ));

    sdcardirAct = new QAction(QIcon(":/images/actualsize.png"), tr("sdcardir"), this);
    sdcardirAct->setShortcut(Qt::Key_9);
    connect(sdcardirAct, SIGNAL(triggered()), this, SLOT(sdcardir() ));

    udiskdirAct = new QAction(QIcon(":/images/fitwindow.png"), tr("udiskdir"), this);
    udiskdirAct->setShortcut(Qt::Key_7);
    connect(udiskdirAct, SIGNAL(triggered()), this, SLOT(udiskdir() ));

    bluetoothAct= new QAction(QIcon(":/images/fitwindow.png"), tr("bluetoothdir"), this);
    bluetoothAct->setShortcut(Qt::Key_7);
    connect(udiskdirAct, SIGNAL(triggered()), this, SLOT(bluetooth() ));

    presentAct = new QAction(QIcon(":/images/present.png"), tr("Present"), this);
    presentAct->setShortcut(Qt::Key_5);
    connect(presentAct, SIGNAL(triggered()), this, SLOT(present() ));

    closeAct = new QAction(QIcon(":/images/close.png"), tr("close"), this);
    closeAct->setShortcut(Qt::Key_Delete);
    connect(closeAct, SIGNAL(triggered()), this, SLOT(close() ));
}

void MainWindow::createToolBars()
{
    toolbar = addToolBar(tr("opetation"));
    toolbar->addAction(dirAct);
    toolbar->addSeparator();
    toolbar->addAction(prevAct);
    toolbar->addAction(nextAct);
    toolbar->addSeparator();
    toolbar->addAction(leftAct);
    toolbar->addAction(rightAct);
    toolbar->addAction(zoomInAct);
    toolbar->addAction(zoomOutAct);
    toolbar->addAction(sdcardirAct);
    toolbar->addAction(udiskdirAct);
    toolbar->addAction(presentAct);
    toolbar->addSeparator();
    toolbar->addAction(closeAct);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::selectDir()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/mnt/yaffs/pic",QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty())
	return;
    imageDir.setPath(dir);
    QStringList filter;
    filter <<"*.jpg" << "*.bmp" << "*.jpeg" << "*.png"<<"*.JPG"<<"*.JPEG"<<"*.PNG";
    imageList = imageDir.entryList ( filter, QDir::Files );
    next();
}

void MainWindow::next()
{
    if(index==(imageList.size()-1)) 
         index=0;
    else 
         index++;

    if(index < imageList.size())
    {	
	imageWidget->setPixmap(imageDir.absolutePath() + QDir::separator() + imageList.at(index));
	statusBar()->showMessage(imageList.at(index));
    }
}

void MainWindow::prev()
{
    if(index==-1||index==0) 
        index=imageList.size()-1;
    else 
        index--;

    if(index >= 0)
    {
	imageWidget->setPixmap(imageDir.absolutePath() + QDir::separator() + imageList.at(index));
	statusBar()->showMessage(imageList.at(index));
    }
}

void MainWindow::rotateLeft()
{
    imageWidget->setAngle(-90);
}

void MainWindow::rotateRight()
{
    imageWidget->setAngle(90);

}

void MainWindow::zoomIn()
{
    imageWidget->scale *= 1.25;
    imageWidget->resize(imageWidget->scale * scrollArea->size());
    imageWidget->zoomFit=true;
}

void MainWindow::zoomOut()
{
    imageWidget->scale *= 0.8;
    imageWidget->resize(imageWidget->scale * scrollArea->size());
    imageWidget->zoomFit=true;
}

void MainWindow::sdcardir()//读取sd卡
{
    int sd_mount_status;
    if(sdFit)
    {
	if ((sd_mount_status = mount ("/dev/mmcblk0p1", "/mnt/sdcard", "vfat", MS_RDONLY, NULL))==0)
    	{
	    QMessageBox::about ( this, tr("SD disk"), tr("SD disk have mount!")) ;
	    sdFit=false;
	    index = 0;
    	    imageDir.setPath("/mnt/sdcard");
    	    QStringList filter1;
    	    filter1 <<"*.jpg" << "*.bmp" << "*.jpeg" << "*.png"<<"*.JPG"<<"*.JPEG"<<"*.PNG";
    	    imageList = imageDir.entryList ( filter1, QDir::Files );
    	    next();
	}
      	else
	    QMessageBox::about ( this, tr("SD disk"), tr("SD disk have not mount!")) ;
    }
    else if((sd_mount_status=umount("/mnt/sdcard"))==0)
    {
	sdFit=true;
        QMessageBox::about ( this, tr("SD disk"), tr("SD disk have umount!")) ;
    }
    else
	QMessageBox::about ( this, tr("SD disk"), tr("SD disk have not umount!")) ;
    

}

void MainWindow::bluetooth()//读取蓝牙
{
    int bluetooth_mount_status;
    if(bluetoothFit)
    {
	if ((bluetoothfit_status = mount ("//192.168.1.63/bluetooth", "/mnt/bluetooth", "smbfs", MS_RDONLY, NULL))==0)
    	{
	    QMessageBox::about ( this, tr("BlueTooth"), tr("BlueTooth have mount!")) ;
	    bluetoothfit=false;
	    index = 0;
    	    imageDir.setPath("/mnt/bluetooth");
    	    QStringList filter1;
    	    filter1 <<"*.jpg" << "*.bmp" << "*.jpeg" << "*.png"<<"*.JPG"<<"*.JPEG"<<"*.PNG";
    	    imageList = imageDir.entryList ( filter1, QDir::Files );
    	    next();
	}
      	else
	    QMessageBox::about ( this, tr("BlueTooth"), tr("BlueTooth have not mount!")) ;
    }
    else if((bluetooth_mount_status=umount("/mnt/blueTooth"))==0)
    {
	blueToothfit=true;
        QMessageBox::about ( this, tr("BlueTooth"), tr("SBlueTooth have umount!")) ;
    }
    else
	QMessageBox::about ( this, tr("SD disk"), tr("SD disk have not umount!")) ;
    

}

void MainWindow::udiskdir()
{
    int u_mount_status;
    if(umFit)
    {
        if ((u_mount_status = mount ("/dev/sda1", "/mnt/udisk", "vfat", MS_RDONLY, NULL))==0||(u_mount_status = mount ("/dev/sda", "/mnt/udisk", "vfat", MS_RDONLY, NULL))==0)
    	{
	     QMessageBox::about ( this, tr("U disk"), tr("U disk have mount!")) ;
	     umFit=false;
    	     index = 0;
    	     imageDir.setPath("/mnt/udisk");
    	     QStringList filter2;
    	     filter2 <<"*.jpg" << "*.bmp" << "*.jpeg" << "*.png" <<"*.JPG"<<"*.JPEG"<<"*.PNG";
	     imageList = imageDir.entryList ( filter2, QDir::Files );
    	     next();
    	}
    	else
	     QMessageBox::about ( this, tr("U disk"), tr("U disk have not mount!")) ;
	
     }
     else if((u_mount_status=umount("/mnt/udisk"))==0)
     {
	 umFit=true;
	 QMessageBox::about ( this, tr("U disk"), tr("U disk have umount!")) ;
     }
     else
 	 QMessageBox::about ( this, tr("U disk"), tr("U disk have not umount!")) ;
    
}

void MainWindow::present()
{
     statusBar()->hide();
     toolbar->hide();
     showFullScreen();
     mouseDouble_num=false;
     imageWidget->bFit = false;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    	if(event->key()==Qt::Key_5)
	{
 	   	if(mouseDouble_num)
  		{
    		 	statusBar()->hide();
     			toolbar->hide();
    			showFullScreen();
     			mouseDouble_num=false;
     			imageWidget->bFit = false;
   		}
   		else
   		{
     			statusBar()->show();
     			toolbar->show();
     			showMaximized();
     			mouseDouble_num=true;
     			imageWidget->bFit = true;
     			showMaximized();
   		}
	}
}
