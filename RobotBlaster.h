//
// Created by Rafael M. A. da Silva on 31/12/17.
//

#ifndef PROJ_ANDROID_STUDIO_ROBOTBLASTER_H
#define PROJ_ANDROID_STUDIO_ROBOTBLASTER_H

#include "cocos2d.h"
#include "Enemy.h"
#include "vector"

USING_NS_CC;

class RobotBlaster : public Enemy
{
public:

    virtual bool init();
    CREATE_FUNC(RobotBlaster);

    virtual Enemy initwithStartPosition(Point position,
                                        double actionTime,
                                        LevelScene *delegate,
                                        EnemyParams params,
                                        EnemyPositions enemyPosition,
                                        Point shootEndPos) override;

    virtual void restartMovement() override;
    virtual void startMovement() override;

    virtual void meeleAttack(BandSprite *bandsprite,
                             BandSprite::BandComponents components,
                             Rect hitrect) override;

    virtual void performAutoDestruction() override;
    virtual void performDeath() override;
    virtual void fireWeapon() override;
    virtual float autoDestruction() override;
    virtual int receiveHeroShoot(float damage, bool killNow, Rect shootRect) override ;


    void update(float) override;

private:

    virtual void divideAnimations(SpriteFrame *frame,
                                  std::vector<SpriteFrame> *animFrames,
                                  std::vector<SpriteFrame> *attackFrames,
                                  int frameidex);


    virtual void performGeneralHitAnimation(Point hitPoint);
    virtual void playEnemyDieSound();
    virtual void doEndAttackAnim();
    virtual Point calculateBandGuysPosition();
    virtual void removeEnemyFire(Node *node);



protected:

    RobotBlaster();
    ~RobotBlaster();
};


#endif //PROJ_ANDROID_STUDIO_ROBOTBLASTER_H
