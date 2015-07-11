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
    
    auto pItmLabel1 =  Label::createWithBMFont("fonts/fnt2.fnt","MoveTo");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu1->setTag(kMoveTo);
    
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt2.fnt", "MoveBy");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu2->setTag(kMoveBy);
    
    auto pItmLabel3 = Label::createWithBMFont("fonts/fnt2.fnt", "JumpTo");
    auto pItmMenu3 = MenuItemLabel::create(pItmLabel3, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu3->setTag(kJumpTo);
    
    auto pItmLabel4 = Label::createWithBMFont("fonts/fnt2.fnt", "JumpBy");
    auto pItmMenu4 = MenuItemLabel::create(pItmLabel4, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu4->setTag(kJumpBy);
    
    auto pItmLabel5 = Label::createWithBMFont("fonts/fnt2.fnt", "BezierBy");
    auto pItmMenu5 = MenuItemLabel::create(pItmLabel5, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu5->setTag(kBezierBy);
    
    auto pItmLabel6 = Label::createWithBMFont("fonts/fnt2.fnt", "ScaleTo");
    auto pItmMenu6 = MenuItemLabel::create(pItmLabel6, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu6->setTag(kScaleTo);
    
    auto pItmLabel7 = Label::createWithBMFont("fonts/fnt2.fnt", "ScaleBy");
    auto pItmMenu7 = MenuItemLabel::create(pItmLabel7, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu7->setTag(kScaleBy);
    
    auto pItmLabel8 = Label::createWithBMFont("fonts/fnt2.fnt", "RotateTo");
    auto pItmMenu8 = MenuItemLabel::create(pItmLabel8, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu8->setTag(kRotateTo);
    
    auto pItmLabel9 = Label::createWithBMFont("fonts/fnt2.fnt", "RotateBy");
    auto pItmMenu9 = MenuItemLabel::create(pItmLabel9, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu9->setTag(kRotateBy);
    
    auto pItmLabel10 = Label::createWithBMFont("fonts/fnt2.fnt", "Blink");
    auto pItmMenu10 = MenuItemLabel::create(pItmLabel10, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu10->setTag(kBlink);
    
    auto pItmLabel11 = Label::createWithBMFont("fonts/fnt2.fnt", "TintTo");
    auto pItmMenu11 = MenuItemLabel::create(pItmLabel11, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu11->setTag(kTintTo);
    
    auto pItmLabel12 = Label::createWithBMFont("fonts/fnt2.fnt", "TintBy");
    auto pItmMenu12 = MenuItemLabel::create(pItmLabel12, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu12->setTag(kTintBy);
    
    auto pItmLabel13 = Label::createWithBMFont("fonts/fnt2.fnt", "FadeTo");
    auto pItmMenu13 = MenuItemLabel::create(pItmLabel13, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu13->setTag(kFadeTo);
    
    auto pItmLabel14 = Label::createWithBMFont("fonts/fnt2.fnt", "FadeIn");
    auto pItmMenu14 = MenuItemLabel::create(pItmLabel14, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu14->setTag(kFadeIn);
    
    auto pItmLabel15 = Label::createWithBMFont("fonts/fnt2.fnt", "FadeOut");
    auto pItmMenu15 = MenuItemLabel::create(pItmLabel15, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu15->setTag(kFadeOut);
    
    auto mn = Menu::create(pItmMenu1,pItmMenu2,pItmMenu3,pItmMenu4,pItmMenu5,
                           pItmMenu6,pItmMenu7,pItmMenu8,pItmMenu9,
                           pItmMenu10,pItmMenu11,pItmMenu12,
                           pItmMenu13,pItmMenu14,pItmMenu15, NULL);
    mn->alignItemsInColumns(3, 3, 3, 3, 3, NULL);
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