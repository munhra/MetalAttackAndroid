//
// Created by Rafael M. A. da Silva on 30/12/17.
//

#ifndef PROJ_ANDROID_STUDIO_ENEMY_H
#define PROJ_ANDROID_STUDIO_ENEMY_H

#include "cocos2d.h"
#include "EnemyParams.h"
#include "BandSprite.h"
#include "vector"
//#include "LevelScene.h"
#include "Level.h"

USING_NS_CC;
using namespace std;


class Enemy : public Node
{
public:


     enum EnemyPositions {
        POS1,
        POS2,
        POS3,
        POS4,
        POS5,
        POS6,
        POS7,
        POS8
     };

    // how many points left from the armor.
    float armor;
    // delay to enter in action in seconds defined by the level json file.
    float delayToAction;
    // weapon damage of the robot
    float weaponDamage;
    // time to reach hero seconds
    double timeToReach;
    // type of power up
    EnemyParams::PowerUp powerupType;
    double timeToStart;

    Point initialPosition;
    //position to make the action of shoot cross the screen
    Point shootPosition;

    Sprite *enemySprite;
    Sprite *shootSprite;
    Action *enemyAction;
    Action *enemyAttack;
    void *delegate;
    bool removeObject;
    ParticleSystem *enemyParticle;
    vector<Enemy *> activeEnemies;



    int scorePoints;
    string name;
    int frames;

    EnemyParams::PowerUp typeOfPowerUp;
    vector<Node *> activeShoots;


    EnemyPositions definedPosition;
    EnemyParams::AtackType attackType;

    bool isMeeleAttacking;
    bool isInMovement;


    Point shootStartPosition;
    int shootZIndex;
    Timer *enemyShootTimer;
    Sprite *meeleAttackRect;
    int dropCoinLowerLevel;
    int dropCoinHighLevel;
    BandSprite *bandsprite;
    Rect hitRect;
    BandSprite::BandComponents hitComponent;
    string *shootSound;
    string *shootHit;
    double shootInterval;
    double enemyUpdateSeconds;


    virtual bool init();
    virtual void startMovement();
    virtual void restartMovement();

    virtual Enemy initwithStartPosition(Point position,
                                        double actionTime,
                                        void *delegate,
                                        EnemyParams params,
                                        EnemyPositions enemyPosition,
                                        Point shootEndPos);
    virtual int receiveHeroShoot(float damage, bool killNow, Rect shootRect);

    virtual void performDeath();
    virtual void performAutoDestruction();
    virtual void fireWeapon();
    virtual float autoDestruction();


    virtual void meeleAttack(BandSprite *bandsprite,
                             BandSprite::BandComponents components,
                             Rect hitrect);

    virtual Rect meeleRect();

    CREATE_FUNC(Enemy);

    /*
     * How to implement this ??? it can be an interface ? check it latter?
     *
     * @protocol spriteManager <NSObject>
        -(void)removeEnemySprite:(CCSprite *)enemySprite;
        -(void)addEnemySprite:(Enemy *)enemy;
        -(BOOL)isGameOver;
        @end
     *
     */

protected:
    Enemy();
    ~Enemy();
};


#endif //PROJ_ANDROID_STUDIO_ENEMY_H
