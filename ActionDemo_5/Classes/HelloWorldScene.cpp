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
    
    auto bg = Sprite::create("Background800x480.png");
    
    // position the label on the center of the screen
    bg->setPosition(Vec2(origin.x + visibleSize.width/2,
                         origin.y + visibleSize.height /2));
    this->addChild(bg);
    
    auto pItmLabel1 = LabelBMFont::create("CallFunc", "fonts/fnt2.fnt");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu1->setTag(func);
    
    auto pItmLabel2 = LabelBMFont::create("CallFuncN", "fonts/fnt2.fnt");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu2->setTag(funcN);
    
    Menu* mn = Menu::create(pItmMenu1,pItmMenu2, NULL);
    mn->alignItemsVertically();
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