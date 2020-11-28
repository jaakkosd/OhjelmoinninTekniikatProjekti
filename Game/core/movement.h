#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <QObject>
#include <QKeyEvent>
namespace Game {
/**
 * @brief The Movement class is used for capturing keyboard and mouse events and providing movement relevent info for other classes.
 */
class Movement : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Movement, default constructor
     * @param parent QObject
     */
    explicit Movement(QObject *parent = nullptr);
signals:
    /**
     * @brief keyPressed is emitted when a relevant keypress or release happends.
     * @param keys emits the internal list of keys currently pressed
     */
    void keyPressed(QSet<int> keys);
protected:
    /**
     * @brief eventFilter is the actual filter that handles the relevent events like mouse scrolling and keyboard asdw and arrow keys.
     * @param obj sender QObject
     * @param event QEvent of occured event
     * @return
     */
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    QSet<int> pressedKeys;
};


}

#endif // MOVEMENT_H
