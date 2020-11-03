#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include "mainwindow.h"
#include "creategame.hh"
#include "core/logic.hh"
#include "city.hh"

#define UPDATES_PER_SECOND 1

class Engine : public QObject
{
    Q_OBJECT
public:
    explicit Engine(QObject *parent = nullptr);

    void init();
signals:

protected slots:
    void updatePositions();
private:
    CourseSide::Logic gamelogic_;
    std::shared_ptr<Interface::ICity>  cp_;
    MainWindow window_;
    QTimer *timer_;

};

#endif // ENGINE_H
