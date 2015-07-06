//
//  SceneC.cpp
//  EventDemo
//
//  Created by ZhangBo on 15/7/6.
//
//

#include "SceneC.h"


USING_NS_CC;

Scene* CLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = CLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CLayer::init()
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
    
    
    auto staticLabel = Label::createWithBMFont("fonts/fnt9.fnt", "Scene C");
    staticLabel->setPosition(Vec2(visibleSize.width/2,
                                  visibleSize.height - 50));
    this->addChild(staticLabel, 1);
    
      auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Return");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(CLayer::menReturnPreviousScene, this));
    
    Menu* mn = Menu::create(pItmMenu2, NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    return true;
}

void CLayer::menUpdate(Ref* pSender)
{
    int num = CCRANDOM_0_1() * 1000;
    __String* s = __String::createWithFormat("SceneA Update %d", num);
    //回调HelloWorld场景
    //    _delegator->callBack(this, s->getCString());
    log("%s", s->getCString());
    
    
}


void CLayer::menReturnPreviousScene(Ref* pSender)
{
    Director::getInstance()->popScene();
}

void CLayer::onEnter()
{
    Layer::onEnter();
    log("HelloWorld onEnter");
    
    auto listener = EventListenerKeyboard::create();
    
    listener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
        log("Key with keycode %d pressed", keyCode);
    };
    
    listener->onKeyReleased = [](EventKeyboard::KeyCode keyCode, Event* event) {
        log("Key with keycode %d released", keyCode);
    };
    
    EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void CLayer::onExit()
{
    Layer::onExit();
    log("HelloWorld onExit");
    Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
}