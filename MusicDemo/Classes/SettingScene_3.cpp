//
//  SettingScene_3.cpp
//  MusicDemo
//
//  Created by ZhangBo on 15/7/11.
//
//

#include "SettingScene_3.h"
USING_NS_CC;
using namespace CocosDenshion;

Scene* Setting_3::createScene()
{
    // 'scene' is an autorelease Ref
    auto scene = Scene::create();
    
    // 'layer' is an autorelease Ref
    auto layer = Setting_3::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Setting_3::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    log("Setting init");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite *bg = Sprite::create("setting-back.png");
    
    // position the label on the center of the screen
    bg->setPosition(Vec2(origin.x + visibleSize.width/2,
                         origin.y + visibleSize.height /2));
    this->addChild(bg);
    
    //音效
    auto soundOnMenuItem = MenuItemImage::create(
                                                 "on.png",
                                                 "on.png");
    auto soundOffMenuItem = MenuItemImage::create(
                                                  "off.png",
                                                  "off.png");
    
    auto soundToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(Setting_3::menuSoundToggleCallback, this),
                                                                  soundOffMenuItem,
                                                                  soundOnMenuItem,
                                                                  NULL);
    soundToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(818, 220)));
    
    //音乐
    auto musicOnMenuItem  = MenuItemImage::create(
                                                  "on.png",
                                                  "on.png");
    auto musicOffMenuItem  = MenuItemImage::create(
                                                   "off.png",
                                                   "off.png");
    auto musicToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(Setting_3::menuMusicToggleCallback, this),
                                                                  musicOffMenuItem,
                                                                  musicOnMenuItem,
                                                                  NULL );
    musicToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(818, 362)));
    
    //Ok按钮
    auto okMenuItem  = MenuItemImage::create(
                                             "ok-down.png",
                                             "ok-up.png",
                                             CC_CALLBACK_1(Setting_3::menuOkCallback, this));
    
    okMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(600, 510)));
    
    Menu* mn = Menu::create(soundToggleMenuItem, musicToggleMenuItem,okMenuItem, NULL);
    mn->setPosition(Vec2::ZERO);
    this->addChild(mn);
    
    return true;
}

void Setting_3::menuOkCallback(Ref* pSender)
{
    Director::getInstance()->popScene();
}

void Setting_3::menuSoundToggleCallback(Ref* pSender)
{
    auto soundToggleMenuItem = (MenuItemToggle*)pSender;
    log("soundToggleMenuItem %d", soundToggleMenuItem->getSelectedIndex());
}


void Setting_3::menuMusicToggleCallback(Ref* pSender)
{
    auto musicToggleMenuItem = (MenuItemToggle*)pSender;
    log("musicToggleMenuItem %d", musicToggleMenuItem->getSelectedIndex());
    
}


void Setting_3::onEnter()
{
    Layer::onEnter();
    log("Setting onEnter");
    
}

void Setting_3::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    log("Setting onEnterTransitionDidFinish");
    SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/Synth.mp3", true);
}

void Setting_3::onExit()
{
    Layer::onExit();
    log("Setting onExit");	
}

void Setting_3::onExitTransitionDidStart()
{
    Layer::onExitTransitionDidStart();
    log("Setting onExitTransitionDidStart");
}

void Setting_3::cleanup()
{
    Layer::cleanup();
    log("Setting cleanup");	
    SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/Synth.mp3");
}