#include "stopuiitem.h"

StopUiItem::StopUiItem(int x,int y):ImgActorItem(x,y)
{
    assert(pixmap_.load(":/img/stop.png")); //assert that png file is loaded
    setOffset(0,-84);
    setScale(0.5);

    //QPixmap pixmapItems = pixmapItem.scaled(QSize(512,512),  Qt::KeepAspectRatio);
    setPixmap(pixmap_);

}