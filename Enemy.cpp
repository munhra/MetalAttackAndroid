//
// Created by Rafael M. A. da Silva on 30/12/17.
//

#include "Enemy.h"

bool Enemy::init() {

    if (!Node::init()) {
        return false;
    }
    return true;
}

Enemy::Enemy() {

}

Enemy::~Enemy() {

}


Enemy *Enemy::initwithStartPosition(Point position,
                            double actionTime,
                            void *delegate,
                            EnemyParams *params,
                            EnemyPositions defPosition,
                            Point shootEndPos) {



}


void Enemy::startMovement() {

}

void Enemy::restartMovement() {

}

int Enemy::receiveHeroShoot(float damage, bool killNow, Rect shootRect) {

}

void Enemy::performDeath() {

}

void Enemy::performAutoDestruction() {

}

void Enemy::fireWeapon() {

}

float Enemy::autoDestruction() {

}

void Enemy::meeleAttack(BandSprite *bandsprite, BandSprite::BandComponents components, Rect hitrect) {

}

Rect Enemy::meeleRect() {

}






