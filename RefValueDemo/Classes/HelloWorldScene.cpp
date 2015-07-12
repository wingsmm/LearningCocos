#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ValueScene.h"
#include "ArrayScene.h"
#include "DictionaryScene.h"
#include "ValueVectorScene.h"
#include "ValueMapScene.h"
#include "VectorScene.h"


/**
 *  
 第13章Cocos2d-x中使用的数据容器类
 13.1Cocos2d-x中两大类——Ref和Value
 13.1.1Cocos2d-x根类Ref
 13.1.2包装类Value
 13.2Ref列表容器
 13.2.1Array容器
 13.2.2实例： Array容器
 13.2.3Vector容器
 13.2.4实例： Vector容器
 13.3Ref字典容器
 13.3.1Dictionary容器
 13.3.2实例： Dictionary容器
 13.3.3Map容器
 13.3.4实例： Map容器
 13.4Value列表容器——ValueVector
 13.4.1ValueVector常用API
 13.4.2实例： 使用ValueVector容器
 13.5Value字典容器——ValueMap和ValueMapIntKey
 13.5.1ValueMap和ValueMapIntKey常用API
 13.5.2实例： 使用ValueMap容器
 本章小结
 */

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
    
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Value");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu1->setTag(200);
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Array");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu2->setTag(201);
    auto pItmLabel3 = Label::createWithBMFont("fonts/fnt8.fnt", "Vector");
    auto pItmMenu3 = MenuItemLabel::create(pItmLabel3, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu3->setTag(202);
    auto pItmLabel4 = Label::createWithBMFont("fonts/fnt8.fnt", "Dictinay");
    auto pItmMenu4 = MenuItemLabel::create(pItmLabel4, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu4->setTag(203);
    
    auto pItmLabel5 = Label::createWithBMFont("fonts/fnt8.fnt", "ValueVector");
    auto pItmMenu5 = MenuItemLabel::create(pItmLabel5, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu5->setTag(204);
    auto pItmLabel6 = Label::createWithBMFont("fonts/fnt8.fnt", "ValueMap");
    auto pItmMenu6 = MenuItemLabel::create(pItmLabel6, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu6->setTag(205);

    Menu* mn = Menu::create(pItmMenu1,pItmMenu2, pItmMenu3,pItmMenu4,pItmMenu5,pItmMenu6,NULL);
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
        
        auto layer = ValueLayer::create();
        sc->addChild(layer);
    }
    
    if (tag==201) {
        auto layer = ArrayLayer::create();
        sc->addChild(layer);
    }
    
    if (tag==202) {
        auto layer = VectorLayer::create();
        sc->addChild(layer);
    }
    
    if (tag==203) {
        auto layer = DictionaryLayer::create();
        sc->addChild(layer);
    }
    if (tag==204) {
        auto layer = ValueVectorLayer::create();
        sc->addChild(layer);
    }
    if (tag==205) {
        auto layer = ValueMapLayer::create();
        sc->addChild(layer);
    }
    
    auto reScene = TransitionSlideInR::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
}



#pragma mark - valuetest


