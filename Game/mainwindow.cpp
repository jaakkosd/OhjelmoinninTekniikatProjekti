#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#define WINDOW_SCALE 1

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //old stuff remove if works:

    //ui->graphicsView->setFixedSize(view_width_, view_width_);
    //ui->centralwidget->setFixedSize(view_width_ + ui->startButton->width() + PADDING, view_width_ + PADDING);

    //ui->startButton->move(map_width_ + PADDING , PADDING);

    map = new QGraphicsScene(this);
    ui->graphicsView->setScene(map);
    map->setSceneRect(0,0,map_width_,map_height_);

    ui->graphicsView->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->graphicsView->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->graphicsView->scale(WINDOW_SCALE,WINDOW_SCALE);


    //resize(minimumSizeHint());
    //ui->gameView->fitInView(0,0, MAPWIDTH, MAPHEIGHT, Qt::KeepAspectRatio);

    //timer = new QTimer(this);
    //connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    //timer->start(tick_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addActor(QGraphicsItem* actor)
{
    map->addItem(actor);
}

void MainWindow::setSize(int w, int h)
{
    map_width_ = w;
    map_height_ = h;
}

void MainWindow::setTick(int t)
{
    //tick_ = t;
}

void MainWindow::setPicture(QImage &img)
{
    map->setBackgroundBrush(img);
}

void MainWindow::setStops(std::shared_ptr<Interface::ICity>  cp_)
{
   City* cityPointer =  dynamic_cast<City*>(cp_.get());
   if (cityPointer){
       for (auto stop : cityPointer->stopList){
               Interface::Location loc = stop->getLocation();
               courseConverter::cords mapcords {loc.giveX(), loc.giveY()};
               courseConverter::cords uicords = courseConverter::mapToUi(mapcords);
               StopUiItem* stoppi =  new StopUiItem(uicords.x, uicords.y);
               map->addItem(stoppi);
       }
   }
}

void MainWindow::addRatikka(Ratikkaitem* ratikka)
{
    map->addItem(ratikka);
}


void MainWindow::on_startButton_clicked()
{
    qDebug() << "Start clicked";
    emit gameStarted();
}





Interface::Location MainWindow::getCenter()
{
    courseConverter::cords input {(ui->graphicsView->horizontalScrollBar()->value() + ui->graphicsView->width()/2)/WINDOW_SCALE,
                          (ui->graphicsView->verticalScrollBar()->value() + ui->graphicsView->height()/2)/WINDOW_SCALE} ;
    auto output = courseConverter::uiToMap(input);
    auto loc = Interface::Location();
    loc.setXY(output.x,output.y);
    return loc;
}

void MainWindow::scrollMap(int x, int y)
{
    ui->graphicsView->horizontalScrollBar()->setValue(x-ui->graphicsView->width()/2);
    ui->graphicsView->verticalScrollBar()->setValue(y-ui->graphicsView->height()/2);
}

