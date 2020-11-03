#include <QApplication>
#include "mainwindow.h"
#include "creategame.hh"
#include "core/logic.hh"
#include "city.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    CourseSide::Logic gamelogic;
    gamelogic.fileConfig();
    std::shared_ptr<Interface::ICity>  cp = Interface::createGame();
    gamelogic.takeCity(cp);//ensin töytyy antaa city
    gamelogic.finalizeGameStart();

    MainWindow window;
    QImage bg = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    window.setPicture(bg);
    auto loc = Interface::Location();
    loc.setXY(250,250);
    auto nearby = cp->getNearbyActors(loc);
    for(auto i : nearby){
        int x = i->giveLocation().giveX();
        int y = i->giveLocation().giveY();
        window.addActor(x,y,0);
    }
    window.show();
    return a.exec();
}


//todo: create own namespace for our own code
