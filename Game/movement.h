#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <QObject>
#include <QKeyEvent>
namespace Game {
class Movement : public QObject
{
    Q_OBJECT
public:
    explicit Movement(QObject *parent = nullptr);
signals:
    void keyPressed(QSet<int> keys);
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    QSet<int> pressedKeys;
};


}

#endif // MOVEMENT_H
