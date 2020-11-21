#include "flyingsquirrel.h"

namespace Game {

FlyingSquirrel::FlyingSquirrel(int x, int y):ImgActorItem(x,y)
{
    assert(squirrelUp.load(":/img/resources/liitoorava.png")); //assert that png file is loaded
    setOffset(-30,-30);
    setScale(1);
    setPixmap(squirrelUp);
    setRotation(180);
    //x_ = rand() % 1065;
}

QPair<int,int> FlyingSquirrel::move(int x, int y){
    moveTo(x_+x,y_+y);
    return QPair<int,int>(x_,y_);
}

}
