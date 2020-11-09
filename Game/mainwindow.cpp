#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


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
    ui->graphicsView->scale(1.5,1.5);

    //ui->graphicsView->horizontalScrollBar()->value()
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
        int x = i.get()->giveLocation().giveX()+ map_width_offset;
        int y = map_height_offset - i.get()->giveLocation().giveY();
        auto iterator  = actors_.find(i);
        if (iterator != actors_.end() && iterator.key() == i) {
            busUiItem* oldBus = actors_.take(i);
            oldBus->move(x,y);
            newActors[std::move(i)] = oldBus;
        }else{
            if (dynamic_cast<CourseSide::Nysse*>(i.get()) != nullptr)
              {
                busUiItem* nActor =  new busUiItem(x,y);
                map->addItem(nActor);
                newActors[std::move(i)] =  nActor;
              }
        }
    }
    for(auto j: actors_){
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

