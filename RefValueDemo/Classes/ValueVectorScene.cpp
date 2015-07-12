//
//  ValueVectorScene.cpp
//  RefValueDemo
//
//  Created by ZhangBo on 15/7/12.
//
//

#include "ValueVectorScene.h"

#include "HelloWorldScene.h"

USING_NS_CC;


Scene* ValueVectorLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ValueVectorLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool ValueVectorLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Go");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(ValueVectorLayer::goMenu, this));
    pItmMenu1->setTag(200);
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Back");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(ValueVectorLayer::backMenu, this));
    pItmMenu2->setTag(201);
    Menu* mn = Menu::create(pItmMenu1,pItmMenu2,NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    for(int i = 0;i < MAX_COUNT; ++i){
        Value spname("Ball.png");
        list.push_back(spname);
    }
    
    return true;
}

void ValueVectorLayer:: backMenu(cocos2d::Ref* pSender)
{
    auto sc = HelloWorld::createScene();
    auto reScene = TransitionSlideInL::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
    
}
void ValueVectorLayer:: goMenu(cocos2d::Ref* pSender)
{
    
    log("List count = %ld",list.size());
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    int tagIndex = 0;
    
    for( auto& v : list)
    {
        int x = CCRANDOM_0_1() * visibleSize.width;
        int y = CCRANDOM_0_1() * visibleSize.height;
        
        this->removeChildByTag(tagIndex);
        
        auto sprite = Sprite::create(v.asString());
        sprite->setPosition(Vec2(x, y));
        this->addChild(sprite, 0, tagIndex++);
    }
    
    
}