#ifndef STATISTICS_H
#define STATISTICS_H

#include "interfaces/istatistics.hh"
#include <QFile>
#include <QDir>

namespace Game {
class Statistics : public Interface::IStatistics
{
public:
    /**
      * @brief Default constructor for the Interface.(For documentation).
      * @post Scores are reset by default.
      */
    Statistics(QString filename = "hiscore.txt");

    /**
      * @brief Interface has default virtual destructor (base class needs to have a virtual destructor).
      */
    ~Statistics() = default;

    /**
     * @brief morePassengers notifies, that more passangers are added to the game.
     * @param num how many new passangers are added.
     * @pre num > 0
     * @post Exception guarantee: strong
     */
    void morePassengers(int num);

    /**
     * @brief nysseRemoved notifies, that the nysse is removed ingame.
     * @pre -
     * @post Exception guarantee: strong
     */
    void nysseRemoved();

    /**
     * @brief newNysse notifies, that a new nysse is added to the game.
     * @pre -
     * @post Exception guarantee: strong
     */
    void newNysse();

    /**
     * @brief nysseLeft notifies, that a nysse has left the game.
     * @pre -
     * @post Exception guarantee: strong
     */
    void nysseLeft();

    /**
     * @brief töttöröö
     * @pre -
     * @post Exception guarantee: ryys
     */

    void addPoints(int points=1);
    int Points();

    void readHiScore();
    void saveHiScore();
    int hiScore();
    int nysses();
    int passangers();
private:
    int points_ = 0;
    int nysses_ = 0;
    int passangers_ = 0;
    int hiScore_ = 0;
    QString filename_;
};
}
#endif // STATISTICS_H
