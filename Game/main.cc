#include <QApplication>
#include "core/engine.h"
#include <QDir>

void startGame();
Game::Engine * engine;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    startGame();
    return a.exec();
    delete engine;
}

void startGame(){
    engine->deleteLater();
    engine = new Game::Engine;
    engine->init();
    QObject::connect(engine, &Game::Engine::gameEnded,&startGame);
}


//todo: create own namespace for our own code
