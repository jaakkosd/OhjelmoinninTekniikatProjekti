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
const static int STARTHOUR = 9;
const static int FPS = 60;
const static int GAMETIME = 60;
const static QList<Interface::Location> STARTLOCATIONS {
    Interface::Location(6826254,3327977),
            Interface::Location(6825071,3326060),
            Interface::Location(6825017,3328246)
};

namespace Game {
class Engine : public QObject
{
    Q_OBJECT

public:
    explicit Engine(QObject *parent = nullptr);
    void init();

public slots:
    void getSettings(int difficulity, int startPoint);
signals:
    void gameEnded();
protected slots:
    void updatePositions();
private slots:
    void updateRatikka();
    void updateSquirrels();
    void updateKeys(QSet<int> keys);
private:
    bool running = true;
    enum endingCases  { timeUp,
                        hitNysse,
                        hitAnimal
                      };

    CourseSide::Logic gamelogic_;
    std::shared_ptr<Game::City>  cp_;
    MainWindow window_;
    SetupDialog setupDialog_;
    QTimer timer_;
    RatikkaItem ratikka_;
    Movement moveKeysObject_;
    QSet<int> keys_;
    QMap<std::shared_ptr<Interface::IActor>,ImgActorItem*> actors_;
    QRandomGenerator randgen = QRandomGenerator(QTime::currentTime().msecsSinceStartOfDay());
    void EndGame(endingCases endingCase);
    int speed_;
    CourseConverter::cords startCords_;
    QDateTime endTime;
    QList<FlyingSquirrel*> squirrels_;
};
}
#endif // ENGINE_H
