//
// Created by Rafael M. A. da Silva on 31/12/17.
//

#include "RobotBlaster.h"

bool RobotBlaster::init() {

    if (!Node::init()) {
        return false;
    }
    return true;
}

Enemy RobotBlaster::initwithStartPosition(Point position, double actionTime, LevelScene *delegate, EnemyParams params,
                                          EnemyPositions enemyPosition, Point shootEndPos) {

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

void RobotBlaster::doEndAttackAnim() {

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
