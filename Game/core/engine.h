#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include "graphic/mainwindow.h"
#include "creategame.hh"
#include "core/logic.hh"
#include "city.hh"
#include "graphicitems/busuiitem.h"
#include "graphicitems/ratikkaitem.h"
#include "movement.h"
#include "graphic/setupdialog.h"

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
    void updateKeys(QSet<int> keys);
private:
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
    void EndGame();
    int speed_;
    courseConverter::cords startCords_;
    const QList<Interface::Location> startLocations_ {Interface::Location(6825438,3328230),
                Interface::Location(6825071,3326060),Interface::Location(6825017,3328246)};

};
}
#endif // ENGINE_H
