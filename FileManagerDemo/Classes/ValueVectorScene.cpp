//
//  ValueVectorScene.cpp
//  FileManagerDemo
//
//  Created by ZhangBo on 15/7/11.
//
//

#include "ValueVectorScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* ValueVectorLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ValueVectorLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ValueVectorLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto pItmLabel = Label::createWithBMFont("fonts/fnt8.fnt", "Read Data");
    auto pItmMenu = MenuItemLabel::create(pItmLabel, CC_CALLBACK_1(ValueVectorLayer::OnClickMenu, this));
    
    
    auto pItmLabel5 = Label::createWithBMFont("fonts/fnt8.fnt", "Go Back");
    auto pItmMenu5 = MenuItemLabel::create(pItmLabel5, CC_CALLBACK_1(ValueVectorLayer::backMenu, this));
    

    Menu* mn = Menu::create(pItmMenu,pItmMenu5,  NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    return true;
}

void ValueVectorLayer::OnClickMenu(Ref* pSender)
{
    auto sharedFileUtils = FileUtils::getInstance();
    std::string fullPath = sharedFileUtils->fullPathForFilename("NotesList.plist");
    log("fullPathForFilename path = %s", fullPath.c_str());
    
    ValueVector arry  = sharedFileUtils->getValueVectorFromFile(fullPath);
    
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

void ValueVectorLayer::backMenu(Ref* pSender)
{
    auto sc = HelloWorld::createScene();
    auto reScene = TransitionSlideInL::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
    
}
