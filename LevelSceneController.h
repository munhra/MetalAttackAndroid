//
// Created by Rafael M. A. da Silva on 02/01/18.
//

#ifndef PROJ_ANDROID_STUDIO_LEVELSCENECONTROLLER_H
#define PROJ_ANDROID_STUDIO_LEVELSCENECONTROLLER_H

#include "cocos2d.h"
#include "vector"
#include "EnemyParams.h"
#include "RobotBlaster.h"
#include "LevelScene.h"
#include "Level.h"
#include "map"

USING_NS_CC;
using namespace std;
using namespace cocos2d::spritebuilder;


class LevelSceneController : public Node , public CCBXReaderOwner
{
public:

    vector<int> levelsPerLevelContext;
    vector<int> firstLevelPerContext;

    int totalLevels;
    vector<Level *> *loadedLevels;
    vector<RobotBlaster *> *enemyArray;

    LevelScene *scnDelegate;

    static LevelSceneController *sharedInstance();
    virtual void loadEnemyDictFromJson();
    virtual Scene *loadLevelScene(int levelNumber, int wave);
    virtual vector<RobotBlaster *> *createEnemies(int levelNumber, int waveNumber);
    virtual void loadLevelJson();
    virtual void startEnemyMovment();

    map<string, EnemyParams *> enemyDictMutable;

private:

    static LevelSceneController *instance;


protected:
    LevelSceneController();
    ~LevelSceneController();
};

#endif //PROJ_ANDROID_STUDIO_LEVELSCENECONTROLLER_H
