#include "graphicitems/stopuiitem.h"
namespace Game {
StopUiItem::StopUiItem(int x,int y):ImgActorItem(x,y)
{
    assert(pixmap_.load(":/img/resources/stop.png")); //assert that png file is loaded
    setOffset(-4,-84);
    setScale(0.3);
    setPixmap(pixmap_);

}
}
