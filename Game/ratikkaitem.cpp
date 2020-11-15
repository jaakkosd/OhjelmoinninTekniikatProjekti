#include "ratikkaitem.h"
#include <QDebug>

Ratikkaitem::Ratikkaitem(int x, int y):ImgActorItem( x,  y)
{
    assert(ratikkaleft.load(":/img/ratikkaleft.png")); //assert that png file is loaded
    assert(ratikkaright.load(":/img/ratikkaright.png")); //assert that png file is loaded
    setOffset(0,-22);
    setScale(1);
    setPixmap(ratikkaright);
}

QPair<int,int> Ratikkaitem::move(int x, int y){
    if ( x < 0 ){
        setPixmap(ratikkaleft);
    } else if ( x > 0) {
        setPixmap(ratikkaright);
    }
    moveTo(x_+x,y_+y);
    return QPair<int,int>(x_,y_);
}
