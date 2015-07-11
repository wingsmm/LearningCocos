#include "HelloWorldScene.h"
#include "Singleton.h"
#include "SceneB.h"

USING_NS_CC;

#define MAX_COUNT 100

using namespace cocostudio::timeline;
using namespace std;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    

    
    auto staticLabel = Label::createWithBMFont("fonts/fnt9.fnt", "Scene A");
    staticLabel->setPosition(Vec2(visibleSize.width/2,
                                  visibleSize.height - 50));
    this->addChild(staticLabel, 1);
    
    auto label = Label::createWithTTF("", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(visibleSize.width/2,
                            visibleSize.height - 200));
    this->addChild(label, 1, 100);
    
    
    
    Button * btn = Button::create("backtotopnormal.png", "backtotoppressed.png");;
    btn->setTitleText("click me");
    btn->setAnchorPoint(Vec2(0.5, 0.5f));
    btn->setPosition(Vec2(visibleSize.width-btn->getContentSize().width,visibleSize.height-btn->getContentSize().height));
    btn->setScale9Enabled(true);
    addChild(btn);
    
    btn->addTouchEventListener(CC_CALLBACK_2(HelloWorld::ClickMe, this));
    
    
    
    
    __NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(HelloWorld::callBack), MSG_STATE, NULL);

    
    return true;
    
    
    
    
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

    return true;
}



void HelloWorld::ClickMe(Ref * pSender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED ) {
        menEnterNextScene(pSender);
    }
}





void HelloWorld::TestSingleton()
{
    Singleton* singleton1 = Singleton::getInstance();
    Singleton* singleton2 = Singleton::getInstance();
    
    if (singleton1 == singleton2) {
        log("singleton1 = singleton2");
    }

}


// 进入下一个场景
void HelloWorld::menEnterNextScene(Ref* pSender)
{
    auto  sc = Scene::create();
    auto  layer = BLayer::create();
//    layer->setDelegator(this);
    sc->addChild(layer);
    
    auto reScene = TransitionSlideInR::create(1.0f, sc);
    Director::getInstance()->pushScene(reScene);
}


void HelloWorld::callBack(cocos2d::Ref *sender)
{
    log("__NotificationCenter callBack");
    __String *str = (__String*)sender;
    Label* label =  (Label*)this->getChildByTag(100);
    if (label)
        label->setString(str->getCString());
}


void HelloWorld::callBack(void *ctx, const char *str)
{
    log("Delegator callBack");
    Label* label =  (Label*)this->getChildByTag(100);
    if (label)
        label->setString(str);
}



HelloWorld::~HelloWorld()
{
    __NotificationCenter::getInstance()->removeObserver(this, MSG_STATE);
}


