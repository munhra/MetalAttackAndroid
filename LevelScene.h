//
// Created by Rafael M. A. da Silva on 24/12/17.
//

#ifndef PROJ_ANDROID_STUDIO_LEVELSCENE_H
#define PROJ_ANDROID_STUDIO_LEVELSCENE_H

#include "cocos2d.h"
#include "Enemy.h"
#include "vector"
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



    /*
     * CGPoint beginTouch;
    CGPoint endTouch;
    NSMutableArray *activeEnemies;
    NSMutableArray *killedEnemies;
    float rotationAngle;
    BOOL moved;
    int waveEnemiesLeft;
    int levelEnemiesLeft;
    GameState gameState;
    int levelNumber;
    int waveNumber;
    int scoreCount;
    int totalLevel;
    int levelCoins;
    CCTouch *playerTouch;
    Level *currentLevel;

    CCSprite *enemyPOS1;
    CCSprite *enemyPOS2;
    CCSprite *enemyPOS3;
    CCSprite *enemyPOS4;
    CCSprite *enemyPOS5;
    CCSprite *enemyPOS6;
    CCSprite *enemyPOS7;
    CCSprite *enemyPOS8;

    NSMutableArray *coinAnimFrames;

    //items effect
    int coinMultiplier;
    BOOL noCoolDown;

    //InvulnerabilityPowerUP *invulnerabilityPowerUP;
    RevivalPowerUp *revivalPowerUp;
    CoinMultiplierPowerUp *coinMultiplierPowerUp;
    HealthPowerUp *healthPowerUp;

    WaveClearedBanner *waveClearedSprite;

    int levelContext;

     */

protected:
    LevelScene();
    ~LevelScene();
};

#endif //PROJ_ANDROID_STUDIO_LEVELSCENE_H
