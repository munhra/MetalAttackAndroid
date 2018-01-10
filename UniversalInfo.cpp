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

}

Point UniversalInfo::enemyPosition1() {

    

}

Point UniversalInfo::enemyPosition2() {


}

Point UniversalInfo::enemyPosition3() {


}

Point UniversalInfo::enemyPosition4() {


}

Point UniversalInfo::enemyPosition5() {


}

Point UniversalInfo::enemyPosition6() {


}

Point UniversalInfo::enemyPosition7() {


}

Point UniversalInfo::enemyPosition8() {


}


UniversalInfo::UniversalInfo() {

}

UniversalInfo::~UniversalInfo() {

}