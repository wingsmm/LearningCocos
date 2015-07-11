//
//  UserDefaultScene.cpp
//  FileManagerDemo
//
//  Created by ZhangBo on 15/7/11.
//
//

#include "UserDefaultScene.h"
#include "HelloWorldScene.h"
#include "audio/include/SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;


Scene* UserDefaultLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = UserDefaultLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool UserDefaultLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
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
                                                           CC_CALLBACK_1(UserDefaultLayer::menuItemStartCallback, this));
    startMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(700, 170)));
    
    // 设置图片菜单
    MenuItemImage *settingMenuItem = MenuItemImage::create(
                                                           "setting-up.png",
                                                           "setting-down.png",
                                                           CC_CALLBACK_1(UserDefaultLayer::menuItemSettingCallback, this));
    settingMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(480, 400)));
    
    // 帮助图片菜单
    MenuItemImage *helpMenuItem = MenuItemImage::create(
                                                        "help-up.png",
                                                        "help-down.png",
                                                        CC_CALLBACK_1(UserDefaultLayer::menuItemHelpCallback, this));
    helpMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(860, 480)));
    
    auto backMenuItem = MenuItemImage::create("Back-up.png","Back-down.png", CC_CALLBACK_1(UserDefaultLayer::backMenu, this));
    backMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(120, 100)));

    
    Menu* mu = Menu::create(startMenuItem, settingMenuItem, helpMenuItem, backMenuItem,NULL);
    mu->setPosition(Vec2::ZERO);
    this->addChild(mu);
    
    return true;
}

void UserDefaultLayer::menuItemSettingCallback(Ref* pSender)
{
    auto sc = Setting::createScene();
    auto reScene = TransitionJumpZoom::create(1.0f, sc);
    Director::getInstance()->pushScene(reScene);
    
    if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
        SimpleAudioEngine::getInstance()->playEffect("sound/Blip.wav");
    }
}

void UserDefaultLayer::menuItemHelpCallback(Ref* pSender)
{
    MenuItem* item = (MenuItem*)pSender;
    log("Touch Help %p", item);
    if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
        SimpleAudioEngine::getInstance()->playEffect("sound/Blip.wav");
    }
}

void UserDefaultLayer::menuItemStartCallback(Ref* pSender)
{
    MenuItem* item = (MenuItem*)pSender;
    log("Touch Start %p", item);
    if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
        SimpleAudioEngine::getInstance()->playEffect("sound/Blip.wav");
    }
}

void UserDefaultLayer::onEnter()
{
    Layer::onEnter();
    log("HelloWorld onEnter");
}

void UserDefaultLayer::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    log("HelloWorld onEnterTransitionDidFinish");
    
    //播放
    if (UserDefault::getInstance()->getBoolForKey(MUSIC_KEY)) {
        SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/Jazz.mp3", true);
    }
}

void UserDefaultLayer::onExit()
{
    Layer::onExit();
    log("HelloWorld onExit");
}

void UserDefaultLayer::onExitTransitionDidStart()
{
    Layer::onExitTransitionDidStart();
    log("HelloWorld onExitTransitionDidStart");
}

void UserDefaultLayer::cleanup()
{
    Layer::cleanup();
    log("HelloWorld cleanup");
    //停止
    SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/Jazz.mp3");
}



void UserDefaultLayer::backMenu(Ref* pSender)
{
    auto sc = HelloWorld::createScene();
    auto reScene = TransitionSlideInL::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
    
}
