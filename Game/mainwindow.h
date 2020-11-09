#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "interfaces/iactor.hh"
#include "actors/nysse.hh"
#include "busuiitem.h"
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
    QMap<std::shared_ptr<Interface::IActor>,busUiItem*> actors_;


    int map_width_ = 1095; //pxls
    int map_height_ = 592;
    int tick_ = 500; //ms
    int map_width_offset = 353;
    int map_height_offset = 556;
};

#endif // MAINWINDOW_H
