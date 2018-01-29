//
// Created by Rafael M. A. da Silva on 09/01/18.
//

#include "UniversalInfo.h"

UniversalInfo *UniversalInfo::instance = 0;

UniversalInfo *UniversalInfo::sharedInstance() {

    if (!UniversalInfo::instance) {
        UniversalInfo::instance = new UniversalInfo();
        UniversalInfo::instance->screenSize = Vec2(Director::getInstance()->getVisibleSize().width
                ,Director::getInstance()->getVisibleSize().height);
    }
    return UniversalInfo::instance;
}

Sprite *UniversalInfo::getSpriteWithCoinAnimation() {

}

string UniversalInfo::addZeroesToNumber(string *number, int zeroes) {

}

UniversalInfo::DeviceType UniversalInfo::getDeviceType() {

}

Point UniversalInfo::calculateAnchorPoint(Point anchorPos, int w, int h) {

}


bool UniversalInfo::isDeviceIpad() {

}

Point UniversalInfo::screenCenter() {
    return Vec2(Director::getInstance()->getWinSize().width * 0.5,
                Director::getInstance()->getWinSize().height * 0.5);
}

Point UniversalInfo::enemyPosition1() {
    return screenSize *= -screenHideProportion;
}

Point UniversalInfo::enemyPosition2() {
    return Vec2(- screenSize.x * screenHideProportion, screenSize.y * 0.5);
}

Point UniversalInfo::enemyPosition3() {
    return Vec2(-screenSize.x * screenHideProportion , screenSize.y *(1+screenHideProportion));
}

Point UniversalInfo::enemyPosition4() {
    return Vec2(screenSize.x * 0.5, screenSize.y*(1+screenHideProportion));
}

Point UniversalInfo::enemyPosition5() {
    return Vec2(screenSize.x * (1+screenHideProportion), screenSize.y*(1+screenHideProportion));

}

Point UniversalInfo::enemyPosition6() {
    return Vec2(screenSize.x * (1+screenHideProportion), screenSize.y * 0.5);
}

Point UniversalInfo::enemyPosition7() {
    return Vec2(screenSize.x * (1+screenHideProportion), -screenSize.y * screenHideProportion);
}

Point UniversalInfo::enemyPosition8() {
    return Vec2(screenSize.x * 0.5, -screenSize.y * screenHideProportion);
}


UniversalInfo::UniversalInfo() {

}

UniversalInfo::~UniversalInfo() {

}