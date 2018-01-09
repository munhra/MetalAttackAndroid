//
// Created by Rafael M. A. da Silva on 09/01/18.
//

#include "UniversalInfo.h"

UniversalInfo *UniversalInfo::instance = 0;

UniversalInfo *UniversalInfo::sharedInstance() {

    if (!UniversalInfo::instance) {
        UniversalInfo::instance = new UniversalInfo();
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

UniversalInfo::UniversalInfo() {

}

UniversalInfo::~UniversalInfo() {

}