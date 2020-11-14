#include "engine.h"
template<typename Base, typename T>
inline bool instanceof(const T*) {
    return std::is_base_of<Base, T>::value;
}

Engine::Engine(QObject *parent) : QObject(parent)
{

}

void Engine::init(){
    gamelogic_.setTime(9,0);
    gamelogic_.fileConfig();
    cp_ = Interface::createGame();
    gamelogic_.takeCity(cp_);    //ensin töytyy antaa city
    gamelogic_.finalizeGameStart();


    QImage bg = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
    window_.setPicture(bg);

    window_.show();
    window_.setStops(cp_);
    timer_ = new QTimer();
    connect(timer_, &QTimer::timeout, this, &Engine::updatePositions);
    timer_->start(1000/UPDATES_PER_SECOND);
    updatePositions();
}

void Engine::updatePositions(){
    std::vector<std::shared_ptr<Interface::IActor> > nearby = cp_->getNearbyActors(window_.getCenter());
    window_.updateActors(nearby);
}


