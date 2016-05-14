#include "drum2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "taiko2.h"
#include <typeinfo>
#include "game.h"

 // there is an external global object called game
extern Game *game;

Drum2::Drum2(QGraphicsItem *parent)
{
    // set the picture
    setPixmap(QPixmap(":/g+.png"));
    setScale(1);

    // make/connect a timer to check() if drum on taiko every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(check()));

    // start the timer
    timer->start(50);
}

void Drum2::check()
{
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Taiko2)){
            // increase the score
            game->score->increase();

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
        else {
            scene()->removeItem(this);
            delete this;
        return;
        }
    }

}
