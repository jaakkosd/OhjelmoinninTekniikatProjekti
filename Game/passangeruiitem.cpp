#include "passangeruiitem.h"

PassangerUiItem::PassangerUiItem(int x, int y):ImgActorItem( x,  y)
{

    assert(pixmap_.load(":/img/passenger.png")); //assert that png file is loaded
    setOffset(-8,-16);
    setScale(0.4);

    //QPixmap pixmapItems = pixmapItem.scaled(QSize(512,512),  Qt::KeepAspectRatio);
    setPixmap(pixmap_);
}

void PassangerUiItem::move(int x,int y){
    setCoord(x,y);
}
