//
// Created by Rafael M. A. da Silva on 24/12/17.
//

#ifndef PROJ_ANDROID_STUDIO_GAMEHUDSPRITE_H
#define PROJ_ANDROID_STUDIO_GAMEHUDSPRITE_H

#include "cocos2d.h"
#include <editor-support/spritebuilder/CCBXNodeLoader.h>
#include <editor-support/spritebuilder/SpriteBuilder.h>
#include <editor-support/spritebuilder/CCBXNodeLoader.h>
#include <editor-support/spritebuilder/CCBXSpriteLoader.h>

USING_NS_CC;
using namespace cocos2d::spritebuilder;

class GameHudSprite : public Sprite, public CCBXReaderOwner
{
public:

    virtual bool init();
    CREATE_FUNC(GameHudSprite);

protected:
    GameHudSprite();
    ~GameHudSprite();
};

class GameHudSpriteLoader : public SpriteLoader {

public:

    static SpriteLoader* create() {
        GameHudSpriteLoader *ret = new GameHudSpriteLoader();
        ret->autorelease();
        return ret;
    }

    virtual Node *createNodeInstance(const Size &parentSize, float mainScale, float additionalScale,
                                     CCBXReaderOwner *owner, Node *rootNode, CCBXReaderOwner *rootOwner,
                                     const cocos2d::ValueMap &customProperties) const override {
        return GameHudSprite::create();
    }
};

#endif //PROJ_ANDROID_STUDIO_GAMEHUDSPRITE_H
