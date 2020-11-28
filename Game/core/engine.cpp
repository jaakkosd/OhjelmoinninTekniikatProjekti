#include "core/engine.h"
#include <QMessageBox>
namespace Game {
Engine::Engine(QObject *parent) : QObject(parent)
{
}

void Engine::init(){
    connect(&setupDialog_, &SetupDialog::settings,
            this, &Engine::getSettings);
    if(!setupDialog_.exec()){
        window_.close();
        return;
    }

    gamelogic_.setTime(STARTHOUR,0);
    gamelogic_.fileConfig();
    std::shared_ptr<Interface::ICity> cp = Interface::createGame();
    gamelogic_.takeCity(cp);

    cp_ = std::dynamic_pointer_cast<Game::City> (cp);
    gamelogic_.finalizeGameStart();

    QImage bg = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
    window_.setPicture(bg);
    window_.show();
    window_.setStops(cp);
    window_.setHiScore(cp_->stats()->hiScore());
    window_.addActor(&ratikka_);
    window_.scrollMap(startCords_.x, startCords_.y);
    ratikka_.moveTo(startCords_.x,startCords_.y);
    window_.installEvents(&moveKeysObject_);
    connect(&timer_, &QTimer::timeout, this, &Engine::updatePositions);
    connect(&moveKeysObject_, &Movement::keyPressed,this, &Engine::updateKeys);
    endTime = QDateTime::currentDateTime().addSecs(GAMETIME);
    timer_.start(1000/FPS);
}

void Engine::updatePositions(){
	updateSquirrels();
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
    auto moved =  cp_->movedActors();
    for(auto &i : nearby){
        CourseConverter::cords input {i.get()->giveLocation().giveX(),
                              i.get()->giveLocation().giveY()} ;
        auto output = CourseConverter::mapToUi(input);
        auto iterator  = actors_.find(i);
        if (iterator != actors_.end() && iterator.key() == i) {
            ImgActorItem* oldActorItem = actors_.take(i);
            if (dynamic_cast<CourseSide::Passenger*>(i.get()) != nullptr){
                if(moved.indexOf(i) != -1){
                    int x = randgen.bounded(30)-15;
                    int y = randgen.bounded(30)-15;
                    oldActorItem->moveTo(output.x+x,output.y+y);
                }
                CourseSide::Passenger * pas = dynamic_cast<CourseSide::Passenger*>(i.get());
                oldActorItem->setVisible(!(pas->isInVehicle()||pas->isRemoved()));
            }else if(moved.indexOf(i) != -1){
                oldActorItem->moveTo(output.x,output.y);
            }
            newActors[std::move(i)] = oldActorItem;
        }else{
            if(i->isRemoved()){
                continue;
            }
            if (dynamic_cast<CourseSide::Nysse*>(i.get()) != nullptr)
              {
                BusUiItem* nActor =  new BusUiItem(output.x, output.y);
                window_.addActor(nActor);
                newActors[std::move(i)] =  nActor;
              }
            else if (dynamic_cast<CourseSide::Passenger*>(i.get()) != nullptr){
                int x = randgen.bounded(30)-15;
                int y = randgen.bounded(30)-15;
                PassangerUiItem* nActor =  new PassangerUiItem(output.x+x, output.y+y);
                window_.addActor(nActor);
                newActors[std::move(i)] =  nActor;
            }
        }
    }
    for(auto &j: actors_){
        j->hide();
        delete j;
    }
    actors_.clear();
    actors_ = std::move(newActors);

    // iterate trough nearby actors and remove all colliding with the RATIKKA
    for(auto &i:actors_.keys()){
        if(actors_[i]->collidesWithItem(&ratikka_)){
            if (dynamic_cast<CourseSide::Passenger*>(i.get()) != nullptr){
                //value is ImgActorItem*
                actors_[i]->hide();
                delete actors_[i];
                // key is Interface::IActor
                cp_->actorRemoved(i);
                actors_.remove(i);
                cp_->stats()->addPoints();
                window_.setScore(cp_->stats()->Points());
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
    speed_ = difficulity + 1;

    if ( STARTLOCATIONS.size() < startPoint || startPoint < 0){
       startPoint = 0;}
    auto loc = STARTLOCATIONS[startPoint];
    startCords_ = CourseConverter::mapToUi(CourseConverter::cords{loc.giveX(),loc.giveY()});

}

void Engine::updateRatikka(){
    if(keys_.empty()){
        return;
    }
    auto oldCords = ratikka_.getCoords();
    bool limitUp = oldCords.y <=20;
    bool limitLeft = oldCords.x <=20;;
    bool limitRight = oldCords.x >= CourseConverter::MAP_WIDTH-20;
    bool limitDown = oldCords.y >= CourseConverter::MAP_HEIGHT;
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

void Engine::updateSquirrels()
{
    int width = 1095;
    int height = 600;
    for(FlyingSquirrel *animal: qAsConst(squirrels_)){
        animal->move(0,SQUIRRELSPEED);
        if(animal->collidesWithItem(&ratikka_)){
            EndGame(hitAnimal);
            return;
        }
        if(animal->getCoords().y>height){
            animal->hide();
            squirrels_.removeAll(animal);
            delete animal;
        }
    }
    if(randgen.bounded(1000)<3){
        int x = randgen.bounded(30,width);
        FlyingSquirrel* sq = new FlyingSquirrel(x,-30);
        window_.addActor(sq);
        squirrels_.insert(0,std::move(sq));
    }
}

void Engine::EndGame(endingCases endingCase)
{
    if(cp_->isGameOver()){
        return;
    }
    running = false;
    cp_->stats()->saveHiScore();
    disconnect(&timer_, &QTimer::timeout, this, &Engine::updatePositions);


    timer_.stop();
    cp_->endGame();
    QString text("%1\n\nGame over!\nYou got %2 points!");
    switch (endingCase) {
    case hitNysse:
    {
        text = text.arg("You collided with a Nysse :(");
    }
        break;
    case timeUp:{
        text = text.arg("Time is up!");
        break;
    }
    case hitAnimal:{
        text = text.arg("You collided with a flying squirrel >:(");
    }
        break;
    default:
            break;
    }

    QMessageBox msgBox;
    msgBox.setStandardButtons(QMessageBox::Retry);
    msgBox.setText(text.arg(cp_->stats()->Points()));
    msgBox.exec();

    emit signalGameEnded();
}
}
