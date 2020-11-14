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

#define UPDATES_PER_SECOND 30

class Engine : public QObject
{
    Q_OBJECT
public:
    explicit Engine(QObject *parent = nullptr);

    void init();

signals:

protected slots:
    void updatePositions();
private slots:
    void updateRatikka();
    void updateKeys(QSet<int> keys);
private:
    CourseSide::Logic gamelogic_;
    std::shared_ptr<Interface::ICity>  cp_;
    MainWindow window_;
    QTimer *timer_;
    QMap<std::shared_ptr<Interface::IActor>,BusUiItem*> actors_;
    Ratikkaitem ratikka_;
    Movement moveKeysObject_;
    QSet<int> keys_;

};

#endif // ENGINE_H
