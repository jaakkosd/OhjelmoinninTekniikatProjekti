#ifndef STATISTICS_H
#define STATISTICS_H

#include "interfaces/istatistics.hh"
#include <QFile>
#include <QDir>

namespace Game {
/**
 * @brief The Statistics class is used to keep track of points, hiscore and gameobject counts.
 */
class Statistics : public Interface::IStatistics
{
public:
    /**
     * @brief Default constructor.
     * @param filename Qsring of a filename with an extension where to read and write the hiscore data
     * @post Hiscore is read and scores are reset by default.
     * @exception Exception guarantee: Basic
     */
    Statistics(QString filename = "hiscore.txt");

    /**
      * @brief Default destructor.
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
     * @brief addPoints adds points to the internal point counter. Works with negative points too.
     * @param points count to add
     * @post internal counter has more points
     * @exception Exception guarantee: No-throw
     */
    void addPoints(int points=1);

    /**
     * @brief Points a getter for the internal point counter
     * @return points of internal counter
     * @exception Exception guarantee: No-throw
     */
    int Points();

    /**
     * @brief readHiScore reads the hi-score from the given file and assigns it to the internal hiscore variable
     * @post if file read was succesfull the internal variable hiScore will contain the hiscore
     * @exception safety: Basic
     */
    void readHiScore();


    /**
     * @brief saveHiScore saves the hi-score to the given file from the internal hiscore variable
     * @post if file write was succesfull the file contains the hiscore
     * @exception safety: Basic
     */
    void saveHiScore();

    /**
     * @brief hiScore getter for the internal varible
     * @return current hiscore
     * @exception Exception guarantee: No-throw
     */
    int hiScore();

    /**
     * @brief nysses getter for the internal varible that counts nysses in game
     * @return count of nysses in game
     * @exception Exception guarantee: No-throw
     */
    int nysses();

    /**
     * @brief passangers getter for the internal varible that counts passangers in game
     * @return count passangers added to game
     * @exception Exception guarantee: No-throw
     */
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
