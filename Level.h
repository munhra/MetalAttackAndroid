//
// Created by Rafael M. A. da Silva on 30/12/17.
//

#ifndef PROJ_ANDROID_STUDIO_LEVEL_H
#define PROJ_ANDROID_STUDIO_LEVEL_H

#include "cocos2d.h"
#include "vector"

USING_NS_CC;
using namespace std;

class Level
{
public:

    vector<int> waves;
    vector<string> avaliableEnemies;
    int totalLevelEnemies;
    int totalWavesPerLevel;
    int levelContext;
    int levelNumberName;

    Level();
    ~Level();

protected:


};


#endif //PROJ_ANDROID_STUDIO_LEVEL_H
