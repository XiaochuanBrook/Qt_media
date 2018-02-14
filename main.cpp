#include <QApplication>
#include <QTextCodec>

#include "mainform.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(mainform);

    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    Mainform *mf = new Mainform;	
    mf->showFullScreen();
    //mf->showMaximized();
    return app.exec();
}
