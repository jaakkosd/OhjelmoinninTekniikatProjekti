#include "creategame.hh"
#include "core/logic.hh"
#include "city.hh"

std::shared_ptr<Interface::ICity> Interface::createGame()
{
    CourseSide::Logic gamelogic;
    gamelogic.fileConfig();
    std::shared_ptr<City> citypointer = std::make_shared<City>();
    gamelogic.takeCity(citypointer);//ensin töytyy antaa city
    gamelogic.finalizeGameStart();
    //std::shared_ptr<City> retCP = citypointer; pitääkö pointerista tehdä kopio tässä?
    return citypointer;

}
