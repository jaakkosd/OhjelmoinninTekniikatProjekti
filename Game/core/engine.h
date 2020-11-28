#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include "ui/mainwindow.h"
#include "creategame.hh"
#include "core/logic.hh"
#include "city.hh"
#include "graphicitems/busuiitem.h"
#include "graphicitems/ratikkaitem.h"
#include "movement.h"
#include "ui/setupdialog.h"
#include "statistics.h"
#include "graphicitems/flyingsquirrel.h"

const static int SQUIRRELSPEED = 4;
const static int STARTHOUR = 12;
const static int FPS = 60;
const static int GAMETIME = 60;
const static QList<Interface::Location> STARTLOCATIONS{
    Interface::Location(6826254, 3327977),
            Interface::Location(6825071, 3326060),
            Interface::Location(6825017, 3328246)};
namespace Game
{
/**
 * @brief The Engine class is used to handle all game events, drive and move ui objects and store information.
 */
class Engine : public QObject
{
    Q_OBJECT

public: /**
     * @brief Engine, default constructor.
     * @param parent QObject
     */
    explicit Engine(QObject *parent = nullptr);

    /**
     * @brief init initialises
     */
    void init();

signals:

    /**
     * @brief gameEnded
     */
    void gameEnded();
private slots:
    void updatePositions();
    void updateKeys(QSet<int> keys);
private:

    void updateRatikka();
    void updateSquirrels();
    void getSettings(int difficulity, int startPoint);
    bool running = true;
    enum endingCases
    {
        timeUp,
        hitNysse,
        hitAnimal
    };

    CourseSide::Logic gamelogic_;
    std::shared_ptr<Game::City> cp_;
    MainWindow window_;
    SetupDialog setupDialog_;
    QTimer timer_;
    RatikkaItem ratikka_;
    Movement moveKeysObject_;
    QSet<int> keys_;
    QMap<std::shared_ptr<Interface::IActor>, ImgActorItem *> actors_;
    QRandomGenerator randgen = QRandomGenerator(QTime::currentTime().msecsSinceStartOfDay());
    void EndGame(endingCases endingCase);
    int speed_;
    CourseConverter::cords startCords_;
    QDateTime endTime;
    QList<FlyingSquirrel *> squirrels_;
};
} // namespace Game
#endif // ENGINE_H
