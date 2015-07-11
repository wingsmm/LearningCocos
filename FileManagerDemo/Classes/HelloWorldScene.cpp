#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "FileUtilsScene.h"
#include "UserDefaultScene.h"
#include "DictionaryScene.h"
#include "ValueMapScene.h"
#include "ValueVectorScene.h"
#include "SqliteLayer.h"
/**
 * 
 
 第14章数据持久化
 14.1使用FileUtils访问文件
 14.1.1Cocos2d-x中的目录
 14.1.2实例： 文件读写
 14.1.3实例： 路径搜索
 14.2持久化简介
 14.3UserDefault数据持久化
 14.3.1UserDefaultAPI
 14.3.2实例： 保存背景音乐和音效设置
 14.4属性列表数据持久化
 14.4.1属性列表简介
 14.4.2实例： MyNotes
 14.4.3使用Dictionary读写属性列表文件
 14.4.4使用ValueMap读写属性列表文件
 14.4.5使用ValueVector读取属性列表文件
 14.5SQLite数据库数据持久化
 14.5.1SQLite数据库简介
 14.5.2Visual Studio下SQLite数据库开发环境设置
 14.5.3实例： 重构MyNotes
 14.5.4创建数据库
 14.5.5SQLite数据库管理工具
 14.5.6查询数据
 14.5.7修改数据
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
    
    
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "FileUtils");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu1->setTag(200);
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "UserDefault");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu2->setTag(201);
    auto pItmLabel3 = Label::createWithBMFont("fonts/fnt8.fnt", "__Dictionary");
    auto pItmMenu3 = MenuItemLabel::create(pItmLabel3, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu3->setTag(202);
    auto pItmLabel4 = Label::createWithBMFont("fonts/fnt8.fnt", "ValueMap");
    auto pItmMenu4 = MenuItemLabel::create(pItmLabel4, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu4->setTag(203);
    
    
    auto pItmLabel5 = Label::createWithBMFont("fonts/fnt8.fnt", "ValueVector");
    auto pItmMenu5 = MenuItemLabel::create(pItmLabel5, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu5->setTag(204);
    
    auto pItmLabel6 = Label::createWithBMFont("fonts/fnt8.fnt", "SQLite");
    auto pItmMenu6 = MenuItemLabel::create(pItmLabel6, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu6->setTag(205);
    
    Menu* mn = Menu::create(pItmMenu1,pItmMenu2, pItmMenu3,pItmMenu4,pItmMenu5, pItmMenu6,NULL);
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
        auto  layer = FileUtilsLayer::create();
        sc->addChild(layer);
    }
    
    if (tag==201) {
        auto  layer = UserDefaultLayer::create();
        sc->addChild(layer);
    }

    if (tag==202) {
        auto  layer = DictionaryLayer::create();
        sc->addChild(layer);
    }
    
    if (tag==203) {
        auto  layer = ValueMapLayer::create();
        sc->addChild(layer);
    }
    
    if (tag==204) {
        auto  layer = ValueVectorLayer::create();
        sc->addChild(layer);
    }
    
    if (tag==205) {
        auto  layer = SqliteLayer::create();
        sc->addChild(layer);
    }
    
    auto reScene = TransitionSlideInR::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
}
