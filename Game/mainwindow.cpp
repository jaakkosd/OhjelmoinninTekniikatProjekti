#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#define WINDOW_SCALE 2

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

void MainWindow::updateActors(std::vector<std::shared_ptr<Interface::IActor> > nearby)
{

    QMap<std::shared_ptr<Interface::IActor>,busUiItem*> newActors;
    for(auto &i : nearby){
        courseConverter::cords input {i.get()->giveLocation().giveX(),
                              i.get()->giveLocation().giveY()} ;
        auto output = courseConverter::mapToUi(input);
        auto iterator  = actors_.find(i);
        if (iterator != actors_.end() && iterator.key() == i) {
            busUiItem* oldBus = actors_.take(i);
            oldBus->move(output.x,output.y);
            newActors[std::move(i)] = oldBus;
        }else{
            if (dynamic_cast<CourseSide::Nysse*>(i.get()) != nullptr)
              {
                busUiItem* nActor =  new busUiItem(output.x, output.y);
                map->addItem(nActor);
                newActors[std::move(i)] =  nActor;
              }
        }
    }
    for(auto j: actors_){
        j->hide();
        delete j;
    }
    actors_.clear();
    actors_ = std::move(newActors);
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


void MainWindow::on_startButton_clicked()
{
    qDebug() << "Start clicked";
    emit gameStarted();
}

void MainWindow::wheelEvent(QWheelEvent *event)
{

}

Interface::Location MainWindow::getCenter()
{
    courseConverter::cords input {(ui->graphicsView->horizontalScrollBar()->value() + ui->graphicsView->height()/2)/WINDOW_SCALE,
                          (ui->graphicsView->verticalScrollBar()->value() + ui->graphicsView->width()/2)/WINDOW_SCALE} ;
    auto output = courseConverter::uiToMap(input);
    auto loc = Interface::Location();
    loc.setXY(output.x,output.y);
    return loc;
}

