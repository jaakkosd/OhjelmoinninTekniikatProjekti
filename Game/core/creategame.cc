#include "creategame.hh"
#include "core/city.hh"

std::shared_ptr<Interface::ICity> Interface::createGame()
{

    std::shared_ptr<Game::City> citypointer = std::make_shared<Game::City>();
    return citypointer;

}

