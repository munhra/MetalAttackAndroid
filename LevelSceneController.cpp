//
// Created by Rafael M. A. da Silva on 02/01/18.
//

#include <json/document.h>
#include "LevelSceneController.h"
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

        /*
         * robot.armor = [[enemyInfo valueForKey:@"armor"] floatValue];
        robot.weaponDamage = [[enemyInfo valueForKey:@"weaponDamage"] floatValue];
        robot.scorePoints = [[enemyInfo valueForKey:@"scorePoints"] floatValue];
        robot.numberOfFrames = [[enemyInfo valueForKey:@"numberOfFrames"] intValue];
        robot.timeToReach = [[enemyInfo valueForKey:@"timeToReach"] doubleValue];
        robot.typeOfPowerUp = [[enemyInfo valueForKey:@"typeOfPowerUp"] floatValue];
        robot.atackType = [self getEnemyAtackType:enemyInfo];

        robot.lowerAction = ccp([[enemyInfo valueForKey:@"lowerActionX"] floatValue], [[enemyInfo valueForKey:@"lowerActionY"] floatValue]);
        robot.sideAction = ccp([[enemyInfo valueForKey:@"sideActionX"] floatValue], [[enemyInfo valueForKey:@"sideActionY"] floatValue]);
        robot.upperAction = ccp([[enemyInfo valueForKey:@"upperActionX"] floatValue], [[enemyInfo valueForKey:@"upperActionY"] floatValue]);

        robot.fLowerAction = ccp([[enemyInfo valueForKey:@"flipLowerActionX"] floatValue], [[enemyInfo valueForKey:@"flipLowerActionY"] floatValue]);
        robot.fSideAction = ccp([[enemyInfo valueForKey:@"flipSideActionX"] floatValue], [[enemyInfo valueForKey:@"flipSideActionY"] floatValue]);
        robot.fUpperAction = ccp([[enemyInfo valueForKey:@"flipUpperActionX"] floatValue], [[enemyInfo valueForKey:@"flipUpperActionY"] floatValue]);

        robot.shootSound = [enemyInfo valueForKey:@"shootSound"];
        robot.shootHit = [enemyInfo valueForKey:@"shootHit"];

        robot.dropCoinLowerLevel = [[enemyInfo valueForKey:@"dropCoinLowerLevel"] intValue];
        robot.dropCoinHighLevel = [[enemyInfo valueForKey:@"dropCoinHighLevel"] intValue];

        if (robot.atackType == WALK_SHOOT) {
            robot.shootStartPosition = ccp([[enemyInfo valueForKey:@"shootStartX"] intValue],
                                           [[enemyInfo valueForKey:@"shootStartY"] intValue]);
            robot.shootStyle = [self convertShootStyle:[[enemyInfo valueForKey:@"shootStyle"] intValue]];
        }

         */


        enemyKey << "enemy" << enemyIndex;

        robot->enemyName = result[enemyKey.str().c_str()]["enemyName"].GetString();
        //robot->weaponDamage = result[enemyKey.str().c_str()]["weaponDamage"].GetFloat();
        //robot->scorePoints = result[enemyKey.str().c_str()]["scorePoints"].GetFloat();
        //robot->numberOfFrames = result[enemyKey.str().c_str()]["numberOfFrames"].GetInt();
        //robot->timeToReach = result[enemyKey.str().c_str()]["timeToReach"].GetDouble();
        //robot->typeOfPowerUp = result[enemyKey.str().c_str()]["typeOfPowerUp"].GetFloat();
        //robot->atackType

        //robot->fLowerAction = Vec2(result[enemyKey.str().c_str()]["lowerActionX"].GetFloat()
        //        ,result[enemyKey.str().c_str()]["lowerActionY"].GetFloat());


        enemyDictMutable[robot->enemyName] = robot;



    }

    CCLOG("Ended Parse Enemies");
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

vector<RobotBlaster *> *LevelSceneController::createEnemies(int levelNumber, int waveNumber) {

    vector<RobotBlaster> *stageEnemyArray;
    Enemy *newEnemy1;
    int delay = 5;


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

