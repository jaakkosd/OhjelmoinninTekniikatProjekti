#include "graphicitems/ratikkaitem.h"
#include <QDebug>
namespace Game {
RatikkaItem::RatikkaItem(int x, int y):ImgActorItem( x,  y)
{
    assert(ratikkaleft.load(":/img/resources/ratikkaleft.png")); //assert that png file is loaded
    assert(ratikkaright.load(":/img/resources/ratikkaright.png")); //assert that png file is loaded
    setOffset(-21,-27);
    setScale(1);
    setPixmap(ratikkaright);
}

QPair<int,int> RatikkaItem::move(int x, int y){
    if ( x < 0 ){
        setPixmap(ratikkaleft);
    } else if ( x > 0) {
        setPixmap(ratikkaright);
    }
    moveTo(x_+x,y_+y);
    return QPair<int,int>(x_,y_);
}
}
