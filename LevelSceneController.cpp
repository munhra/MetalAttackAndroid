//
// Created by Rafael M. A. da Silva on 02/01/18.
//

#include <json/document.h>
#include "LevelSceneController.h"
#include "UniversalInfo.h"
#include <string>

LevelSceneController *LevelSceneController::instance = 0;

LevelSceneController *LevelSceneController::sharedInstance() {

    if (!LevelSceneController::instance) {
        LevelSceneController::instance = new LevelSceneController();
    }
    return LevelSceneController::instance;
}

void LevelSceneController::loadEnemyDictFromJson() {

    CCLOG("loadEnemyDictFromJson");

    string fullPath = "res/enemies.json";
    string jsonString;

    jsonString = FileUtils::getInstance()->getStringFromFile(fullPath);
    rapidjson::Document result;
    result.Parse<0>(jsonString.c_str());

    for (int enemyIndex = 1 ; enemyIndex <= 25 ; enemyIndex++) {
        stringstream enemyKey;
        EnemyParams *robot = new EnemyParams();

        enemyKey << "enemy" << enemyIndex;

        robot->enemyName = result[enemyKey.str().c_str()]["enemyName"].GetString();
        robot->weaponDamage = atof(result[enemyKey.str().c_str()]["weaponDamage"].GetString());
        robot->scorePoints = atof(result[enemyKey.str().c_str()]["scorePoints"].GetString());
        robot->numberOfFrames = atoi(result[enemyKey.str().c_str()]["numberOfFrames"].GetString());
        robot->timeToReach = atof(result[enemyKey.str().c_str()]["timeToReach"].GetString());

        robot->typeOfPowerUp = EnemyParams::COIN;

        string isMeele = result[enemyKey.str().c_str()]["meele"].GetString();
        string isAutoDestruction = result[enemyKey.str().c_str()]["autoDestruction"].GetString();
        robot->atackType = getEnemyAtackType(isAutoDestruction, isMeele);


        if (robot->atackType != EnemyParams::AUTODESTRUCTION) {

            robot->lowerAction = Vec2(atof(result[enemyKey.str().c_str()]["lowerActionX"].GetString()),
                                      atof(result[enemyKey.str().c_str()]["lowerActionY"].GetString()));

            robot->sideAction = Vec2(atof(result[enemyKey.str().c_str()]["sideActionX"].GetString()),
                                     atof(result[enemyKey.str().c_str()]["sideActionY"].GetString()));

            robot->upperAction = Vec2(atof(result[enemyKey.str().c_str()]["upperActionX"].GetString()),
                                      atof(result[enemyKey.str().c_str()]["upperActionY"].GetString()));



            robot->fLowerAction = Vec2(atof(result[enemyKey.str().c_str()]["flipLowerActionX"].GetString()),
                                       atof(result[enemyKey.str().c_str()]["flipLowerActionY"].GetString()));


            robot->fSideAction = Vec2(atof(result[enemyKey.str().c_str()]["flipSideActionX"].GetString()),
                                      atof(result[enemyKey.str().c_str()]["flipSideActionY"].GetString()));


            robot->fUpperAction = Vec2(atof(result[enemyKey.str().c_str()]["flipUpperActionX"].GetString()),
                                       atof(result[enemyKey.str().c_str()]["flipUpperActionY"].GetString()));
        }

        robot->shootSound = result[enemyKey.str().c_str()]["shootSound"].GetString();
        robot->shootSound = result[enemyKey.str().c_str()]["shootHit"].GetString();
        robot->dropCoinHighLevel = atoi(result[enemyKey.str().c_str()]["dropCoinLowerLevel"].GetString());
        robot->dropCoinLowerLevel = atoi(result[enemyKey.str().c_str()]["dropCoinLowerLevel"].GetString());

        if (robot->atackType == EnemyParams::WALK_SHOOT) {
            robot->shootStyle = convertShootStyle(atoi(result[enemyKey.str().c_str()]["shootStyle"].GetString()));
            robot->shootStartPosition = Vec2(atoi(result[enemyKey.str().c_str()]["shootStartX"].GetString()),
                                             atoi(result[enemyKey.str().c_str()]["shootStyle"].GetString()));
        }
    }

    CCLOG("Ended Parse Enemies");
}

EnemyParams::ShootStyle LevelSceneController::convertShootStyle(int style) {
    switch (style) {
        case 0:
            return EnemyParams::SINGLE;
        case 1:
            return EnemyParams::ROTATION;
        case 2:
            return EnemyParams::JUMP;
        default:
            return EnemyParams::SINGLE;
    }
}

EnemyParams::AtackType LevelSceneController::getEnemyAtackType(string isAutoDestruction, string isMeele) {

    if (isMeele.compare("YES") == 0) {
        return EnemyParams::MEELEE;
    }else if (isAutoDestruction.compare("YES") == 0) {
        return EnemyParams::AUTODESTRUCTION;
    }else{
        return EnemyParams::WALK_SHOOT;
    }
}

