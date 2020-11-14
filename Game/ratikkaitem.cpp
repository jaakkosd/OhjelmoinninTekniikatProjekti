#include "ratikkaitem.h"

ratikkaitem::ratikkaitem(int x, int y):imgActorItem( x,  y)
{
assert(ratikka.load(":/img/ratikka.png")); //assert that png file is loaded
setOffset(-18,-9);
setScale(1);
}

void ratikkaitem::move(int x, int y)
{

}
