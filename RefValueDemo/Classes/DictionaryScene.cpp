//
//  DictionaryScene.cpp
//  RefValueDemo
//
//  Created by ZhangBo on 15/7/12.
//
//

#include "DictionaryScene.h"

#include "HelloWorldScene.h"

USING_NS_CC;


Scene* DictionaryLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = DictionaryLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool DictionaryLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Go");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(DictionaryLayer::goMenu, this));
    pItmMenu1->setTag(200);
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Back");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(DictionaryLayer::backMenu, this));
    pItmMenu2->setTag(201);
    Menu* mn = Menu::create(pItmMenu1,pItmMenu2,NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    
    
    this->dict1  = __Dictionary::create();
    this->dict1->retain();
    this->dict2  = __Dictionary::create();
    this->dict2->retain();
    
    for(int i = 0;i < MAX_COUNT; ++i){
        
        auto sprite1 = Sprite::create("Ball.png");
        this->dict1->setObject(sprite1, i);
        
        auto sprite2 = Sprite::create("icon.png");
        __String *key = __String::createWithFormat("key%d",i);
        this->dict2->setObject(sprite2, key->getCString());
    }

    
    return true;
}

void DictionaryLayer:: backMenu(cocos2d::Ref* pSender)
{
    auto sc = HelloWorld::createScene();
    auto reScene = TransitionSlideInL::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
    
}
void DictionaryLayer:: goMenu(cocos2d::Ref* pSender)
{
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    DictElement* pElement;
    
    log("Dict1 key-value count = %d",this->dict1->count());
    CCDICT_FOREACH(dict1, pElement)
    {
        long key = pElement->getIntKey();
        log("Add Sprite %ld", key);
        
        Sprite* sprite = (Sprite*)pElement->getObject();
        
        int x = CCRANDOM_0_1() * visibleSize.width;
        int y = CCRANDOM_0_1() * visibleSize.height;
        
        sprite->setPosition( Vec2(x, y) );
        this->removeChild(sprite);
        this->addChild(sprite);
    }
    
    
    log("Dict2 key-value count = %d",this->dict2->count());
    CCDICT_FOREACH(dict2, pElement)
    {
        const char *key = pElement->getStrKey();
        log("Add Sprite %s", key);
        
        Sprite* sprite = (Sprite*)pElement->getObject();
        
        int x = CCRANDOM_0_1() * visibleSize.width;
        int y = CCRANDOM_0_1() * visibleSize.height;
        
        sprite->setPosition( Vec2(x, y) );
        this->removeChild(sprite);
        this->addChild(sprite);
    }

    
}

DictionaryLayer::~DictionaryLayer()
{
    this->dict1->removeAllObjects();
    CC_SAFE_RELEASE_NULL(this->dict1);
    
    this->dict2->removeAllObjects();
    CC_SAFE_RELEASE_NULL(this->dict2);
}