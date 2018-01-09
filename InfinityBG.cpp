//
// Created by Rafael M. A. da Silva on 21/12/17.
//

#include "InfinityBG.h"

bool InfinityBG::init() {

    if (!Node::init()) {
        return false;
    }
    return true;
}

InfinityBG::InfinityBG() {

    CCBX_SIMPLE_MEMBER_VARIABLE(visibleBG);
    CCBX_SIMPLE_MEMBER_VARIABLE(leftBG);
    CCBX_SIMPLE_MEMBER_VARIABLE(rightBG);
    CCBX_SIMPLE_MEMBER_VARIABLE(upperBG);
    CCBX_SIMPLE_MEMBER_VARIABLE(lowerBG);
    CCBX_SIMPLE_MEMBER_VARIABLE(upperRightBG);
    CCBX_SIMPLE_MEMBER_VARIABLE(lowerLeftBG);
    CCBX_SIMPLE_MEMBER_VARIABLE(fixedBG);

    this->scheduleUpdate();
}

InfinityBG::~InfinityBG() {

}

void InfinityBG::moveBgToUpperRight() {
    /*
    if ((_lowerLeftBG->getPosition().x >= 0.5) && (_lowerLeftBG->getPosition().y >= 0.5)) {
        Sprite *bgaux = _visibleBG;
        _visibleBG = _lowerLeftBG;
        _lowerLeftBG = bgaux;
        _visibleBG->setPosition(0.5, 0.5);
        _lowerLeftBG->setPosition(-0.776,-0.65);
        _leftBG->setPosition(-0.776,0.5);
        _lowerBG->setPosition(0.5,-0.65);
    }

    _visibleBG->setPosition(ccpAdd(_visibleBG->getPosition(),ccp(0.01001, 0.009005)));
    _lowerLeftBG->setPosition(ccpAdd(_lowerLeftBG->getPosition(), ccp(0.01001, 0.009005)));
    _leftBG->setPosition(ccpAdd(_leftBG->getPosition(), ccp(0.01001, 0.009005)));
    _lowerBG->setPosition(ccpAdd(_lowerBG->getPosition(), ccp(0.01001, 0.009005)));*/

}

void InfinityBG::update(float delta) {
    this->moveBgToUpperRight();
}
