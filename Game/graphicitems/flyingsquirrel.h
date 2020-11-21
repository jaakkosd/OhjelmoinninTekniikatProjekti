#ifndef FLYINGSQUIRREL_H
#define FLYINGSQUIRREL_H

#include "imgactoritem.h"

namespace Game {
class FlyingSquirrel : public ImgActorItem
{
public:
    FlyingSquirrel(int x=0, int y=0);

private:
    QPixmap squirrelUp;
};
}

#endif // FLYINGSQUIRREL_H
