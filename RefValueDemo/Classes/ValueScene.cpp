//
//  ValueScene.cpp
//  RefValueDemo
//
//  Created by ZhangBo on 15/7/12.
//
//

#include "ValueScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;


Scene* ValueLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ValueLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool ValueLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Go");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(ValueLayer::goMenu, this));
    pItmMenu1->setTag(200);
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Back");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(ValueLayer::backMenu, this));
    pItmMenu2->setTag(201);
      Menu* mn = Menu::create(pItmMenu1,pItmMenu2,NULL);
    mn->alignItemsVertically();
    this->addChild(mn);

    
    return true;
}

void ValueLayer:: backMenu(cocos2d::Ref* pSender)
{
    auto sc = HelloWorld::createScene();
    auto reScene = TransitionSlideInL::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
    
}
void ValueLayer:: goMenu(cocos2d::Ref* pSender)
{
    
    Value v1;
    CCASSERT(v1.isNull(), ".....");
    
    
    Value v2(100);
    log("%s",v2.getDescription().c_str());
    log("%c",v2.asByte());
    
    
    Value v3(110.3f);
    log("%s",v3.getDescription().c_str());
    log("%d",v3.asInt());
    
    unsigned char byte = 56;
    Value v4(byte);
    log("%s",v4.getDescription().c_str());
    log("%c",v4.asByte());
    
    
    Value v6(true);
    log("%s",v6.getDescription().c_str());
    
    
    Value v7("hello world");
    log("%s",v7.getDescription().c_str());
    log("%d",v7.asInt());

}