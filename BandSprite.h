//
// Created by Rafael M. A. da Silva on 24/12/17.
//

#ifndef PROJ_ANDROID_STUDIO_BANDSPRITE_H
#define PROJ_ANDROID_STUDIO_BANDSPRITE_H

#include "cocos2d.h"
#include <editor-support/spritebuilder/CCBXNodeLoader.h>
#include <editor-support/spritebuilder/SpriteBuilder.h>
#include <editor-support/spritebuilder/CCBXNodeLoader.h>
#include <editor-support/spritebuilder/CCBXSpriteLoader.h>
#include <string>
#include "BandGuySprite.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::spritebuilder;

class BandSprite : public Sprite, public CCBXReaderOwner
{
public:

    virtual bool init();
    CREATE_FUNC(BandSprite);

    enum BandComponents {GUITARRIST1_TYPE, GUITARRIST2_TYPE, BASS_TYPE,
                            VOCALS_TYPE, DRUMMER_TYPE,  ALL_GUITARS, ALL_GUYS};

    //NSMutableArray *activeShoots;

    float drummerArmor;
    float guitar1Armor;
    float guitar2Armor;
    float vocalArmor;
    float bassArmor;

    float totalDrummerArmor;
    float totalGuitar1Armor;
    float totalGuitar2Armor;
    float totalVocalArmor;
    float totalBassArmor;

    float drummerPowerConsumption;
    float drummerPowerRestoration;
    float guitar1PowerConsumption;
    float guitar1PowerRestoration;
    float guitar2PowerConsumption;
    float guitar2PowerRestoration;
    float vocalPowerConsumption;
    float vocalPowerRestoration;
    float bassPowerConsumption;
    float bassPowerRestoration;

    bool bandReleaseFire;
    bool isGuita1Death;
    bool isGuita2Death;
    bool isBassDeath;
    bool isDrummerDeath;
    bool isVocalDeath;

    ParticleSystem *bandParticle;
    ParticleSystem *bandParticleBlaster;

    float guitar1ShootPower;
    float guitar2ShootPower;
    float bassShootPower;
    float vocalsShootPower;
    float drummerShootPower;
    float shootPower;

    int bandBlast;
    int bandCoins;
    int maxBandLevel;

    //BandShoot *bandShoot;

    //NSMutableArray *megaShoots;

    Sprite *drummerPoster;
    Sprite *bassPoster;
    Sprite *vocalPoster;
    Sprite *leadPoster;
    Sprite *basePoster;

    Sprite *drummerEnd;
    Sprite *bassEnd;
    Sprite *vocalEnd;
    Sprite *leadEnd;
    Sprite *baseEnd;

    string drummerEndingText;
    string bassEndText;
    string vocalEndText;
    string leadEndText;
    string baseEndText;

    string drummerEndFileName;
    string bassEndFileName;
    string vocalEndFileName;
    string leadEndFileName;
    string baseEndFileName;

    Sprite *drummerLife;
    Sprite *bassLife;
    Sprite *vocalLife;
    Sprite *leadLife;
    Sprite *baseLife;

    BandGuySprite *drummer;
    BandGuySprite *leadGuitar;
    BandGuySprite *baseGuitar;
    BandGuySprite *vocal;
    BandGuySprite *bass;

    Node *revivalAll;

    bool invulnerability;
    bool drummerInvulnerabiliy;
    bool bassInvulnerabiliy;
    bool guitarBothInvulnerabiliy;
    bool vocalInvulnerabiliy;

    float megaShotValue;
    int megaShieldValue;
    int selectedMegaShoot;

protected:
    BandSprite();
    ~BandSprite();
};

class BandSpriteLoader : public SpriteLoader {

public:

    static SpriteLoader* create() {
        BandSpriteLoader *ret = new BandSpriteLoader();
        ret->autorelease();
        return ret;
    }

    virtual Node *createNodeInstance(const Size &parentSize, float mainScale, float additionalScale,
                                     CCBXReaderOwner *owner, Node *rootNode, CCBXReaderOwner *rootOwner,
                                     const cocos2d::ValueMap &customProperties) const override {
        return BandSprite::create();
    }
};


#endif //PROJ_ANDROID_STUDIO_BANDSPRITE_H
