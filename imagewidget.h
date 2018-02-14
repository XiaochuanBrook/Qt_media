#ifndef IMAGEWIDGET_H_
#define IMAGEWIDGET_H_

#include <QtGui>

class ImageWidget : public QWidget
{
    Q_OBJECT

public:
    bool bFit;
    bool zoomFit;
    bool rFit;
    qreal scale;
    QPixmap pixmap; 


public:
    ImageWidget(QWidget *parent = 0);
    void setPixmap(QString fileName);
    void setAngle(qreal rotateAngle);

protected:
    void paintEvent(QPaintEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
 
private:
    qreal angle;
    int w,h;
};

#endif /*IMAGEWIDGET_H_*/
