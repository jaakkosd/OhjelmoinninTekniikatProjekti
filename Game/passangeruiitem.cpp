#include "passangeruiitem.h"

PassangerUiItem::PassangerUiItem(int x, int y):ImgActorItem( x,  y)
{

    assert(pixmap_.load(":/img/passenger.png")); //assert that png file is loaded
    setOffset(-12,-46);
    setScale(0.4);

    //QPixmap pixmapItems = pixmapItem.scaled(QSize(512,512),  Qt::KeepAspectRatio);
    setPixmap(pixmap_);
}

void PassangerUiItem::moveTo(int x,int y){
    setCoord(x+offx_,y+offy_);
}

void PassangerUiItem::setOffset(int x, int y)
{
    offx_ = x;
    offy_ = y;
}
