//
//  MusicScene_3.cpp
//  MusicDemo
//
//  Created by ZhangBo on 15/7/11.
//
//

#include "MusicScene_3.h"


USING_NS_CC;
Scene* MusicLayer_3::createScene()
{
    // 'scene' is an autorelease Ref
    auto scene = Scene::create();
    
    // 'layer' is an autorelease Ref
    auto layer = MusicLayer_3::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MusicLayer_3::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    log("MusicLayer_3 init");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite *bg = Sprite::create("background.png");
    
    // position the label on the center of the screen
    bg->setPosition(Vec2(origin.x + visibleSize.width/2,
                         origin.y + visibleSize.height /2));
    this->addChild(bg);
    
    //开始精灵
    Sprite *startSpriteNormal = Sprite::create("start-up.png");
    Sprite *startSpriteSelected = Sprite::create("start-down.png");
    
    MenuItemSprite *startMenuItem = MenuItemSprite::create(startSpriteNormal,
                                                           startSpriteSelected,
                                                           CC_CALLBACK_1(MusicLayer_3::menuItemStartCallback, this));
    startMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(700, 170)));
    
    // 设置图片菜单
    MenuItemImage *settingMenuItem = MenuItemImage::create(
                                                           "setting-up.png",
                                                           "setting-down.png",
                                                           CC_CALLBACK_1(MusicLayer_3::menuItemSettingCallback, this));
    settingMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(480, 400)));
    
    // 帮助图片菜单
    MenuItemImage *helpMenuItem = MenuItemImage::create(
                                                        "help-up.png",
                                                        "help-down.png",
                                                        CC_CALLBACK_1(MusicLayer_3::menuItemHelpCallback, this));
    helpMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(860, 480)));
    
    Menu* mu = Menu::create(startMenuItem, settingMenuItem, helpMenuItem, NULL);
    mu->setPosition(Vec2::ZERO);
    this->addChild(mu);
    
    return true;
}

void MusicLayer_3::menuItemSettingCallback(Ref* pSender)
{
    auto sc = Setting_3::createScene();
    auto reScene = TransitionJumpZoom::create(1.0f, sc);
    Director::getInstance()->pushScene(reScene);
}

void MusicLayer_3::menuItemHelpCallback(Ref* pSender)
{
    MenuItem* item = (MenuItem*)pSender;
    log("Touch Help %p", item);
}

void MusicLayer_3::menuItemStartCallback(Ref* pSender)
{
    MenuItem* item = (MenuItem*)pSender;
    log("Touch Start %p", item);
}

void MusicLayer_3::onEnter()
{
    Layer::onEnter();
    log("HelloWorld onEnter");	
    SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/Jazz.mp3", true);
}

void MusicLayer_3::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    log("HelloWorld onEnterTransitionDidFinish");
}

void MusicLayer_3::onExit()
{
    Layer::onExit();
    log("HelloWorld onExit");
}

void MusicLayer_3::onExitTransitionDidStart()
{
    Layer::onExitTransitionDidStart();
    log("HelloWorld onExitTransitionDidStart");
    
}

void MusicLayer_3::cleanup()
{
    Layer::cleanup();
    log("HelloWorld cleanup");	
    SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/Jazz.mp3");
}