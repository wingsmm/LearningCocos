//
//  SqliteLayer.cpp
//  FileManagerDemo
//
//  Created by ZhangBo on 15/7/11.
//
//

#include "SqliteLayer.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* SqliteLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SqliteLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SqliteLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Init DB");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(SqliteLayer::OnClickMenu1, this));
    
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Insert Data");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(SqliteLayer::OnClickMenu2, this));
    
    auto pItmLabel3 = Label::createWithBMFont("fonts/fnt8.fnt", "Delete Data");
    auto pItmMenu3 = MenuItemLabel::create(pItmLabel3, CC_CALLBACK_1(SqliteLayer::OnClickMenu3, this));
    
    auto pItmLabel4 = Label::createWithBMFont("fonts/fnt8.fnt", "Update Data");
    auto pItmMenu4 = MenuItemLabel::create(pItmLabel4, CC_CALLBACK_1(SqliteLayer::OnClickMenu4, this));
    
    auto pItmLabel5 = Label::createWithBMFont("fonts/fnt8.fnt", "Read Data");
    auto pItmMenu5 = MenuItemLabel::create(pItmLabel5, CC_CALLBACK_1(SqliteLayer::OnClickMenu5, this));
    
    
    auto pItmLabel6 = Label::createWithBMFont("fonts/fnt8.fnt", "Go Back");
    auto pItmMenu6 = MenuItemLabel::create(pItmLabel6, CC_CALLBACK_1(SqliteLayer::backMenu, this));
    
    Menu* mn = Menu::create(pItmMenu1,pItmMenu2, pItmMenu3,pItmMenu4, pItmMenu5, pItmMenu6,NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    return true;
}

void SqliteLayer::OnClickMenu1(Ref* pSender)
{
    NoteDAO::initDB();
    NoteDAO::create("2008-08-16 10:01:02", "初始化数据.");
}

void SqliteLayer::OnClickMenu2(Ref* pSender)
{
    string currentTime = MyUtility::getCurrentTime();
    log("%s",currentTime.c_str());
    NoteDAO::create(currentTime, "欢迎使用MyNote.");
}

void SqliteLayer::OnClickMenu3(Ref* pSender)
{
    NoteDAO::remove("2008-08-16 10:01:02");
}

void SqliteLayer::OnClickMenu4(Ref* pSender)
{
    NoteDAO::modify("2008-08-16 10:01:02", "修改数据.");
}

void SqliteLayer::OnClickMenu5(Ref* pSender)
{
    auto arry = NoteDAO::findAll();
    
    for (auto& v: arry)
    {
        log("-----------------");
        ValueMap row = v.asValueMap();
        string date = row["date"].asString();
        string content = row["content"].asString();
        
        log("===>date: : %s", date.c_str());
        log("===>content: : %s", content.c_str());
    }
    
}


void SqliteLayer::backMenu(Ref* pSender)
{
    auto sc = HelloWorld::createScene();
    auto reScene = TransitionSlideInL::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
    
}







