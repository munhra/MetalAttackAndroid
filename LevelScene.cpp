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

    this->scheduleUpdate();
    gameState = UniversalInfo::GAME_STARTED;
    waveEnemiesLeft = 0;
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
    Node::onEnter();
    this->doLevelEnterAnimation();
}

void LevelScene::doLevelEnterAnimation() {
    activateEnemies();
}

void LevelScene::update(float delta) {

    if ((waveEnemiesLeft == 0) && (gameState == UniversalInfo::GAME_STARTED)) {
        doWaveClearedAnimation(waveNumber);
    }



    //if ((Director::getInstance()->isPaused() == false) && (gameState != UniversalInfo::GAME_OVER)) {

    //}else if ((waveEnemiesLeft == 0) && (gameState == UniversalInfo::GAME_STARTED)){
        //doWaveClearedAnimation(waveNumber);
    //}else{

    //}
}

void LevelScene::doWaveClearedAnimation(int waveNumberCleared) {
    releaseNewWave();
}

void LevelScene::releaseNewWave() {
    LevelSceneController *lvcontroller = LevelSceneController::sharedInstance();
    currentLevel = lvcontroller->loadLevelWave(levelNumber, waveNumber, this);
    waveEnemiesLeft = currentLevel->waves.at(waveNumber);
    gameState = UniversalInfo::GAME_STARTED;
}


LevelScene::LevelScene() {

}

LevelScene::~LevelScene() {

}