#include "busuiitem.h"

busUiItem::busUiItem(int x, int y):imgActorItem( x,  y)
{
    assert(pixmapLeft_.load(":/img/pin_red16.png")); //assert that png file is loaded
    assert(pixmapRight_.load(":/img/pin_green16.png")); //assert that png file is loaded
    setOffset(-8,-16);
    setScale(1);

    //QPixmap pixmapItems = pixmapItem.scaled(QSize(512,512),  Qt::KeepAspectRatio);
    setPixmap(pixmapLeft_);

}

void busUiItem::move(int x,int y)
{
    // the idea here is that when the bus is going left it should show the picture of a bus going left
    // now it's not working
    // DOTO: Jaakko FIX THIS
    // The cordinate system is using a grid so this looks funky, choppy and bad. Maybe implement some sort of (P)I(D) controller :)
    if(x==x_ && y==y_){
        return;
    }
    int angle = -qRadiansToDegrees(qAtan2(x-x_,y-y_));
    if(angle >90  || angle < -90){
        setPixmap(pixmapLeft_);
    }else{
        setPixmap(pixmapRight_);
    }
    setRotation(angle);
    setCoord(x,y);
}
