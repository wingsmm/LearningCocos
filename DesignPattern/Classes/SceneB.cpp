//
//  SceneB.cpp
//  AdvancedUI
//
//  Created by ZhangBo on 15/7/3.
//
//

#include "SceneB.h"


USING_NS_CC;

Scene* BLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = BLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool BLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto staticLabel = Label::createWithBMFont("fonts/fnt9.fnt", "Scene B");
    staticLabel->setPosition(Vec2(visibleSize.width/2,
                                  visibleSize.height - 50));
    this->addChild(staticLabel, 1);
    
    auto label = Label::createWithTTF("", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(visibleSize.width/2,
                            visibleSize.height - 200));
    this->addChild(label, 1, 100);
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Update Status");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(BLayer::menUpdate, this));
    
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Return");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(BLayer::menReturnPreviousScene, this));
    
    Menu* mn = Menu::create(pItmMenu1,pItmMenu2, NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    return true;
}

void BLayer::menUpdate(Ref* pSender)
{
    int num = CCRANDOM_0_1() * 1000;
    __String* s = __String::createWithFormat("SceneA Update %d", num);
    //回调HelloWorld场景
//    _delegator->callBack(this, s->getCString());
    log("%s", s->getCString());
    
    __NotificationCenter::getInstance()->postNotification(MSG_STATE, s);

}


void BLayer::menReturnPreviousScene(Ref* pSender)
{   
    Director::getInstance()->popScene();
}

void BLayer::setDelegator(SceneBDelegator* delegator)
{
    _delegator = delegator;
}