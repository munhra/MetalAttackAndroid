//
// Created by Rafael M. A. da Silva on 23/12/17.
//

#include "MainScene.h"
#include "LevelScene.h"

bool MainScene::init() {

    if (!Node::init()) {
        return false;
    }
    return true;
}

MainScene::MainScene() {

    CCBX_SIMPLE_MEMBER_VARIABLE(handButton);
    CCBX_SIMPLE_SELECTOR_CLICK(doRight);
    CCBX_SIMPLE_SELECTOR_CLICK(doNewGame);

}

void MainScene::doNewGame(Ref *target) {
    CCLOG("doNewGame");
    CCBXReader *reader = CCBXReader::createFromFile("Levels/Level1.ccbi");
    Node *node = reader->createNode(this, SceneScaleType::MINSCALE);
    Scene *scene = Scene::create();
    scene->addChild(node);
    Director::getInstance()->replaceScene(scene);
    //Director::replaceScene(scene);
}

void MainScene::doRight(Ref *target) {

    CCLOG("doRight");
    CCBAnimationManager *animationManager = CCBAnimationManager::fromNode(this);

    if (rightMoved) {
        rightMoved = false;
        animationManager->runAnimationsForSequenceNamed("MoveMenuLeft",NULL);
    }else{
        animationManager->runAnimationsForSequenceNamed("MoveMenuRight",NULL);

        rightMoved = true;
    }

}

MainScene::~MainScene() {

}

