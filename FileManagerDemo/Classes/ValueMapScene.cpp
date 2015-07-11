//
//  DictionaryScene.cpp
//  FileManagerDemo
//
//  Created by ZhangBo on 15/7/11.
//
//

#include "ValueMapScene.h"
#include "HelloWorldScene.h"


USING_NS_CC;

Scene*  ValueMapLayer ::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ValueMapLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ValueMapLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Init Plist");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(ValueMapLayer::OnClickMenu1, this));
    
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Insert Data");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(ValueMapLayer::OnClickMenu2, this));
    
    auto pItmLabel3 = Label::createWithBMFont("fonts/fnt8.fnt", "Delete Data");
    auto pItmMenu3 = MenuItemLabel::create(pItmLabel3, CC_CALLBACK_1(ValueMapLayer::OnClickMenu3, this));
    
    auto pItmLabel4 = Label::createWithBMFont("fonts/fnt8.fnt", "Read Data");
    auto pItmMenu4 = MenuItemLabel::create(pItmLabel4, CC_CALLBACK_1(ValueMapLayer::OnClickMenu4, this));
    
    
    auto pItmLabel5 = Label::createWithBMFont("fonts/fnt8.fnt", "Go Back");
    auto pItmMenu5 = MenuItemLabel::create(pItmLabel5, CC_CALLBACK_1(ValueMapLayer::backMenu, this));
    
    
    Menu* mn = Menu::create(pItmMenu1,pItmMenu2, pItmMenu3,pItmMenu4,pItmMenu5,  NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    return true;
}

void ValueMapLayer::OnClickMenu1(Ref* pSender)
{
    auto sharedFileUtils = FileUtils::getInstance();
    
    ValueMap root;
    ValueVector arry;
    
    //µÚÒ»¸öÔªËØ
    ValueMap dict;
    dict["date"] = "2008-08-16 10:01:01";
    dict["content"] = "³õÊ¼»¯Êý¾Ý¡£";
    arry.push_back(Value(dict));
    
    root["root"] = arry;
    string writablePath = sharedFileUtils->getWritablePath();
    string fullPath = writablePath + "NotesList.plist";
    sharedFileUtils->writeToFile(root, fullPath);

}

void ValueMapLayer::OnClickMenu2(Ref* pSender)
{
    auto sharedFileUtils = FileUtils::getInstance();
    
    string writablePath = sharedFileUtils->getWritablePath();
    string fullPath = writablePath + "NotesList.plist";
    
    bool isExist = false;
    isExist = sharedFileUtils->isFileExist(fullPath);
    if (!isExist) {
        log("NotesList.plist doesn't exist.");
        return;
    }
    
    string currentTime = MyUtility::getCurrentTime();
    log("%s",currentTime.c_str());
    
    ValueMap root = sharedFileUtils->getValueMapFromFile(fullPath);
    ValueVector arry = root["root"].asValueVector();
    
    //ÔªËØ
    ValueMap dict;
    dict["date"] = currentTime;
    dict["content"] = "»¶Ó­Ê¹ÓÃMyNote¡£";
    arry.push_back(Value(dict));
    
    root["root"] = arry;
    sharedFileUtils->writeToFile(root, fullPath);
}

void ValueMapLayer::OnClickMenu3(Ref* pSender)
{
    auto sharedFileUtils = FileUtils::getInstance();
    
    string writablePath = sharedFileUtils->getWritablePath();
    string fullPath = writablePath + "NotesList.plist";
    
    bool isExist = false;
    isExist = sharedFileUtils->isFileExist(fullPath);
    if (!isExist) {
        log("NotesList.plist doesn't exist.");
        return;
    }
    
    ValueMap root = sharedFileUtils->getValueMapFromFile(fullPath);
    ValueVector arry = root["root"].asValueVector();
    
    if (arry.size() > 0) {
        //É¾³ýÒ»¸öÔªËØ
        arry.pop_back();
        
        root["root"] = arry;
        
        string writablePath = sharedFileUtils->getWritablePath();
        string fullPath = writablePath + "NotesList.plist";
        sharedFileUtils->writeToFile(root, fullPath);
    }
}

void ValueMapLayer::OnClickMenu4(Ref* pSender)
{
    auto sharedFileUtils = FileUtils::getInstance();
    
    string writablePath = sharedFileUtils->getWritablePath();
    const string fullPath = writablePath + "NotesList.plist";
    
    bool isExist = false;
    isExist = sharedFileUtils->isFileExist(fullPath);
    if (!isExist) {
        log("NotesList.plist doesn't exist.");
        return;
    }
    
    ValueMap root = sharedFileUtils->getValueMapFromFile(fullPath);
    ValueVector arry = root["root"].asValueVector();
    
    int index = 0;
    for (auto& v: arry)
    {
        log("-----------------");
        ValueMap row = v.asValueMap();
        string date = row["date"].asString();
        string content = row["content"].asString();
        
        log("===>date: : %s", date.c_str());
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
        content = MyUtility::gbk_2_utf8(content);
#endif
        log("===>content: : %s", content.c_str());
    }

}

void ValueMapLayer::backMenu(Ref* pSender)
{
    auto sc = HelloWorld::createScene();
    auto reScene = TransitionSlideInL::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
    
}