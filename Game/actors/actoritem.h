#ifndef ACTORITEM_H
#define ACTORITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
namespace Game {

const int WIDTH = 5;
const int HEIGHT = 5;


class ActorItem : public QGraphicsItem
{
public:
    ActorItem(int x, int y, int type = 0);
    virtual ~ActorItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setCoord(int x, int y);
    void move(int x, int y);

private:
    int x_;
    int y_;
    int type_;
};
}
#endif // ACTORITEM_H
