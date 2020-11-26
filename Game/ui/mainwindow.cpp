#include "ui/mainwindow.h"
#include "ui_mainwindow.h"

#define WINDOW_SCALE 1.2
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&map);
    map.setSceneRect(0,0,map_width_,map_height_);

    ui->graphicsView->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->graphicsView->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->graphicsView->scale(WINDOW_SCALE,WINDOW_SCALE);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addActor(QGraphicsItem* actor)
{
    map.addItem(actor);
}

void MainWindow::setSize(int w, int h)
{
    map_width_ = w;
    map_height_ = h;
}

void MainWindow::setPicture(QImage &img)
{
    map.setBackgroundBrush(img);
}

void MainWindow::setStops(std::shared_ptr<Interface::ICity>  cp_)
{
   Game::City* cityPointer =  dynamic_cast<Game::City*>(cp_.get());
   if (cityPointer){
       for (auto &stop : cityPointer->stopList){
               Interface::Location loc = stop->getLocation();
               Game::CourseConverter::cords mapcords {loc.giveX(), loc.giveY()};
               Game::CourseConverter::cords uicords = Game::CourseConverter::mapToUi(mapcords);
               Game::StopUiItem* stoppi =  new Game::StopUiItem(uicords.x, uicords.y);
               map.addItem(stoppi);
       }
   }
}

Interface::Location MainWindow::getCenter()
{
    Game::CourseConverter::cords input {static_cast<int>((ui->graphicsView->horizontalScrollBar()->value() + ui->graphicsView->width()/2)/WINDOW_SCALE),
                          static_cast<int>((ui->graphicsView->verticalScrollBar()->value() + ui->graphicsView->height()/2)/WINDOW_SCALE)} ;
    auto output = Game::CourseConverter::uiToMap(input);
    auto loc = Interface::Location();
    loc.setXY(output.x,output.y);
    return loc;
}

void MainWindow::scrollMap(int x, int y)
{
    ui->graphicsView->horizontalScrollBar()->setValue(x*WINDOW_SCALE-ui->graphicsView->width()/2);
    ui->graphicsView->verticalScrollBar()->setValue(y*WINDOW_SCALE-ui->graphicsView->height()/2);
}

void MainWindow::installEvents(QObject *handler)
{
    ui->graphicsView->installEventFilter(handler);
    ui->graphicsView->viewport()->installEventFilter(handler);
}

void MainWindow::setClock(QString str)
{
    ui->lcdNumber->display(str);
}

void MainWindow::setScore(int score)
{
    ui->lcdNumber_2->display(score);
}

void MainWindow::setHiScore(int score)
{
    ui->lcdNumber_3->display(score);
}
