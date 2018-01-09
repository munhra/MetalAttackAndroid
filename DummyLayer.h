//
// Created by Rafael M. A. da Silva on 21/12/17.
//

#ifndef PROJ_ANDROID_STUDIO_DUMMYLAYER_H
#define PROJ_ANDROID_STUDIO_DUMMYLAYER_H

#include "cocos2d.h"
#include <editor-support/spritebuilder/CCBXNodeLoader.h>
#include <editor-support/spritebuilder/SpriteBuilder.h>
#include <editor-support/spritebuilder/CCBXNodeLoader.h>

USING_NS_CC;
using namespace cocos2d::spritebuilder;

class DummyLayer : public Node, public CCBXReaderOwner
{
public:

    Sprite *logo2;

    virtual bool init();
    void update(float) override;
    CREATE_FUNC(DummyLayer);

private:
    Sprite *_logo2;

protected:
    DummyLayer();
    ~DummyLayer();
};

#endif //PROJ_ANDROID_STUDIO_DUMMYLAYER_H