void LevelSceneController::loadLevelJson() {

    CCLOG("loadLevelJson");

    string fullPath = "res/levels.json";
    string jsonString;

    jsonString = FileUtils::getInstance()->getStringFromFile(fullPath);
    rapidjson::Document result;
    result.Parse<0>(jsonString.c_str());

    totalLevels = result.Size();

    string *level;
    int numberWaves;
    vector<string> *wavesArray = new vector<string>();
    loadedLevels = new vector<Level *>;

    int oldContextNumber = 1;
    int levelPerContextCounter = 0;
    int firstLevelOnContext = 1;

    int lastLevel = 1;

    firstLevelPerContext.push_back(firstLevelOnContext);


    for (int levelIndex = 0; levelIndex < totalLevels ; levelIndex++) {

        Level *readLevel = new Level();

        int wavesArraySize = result[levelIndex]["waves"].GetArray().Size();
        for (int waveIndex = 0; waveIndex < wavesArraySize ; waveIndex ++) {
            wavesArray->push_back(result[levelIndex]["waves"][waveIndex].GetString());
        }

        readLevel->levelContext = atoi(result[levelIndex]["levelContext"].GetString());
        readLevel->totalLevelEnemies = atoi(result[levelIndex]["levelTotalEnemies"].GetString());
        readLevel->levelNumberName = atoi(result[levelIndex]["levelNumber"].GetString());

        int levelContext = atoi(result[levelIndex]["levelContext"].GetString());

        for (int i = 0; i < wavesArray->size(); i++) {
            string waveStr = (string) wavesArray->at(i);
            int waveEnemiesInt = atoi(waveStr.c_str());
            readLevel->waves.push_back(waveEnemiesInt);
        }

        if (levelContext != oldContextNumber) {
            levelPerContextCounter = atoi(result[levelIndex]["levelNumber"].GetString());
            firstLevelOnContext = levelPerContextCounter - 1;
            levelsPerLevelContext.push_back(levelPerContextCounter - 1);
            firstLevelPerContext.push_back(firstLevelOnContext);
            oldContextNumber = readLevel->levelContext;
        }

        int enemiesArraySize = result[levelIndex]["enemies"].GetArray().Size();
        for (int enemyIndex = 0; enemyIndex < enemiesArraySize ; enemyIndex ++) {
            readLevel->avaliableEnemies.push_back(result[levelIndex]["enemies"][enemyIndex].GetString());
        }

        loadedLevels->push_back(readLevel);
        lastLevel = atoi(result[levelIndex]["levelNumber"].GetString());


    }

    levelsPerLevelContext.push_back(lastLevel);
    this->loadEnemyDictFromJson();

    CCLOG("LevelLoadedWithSuccess");

}

