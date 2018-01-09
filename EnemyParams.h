//
// Created by Rafael M. A. da Silva on 30/12/17.
//

#ifndef PROJ_ANDROID_STUDIO_ENEMYPARAMS_H
#define PROJ_ANDROID_STUDIO_ENEMYPARAMS_H

#include "cocos2d.h"
#include "vector"

USING_NS_CC;
using namespace std;

class EnemyParams //:public Ref
{
public:

    enum PowerUp {
        GUNPOWER_1,
        GUNPOWER_2,
        HEALTHPOWER,
        RADIOPOWER,
        COIN,
        NOPOWERUP
    };

    enum AtackType {
        MEELEE,
        AUTODESTRUCTION,
        WALK_SHOOT,
    };

    enum ShootStyle {
        SINGLE,
        ROTATION,
        JUMP,
    };

    string enemyName;
    float armor;
    float weaponDamage;
    float scorePoints;
    int numberOfFrames;
    double timeToReach;
    PowerUp typeOfPowerUp;
    AtackType atackType;
    Point shootStartPosition;
    ShootStyle shootStyle;
    Point upperAction;
    Point sideAction;
    Point lowerAction;
    Point fUpperAction;
    Point fSideAction;
    Point fLowerAction;
    string shootSound;
    string shootHit;
    int dropCoinLowerLevel;
    int dropCoinHighLevel;

    EnemyParams();
    ~EnemyParams();

};

#endif //PROJ_ANDROID_STUDIO_ENEMYPARAMS_H
