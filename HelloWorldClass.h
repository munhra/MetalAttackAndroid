//
// Created by Rafael M. A. da Silva on 20/12/17.
//

#ifndef PROJ_ANDROID_STUDIO_HELLOWORLDCLASS_H
#define PROJ_ANDROID_STUDIO_HELLOWORLDCLASS_H

#include "cocos2d.h"
#include <editor-support/spritebuilder/CCBXNodeLoader.h>
#include <editor-support/spritebuilder/SpriteBuilder.h>
#include <editor-support/spritebuilder/CCBXNodeLoader.h>

USING_NS_CC;
using namespace cocos2d::spritebuilder;

class HelloWorldClass : public Node, public CCBXReaderOwner
{
    public:
        virtual bool init();
        CREATE_FUNC(HelloWorldClass);
    protected:
        HelloWorldClass();
        ~HelloWorldClass();

};

#endif //PROJ_ANDROID_STUDIO_HELLOWORLDCLASS_H