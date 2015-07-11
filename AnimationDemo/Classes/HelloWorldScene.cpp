#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
  
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("run.plist");
    
    auto background = Sprite::createWithSpriteFrameName("background.png");
    background->setAnchorPoint(Vec2::ZERO);
    this->addChild(background,0);
    
    sprite = Sprite::createWithSpriteFrameName("h1.png");
    sprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height /2));
    this->addChild(sprite);
    
    isPlaying = false;
    
    //toggle菜单
    auto goSprite = Sprite::createWithSpriteFrameName("go.png");
    auto stopSprite = Sprite::createWithSpriteFrameName("stop.png");
    
    auto goToggleMenuItem = MenuItemSprite::create(goSprite, goSprite);
    auto stopToggleMenuItem = MenuItemSprite::create(stopSprite, stopSprite);
    
    auto toggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(HelloWorld::OnAction, this),
                                                             goToggleMenuItem , stopToggleMenuItem, NULL);
    
    toggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(930, 540)));
    
    auto mn = Menu::create(toggleMenuItem, NULL);
    mn->setPosition(Vec2::ZERO);
    this->addChild(mn);
    
    return true;
}

void HelloWorld::OnAction(Ref* pSender)
{
    
    if (!isPlaying) {
        
        ///////////////动画开始//////////////////////
        Animation* animation = Animation::create();
        for( int i=1; i<= 4; i++)
        {
            __String *frameName = __String::createWithFormat("h%d.png",i);
            log("frameName = %s",frameName->getCString());
            SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
            animation->addSpriteFrame(spriteFrame);
        }
        
        animation->setDelayPerUnit(0.15f);           //设置两个帧播放时间
        animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态
        
        Animate* action = Animate::create(animation);
        sprite->runAction(RepeatForever::create(action));
        //////////////////动画结束///////////////////
        
        isPlaying = true;
        
    } else {        
        sprite->stopAllActions();        
        isPlaying = false;
    }
}