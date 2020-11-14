#include "ratikkaitem.h"

Ratikkaitem::Ratikkaitem(int x, int y):ImgActorItem( x,  y)
{
assert(ratikka.load(":/img/ratikka.png")); //assert that png file is loaded
setOffset(-18,-9);
setScale(1);
setPixmap(ratikka);
}
