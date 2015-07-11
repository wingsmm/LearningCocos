//
//  SceneG.cpp
//  EventDemo
//
//  Created by ZhangBo on 15/7/6.
//
//

#include "SceneG.h"


USING_NS_CC;

Scene* GLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GLayer::init()
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
    
    auto ball = Sprite::create("Ball.png");
    ball->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2));
    addChild(ball, 10, kBall_Tag);
    
    auto staticLabel = Label::createWithBMFont("fonts/fnt9.fnt", "Scene G");
    staticLabel->setPosition(Vec2(visibleSize.width/2,
                                  visibleSize.height - 50));
    this->addChild(staticLabel, 1);
    
       auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Return");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(GLayer::menReturnPreviousScene, this));
    
    Menu* mn = Menu::create(pItmMenu2, NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    return true;
}




void GLayer::menReturnPreviousScene(Ref* pSender)
{
    Director::getInstance()->popScene();
}



void GLayer::onEnter()
{
    Layer::onEnter();
    log("HelloWorld onEnter");
    
    setAccelerometerEnabled(true);
}

void GLayer::onAcceleration(Acceleration* acc, Event *unused_event)
{
    log("onAcceleration x = %f,y = %f,z = %f", acc->x,acc->y,acc->z);
}

void GLayer::onExit()
{
    Layer::onExit();
    log("HelloWorld onExit");
}