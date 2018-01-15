//
// Created by Rafael M. A. da Silva on 31/12/17.
//

#include "RobotBlaster.h"
#include "LevelScene.h"

bool RobotBlaster::init() {

    if (!Node::init()) {
        return false;
    }
    return true;
}

Enemy *RobotBlaster::initwithStartPosition(Point position, double actionTime, void *scnDelegate, EnemyParams *params,
                                          EnemyPositions defPosition, Point shootEndPos) {
    
    Enemy *robotBlaster = new Enemy();
    Rect frameRect;
    Point meeleAttackPos;
    activeShoots = new vector<Node *>;
    shootPosition = shootEndPos;
    initialPosition = position;
    armor = params->armor;
    weaponDamage = params->weaponDamage;
    scorePoints = params->scorePoints;
    timeToReach = params->timeToReach;
    typeOfPowerUp = params->typeOfPowerUp;
    name = params->enemyName;
    frames = params->numberOfFrames;
    definedPosition = defPosition;
    attackType = params->atackType;
    isMeeleAttacking = false;
    isInMovement = false;
    shootStyle = params->shootStyle;
    shootStartPosition = params->shootStartPosition;
    timeToStart = actionTime;
    dropCoinLowerLevel = params->dropCoinLowerLevel;
    dropCoinHighLevel = params->dropCoinHighLevel;

    Vector<AnimationFrame *> animFrames;
    Vector<AnimationFrame *> attackFrames;

    Animate *attackAnim;

    initializeAnimationsCallBack();

    enemySprite = new Sprite();


    if ((defPosition == POS8) || (defPosition == POS7) || (defPosition == POS1)){
        /******** Missing Codee *********/
    }else if ((defPosition == POS3) || (defPosition == POS4) || (defPosition == POS5)) {
        /******** Missing Codee *********/
    }else{
        /******** Missing Codee *********/
    }

    enemySprite->setScaleX(0.25);
    enemySprite->setScaleY(0.25);

    Animation *animation = Animation::create(animFrames, 0.09, 0);
    Animation *attackAnimation = Animation::create(attackFrames, 0.09, 0);

    enemySprite->setPosition(position);
    enemyAction = RepeatForever::create(Animate::create(animation));

    if (attackType == EnemyParams::MEELEE) {
        attackAnim = Animate::create(attackAnimation);
        Sequence::create(attackAnim, doEndMeeleAttackAnim, nullptr);
    }else{
        attackAnim = Animate::create(attackAnimation);
        Sequence::create(attackAnim, doEndAttackAnim, nullptr);
    }

    enemySprite->runAction(enemyAction);
    delegate = scnDelegate;

    meeleAttackRect = Sprite::create("testsprt.png");
    meeleAttackRect->setScale(0.25);
    meeleAttackRect->setPosition(meeleAttackPos);
    meeleAttackRect->setName("meeleAttackRect");
    meeleAttackRect->setOpacity(0);
    enemySprite->addChild(meeleAttackRect);

    if (defPosition == POS2 || defPosition == POS6) {
        shootInterval = 0.8 + rand() % 11 * 0.1;
    }else{
        shootInterval = 1.1 + rand() % 3 * 0.1;
    }

    enemyUpdateSeconds = 0;


    return robotBlaster;
}

void RobotBlaster::initializeAnimationsCallBack() {

    doEndMeeleAttackAnim = CallFunc::create([](){

    });


    doEndAttackAnim = CallFunc::create([](){

    });

}




void RobotBlaster::divideAnimations(SpriteFrame *frame,
                                    std::vector<SpriteFrame> *animFrames,
                                    std::vector<SpriteFrame> *attackFrames,
                                    int frameidex) {

}

void RobotBlaster::startMovement() {


}

void RobotBlaster::restartMovement() {

}

void RobotBlaster::update(float delta) {

}

void RobotBlaster::performGeneralHitAnimation(Point hitPoint) {

}

void RobotBlaster::meeleAttack(BandSprite *bandsprite,
                         BandSprite::BandComponents components,
                         Rect hitrect) {

}

void RobotBlaster::performAutoDestruction() {

}

void RobotBlaster::performDeath() {

}

void RobotBlaster::playEnemyDieSound() {

}

Point RobotBlaster::calculateBandGuysPosition() {

}

void RobotBlaster::fireWeapon() {

}

float RobotBlaster::autoDestruction() {

}

void RobotBlaster::removeEnemyFire(Node *node) {

}

int RobotBlaster::receiveHeroShoot(float damage, bool killNow, Rect shootRect) {


}

RobotBlaster::RobotBlaster() {

}

RobotBlaster::~RobotBlaster() {

}
