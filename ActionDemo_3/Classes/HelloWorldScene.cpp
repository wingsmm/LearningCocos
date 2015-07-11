#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

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
    
    auto bg = Sprite::create("Background.png");
    bg->setPosition(Vec2(visibleSize.width/2, visibleSize.height /2));
    this->addChild(bg);
    
    auto pItmLabel1 =  Label::createWithBMFont("fonts/fnt2.fnt","Sequence");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu1->setTag(kSequence);
    
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt2.fnt", "Spawn");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu2->setTag(kSpawn);
    
    auto pItmLabel3 = Label::createWithBMFont("fonts/fnt2.fnt", "Repeate");
    auto pItmMenu3 = MenuItemLabel::create(pItmLabel3, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu3->setTag(kRepeate);
    
    auto pItmLabel4 = Label::createWithBMFont("fonts/fnt2.fnt", "RepeatForever");
    auto pItmMenu4 = MenuItemLabel::create(pItmLabel4, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu4->setTag(kRepeatForever1);
    
    auto pItmLabel5 = Label::createWithBMFont("fonts/fnt2.fnt", "Reverse");
    auto pItmMenu5 = MenuItemLabel::create(pItmLabel5, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu5->setTag(kReverse);
    
    auto mn = Menu::create(pItmMenu1,pItmMenu2,pItmMenu3,pItmMenu4,pItmMenu5, NULL);
    mn->alignItemsVerticallyWithPadding(50);
    this->addChild(mn);
    
    return true;
}

void HelloWorld::OnClickMenu(Ref* pSender)
{
    MenuItem *nmitem = (MenuItem*)pSender;
    
    auto  sc = Scene::create();
    auto  layer = MyAction::create();
    layer->setTag(nmitem->getTag());
    
    sc->addChild(layer);
    
    auto reScene = TransitionSlideInR::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
}
