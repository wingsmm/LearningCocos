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
    
    auto pItmLabel1 =  Label::createWithBMFont("fonts/fnt2.fnt","EaseIn");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1,
                                           CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu1->setTag(kEaseIn);
    
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt2.fnt", "EaseOut");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2,
                                           CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu2->setTag(kEaseOut);
    
    auto pItmLabel3 = Label::createWithBMFont("fonts/fnt2.fnt", "EaseInOut");
    auto pItmMenu3 = MenuItemLabel::create(pItmLabel3,
                                           CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu3->setTag(kEaseInOut);
    
    auto pItmLabel4 = Label::createWithBMFont("fonts/fnt2.fnt", "EaseSineIn");
    auto pItmMenu4 = MenuItemLabel::create(pItmLabel4,
                                           CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu4->setTag(kEaseSineIn);
    
    auto pItmLabel5 = Label::createWithBMFont("fonts/fnt2.fnt", "EaseSineOut");
    auto pItmMenu5 = MenuItemLabel::create(pItmLabel5,
                                           CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu5->setTag(kEaseSineOut);
    
    auto pItmLabel6 = Label::createWithBMFont("fonts/fnt2.fnt", "EaseSineInOut");
    auto pItmMenu6 = MenuItemLabel::create(pItmLabel6,
                                           CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu6->setTag(kEaseSineInOut);
    
    auto pItmLabel7 = Label::createWithBMFont("fonts/fnt2.fnt", "EaseExponentialIn");
    auto pItmMenu7 = MenuItemLabel::create(pItmLabel7,
                                           CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu7->setTag(kEaseExponentialIn);
    
    auto pItmLabel8 = Label::createWithBMFont("fonts/fnt2.fnt", "EaseExponentialOut");
    auto pItmMenu8 = MenuItemLabel::create(pItmLabel8,
                                           CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu8->setTag(kEaseExponentialOut);
    
    auto pItmLabel9 = Label::createWithBMFont("fonts/fnt2.fnt", "EaseExponentialInOut");
    auto pItmMenu9 = MenuItemLabel::create(pItmLabel9,
                                           CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu9->setTag(kEaseExponentialInOut);
    
    auto pItmLabel10 = Label::createWithBMFont("fonts/fnt2.fnt", "Speed");
    auto pItmMenu10 = MenuItemLabel::create(pItmLabel10, 
                                            CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu10->setTag(kSpeed);
    
    auto mn = Menu::create(pItmMenu1,pItmMenu2,pItmMenu3,pItmMenu4,pItmMenu5,
                           pItmMenu6,pItmMenu7,pItmMenu8,pItmMenu9, pItmMenu10,NULL);
    
    mn->alignItemsInColumns(2, 2, 2, 2, 2, NULL);
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

