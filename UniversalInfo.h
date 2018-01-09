//
// Created by Rafael M. A. da Silva on 09/01/18.
//

#ifndef PROJ_ANDROID_STUDIO_UNIVERSALINFO_H
#define PROJ_ANDROID_STUDIO_UNIVERSALINFO_H

#include "cocos2d.h"
#include "vector"

USING_NS_CC;
using namespace std;

class UniversalInfo {
public:

    static UniversalInfo *sharedInstance();

    enum GameState {GAME_STARTED, WAVE_CLEARED, LEVEL_CLEARED,
        GAME_OVER, GAME_PAUSED};

    enum DeviceType {IPHONE_5, IPHONE_4_OR_LESS, IPHONE_6, IPHONE_6P, IPAD, IPAD_RETINA};

    enum nextScence {MENU, NEXT_LEVEL, STORE, REPLAY};

    bool gotoStore;
    bool gotoNextLevel;

    bool isDeviceIpad;
    Point screenCenter;

    Point enemyPosition1;
    Point enemyPosition2;
    Point enemyPosition3;
    Point enemyPosition4;
    Point enemyPosition5;
    Point enemyPosition6;
    Point enemyPosition7;
    Point enemyPosition8;

    Point calculateAnchorPoint(Point anchorPos, int w, int h);
    DeviceType getDeviceType();
    string addZeroesToNumber(string *number, int zeroes);
    Sprite *getSpriteWithCoinAnimation();

private:

    static UniversalInfo *instance;

protected:
    UniversalInfo();
    ~UniversalInfo();


};


#endif //PROJ_ANDROID_STUDIO_UNIVERSALINFO_H
