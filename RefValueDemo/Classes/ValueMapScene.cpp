//
//  ValueMapScene.cpp
//  RefValueDemo
//
//  Created by ZhangBo on 15/7/12.
//
//

#include "ValueMapScene.h"

#include "HelloWorldScene.h"

USING_NS_CC;


Scene* ValueMapLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ValueMapLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool ValueMapLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Go");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(ValueMapLayer::goMenu, this));
    pItmMenu1->setTag(200);
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Back");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(ValueMapLayer::backMenu, this));
    pItmMenu2->setTag(201);
    Menu* mn = Menu::create(pItmMenu1,pItmMenu2,NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    
    for(int i = 0;i < MAX_COUNT; ++i){
        
        std::ostringstream stringStream1;
        stringStream1 << "key_ball_" << i;
        std::string keyBall = stringStream1.str();
        
        std::pair<std::string,Value> pair1(keyBall,Value("Ball.png"));
        map1.insert(pair1);
        
        std::ostringstream stringStream2;
        stringStream2 << "key_icon_" << i;
        std::string keyIcon = stringStream2.str();
        
        std::pair<std::string,Value> pair2(keyIcon,Value("icon.png"));
        map2.insert(pair2);
    }
    
    return true;
}

void ValueMapLayer:: backMenu(cocos2d::Ref* pSender)
{
    auto sc = HelloWorld::createScene();
    auto reScene = TransitionSlideInL::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
    
}
void ValueMapLayer:: goMenu(cocos2d::Ref* pSender)
{
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    log("Map1 key-value count = %ld",this->map1.size());
    int tagIndex = 0;
    for (auto& pair: map1)
    {
        log("Map1 key-value = %s - %s", pair.first.c_str(),pair.second.asString().c_str());
        
        int x = CCRANDOM_0_1() * visibleSize.width;
        int y = CCRANDOM_0_1() * visibleSize.height;
        
        this->removeChildByTag(tagIndex);
        
        auto sprite = Sprite::create(pair.second.asString());
        sprite->setPosition(Vec2(x, y));
        this->addChild(sprite, 0, tagIndex++);
    }
    
    log("Map2 key-value count = %ld",this->map2.size());
    
    for (auto& pair: map2)
    {
        log("Map2 key-value = %s - %s", pair.first.c_str(),pair.second.asString().c_str());
        
        int x = CCRANDOM_0_1() * visibleSize.width;
        int y = CCRANDOM_0_1() * visibleSize.height;
        
        this->removeChildByTag(tagIndex);
        
        auto sprite = Sprite::create(pair.second.asString());
        sprite->setPosition(Vec2(x, y));
        this->addChild(sprite, 0, tagIndex++);
    }
}