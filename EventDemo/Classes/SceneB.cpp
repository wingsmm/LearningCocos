//
//  SceneB.cpp
//  EventDemo
//
//  Created by ZhangBo on 15/7/6.
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
    
    
    
    //贴图的纹理图片宽高必须是2的n次幂，128x128
    auto bg = Sprite::create("BackgroundTile.png", Rect(0, 0, visibleSize.width, visibleSize.height));
    //贴图的纹理参数，水平重复平铺，垂直重复平铺
    Texture2D::TexParams tp = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
    bg->getTexture()->setTexParameters(tp);
    bg->setPosition(origin + Vec2(visibleSize.width/2, visibleSize.height/2));
    addChild(bg, 0);
    
    Sprite* boxA = Sprite::create("BoxA2.png");
    boxA->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2) + Vec2(-120, 120));
    addChild(boxA, 10, kBoxA_Tag);
    
    Sprite* boxB = Sprite::create("BoxB2.png");
    boxB->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2));
    addChild(boxB, 20, kBoxB_Tag);
    
    Sprite* boxC = Sprite::create("BoxC2.png");
    boxC->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2) + Vec2(120, 160));
    addChild(boxC, 30, kBoxC_Tag);
    
    
    auto staticLabel = Label::createWithBMFont("fonts/fnt9.fnt", "Scene B");
    staticLabel->setPosition(Vec2(visibleSize.width/2,
                                  visibleSize.height - 50));
    this->addChild(staticLabel, 1);
    

    
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Return");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(BLayer::menReturnPreviousScene, this));
    
    Menu* mn = Menu::create(pItmMenu2, NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    return true;
}

void BLayer::onEnter()
{
    Layer::onEnter();
    log("HelloWorld onEnter");
    
    // 创建一个事件监听器 OneByOne 为单点触摸
    auto listener = EventListenerTouchOneByOne::create();
    // 设置是否吞没事件，在 onTouchBegan 方法返回 true 时吞没
    listener->setSwallowTouches(true);
    
    // 使用 lambda 实现 onTouchBegan 事件回调函数
    listener->onTouchBegan = [](Touch* touch, Event* event){
        // 获取事件所绑定的 target
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        // 获取当前点击点所在相对按钮的位置坐标
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        // 点击范围判断检测
        if (rect.containsPoint(locationInNode))
        {
            log("sprite x = %f, y = %f ", locationInNode.x, locationInNode.y);
            log("sprite tag = %d", target->getTag());
            target->runAction(ScaleBy::create(0.06f, 1.06f));
            return true;
        }
        return false;
    };
    
    // 触摸移动时触发
    listener->onTouchMoved = [](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        // 移动当前按钮精灵的坐标位置
        target->setPosition(target->getPosition() + touch->getDelta());
    };
    
    // 点击事件结束处理
    listener->onTouchEnded = [](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        log("sprite onTouchesEnded.. ");
        
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        // 点击范围判断检测
        if (rect.containsPoint(locationInNode))
        {
            log("sprite x = %f, y = %f ", locationInNode.x, locationInNode.y);
            log("sprite tag = %d", target->getTag());
            target->runAction(ScaleTo::create(0.06f, 1.0f));
        }
    };
    
    // 注册监听器
    EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener, getChildByTag(kBoxA_Tag));
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), getChildByTag(kBoxB_Tag));
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), getChildByTag(kBoxC_Tag));
}

void BLayer::onExit()
{
    Layer::onExit();
    log("HelloWorld onExit");
    Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
}

void BLayer::menReturnPreviousScene(Ref* pSender)
{
    Director::getInstance()->popScene();
}