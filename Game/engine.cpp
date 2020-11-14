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
    window_.addRatikka(&ratikka_);
    updatePositions();
    window_.installEventFilter(&moveKeysObject_);
    connect(&moveKeysObject_, &Movement::keyPressed,this, &Engine::updateKeys);
}

void Engine::updatePositions(){
    std::vector<std::shared_ptr<Interface::IActor> > nearby = cp_->getNearbyActors(window_.getCenter());
    window_.updateActors(nearby);
    updateRatikka();
}

void Engine::updateKeys(QSet<int> keys){
    keys_ = keys;
}

void Engine::updateRatikka(){
    bool a = keys_.contains(65);
    bool s = keys_.contains(83);
    bool w = keys_.contains(87);
    bool d = keys_.contains(68);
    int x = 0;
    int y = 0;
    if(a){
        x = -1;
    }else if(d){
        x = 1;
    }
    if(w){
        y = -1;
    }else if(s){
        y = 1;
    }
    auto cords = ratikka_.move(x,y);
    window_.scrollMap(cords.first, cords.second);
}

