#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "interfaces/iactor.hh"
#include "actors/nysse.hh"
#include "actoritem.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>

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

public slots:
    void updateActors(std::vector<std::shared_ptr<Interface::IActor> > nearby);
signals:
    void gameStarted();

private slots:
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    QMap<std::shared_ptr<Interface::IActor>,ActorItem*> actors_;
    ActorItem* last_;

    int width_ = 500; //pxls
    int height_ = 500;
    int tick_ = 500; //ms
};

#endif // MAINWINDOW_H
