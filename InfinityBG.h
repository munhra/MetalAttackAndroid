//
// Created by Rafael M. A. da Silva on 21/12/17.
//

#ifndef PROJ_ANDROID_STUDIO_INFINITYBG_H
#define PROJ_ANDROID_STUDIO_INFINITYBG_H

#include "cocos2d.h"
#include <editor-support/spritebuilder/CCBXNodeLoader.h>
#include <editor-support/spritebuilder/SpriteBuilder.h>
#include <editor-support/spritebuilder/CCBXNodeLoader.h>

USING_NS_CC;
using namespace cocos2d::spritebuilder;

class InfinityBG : public Node, public CCBXReaderOwner
{
public:

    virtual bool init();
    void update(float) override;
    void moveBgToUpperRight();
    CREATE_FUNC(InfinityBG);

private:

    Sprite *_visibleBG;
    Sprite *_leftBG;
    Sprite *_rightBG;
    Sprite *_upperBG;
    Sprite *_lowerBG;
    Sprite *_upperRightBG;
    Sprite *_lowerLeftBG;
    Sprite *_fixedBG;

protected:
    InfinityBG();
    ~InfinityBG();

};
#endif //PROJ_ANDROID_STUDIO_INFINITYBG_H
