#include "core/city.hh"
#include <QTime>
#include <QDebug>

#define VIEW_DISTANCE  500

namespace Game {
City::City()
{
}

void City::setBackground(QImage& basicbackground, QImage& bigbackground){
    basicbackground_ = basicbackground;
    bigbackground_ = bigbackground;
};

void City::setClock(QTime clock) {
    (void)clock;
};

void City::addStop(std::shared_ptr<Interface::IStop> newstop) {
    stopList_.append(newstop); 
};

void City::startGame(){
    isGameStarted_ = true;

};

void City::addActor(std::shared_ptr<Interface::IActor> newactor) {

    if (dynamic_cast<CourseSide::Nysse*>(newactor.get()) != nullptr){
        stats_.newNysse();
    }else{
        stats_.morePassengers(1);
    }
    actorList_.append(newactor);
} ;

void City::removeActor(std::shared_ptr<Interface::IActor> actor) {
    if (!findActor(actor)){
        throw Interface::GameError("Actor not found in city");
        return;
    }
    if (dynamic_cast<CourseSide::Nysse*>(actor.get()) != nullptr){
        stats_.nysseLeft();
    }
    actorList_.removeAll(actor);
    actor->remove();
} ;

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor) {
    if (!findActor(actor)){
        throw Interface::GameError("Actor not found in city");
        return;
    }
    if (dynamic_cast<CourseSide::Nysse*>(actor.get()) != nullptr){
        stats_.nysseRemoved();
    }
    actor->remove();
} ;

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const  {
    int i = actorList_.indexOf(actor);
    return i != -1;
} ;

void City::actorMoved(std::shared_ptr<Interface::IActor> actor) {
    if (!findActor(actor)){
        throw Interface::GameError("Actor not found in city");
        return;
    }
    movedActors_.append(actor);
}

QList<std::shared_ptr<Interface::IActor> > City::movedActors()
{
    auto list = move(movedActors_);
    return list;
} ;

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const {
    std::vector<std::shared_ptr<Interface::IActor> > output;
    for(auto &i: actorList_){
        if(i->giveLocation().isClose(loc,VIEW_DISTANCE)){
            output.push_back(i);
        }
    }
    return output;
}

bool City::isGameStarted() const
{
    return isGameStarted_;
}

bool City::isGameOver() const {
    return isGameOver_;
}

void City::endGame()
{
    isGameOver_ = true;
}

Statistics *City::stats()
{
    return &stats_;
}

QList<std::shared_ptr<Interface::IStop> > City::stopList()
{
    return stopList_;
}

QImage City::basicbackground()
{
    return basicbackground_;
}

QImage City::bigbackground()
{
    return bigbackground_;
};
}

