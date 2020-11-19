#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "interfaces/iactor.hh"
#include "actoritem.h"
#include "actors/nysse.hh"
#include "busuiitem.h"
#include "offlinereader.hh"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>
#include <QScrollBar>
#include <core/location.hh>
#include <courseconverter.h>
#include <QPair>
#include "passangeruiitem.h"
#include "city.hh"
#include <QRandomGenerator>
#include "stopuiitem.h"
#include "ratikkaitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    void setSize(int w, int h);
    void setTick(int t);

    void updateCoords(int nX, int nY);
    void setPicture(QImage &img);

    void setStops(std::shared_ptr<Interface::ICity>  cp_);

    void addRatikka(Game::Ratikkaitem* ratikka);

    Interface::Location getCenter();
    void  scrollMap(int x,int y);

    void installEvents(QObject *handler);
public slots:
    void addActor(QGraphicsItem *actor);
    void setClock(QString str);
signals:
    void gameStarted();

private slots:
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene map;

    int map_width_ = 1095; //pxls
    int map_height_ = 592;
    int tick_ = 500; //ms
};

#endif // MAINWINDOW_H