vector<RobotBlaster *> *LevelSceneController::createEnemies(int levelNumber, int wave) {

    vector<RobotBlaster *> *stageEnemyArray = new vector<RobotBlaster *>();
    RobotBlaster *newEnemy1;
    int delay = 5;

    Level *loadlevel = loadedLevels->at(levelNumber);

    int typeOfEnemies = loadlevel->avaliableEnemies.size();
    int groupCount = loadlevel->waves.at(wave) / 8;

    int randonEnemy;
    string enemyName;
    EnemyParams * eparams;

    int levelContext = loadlevel->levelContext;

    //there should be a switch case here but for now let's consider level one only
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemySheetNew.plist");


    for (int i = 0; i < groupCount ; i++) {
        if (i == 0) {
            delay = 1;
        } else {
            delay = 5;
        }

        //Position 7

        randonEnemy = rand() % typeOfEnemies;
        enemyName = loadlevel->avaliableEnemies.at(randonEnemy);
        eparams = enemyDictMutable[enemyName];
        eparams->typeOfPowerUp = EnemyParams::COIN;

        newEnemy1 = new RobotBlaster();
        newEnemy1->initwithStartPosition(UniversalInfo::sharedInstance()->enemyPosition7(),
                                         1.7*i+delay, NULL, eparams,
                                         Enemy::POS7, UniversalInfo::sharedInstance()->enemyPosition3());


        stageEnemyArray->push_back(newEnemy1);

        //Position 8

        randonEnemy = rand() % typeOfEnemies;
        enemyName = loadlevel->avaliableEnemies.at(randonEnemy);
        eparams = enemyDictMutable[enemyName];
        eparams->typeOfPowerUp = EnemyParams::COIN;

        newEnemy1 = new RobotBlaster();
        newEnemy1->initwithStartPosition(UniversalInfo::sharedInstance()->enemyPosition8(),
                                         2.9*i+delay, NULL, eparams,
                                         Enemy::POS8, UniversalInfo::sharedInstance()->enemyPosition4());

        stageEnemyArray->push_back(newEnemy1);


        //Position 4

        randonEnemy = rand() % typeOfEnemies;
        enemyName = loadlevel->avaliableEnemies.at(randonEnemy);
        eparams = enemyDictMutable[enemyName];
        eparams->typeOfPowerUp = EnemyParams::COIN;

        newEnemy1 = new RobotBlaster();
        newEnemy1->initwithStartPosition(UniversalInfo::sharedInstance()->enemyPosition4(),
                                         2.5*i+delay, NULL, eparams,
                                         Enemy::POS4, UniversalInfo::sharedInstance()->enemyPosition8());

        stageEnemyArray->push_back(newEnemy1);

        //Position 2

        randonEnemy = rand() % typeOfEnemies;
        enemyName = loadlevel->avaliableEnemies.at(randonEnemy);
        eparams = enemyDictMutable[enemyName];
        eparams->typeOfPowerUp = EnemyParams::COIN;

        newEnemy1 = new RobotBlaster();
        newEnemy1->initwithStartPosition(UniversalInfo::sharedInstance()->enemyPosition2(),
                                         1*i+delay, NULL, eparams,
                                         Enemy::POS2, UniversalInfo::sharedInstance()->enemyPosition6());

        stageEnemyArray->push_back(newEnemy1);

        //Position 6

        randonEnemy = rand() % typeOfEnemies;
        enemyName = loadlevel->avaliableEnemies.at(randonEnemy);
        eparams = enemyDictMutable[enemyName];
        eparams->typeOfPowerUp = EnemyParams::COIN;

        newEnemy1 = new RobotBlaster();
        newEnemy1->initwithStartPosition(UniversalInfo::sharedInstance()->enemyPosition6(),
                                         1.8*i+delay, NULL, eparams,
                                         Enemy::POS6, UniversalInfo::sharedInstance()->enemyPosition2());

        stageEnemyArray->push_back(newEnemy1);

        //Position 1

        randonEnemy = rand() % typeOfEnemies;
        enemyName = loadlevel->avaliableEnemies.at(randonEnemy);
        eparams = enemyDictMutable[enemyName];
        eparams->typeOfPowerUp = EnemyParams::COIN;

        newEnemy1 = new RobotBlaster();
        newEnemy1->initwithStartPosition(UniversalInfo::sharedInstance()->enemyPosition1(),
                                         0.3*i+delay, NULL, eparams,
                                         Enemy::POS1, UniversalInfo::sharedInstance()->enemyPosition5());

        stageEnemyArray->push_back(newEnemy1);

        //Position 3

        randonEnemy = rand() % typeOfEnemies;
        enemyName = loadlevel->avaliableEnemies.at(randonEnemy);
        eparams = enemyDictMutable[enemyName];
        eparams->typeOfPowerUp = EnemyParams::COIN;

        newEnemy1 = new RobotBlaster();
        newEnemy1->initwithStartPosition(UniversalInfo::sharedInstance()->enemyPosition3(),
                                         0.3*i+5+delay, NULL, eparams,
                                         Enemy::POS3, UniversalInfo::sharedInstance()->enemyPosition7());

        stageEnemyArray->push_back(newEnemy1);

        //Position 5

        randonEnemy = rand() % typeOfEnemies;
        enemyName = loadlevel->avaliableEnemies.at(randonEnemy);
        eparams = enemyDictMutable[enemyName];
        eparams->typeOfPowerUp = EnemyParams::COIN;

        newEnemy1 = new RobotBlaster();
        newEnemy1->initwithStartPosition(UniversalInfo::sharedInstance()->enemyPosition5(),
                                         0.3*i+5+delay, NULL, eparams,
                                         Enemy::POS5, UniversalInfo::sharedInstance()->enemyPosition1());

        stageEnemyArray->push_back(newEnemy1);

    }
}

Scene *LevelSceneController::loadLevelScene(int levelNumber, int wave) {
    CCLOG("LevelSceneController");

    Scene *gamePlayScene;
    Level *loadlevel = loadedLevels->at(levelNumber);
    int groupCount = loadlevel->waves.at(wave) / 8;

    enemyArray = createEnemies(levelNumber,wave);
    int levelContext = loadlevel->levelContext;
    //switch level context for now fixed to level1

    CCBXReader *reader = CCBXReader::createFromFile("Levels/Level1.ccbi");
    scnDelegate =  (LevelScene *) reader->createNode(this, SceneScaleType::MINSCALE);

    scnDelegate->totalLevel = totalLevels;
    scnDelegate->levelNumber = levelNumber;
    scnDelegate->levelContext = levelContext;
    scnDelegate->levelEnemiesLeft = loadlevel->totalLevelEnemies;
    scnDelegate->waveEnemiesLeft = loadlevel->waves.at(wave);

    return (Scene *)scnDelegate;
}

void LevelSceneController::startEnemyMovment() {
    for (int enemyIndex = 0; enemyIndex < enemyArray->size(); enemyIndex++) {
        RobotBlaster *enemy = enemyArray->at(enemyIndex);
        enemy->delegate = scnDelegate;
        auto enemyStartMovementCallBack = [&enemy](float time) {enemy->startMovement();};
        string enemyKey;
        this->scheduleOnce(enemyStartMovementCallBack, 1, enemyKey);
    }
}

LevelSceneController::LevelSceneController() {

}

LevelSceneController::~LevelSceneController() {

}

