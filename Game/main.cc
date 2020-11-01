#include <QApplication>
#include "graphics/simplemainwindow.hh"
#include "creategame.hh"
#include "city.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    CourseSide::SimpleMainWindow window;
    QImage bg = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    window.setPicture(bg);
    window.addActor(1,1);
    window.addActor(10,10);
    window.setSize(200,200);
    std::shared_ptr<Interface::ICity>  cp = Interface::createGame();
    window.show();
    return a.exec();
}


//todo: create own namespace for our own code
