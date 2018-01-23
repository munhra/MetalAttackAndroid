//
// Created by Rafael M. A. da Silva on 24/12/17.
//

#ifndef PROJ_ANDROID_STUDIO_LEVELSCENE_H
#define PROJ_ANDROID_STUDIO_LEVELSCENE_H

#include "cocos2d.h"
#include "Enemy.h"
#include "vector"
#include "UniversalInfo.h"
#include <editor-support/spritebuilder/CCBXNodeLoader.h>
#include <editor-support/spritebuilder/SpriteBuilder.h>
#include <editor-support/spritebuilder/CCBXNodeLoader.h>

USING_NS_CC;
using namespace cocos2d::spritebuilder;

class LevelScene : public Node, public CCBXReaderOwner
{
public:

    virtual bool init();
    CREATE_FUNC(LevelScene);


    Point endTouch;
    vector<Enemy *> *activeEnemies;
    vector<Enemy *> *killedEnemies;
    float rotationAngle;
    bool moved;
    int waveEnemiesLeft;
    int levelEnemiesLeft;

    UniversalInfo::GameState gameState;

    int levelNumber;
    int waveNumber;
    int scoreCount;
    int totalLevel;
    int levelCoins;

    Touch *playerTouch;
    Level *currentLevel;

    Sprite *enemyPOS1;
    Sprite *enemyPOS2;
    Sprite *enemyPOS3;
    Sprite *enemyPOS4;
    Sprite *enemyPOS5;
    Sprite *enemyPOS6;
    Sprite *enemyPOS7;
    Sprite *enemyPOS8;



    int coinMultiplier;
    bool noCoolDown;


    BandSprite *bandSprite;


    int levelContext;

    virtual bool isGameOver();
    virtual void addEnemySprite(Enemy *enemy);
    void update(float) override;
    void onEnter() override;



private:

    virtual void activateEnemies();
    virtual void doLevelEnterAnimation();

protected:
    LevelScene();
    ~LevelScene();
};

#endif //PROJ_ANDROID_STUDIO_LEVELSCENE_H
