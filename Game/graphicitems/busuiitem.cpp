#include "graphicitems/busuiitem.h"
namespace Game {
BusUiItem::BusUiItem(int x, int y):ImgActorItem( x,  y)
{
    assert(pixmapLeft_.load(":/img/resources/nysse_left.png")); //assert that png file is loaded
    assert(pixmapRight_.load(":/img/resources/nysse_right.png")); //assert that png file is loaded
    setOffset(-18,-9);
    setScale(2);

    //QPixmap pixmapItems = pixmapItem.scaled(QSize(512,512),  Qt::KeepAspectRatio);
    setPixmap(pixmapLeft_);

}

void BusUiItem::moveTo(int x,int y)
{
    // the idea here is that when the bus is going left it should show the picture of a bus going left
    // now it's not working
    // DOTO: Jaakko FIX THIS
    // The cordinate system is using a grid so this looks funky, choppy and bad. Maybe implement some sort of (P)I(D) controller :)
    if(x==x_ && y==y_){
        return;
    }
    float angle = -qRadiansToDegrees(qAtan2(x-x_,y-y_));
    float dangle = angle-angle_;
    if(dangle != 0){
        if(dangle > 180){
            dangle -= 360;
        }else if(dangle < -180){
            dangle += 360;
        }
        angle_ -= dangle/25;
        bool change = false;
        if((angle_ >0 &&  angle_< 180) || angle_< -180 ){
            change = true;
            setPixmap(pixmapRight_);
        }else{
            setPixmap(pixmapLeft_);
        }
        setRotation(angle_+180*change+90);
    }
    setCoords(x,y);
}
}
