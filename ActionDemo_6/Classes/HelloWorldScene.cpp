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
    
    auto bg = Sprite::create("background.png");
    
    // position the label on the center of the screen
    bg->setPosition(Vec2(origin.x + visibleSize.width/2,
                         origin.y + visibleSize.height /2));
    this->addChild(bg);
    
    auto pItmLabelFlipX3D = Label::createWithBMFont("fonts/fnt2.fnt", "FlipX3D");
    auto pItmMenupFlipX3D = MenuItemLabel::create(pItmLabelFlipX3D, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenupFlipX3D->setTag(kFlipX3D);
    
    auto pItmLabelPageTurn3D = Label::createWithBMFont("fonts/fnt2.fnt", "PageTurn3D");
    auto pItmMenuPageTurn3D = MenuItemLabel::create(pItmLabelPageTurn3D, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenuPageTurn3D->setTag(kPageTurn3D);
    
    auto pItmLabelLens3D = Label::createWithBMFont("fonts/fnt2.fnt", "Lens3D");
    auto pItmMenuLens3D = MenuItemLabel::create(pItmLabelLens3D, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenuLens3D->setTag(kLens3D);
    
    auto pItmLabelShaky3D = Label::createWithBMFont("fonts/fnt2.fnt", "Shaky3D");
    auto pItmMenuShaky3D = MenuItemLabel::create(pItmLabelShaky3D, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenuShaky3D->setTag(kShaky3D);
    
    auto pItmLabelWaves3D = Label::createWithBMFont("fonts/fnt2.fnt", "Waves3D");
    auto pItmMenuWaves3D = MenuItemLabel::create(pItmLabelWaves3D, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenuWaves3D->setTag(kWaves3D);
    
    auto pItmLabelJumpTiles3D = Label::createWithBMFont("fonts/fnt2.fnt", "JumpTiles3D");
    auto pItmMenuJumpTiles3D = MenuItemLabel::create(pItmLabelJumpTiles3D, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenuJumpTiles3D->setTag(kJumpTiles3D);
    
    auto pItmLabelShakyTiles3D = Label::createWithBMFont("fonts/fnt2.fnt", "ShakyTiles3D");
    auto pItmMenuShakyTiles3D = MenuItemLabel::create(pItmLabelShakyTiles3D, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenuShakyTiles3D->setTag(kShakyTiles3D);
    
    auto pItmLabelWavesTiles3D = Label::createWithBMFont("fonts/fnt2.fnt", "WavesTiles3D");
    auto pItmMenuWavesTiles3D = MenuItemLabel::create(pItmLabelWavesTiles3D, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenuWavesTiles3D->setTag(kWavesTiles3D);
    
    Menu* mn = Menu::create(pItmMenupFlipX3D,pItmMenuPageTurn3D,
                            pItmMenuLens3D, pItmMenuShaky3D,
                            pItmMenuWaves3D, pItmMenuJumpTiles3D,
                            pItmMenuShakyTiles3D, pItmMenuWavesTiles3D, NULL);
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