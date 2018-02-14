#include <QtGui>

#include "analogclock.h"

AnalogClock::AnalogClock(QWidget *parent)
    : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

    setWindowTitle(tr("Analog Clock"));
    resize(200, 200);
}

void AnalogClock::paintEvent(QPaintEvent *)
{
    static const QPoint hourHand[3] = {
        QPoint(2, 2),                     //7 8
        QPoint(-2, 2),                    //-7 8
        QPoint(0, -40)                    //0 -40
    };
    static const QPoint minuteHand[3] = {
        QPoint(2, 2),                     //7 8
        QPoint(-2, 2),                    //-7 8
        QPoint(0, -70)                    //0 -70
    };

    QColor hourColor(0, 0, 0);
    QColor minuteColor(3, 105, 69, 255);
    QColor hourColor2(255, 255, 255);
    QColor minuteColor2(3, 105, 69, 255);
    
    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor2);

    painter.save();
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();

    painter.setPen(hourColor);

   // for (int i = 0; i < 12; ++i) {
       // painter.drawLine(88, 0, 96, 0);
       // painter.rotate(30.0);
    //}

    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor2);

    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    painter.setPen(minuteColor);

  //  for (int j = 0; j < 60; ++j) {
   //     if ((j % 5) != 0)
   //         painter.drawLine(92, 0, 96, 0);
  //      painter.rotate(6.0);
  //  }
}
