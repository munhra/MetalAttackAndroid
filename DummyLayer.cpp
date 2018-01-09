//
// Created by Rafael M. A. da Silva on 21/12/17.
//

#include "DummyLayer.h"

bool DummyLayer::init() {

    if (!Node::init()) {
        return false;
    }

    return true;
}

void DummyLayer::update(float delta) {
    auto position = this->_logo2->getPosition();
    this->_logo2->setPosition(position.x + 1, position.y +1);
}

DummyLayer::DummyLayer() {
    this->_logo2 = NULL;

    //CCBX_MEMBERVARIABLEASSIGNER_GLUE(this, "logo", CCSprite *, this->logo);
    CCBX_SIMPLE_MEMBER_VARIABLE(logo2);


    this->scheduleUpdate();
}

DummyLayer::~DummyLayer() {

}