#include "core/engine.h"
#include <QMessageBox>
namespace Game {
Engine::Engine(QObject *parent) : QObject(parent)
{

}

void Engine::init(){

    connect(&setupDialog_, &SetupDialog::settings,
            this, &Engine::getSettings);
    setupDialog_.exec();

    gamelogic_.setTime(9,0);
    gamelogic_.fileConfig();
    cp_ = Interface::createGame();
    gamelogic_.takeCity(cp_);    //ensin töytyy antaa city
    gamelogic_.finalizeGameStart();

    QImage bg = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
    window_.setPicture(bg);
    window_.show();
    window_.setStops(cp_);
    connect(&timer_, &QTimer::timeout, this, &Engine::updatePositions);
    window_.addRatikka(&ratikka_);
    ratikka_.setCoords(startCords_.x,startCords_.y);
    window_.installEvents(&moveKeysObject_);
    connect(&moveKeysObject_, &Movement::keyPressed,this, &Engine::updateKeys);
    endTime = QDateTime::currentDateTime().addSecs(60);
    timer_.start(1000/UPDATES_PER_SECOND);
}

void Engine::updatePositions(){
    auto between = QDateTime::currentDateTime().secsTo(endTime);
    QString text = QString("%1:%2").arg(between/60).arg(between%60);
    window_.setClock(text);
    if(between<=0){
        EndGame(timeUp);
        return;
    }
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
            if (dynamic_cast<CourseSide::Passenger*>(i.get()) != nullptr){
                //value is ImgActorItem*
                actors_[i]->hide();
                delete actors_[i];
                // key is Interface::IActor
                cp_->removeActor(i);
                actors_.remove(i);
                stats_.addPoints();
                window_.setScore(stats_.getPoints());
            }else {
                EndGame(hitNysse);
                return;

            }
        }
    }
}

void Engine::updateKeys(QSet<int> keys){
    keys_ = keys;
}

void Engine::getSettings(int difficulity, int startPoint)
{
    speed_ = (difficulity + 1) * 2;

    if ( startLocations_.size() < startPoint || startPoint < 0){
       startPoint = 0;}
    auto loc = startLocations_[startPoint];
    startCords_ = courseConverter::mapToUi(courseConverter::cords{loc.giveX(),loc.giveY()});

}

void Engine::updateRatikka(){
    auto oldCords = ratikka_.getCoords();
    bool limitUp = oldCords.y <=0;
    bool limitLeft = oldCords.x <=0;;
    bool limitRight = oldCords.x >= courseConverter::map_width;
    bool limitDown = oldCords.y >= courseConverter::map_height;
    bool a = keys_.contains(65) && !limitLeft;
    bool s = keys_.contains(83) && !limitDown;
    bool w = keys_.contains(87) && !limitUp;
    bool d = keys_.contains(68) && !limitRight;
    int x = 0;
    int y = 0;
    if(a){
        x = -speed_;
    }else if(d){
        x = speed_;
    }
    if(w){
        y = -speed_;
    }else if(s){
        y = speed_;
    }
    auto cords = ratikka_.move(x*2,y*2);
    window_.scrollMap(cords.first, cords.second);
}

void Engine::EndGame(endingCases endingCase)
{
    qDebug("GAME END");
    disconnect(&timer_, &QTimer::timeout, this, &Engine::updatePositions);

    /*if(!running){
        return;
    }
    running = false;*/
    timer_.stop();
    dynamic_cast<City*>(cp_.get())->endGame();
    switch (endingCase) {
        case hitNysse:{
            QMessageBox msgBox;
            msgBox.setText("Nysse ajoi päällesi :( \n\nPeli ohi!");
            msgBox.exec();
        }break;
        default:
            break;
    }
    emit gameEnded();
}
}
