#include <QApplication>
#include <QProcess>
#include <QVBoxLayout>
#include <QLayoutItem>
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QColor>
#include <QRect>
#include <QLinearGradient>
#include <QSizePolicy>
#include <QPushButton>
#include <QTextEdit>
#include <QSlider>
#include <QCloseEvent>
#include <QTimer>
#include <QtGui>

const QString mplayerPath("mplayer");

class PlayerWidget: public QWidget
{
	Q_OBJECT

public:
	PlayerWidget(QWidget *parent =0):QWidget(parent), isPlaying(false)

	{       

                currentMovieDirectory="/";
		
		
		renderTarget = new QWidget(this);
		renderTarget->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
		renderTarget->setAttribute(Qt::WA_PaintOnScreen);
		renderTarget->setMinimumSize(640, 480);
               renderTarget->setAutoFillBackground(true);
		
		timeLine = new QSlider(Qt::Horizontal);
                openfile = new QPushButton("Open");
                openfile->setGeometry(QRect(50, 280, 32, 32));
                controller = new QPushButton("Play");
                controller->setGeometry(QRect(500, 280, 32, 32));
		log = new QTextEdit;
		log->setReadOnly(true);
                log->append("[welcome to use ZHBIT Mediaplay ]2008 by DreamFly");

		QVBoxLayout *layout = new QVBoxLayout;
                 layout->addWidget(log);
        
		layout->addWidget(renderTarget);
		//layout->addWidget(timeLine);
                 layout->addWidget(openfile);
		//layout->addWidget(controller);
		setLayout(layout);
                 //renderTarget->setAutoFillBackground(true);

		mplayerProcess = new QProcess(this);

		poller = new QTimer(this);
                QObject::connect(openfile, SIGNAL(clicked()), this, SLOT(open()));
                QObject::connect(controller, SIGNAL(clicked()), this, SLOT(switchPlayState()));
                connect(openfile,SIGNAL(clicked()),this,SLOT(open()));
		connect(controller, SIGNAL(clicked()), this, SLOT(switchPlayState()));
		connect(mplayerProcess, SIGNAL(readyReadStandardOutput()),
			this, SLOT(catchOutput()));
		connect(mplayerProcess, SIGNAL(finished(int, QProcess::ExitStatus)),
			this, SLOT(mplayerEnded(int, QProcess::ExitStatus)));
		connect(poller, SIGNAL(timeout()), this, SLOT(pollCurrentTime()));
		connect(timeLine, SIGNAL(sliderMoved(int)), this, SLOT(timeLineChanged(int)));
	}

protected:
	virtual void closeEvent(QCloseEvent *e)
	{
		stopMPlayer();
		e->accept();
	}


void keyPressEvent(QKeyEvent *event)
{if(event->key()==Qt::Key_Period)
    this->close();
 if (event->key() == Qt::Key_0)
      {QKeyEvent *event1 = new QKeyEvent(QKeyEvent::KeyPress,Qt::Key_Tab,Qt::NoModifier);
              QApplication::sendEvent(this,event1);
      }
      if(event->key() == Qt::Key_1)
      {open();}
 if(event->key() == Qt::Key_3)
{showMinimized();}
    if(event->key() == Qt::Key_2)
      {switchPlayState();}
}
private:
 

	bool startMPlayer()
	{
		if(isPlaying)
			return true;

		QStringList args;
		
		// set the command model
		args << "-slave";
		// less information
		args << "-quiet";
	
		
		//args << "-wid" << QString::number(renderTarget->winId());

		

		args<<"-fs";
               log->append("start movie");
                args<<movieFile;
		mplayerProcess->setProcessChannelMode(QProcess::MergedChannels);
		mplayerProcess->start(mplayerPath, args);
                
		if(!mplayerProcess->waitForStarted(3000))
		{
			qDebug("error");
			return false;
		}

		mplayerProcess->write("get_video_resolution\n");
		mplayerProcess->write("get_time_length\n");
//log->append(movieFile);
		poller->start(1000);

		isPlaying = true;

		return true;
	}

