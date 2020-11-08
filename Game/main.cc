#include <QApplication>
#include "engine.h"
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    qDebug() << QDir::currentPath();
    Engine engine;
    engine.init();
    return a.exec();
}


//todo: create own namespace for our own code
