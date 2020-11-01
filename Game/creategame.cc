#include "creategame.hh"
#include "core/logic.hh"
#include "city.hh"

std::shared_ptr<Interface::ICity> Interface::createGame()
{
    while(1) {
        qDebug() << QTime::currentTime().second();
        if(QTime::currentTime().second() % 15 == 0){
            break;
        }else{
            _sleep(1000);
        }
    }
    CourseSide::Logic gamelogic;
    gamelogic.fileConfig();
    std::shared_ptr<City> citypointer = std::make_shared<City>();
    gamelogic.takeCity(citypointer);//ensin töytyy antaa city
    gamelogic.finalizeGameStart();
    qDebug() << "Hei me mennään junalla!";
    std::shared_ptr<City> retCP = citypointer;
    return retCP;

}
