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
#include "graphicitems/flyingsquirrel.h"


#define UPDATES_PER_SECOND 30
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
    const static int squirrelSpeed = 8;
    bool running = true;
    enum endingCases  { timeUp,
                        hitNysse,
                        hitAnimal
                      };

    CourseSide::Logic gamelogic_;
    std::shared_ptr<Interface::ICity>  cp_;
    MainWindow window_;
    SetupDialog setupDialog_;
    QTimer timer_;
    Ratikkaitem ratikka_;
    Movement moveKeysObject_;
    QSet<int> keys_;
    QMap<std::shared_ptr<Interface::IActor>,ImgActorItem*> actors_;
    QRandomGenerator randgen = QRandomGenerator(QTime::currentTime().msecsSinceStartOfDay());
    void EndGame(endingCases endingCase);
    int speed_;
    courseConverter::cords startCords_;
    const QList<Interface::Location> startLocations_ {Interface::Location(6825438,3328230),
                Interface::Location(6825071,3326060),Interface::Location(6825017,3328246)};
    QList<FlyingSquirrel*> squirrels_;


};
}
#endif // ENGINE_H
