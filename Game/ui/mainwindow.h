#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "interfaces/iactor.hh"
#include "actors/nysse.hh"
#include "graphicitems/busuiitem.h"
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
#include <core/courseconverter.h>
#include <QPair>
#include "graphicitems/passangeruiitem.h"
#include "core/city.hh"
#include <QRandomGenerator>
#include "graphicitems/stopuiitem.h"
#include "graphicitems/ratikkaitem.h"


namespace Ui {
class MainWindow;
}
/**
 * @brief The MainWindow class creates mainwindow for game
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
     * @brief virtual Destructor. MIKSI
     */
    virtual ~MainWindow();
    /**
     * @brief setPicture set map picture to window
     * @param img wanted picture
     */
    void setPicture(QImage &img);
    /**
     * @brief setStops create stop objects and add them to ui
     * @param cp_
     */
    void setStops(std::shared_ptr<Interface::ICity>  cp_);
    /**
     * @brief getCenter returns location of current map center
     * @return Locatation of center
     */
    Interface::Location getCenter();
    /**
     * @brief scrollMap scrolls map to given start position
     * @param x starting x coordinate
     * @param y starting y coordinate
     */
    void  scrollMap(int x,int y);
    /**
     * @brief installEvents creates hander to listen moving keys
     * @param handler is QObject pointer
     */
    void installEvents(QObject *handler);

public slots:
    /**
     * @brief addActor add actor to ui
     * @param actor actor to be added
     */
    void addActor(QGraphicsItem *actor);
    /**
     * @brief setClock updates current time to mainwindow's lcdnumber
     * @param str is current time in QString format
     */
    void setClock(QString str);
    /**
     * @brief setScore updates current score to mainwindowäs lcdnumber
     * @param score is current score
     */
    void setScore(int score);
    /**
     * @brief setHiScore updates high score to mainwindows lcdnumber if new record
     * @param score is high score to be added
     */
    void setHiScore(int score);


private:
    Ui::MainWindow *ui;
    QGraphicsScene map;

    int map_width_ = 1095; //pxls
    int map_height_ = 592;
    int tick_ = 500; //ms
};

#endif // MAINWINDOW_H
