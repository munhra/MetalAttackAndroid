//
// Created by Rafael M. A. da Silva on 24/12/17.
//

#ifndef PROJ_ANDROID_STUDIO_GAMEPAUSESPRITE_H
#define PROJ_ANDROID_STUDIO_GAMEPAUSESPRITE_H

#include "cocos2d.h"
#include <editor-support/spritebuilder/CCBXNodeLoader.h>
#include <editor-support/spritebuilder/SpriteBuilder.h>
#include <editor-support/spritebuilder/CCBXNodeLoader.h>
#include <editor-support/spritebuilder/CCBXSpriteLoader.h>

USING_NS_CC;
using namespace cocos2d::spritebuilder;

class GamePauseSprite : public Sprite, public CCBXReaderOwner
{
public:

    virtual bool init();
    CREATE_FUNC(GamePauseSprite);

protected:
    GamePauseSprite();
    ~GamePauseSprite();
};

class GamePauseSpriteLoader : public SpriteLoader {

public:

    static SpriteLoader* create() {
        GamePauseSpriteLoader *ret = new GamePauseSpriteLoader();
        ret->autorelease();
        return ret;
    }

    virtual Node *createNodeInstance(const Size &parentSize, float mainScale, float additionalScale,
                                     CCBXReaderOwner *owner, Node *rootNode, CCBXReaderOwner *rootOwner,
                                     const cocos2d::ValueMap &customProperties) const override {
        return GamePauseSprite::create();
    }
};
#endif //PROJ_ANDROID_STUDIO_GAMEPAUSESPRITE_H
