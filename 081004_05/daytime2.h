#ifndef _DAYTIME_H
#define _DAYTIME_H

#include "ui_daytime4.h"

class DayTime : public QWidget
{
	Q_OBJECT

public:
	DayTime(QWidget* = 0);
void keyPressEvent(QKeyEvent *event);
//public slots:
   // void QuitButton();

private:
	Ui_Form ui;
};

#endif
