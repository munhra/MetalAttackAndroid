//
// Created by Rafael M. A. da Silva on 02/01/18.
//

#ifndef PROJ_ANDROID_STUDIO_LEVELSCENECONTROLLER_H
#define PROJ_ANDROID_STUDIO_LEVELSCENECONTROLLER_H

#include <json/document.h>
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
    virtual vector<RobotBlaster *> *createEnemies(int levelNumber, int wave);
    virtual void loadLevelJson();
    virtual void startEnemyMovment();
    virtual Level *loadLevelWave(int levelNumber, int wave, LevelScene * scnDelegate);

    map<string, EnemyParams *> *enemyDictMutable;
    void onEnter() override;

private:

    static LevelSceneController *instance;
    virtual EnemyParams::AtackType getEnemyAtackType(string isAutoDestruction, string isMeele);
    virtual EnemyParams::ShootStyle convertShootStyle(int style);

protected:
    LevelSceneController();
    ~LevelSceneController();
};

#endif //PROJ_ANDROID_STUDIO_LEVELSCENECONTROLLER_H
