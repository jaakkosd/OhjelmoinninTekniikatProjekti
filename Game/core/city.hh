#ifndef CITY_HH
#define CITY_HH
#include "interfaces/icity.hh"
#include "statistics.h"
#include "actors/nysse.hh"
#include "errors/gameerror.hh"

namespace Game
{
/**
 * @brief CityIF is an interface that every city in the game must fulfill. Kaupunki
 *
 * If class method doesn't have exception guarantee of nothrow, method can leak out exception `std::bad_alloc` (out of memory)
 */
class City : public Interface::ICity
{
public:
    /**
      * @brief Constructor
      * @post City is initialized.
      */
    City();

    /**
     * @brief setBackground saves the bitmap pictures of the game area.
     * @param basicbackground  Normal sized picture used as the game area. Bottom left position of the picture in pixelcoordinates can be found out using the offset()-method.
     * @param bigbackground  Background of the game that is bigger than normal. Used only if doing Scrolling map-expansion. Bottom left position of the picture in pixelcoordinates can be found out using the offset()-method.
     * @pre City object is created.
     * @post Pictures for the game area are saved. Exception guarantee: basic.
     * @exception InitError Setting the picture was unsuccesful or the picture was invalid.
     */
    void setBackground(QImage &basicbackground, QImage &bigbackground);

    /**
     * @brief setClock is deprecated, not used and won't affect game time because game logic isn't handeled by City class.
     * @param clock Game clock time at the function call.
     * @exception Exception guarantee: nothrow.
     */
    [[deprecated]] void setClock(QTime clock);

    /**
     * @brief addStop adds a stop to the city.
     * @param stop pointer to a stop object.
     * @pre City is in init state.
     * @post Stop is added to the city. Exception guarantee: basic
     * @exception InitError Stops position is not valid.
     */
    void addStop(std::shared_ptr<Interface::IStop> newstop);

    /**
     * @brief startGame sets isGameStarted flag to true.
     * @exception Exception guarantee: nothrow.
     */
    void startGame();

    /**
     * @brief addActor adds a new actor to the city.
     * @param newactor actor to be added to the city that fulfills ActorIF.
     * @post Actor is added to the city. Exception guarantee: basic.
     * @exception GameError Actor is already in the city.
     */
    void addActor(std::shared_ptr<Interface::IActor> newactor);

    /**
     * @brief removeActor removes the actor from the city.
     * @param actor Actor to be removed.
     * @post Actor is removed from the city. Exception guarantee: strong.
     * @exception GameError Actor not found in the city
     */
    void removeActor(std::shared_ptr<Interface::IActor> actor);

    /**
     * @brief actorRemoved tells the city that actor is removed ingame.
     * @param actor Actor that is set removed ingame.
     * @pre City is in gamestate. Given actor is found in the city. Actor has `actor.isRemoved() == true`.
     * @post Exception guarantee: strong.
     */
    void actorRemoved(std::shared_ptr<Interface::IActor> actor);

    /**
     * @brief findActor checks if the given actor is in the city.
     * @param actor Actor that that is looked for in the city.
     * @pre -
     * @return Boolean that tells wether the actor is in the city.
     * @post Exception guarantee: nothrow.
     */
    bool findActor(std::shared_ptr<Interface::IActor> actor) const;

    /**
     * @brief actorMoved is an operation that is used to tell wether certain actor has moved.
     * @param actor Actor that has moved.
     * @pre City is in gamestate. Given actor is found in the city.
     * @post Exception guarantee: basic.
     */
    void actorMoved(std::shared_ptr<Interface::IActor> actor);

    /**
     * @brief movedActors returns a list of moved actors since movedActors was last called.
     * @return Qlist that includes all moved actors.
     * @post movedActors_ list is empty
     * @exception Exception guarantee: nothrow.
     */
    QList<std::shared_ptr<Interface::IActor>> movedActors();

    /**
     * @brief getNearbyActors returns actors that are close to given position.
     * @param loc Location for getting the actors close to it.
     * @pre City is in gamestate.
     * @return Vector containing actors close to the location, that pass `getLocation().isClose(loc) == true`.
     * @post Exception guarantee: strong.
     */
    std::vector<std::shared_ptr<Interface::IActor>> getNearbyActors(Interface::Location loc) const;

    /**
     * @brief isGameOver tells whether the game has started overor not.
     * @return `true`, if game has started, else ´false´
     * @post Exception guarantee: nothrow.
     */
    bool isGameStarted() const;

    /**
     * @brief isGameOver tells whether the game is overor not.
     * @return `true`, if game is over, else ´false´
     * @post Exception guarantee: nothrow.
     */
    bool isGameOver() const;

    /**
     * @brief endGame sets the isGameOver flag to true.
     * @exception Exception guarantee: nothrow.
     */
    void endGame();

    /**
     * @brief stats returns a pointer to starts object for easy access.
     * @return pointer to stats object
     * @pre pointer have not been deleted outside the class.
     * @exception Exception guarantee: nothrow.
     */
    Statistics *stats();

    /**
     * @brief stopList contains all stops in the city
     * @return QList containing stops in the city
     * @pre pointer have not been deleted outside the class.
     * @exception Exception guarantee: nothrow.
     */
    QList<std::shared_ptr<Interface::IStop>> stopList();

    /**
     * @brief basicbackground returns the stored image stored by setBackground.
     * @return QImage of stored image.
     * @pre setBackground called.
     * @exception Exception guarantee: nothrow.
     */
    QImage basicbackground();

    /**
     * @brief bigbackground returns the stored image stored by setBackground.
     * @return QImage of stored image.
     * @pre setBackground called.
     * @exception Exception guarantee: nothrow.
     */
    QImage bigbackground();
public slots:

private:
    QList<std::shared_ptr<Interface::IStop>> stopList_;
    QList<std::shared_ptr<Interface::IActor>> actorList_;
    QList<std::shared_ptr<Interface::IActor>> movedActors_;

    bool isGameStarted_ = false;
    bool isGameOver_ = false;
    Statistics stats_;
    QImage basicbackground_;
    QImage bigbackground_;
};

} // namespace Game

#endif // CITY_HH
