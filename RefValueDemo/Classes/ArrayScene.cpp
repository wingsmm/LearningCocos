//
//  ArrayScene.cpp
//  RefValueDemo
//
//  Created by ZhangBo on 15/7/12.
//
//

#include "ArrayScene.h"


#include "HelloWorldScene.h"

USING_NS_CC;


Scene* ArrayLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ArrayLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool ArrayLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Go");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(ArrayLayer::goMenu, this));
    pItmMenu1->setTag(200);
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Back");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(ArrayLayer::backMenu, this));
    pItmMenu2->setTag(201);
    Menu* mn = Menu::create(pItmMenu1,pItmMenu2,NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    
    this->list  = __Array::createWithCapacity(MAX_COUNT);
    this->list->retain();
    
    for(int i = 0;i < MAX_COUNT; ++i){
        Sprite* sprite = Sprite::create("Ball.png");
        this->list->addObject(sprite);
    }
    

    
    
    return true;
}

void ArrayLayer:: backMenu(cocos2d::Ref* pSender)
{
    auto sc = HelloWorld::createScene();
    auto reScene = TransitionSlideInL::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
    
}
void ArrayLayer:: goMenu(cocos2d::Ref* pSender)
{
    
    
    Ref* obj = nullptr;
    log("list->count() = %ld",this->list->count());
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    CCARRAY_FOREACH(this->list, obj) {
        
        Sprite* sprite = (Sprite*)obj;
        
        int x = CCRANDOM_0_1() * visibleSize.width;
        int y = CCRANDOM_0_1() * visibleSize.height;
        
        sprite->setPosition( Vec2(x, y) );
        this->removeChild(sprite);
        this->addChild(sprite);
    }

}


ArrayLayer :: ~ArrayLayer()
{
    
    this->list->removeAllObjects();
    CC_SAFE_RELEASE_NULL(this->list);

}