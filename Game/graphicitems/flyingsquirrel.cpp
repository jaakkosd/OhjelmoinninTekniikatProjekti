#include "flyingsquirrel.h"

namespace Game {

FlyingSquirrel::FlyingSquirrel(int x, int y):ImgActorItem(x,y)
{
    assert(squirrelUp.load(":/img/resources/liitoorava.png")); //assert that png file is loaded
    setOffset(-30,-30);
    setScale(1);
    setPixmap(squirrelUp);
}
}
