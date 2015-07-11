//
//  SceneX.cpp
//  EventDemo
//
//  Created by ZhangBo on 15/7/6.
//
//


/**
 *  Cocos2dx 3.0 过渡篇（三） 触摸机制
    http://blog.csdn.net/start530/article/details/18325493
 */

#include "SceneX.h"


USING_NS_CC;

Scene* XLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = XLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool XLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
  
    
    
  
    
    
    
    auto staticLabel = Label::createWithBMFont("fonts/fnt9.fnt", "Scene X");
    staticLabel->setPosition(Vec2(visibleSize.width/2,
                                  visibleSize.height - 50));
    this->addChild(staticLabel, 1);
    
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Return");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(XLayer::menReturnPreviousScene, this));
    
    Menu* mn = Menu::create(pItmMenu2, NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    return true;
}




void XLayer::menReturnPreviousScene(Ref* pSender)
{
    Director::getInstance()->popScene();
}


void XLayer::onEnter()
{
    Layer::onEnter();
    log("HelloWorld onEnter");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    
    auto ball = Sprite::create("Ball.png");
    ball->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2));
    addChild(ball, 10, kBall_Tag);
    
    auto listener1 = EventListenerTouchOneByOne::create();//创建一个触摸监听
    listener1->setSwallowTouches(true);//设置是否想下传递触摸
    
    //3.0 后可以直接在touchBegan后添加它的实现代码，而不用特意去写一个touchBegan的函数
    listener1->onTouchBegan = [](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());//获取的当前触摸的目标
        
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode))//判断触摸点是否在目标的范围内
            return true;
        else
            return false;
    };
    
    //拖动精灵移动
    listener1->onTouchMoved = [](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setPosition(target->getPosition() + touch->getDelta());
    };
    
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
    };
    //将触摸监听添加到eventDispacher中去
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1 ,ball);

}


void XLayer::onExit()
{
    Layer::onExit();
    log("HelloWorld onExit");
    Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);

}