	bool stopMPlayer()
	{
		if(!isPlaying)
			return true;

		mplayerProcess->write("quit\n");
		if(!mplayerProcess->waitForFinished(3000))
		{
			qDebug("error");
			return false;
		}

		return true;
	}

private slots:
   

  
void open()
{    
    movieFile = QFileDialog::getOpenFileName(this);
    if (!movieFile.isEmpty())
       switchPlayState();
    log->append(movieFile);
}
void catchOutput()
{               log->append("begin to output");
		while(mplayerProcess->canReadLine())
		{
			QByteArray buffer(mplayerProcess->readLine());
			log->append(QString(buffer));
			
			if(buffer.startsWith("ANS_VIDEO_RESOLUTION"))
			{
				buffer.remove(0, 21); // vire ANS_VIDEO_RESOLUTION=
				buffer.replace(QByteArray("'"), QByteArray(""));
				buffer.replace(QByteArray(" "), QByteArray(""));
				buffer.replace(QByteArray("\n"), QByteArray(""));
				buffer.replace(QByteArray("\r"), QByteArray(""));
				int sepIndex = buffer.indexOf('x');
				int resX = buffer.left(sepIndex).toInt();
				int resY = buffer.mid(sepIndex+1).toInt();
				renderTarget->setMinimumSize(resX, resY);
			}
			// r閜onse ?get_time_length : ANS_LENGTH=xx.yy
			else if(buffer.startsWith("ANS_LENGTH"))
			{
				buffer.remove(0, 11); // vire ANS_LENGTH=
				buffer.replace(QByteArray("'"), QByteArray(""));
				buffer.replace(QByteArray(" "), QByteArray(""));
				buffer.replace(QByteArray("\n"), QByteArray(""));
				buffer.replace(QByteArray("\r"), QByteArray(""));
				float maxTime = buffer.toFloat();
				timeLine->setMaximum(static_cast<int>(maxTime+1));
			}
			// get_time_pos : ANS_TIME_POSITION=xx.y
			else if(buffer.startsWith("ANS_TIME_POSITION"))
			{
				buffer.remove(0, 18); // vire ANS_TIME_POSITION=
				buffer.replace(QByteArray("'"), QByteArray(""));
				buffer.replace(QByteArray(" "), QByteArray(""));
				buffer.replace(QByteArray("\n"), QByteArray(""));
				buffer.replace(QByteArray("\r"), QByteArray(""));
				float currTime = buffer.toFloat();
				timeLine->setValue(static_cast<int>(currTime+1));
			}
		}
	}

	void pollCurrentTime()
	{
		mplayerProcess->write("get_time_pos\n");
	}

	// Dirige la timeline
	void timeLineChanged(int pos)
	{
		mplayerProcess->write(QString("seek " + QString::number(pos) + " 2\n").toUtf8());
	}

	// Play/stop
	void switchPlayState()
	{
		if(!isPlaying)
		{
			if(!startMPlayer())
				return;

			//log->clear();
			controller->setText("Stop");
			isPlaying = true;
		}
		else
		{
			if(!stopMPlayer())
				{log->append("stopped");
                            return;}

			poller->stop();
			//log->clear();
			controller->setText("Play");
			isPlaying = false;
                       log->append("stop the media");
		}
	}

	void mplayerEnded(int exitCode, QProcess::ExitStatus exitStatus)
	{
		isPlaying = false;
		controller->setText("Play");
		poller->stop();
	}

private:
	QWidget *renderTarget;
	QProcess *mplayerProcess;
	bool isPlaying;
        QPushButton *openfile;
        QPushButton *controller;

	QSlider *timeLine;
	QTimer *poller;
	QTextEdit *log;
        QString movieFile;
QString  currentMovieDirectory;

};


