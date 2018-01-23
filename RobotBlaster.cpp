//
// Created by Rafael M. A. da Silva on 31/12/17.
//

#include "RobotBlaster.h"
#include "LevelScene.h"
#include "UniversalInfo.h"

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

    Vector<SpriteFrame *> animFrames;
    Vector<SpriteFrame *> attackFrames;

    Animate *attackAnim;

    initializeAnimationsCallBack();

    enemySprite = new Sprite();


    if ((defPosition == POS8) || (defPosition == POS7) || (defPosition == POS1)){

        shootZIndex = 49;

        for(int i = 1; i <= frames; i++) {
            char stringBuffer[50];

            snprintf(stringBuffer, sizeof(stringBuffer), "%s_back_%d.png",name.c_str(),i);
            string frameName = stringBuffer;
            SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName);
            frameRect = frame->getRect();
            meeleAttackPos = Vec2(params->lowerAction.x * frameRect.size.width,
                                  frameRect.size.height*params->lowerAction.y);
            divideAnimations(frame, animFrames, attackFrames, i);
        }

        if (defPosition == POS7) {
            enemySprite->setFlippedX(true);
            meeleAttackPos = Vec2(params->fLowerAction.x * frameRect.size.width,
                                  frameRect.size.height * params->fLowerAction.y);
        }

    }else if ((defPosition == POS3) || (defPosition == POS4) || (defPosition == POS5)) {

        shootZIndex = 30;

        for(int i = 1; i <= frames; i++) {
            char stringBuffer[50];

            snprintf(stringBuffer, sizeof(stringBuffer), "%s_front_%d.png",name.c_str(),i);

            //printf(stringBuffer, "%s_front_%d.png",name.c_str(),i);
            string frameName = stringBuffer;
            SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName);
            frameRect = frame->getRect();
            meeleAttackPos = Vec2(params->upperAction.x*frameRect.size.width,
                                  frameRect.size.height*params->upperAction.y);
            divideAnimations(frame, animFrames, attackFrames, i);
        }

        if (defPosition == POS5) {
            enemySprite->setFlippedX(true);
            meeleAttackPos = Vec2(params->fUpperAction.x*frameRect.size.width,
                                  frameRect.size.height*params->fUpperAction.y);
        }

    }else{

        shootZIndex = 30;

        for(int i = 1; i <= frames; i++) {
            char stringBuffer[50];
            snprintf(stringBuffer, sizeof(stringBuffer), "%s_left_%d.png",name.c_str(),i);
            //printf(stringBuffer, "%s_left_%d.png",name.c_str(),i);
            string frameName = stringBuffer;
            SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName);
            frameRect = frame->getRect();
            meeleAttackPos = Vec2(params->sideAction.x*frameRect.size.width,
                                  frameRect.size.height*params->sideAction.y);
            divideAnimations(frame, animFrames, attackFrames, i);
        }

        if (defPosition == POS2) {
            enemySprite->setFlippedX(false);
            meeleAttackPos = Vec2(params->fSideAction.x*frameRect.size.width,
                                  frameRect.size.height*params->fSideAction.y);
        }

    }

    enemySprite->setScaleX(0.25);
    enemySprite->setScaleY(0.25);

    Animation *animation = Animation::createWithSpriteFrames(animFrames, 0.09, 0);
    Animation *attackAnimation = Animation::createWithSpriteFrames(attackFrames, 0.09, 0);

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
                                    Vector<SpriteFrame *> animFrames,
                                    Vector<SpriteFrame *> attackFrames,
                                    int frameindex) {

    if (attackType == EnemyParams::AUTODESTRUCTION ){

        if (frameindex <= 2) {
            animFrames.pushBack(frame);
        }else{
            attackFrames.pushBack(frame);
        }
    }else{
        switch(frameindex) {
            case 1:
                animFrames.pushBack(frame);
                break;
            case 2:
                animFrames.pushBack(frame);
                attackFrames.pushBack(frame);
                break;
            case 3:
                attackFrames.pushBack(frame);
                break;
            default:
                break;
        }
    }
}

void RobotBlaster::startMovement() {

    LevelScene *sceneDelegate = (LevelScene *) delegate;

    if (sceneDelegate->isGameOver()) {
        sceneDelegate->addEnemySprite(this);

        Point bandRelPosition = sceneDelegate->bandSprite->getPosition();
        Point bassRelPos = sceneDelegate->bandSprite->bass->getPosition();
        Point leadRelPos = sceneDelegate->bandSprite->leadGuitar->getPosition();

        Size screnSize = Director::getInstance()->getWinSize();
        Point bandSprtAbsPos = Vec2(bandRelPosition.x * screnSize.width,
                                    bandRelPosition.y * screnSize.height);

        Vec2 bassPosition =  bassRelPos + bandSprtAbsPos;
        Vec2 leadGuitarPosition = leadRelPos + bandSprtAbsPos;

        if (definedPosition == POS2){
            enemySprite->runAction(MoveTo::create(timeToReach, leadGuitarPosition));
        }else if (definedPosition == POS6){
            enemySprite->runAction(MoveTo::create(timeToReach, bassPosition));
        }else{
            enemySprite->runAction(MoveTo::create(timeToReach, UniversalInfo::sharedInstance()->screenCenter()));
        }

        isInMovement = true;
    }
}

void RobotBlaster::restartMovement() {

}
/*
void RobotBlaster::update(float delta) {
    //call super from update
    Enemy::update(delta);
    (Director::getInstance()->isPaused() == false);
    //if (([[CCDirector sharedDirector]isPaused] == NO) && (gameState != GAME_OVER)){

    //}
}*/

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
