#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include "mainwindow.h"
#include "creategame.hh"
#include "core/logic.hh"
#include "city.hh"
#include "busuiitem.h"
#include "ratikkaitem.h"
#include "movement.h"
#include "setupdialog.h"

#define UPDATES_PER_SECOND 30

class Engine : public QObject
{
    Q_OBJECT

public:
    explicit Engine(QObject *parent = nullptr);

    void init();

public slots:
    void getSettings(int difficulity, int startPoint);

protected slots:
    void updatePositions();
private slots:
    void updateRatikka();
    void updateKeys(QSet<int> keys);
private:
    CourseSide::Logic gamelogic_;
    std::shared_ptr<Interface::ICity>  cp_;
    MainWindow window_;
    SetupDialog setupdialog_;
    QTimer *timer_;
    Ratikkaitem ratikka_;
    Movement moveKeysObject_;
    QSet<int> keys_;
    QMap<std::shared_ptr<Interface::IActor>,ImgActorItem*> actors_;
    QRandomGenerator randgen = QRandomGenerator(QTime::currentTime().msecsSinceStartOfDay());
    int speed_;
    courseConverter::cords startCords_;
    const QList<Interface::Location> startLocations_ {Interface::Location(6825438,3328230),
                Interface::Location(6825071,3326060),Interface::Location(6825017,3328246)};
};

#endif // ENGINE_H
