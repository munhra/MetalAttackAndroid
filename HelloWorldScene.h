#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos/editor-support/spritebuilder/SpriteBuilder.h"
#include "cocos/editor-support/spritebuilder/CCBXNodeLoaderLibrary.h"

USING_NS_CC;
using namespace cocos2d::spritebuilder;
using namespace cocos2d::ui;


class HelloWorld : public cocos2d::Scene, public cocos2d::spritebuilder::CCBXReaderOwner
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
