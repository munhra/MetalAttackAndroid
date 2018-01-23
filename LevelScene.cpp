//
// Created by Rafael M. A. da Silva on 24/12/17.
//

#include "LevelScene.h"
#include "UniversalInfo.h"
#include "LevelSceneController.h"

bool LevelScene::init() {

    if (!Node::init()) {
        return false;
    }

    return true;
}

bool LevelScene::isGameOver() {

    if (gameState == UniversalInfo::GAME_OVER) {
        return true;
    }else{
        return false;
    }
}

void LevelScene::addEnemySprite(Enemy *enemy) {

}

void  LevelScene::activateEnemies() {

    LevelSceneController *lvcontroller = LevelSceneController::sharedInstance();
    lvcontroller->startEnemyMovment();

}

void LevelScene::onEnter() {

    this->doLevelEnterAnimation();

}

void LevelScene::doLevelEnterAnimation() {
    activateEnemies();
}

void LevelScene::update(float) {

}

LevelScene::LevelScene() {

}

LevelScene::~LevelScene() {

}