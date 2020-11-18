#ifndef RATIKKAITEM_H
#define RATIKKAITEM_H

#include "imgactoritem.h"
namespace Game {
class Ratikkaitem : public ImgActorItem
{
public:
    Ratikkaitem(int x=0, int y=0);
    QPair<int,int> move(int x, int y);
private:
    QPixmap ratikkaleft;
    QPixmap ratikkaright;
};
}
#endif // RATIKKAITEM_H
