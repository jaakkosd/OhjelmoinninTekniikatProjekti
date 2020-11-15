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
    window_.installEvents(&moveKeysObject_);
    connect(&moveKeysObject_, &Movement::keyPressed,this, &Engine::updateKeys);
}

void Engine::updatePositions(){
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    window_.setClock(text);
    updateRatikka();
    std::vector<std::shared_ptr<Interface::IActor> > nearby = cp_->getNearbyActors(window_.getCenter());
    QMap<std::shared_ptr<Interface::IActor>,ImgActorItem*> newActors;
    for(auto &i : nearby){
        courseConverter::cords input {i.get()->giveLocation().giveX(),
                              i.get()->giveLocation().giveY()} ;
        auto output = courseConverter::mapToUi(input);
        auto iterator  = actors_.find(i);
        if (iterator != actors_.end() && iterator.key() == i) {
            ImgActorItem* oldActorItem = actors_.take(i);
            oldActorItem->moveTo(output.x,output.y);
            if (dynamic_cast<CourseSide::Passenger*>(i.get()) != nullptr){
                CourseSide::Passenger * pas = dynamic_cast<CourseSide::Passenger*>(i.get());
                oldActorItem->setVisible(!pas->isInVehicle());
            }
            newActors[std::move(i)] = oldActorItem;
        }else{
            if (dynamic_cast<CourseSide::Nysse*>(i.get()) != nullptr)
              {
                BusUiItem* nActor =  new BusUiItem(output.x, output.y);
                window_.addActor(nActor);
                newActors[std::move(i)] =  nActor;
              }
            else if (dynamic_cast<CourseSide::Passenger*>(i.get()) != nullptr){
                PassangerUiItem* nActor =  new PassangerUiItem(output.x, output.y);
                int x = randgen.bounded(-3,4);
                int y = randgen.bounded(-3,4);
                nActor->setOffset(x,y);
                window_.addActor(nActor);
                newActors[std::move(i)] =  nActor;
            }
        }
    }
    for(auto j: actors_){
        j->hide();
        delete j;
    }
    actors_.clear();
    actors_ = std::move(newActors);

    // iterate trough nearby actors and remove all colliding with the RATIKKA
    for(auto i:actors_.keys()){
        if(actors_[i]->collidesWithItem(&ratikka_)){
            //value is ImgActorItem*
            actors_[i]->hide();
            delete actors_[i];
            // key is Interface::IActor
            cp_->removeActor(i);
            actors_.remove(i);
            //TODO: add points for hitting busses and maybe passengers mayne test is subject is a nysse or passenger
        }
    }
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

