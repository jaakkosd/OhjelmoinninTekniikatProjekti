#include <QApplication>
#include "engine.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    Engine engine;
    engine.init();
    return a.exec();
}


//todo: create own namespace for our own code
