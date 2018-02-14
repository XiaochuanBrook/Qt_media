#include <QtGui>
#include "daytime2.h"

DayTime::DayTime(QWidget* parent)
:QWidget(parent)
{
	ui.setupUi(this);
//QObject::connect(QuitButton,SIGNAL(clicked()), this, SLOT(close()));

}
void DayTime::keyPressEvent(QKeyEvent *event)
{if(event->key()==Qt::Key_NumLock)
      {this->close();} }

