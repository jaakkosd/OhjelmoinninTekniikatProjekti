#include "graphicitems/passangeruiitem.h"
namespace Game {
PassangerUiItem::PassangerUiItem(int x, int y):ImgActorItem( x,  y)
{

    assert(pixmap_.load(":/img/resources/passenger.png")); //assert that png file is loaded
    setOffset(-13,-46);
    setScale(0.5);

    //QPixmap pixmapItems = pixmapItem.scaled(QSize(512,512),  Qt::KeepAspectRatio);
    setPixmap(pixmap_);
}
}
