//
//  SceneF.cpp
//  EventDemo
//
//  Created by ZhangBo on 15/7/6.
//
//

#include "SceneF.h"


USING_NS_CC;

Scene* FLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = FLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool FLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //贴图的纹理图片宽高必须是2的n次幂，128x128
    auto bg = Sprite::create("BackgroundTile.png", Rect(0, 0, visibleSize.width, visibleSize.height));
    //贴图的纹理参数，水平重复平铺，垂直重复平铺
    Texture2D::TexParams tp = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
    bg->getTexture()->setTexParameters(tp);
    bg->setPosition(origin + Vec2(visibleSize.width/2, visibleSize.height/2));
    addChild(bg, 0);
    
    Sprite* boxA = Sprite::create("BoxA2.png");
    boxA->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2));
    addChild(boxA, 10, kBoxA_Tag);
    
    auto staticLabel = Label::createWithBMFont("fonts/fnt9.fnt", "Scene F");
    staticLabel->setPosition(Vec2(visibleSize.width/2,
                                  visibleSize.height - 50));
    this->addChild(staticLabel, 1);
    
    
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Return");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(FLayer::menReturnPreviousScene, this));
    
    Menu* mn = Menu::create(pItmMenu2, NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    return true;
}


void FLayer::menReturnPreviousScene(Ref* pSender)
{
    Director::getInstance()->popScene();
}


void FLayer::onEnter()
{
    Layer::onEnter();
    log("HelloWorld onEnter");
    
    Device::setAccelerometerEnabled(true);
    
    EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerAcceleration::create([](Acceleration* acc, Event* event)
    {
        
        log("onAcceleration x = %f,y = %f,z = %f", acc->x,acc->y,acc->z);
    
    });
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
}

void FLayer::onExit()
{
    Layer::onExit();
    log("HelloWorld onExit");
    Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
}
