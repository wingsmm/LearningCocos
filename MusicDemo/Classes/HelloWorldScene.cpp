#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "MusicScene_1.h"
#include "MusicScene_2.h"
#include "MusicScene_3.h"
#include "MusicScene_4.h"



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
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Music_1");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu1->setTag(200);
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Music_2");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu2->setTag(201);
    auto pItmLabel3 = Label::createWithBMFont("fonts/fnt8.fnt", "Music_3");
    auto pItmMenu3 = MenuItemLabel::create(pItmLabel3, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu3->setTag(202);
    auto pItmLabel4 = Label::createWithBMFont("fonts/fnt8.fnt", "Music_4");
    auto pItmMenu4 = MenuItemLabel::create(pItmLabel4, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu4->setTag(203);
    Menu* mn = Menu::create(pItmMenu1,pItmMenu2, pItmMenu3,pItmMenu4,NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    


    return true;
}

void HelloWorld::OnClickMenu(Ref* pSender)
{
    MenuItemLabel * label = dynamic_cast<MenuItemLabel *>(pSender);
    
    long tag = label->getTag();
    
    auto  sc = Scene::create();
    
    if (tag==200) {
        auto  layer = MusicLayer_1::create();
        sc->addChild(layer);
    }
    
    if (tag==201) {
        auto  layer = MusicLayer_2::create();
        sc->addChild(layer);
    }
    
    if (tag==202) {
        auto  layer = MusicLayer_3::create();
        sc->addChild(layer);
    }
    
    if (tag==203) {
        auto  layer = MusicLayer_4::create();
        sc->addChild(layer);
    }
    
    auto reScene = TransitionSlideInR::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
}

