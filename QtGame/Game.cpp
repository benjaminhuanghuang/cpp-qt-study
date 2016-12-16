#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>

#include "Bullet.h"
#include "Game.h"

void Game::Game(QWidget *parent)
{
    // Create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    // 
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    // create player
    player = new Player();
    player->setRect(0, 0, 100,100);
    pylayer->setPos(400,500);
    player->setFlag(QGrapyicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    // Spawn enemies
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    show();
}