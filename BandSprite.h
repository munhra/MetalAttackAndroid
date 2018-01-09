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

USING_NS_CC;
using namespace cocos2d::spritebuilder;

class BandSprite : public Sprite, public CCBXReaderOwner
{
public:

    virtual bool init();
    CREATE_FUNC(BandSprite);

    enum BandComponents {GUITARRIST1_TYPE, GUITARRIST2_TYPE, BASS_TYPE,
                            VOCALS_TYPE, DRUMMER_TYPE,  ALL_GUITARS, ALL_GUYS};

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
