//
// Created by Rafael M. A. da Silva on 23/12/17.
//

#ifndef PROJ_ANDROID_STUDIO_MAINSCENE_H
#define PROJ_ANDROID_STUDIO_MAINSCENE_H


#include "cocos2d.h"
#include "ui/UIButton.h"
#include <editor-support/spritebuilder/CCBXNodeLoader.h>
#include <editor-support/spritebuilder/SpriteBuilder.h>
#include <editor-support/spritebuilder/CCBXNodeLoader.h>

USING_NS_CC;
using namespace cocos2d::spritebuilder;
using namespace ui;

class MainScene : public Node, public CCBXReaderOwner
{
public:

    virtual bool init();
    void doRight(Ref *target);
    void doNewGame(Ref *target);
    CREATE_FUNC(MainScene);

private:

    Button *_handButton;
    bool rightMoved;


protected:
    MainScene();
    ~MainScene();

};

#endif //PROJ_ANDROID_STUDIO_MAINSCENE_H
