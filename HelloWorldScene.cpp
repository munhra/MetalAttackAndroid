#include <spritebuilder/CCBXReaderParams.h>
#include "HelloWorldScene.h"

#include "LevelSceneController.h"
#include "InfinityBG.h"
#include "DummyLayer.h"
#include "DoorSprite.h"
#include "MainScene.h"
#include "MenuGuysSprite.h"
#include "LevelScene.h"
#include "ItempackSprite.h"
#include "BandSprite.h"
#include "GameHudSprite.h"
#include "GamePauseSprite.h"
#include "BandGuySprite.h"

#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"

#include "cocos/editor-support/spritebuilder/CCBXNodeLoader.h"
#include "cocos/editor-support/spritebuilder/CCBXSpriteLoader.h"
#include "cocos/editor-support/spritebuilder/CCBXSpriteLoader.h"

#include "HelloWorldClass.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{

    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init() {

    if(!Scene::init()) {
        return false;
    }

    
    LevelSceneController::sharedInstance()->loadLevelJson();

    cocos2d::spritebuilder::NodeLoaderLibrary *library = NodeLoaderLibrary::getDefault();

    using HelloWorldClassLoader = SimpleNodeLoader<HelloWorldClass>;
    library->registerNodeLoader("HelloWorldClass", &HelloWorldClassLoader::create);

    using InfinityBGLoader = SimpleNodeLoader<InfinityBG>;
    library->registerNodeLoader("InfinityBG", &InfinityBGLoader::create);

    using DummyLayerLoader = SimpleNodeLoader<DummyLayer>;
    library->registerNodeLoader("DummyLayer", &DummyLayerLoader::create);

    using MainSceneLoader = SimpleNodeLoader<MainScene>;
    library->registerNodeLoader("MainScene", &MainSceneLoader::create);

    using LevelSceneLoader = SimpleNodeLoader<LevelScene>;
    library->registerNodeLoader("LevelScene",&LevelSceneLoader::create);

    //using ItempackSpriteLoader = SimpleNodeLoader<ItempackSprite>;
    library->registerNodeLoader("ItempackSprite", &ItempackSpriteLoader::create);

    //using DoorSpriteLoader = SimpleNodeLoader<DoorSprite>;
    library->registerNodeLoader("DoorSprite", &DoorSpriteLoader::create);

    library->registerNodeLoader("GameHudSprite", &GameHudSpriteLoader::create);
    library->registerNodeLoader("GamePauseSprite", &GamePauseSpriteLoader::create);
    library->registerNodeLoader("BandSprite", &BandSpriteLoader::create);
    library->registerNodeLoader("BandGuySprite", &BandGuySpriteLoader::create);
    library->registerNodeLoader("MenuGuysSprite", &MenuGuysSpriteLoader::create);

    //using MenuGuysSpriteLoader = SpriteLoader::create();
    //using MenuGuysSpriteLoader = SimpleNodeLoader<MenuGuysSprite>;
    //library->registerNodeLoader("MenuGuysSprite", &MenuGuysSpriteLoader::create);

    //DoorSprite

    //CCBXReader *reader = CCBXReader::createFromFile("InfinityBG.ccbi");
    //CCBXReader *reader = CCBXReader::createFromFile("InfinityBG.ccbi");
    //CCBXReader *reader = CCBXReader::createFromFile("DummyLayer.ccbi");
    //CCBXReader *reader = CCBXReader::createFromFile("DoorTransition.ccbi");
    //CCBXReader *reader = CCBXReader::createFromFile("MainMenu.ccbi");
    //CCBXReader *reader = CCBXReader::createFromFile("BandGuys/Fake.ccbi");


    //CCBXReader *reader = CCBXReader::createFromFile("Levels/Level1.ccbi");
    //CCBXReader *reader = CCBXReader::createFromFile("levelScene");

    Scene *levelScene = LevelSceneController::sharedInstance()->loadLevelScene(1,0);


    //cocos2d::Node * scene = reader->createNode(this, SceneScaleType::MINSCALE);
    //this->addChild(scene);
    this->addChild(levelScene);

    return true;

}
// on "init" you need to initialize your instance

/*
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    return true;
}*/


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
