#include <QtCore>
#include <QtDebug>
#include "imagewidget.h"
#include "imagemainwindow.h"

ImageWidget::ImageWidget(QWidget *parent): QWidget(parent)
{
	scale = 1;
	angle = 0;
	bFit = true;
	setAcceptDrops(true);
}

void ImageWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
        painter.setClipRect(event->rect());
        w=pixmap.width();
        h=pixmap.height();

        if(angle==90||(int)(angle-90)%360==0)
	{
		painter.rotate(angle);
		if(w>h)
			painter.scale((qreal)h/w,(qreal)h/w);
		else
			painter.scale((qreal)w/h,(qreal)w/h);
                painter.translate(0,-h);
        }

        if(angle==180||(int)(angle-180)%360==0)
	{
		painter.rotate(angle);
                painter.translate(-w,-h);
        }

        if(angle==270||(int)(angle-270)%360==0)
	{
		if(w>h)
			painter.scale((qreal)h/w,(qreal)h/w);
		else
			painter.scale((qreal)w/h,(qreal)w/h);
		painter.rotate(angle);
                painter.translate(-w,0);

        }

        if((int)angle%360==0)
        {
		painter.rotate(angle);
	}

	if(bFit)
	{
		if(zoomFit) 
        	{
			zoomFit=true;
			pixmap=pixmap.scaled(width(),height(), Qt::KeepAspectRatio);
 			painter.drawPixmap(0, 0, pixmap);
        	} 
		else
        	{
			if(width()<w) 
				pixmap=pixmap.scaled(width(),h, Qt::KeepAspectRatio);
			if(height()<h) 
				pixmap=pixmap.scaled(w,height(), Qt::KeepAspectRatio);
			if(width()<w && height()<h)
				pixmap=pixmap.scaled(width(),height(), Qt::KeepAspectRatio);
                painter.drawPixmap(0, 0, pixmap);
		}
	}
	else
        {       QPixmap fitPixmap1 = pixmap.scaled(width(),height(), Qt::IgnoreAspectRatio);
	  	painter.drawPixmap(0, 0, fitPixmap1);//full screen

        }
}

void ImageWidget::setPixmap(QString fileName)
{
	pixmap.load(fileName);
	update();
}


void ImageWidget::setAngle(qreal rotateAngle)
{
	angle += rotateAngle;
	update();
}

void ImageWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) {
		QString localFile;
		QRegExp rx("\\.(jpg|bmp|jpeg|png|xpm)$", Qt::CaseInsensitive);
		foreach(QUrl url , event->mimeData()->urls()) {
			localFile = url.toLocalFile();
			if(rx.indexIn(localFile) >= 0) {
				event->accept();
				return;
			}
			else {
			        event->ignore();
			}
		}
    } else {
        event->ignore();
    }
}

void ImageWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasUrls()) {
		QString localFile;
		QRegExp rx("\\.(jpg|bmp|jpeg|png|xpm)$", Qt::CaseInsensitive);
		foreach(QUrl url , event->mimeData()->urls()) {
			localFile = url.toLocalFile();
			if(rx.indexIn(localFile) >= 0) {
				event->accept();
				setPixmap(localFile);
				return;
			}
			else {
			        event->ignore();
			}
		}
    } else {
        event->ignore();
    }
}

void ImageWidget::dragLeaveEvent(QDragLeaveEvent *event)
{
 	event->accept();
}


