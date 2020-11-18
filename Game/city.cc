#include "city.hh"
#include <QTime>
#include <QDebug>

#define VIEW_DISTANCE  500

namespace Game {
City::City()
{
}

void City::setBackground(QImage& basicbackground, QImage& bigbackground){};
void City::setClock(QTime clock) {

    //todo: todo this if we want to know the time
};
void City::addStop(std::shared_ptr<Interface::IStop> newstop) {
    stopList.append(newstop); 
};
void City::startGame(){

};
void City::addActor(std::shared_ptr<Interface::IActor> newactor) {
    actorList.append(newactor);
} ;
void City::removeActor(std::shared_ptr<Interface::IActor> actor) {
    actorList.removeAll(actor);
    actor->remove();
} ;
void City::actorRemoved(std::shared_ptr<Interface::IActor> actor) {} ;
bool City::findActor(std::shared_ptr<Interface::IActor> actor) const  {
    int i = actorList.indexOf(actor);
    return i != -1;
} ;
void City::actorMoved(std::shared_ptr<Interface::IActor> actor) {
    //todo: todo this if we want to know if actor is moved
} ;

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const {
    std::vector<std::shared_ptr<Interface::IActor> > output;
    for(auto i: actorList){
        if(i->giveLocation().isClose(loc,VIEW_DISTANCE)){
            output.push_back(i);
        }
    }
    return output;
}

bool City::isGameOver() const {
    return gameEnded_;
}

void City::endGame()
{
    gameEnded_ = true;
};
}
