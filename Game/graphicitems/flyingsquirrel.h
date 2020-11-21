#ifndef FLYINGSQUIRREL_H
#define FLYINGSQUIRREL_H

#include "imgactoritem.h"

namespace Game {
class FlyingSquirrel : public ImgActorItem
{
public:
    FlyingSquirrel(int x=-30, int y=-30);
    int giveX();
    int giveY();

private:
    QPixmap squirrelUp;
    int x_;
};
}

#endif // FLYINGSQUIRREL_H
