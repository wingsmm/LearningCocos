#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "MyActionScene.h"

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
    
    auto placeLabel = Label::createWithBMFont("fonts/fnt2.fnt", "Place");
    auto placeMenu = MenuItemLabel::create(placeLabel, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    placeMenu->setTag(PLACE_TAG);
    
    auto flipXLabel = Label::createWithBMFont("fonts/fnt2.fnt", "FlipX");
    auto flipXMenu = MenuItemLabel::create(flipXLabel, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    flipXMenu->setTag(FLIPX_TAG);
    
    auto flipYLabel = Label::createWithBMFont("fonts/fnt2.fnt", "FlipY");
    auto flipYMenu = MenuItemLabel::create(flipYLabel, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    flipYMenu->setTag(FLIPY_TAG);
    
    auto hideLabel = Label::createWithBMFont("fonts/fnt2.fnt", "Hide or Show");
    auto hideMenu = MenuItemLabel::create(hideLabel, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    hideMenu->setTag(HIDE_SHOW_TAG);
    
    auto toggleLabel = Label::createWithBMFont("fonts/fnt2.fnt", "Toggle");
    auto toggleMenu = MenuItemLabel::create(toggleLabel, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    toggleMenu->setTag(TOGGLE_TAG);
    
    auto mn = Menu::create(placeMenu,flipXMenu,flipYMenu, hideMenu, toggleMenu, NULL);
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

