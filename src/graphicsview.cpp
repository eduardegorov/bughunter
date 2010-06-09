#include "graphicsview.h"
#include "startscene.h"
#include "gamescene.h"


GraphicsView::GraphicsView(QWidget *parent)
    :QGraphicsView(parent)
{
    setRenderHint(QPainter::Antialiasing);
    StartScene *scene = new StartScene();

    setScene(scene);
    setSceneRect(0,0, 800, 480);
    connect(scene, SIGNAL(game(int, int)), this, SLOT(startGame(int, int)));
    connect(scene, SIGNAL(exit()), this, SLOT(close()));

    setFixedSize(sceneRect().width(), sceneRect().height());
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}


void GraphicsView::startGame(int level, int music)
{
    if(scene())
        delete scene();

    GameScene *game = new GameScene(0, level, music);
    setScene(game);
}


