//
//  DictionaryScene.cpp
//  FileManagerDemo
//
//  Created by ZhangBo on 15/7/11.
//
//

#include "DictionaryScene.h"
#include "HelloWorldScene.h"


USING_NS_CC;

Scene*  DictionaryLayer ::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = DictionaryLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool DictionaryLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Init Plist");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(DictionaryLayer::OnClickMenu1, this));
    
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Insert Data");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(DictionaryLayer::OnClickMenu2, this));
    
    auto pItmLabel3 = Label::createWithBMFont("fonts/fnt8.fnt", "Delete Data");
    auto pItmMenu3 = MenuItemLabel::create(pItmLabel3, CC_CALLBACK_1(DictionaryLayer::OnClickMenu3, this));
    
    auto pItmLabel4 = Label::createWithBMFont("fonts/fnt8.fnt", "Read Data");
    auto pItmMenu4 = MenuItemLabel::create(pItmLabel4, CC_CALLBACK_1(DictionaryLayer::OnClickMenu4, this));
    
    
    auto pItmLabel5 = Label::createWithBMFont("fonts/fnt8.fnt", "Go Back");
    auto pItmMenu5 = MenuItemLabel::create(pItmLabel5, CC_CALLBACK_1(DictionaryLayer::backMenu, this));
    
    
    Menu* mn = Menu::create(pItmMenu1,pItmMenu2, pItmMenu3,pItmMenu4,pItmMenu5,  NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    return true;
}

void DictionaryLayer::OnClickMenu1(Ref* pSender)
{
    auto root = __Dictionary::create();
    auto arry = __Array::create();
    
    string currentTime = MyUtility::getCurrentTime();
    log("%s",currentTime.c_str());
    
    //µÚÒ»¸öÔªËØ
    auto dict = __Dictionary::create();
    dict->setObject(String::create("2008-08-16 10:01:01"), "date");
    dict->setObject(String::create("³õÊ¼»¯Êý¾Ý¡£"), "content");
    arry->addObject(dict);
    
    root->setObject(arry, "root");
    
    string writablePath = FileUtils::getInstance()->getWritablePath();
    string fullPath = writablePath + "NotesList.plist";
    
    if(root->writeToFile(fullPath.c_str()))
        log("see the plist file at %s", fullPath.c_str());
    else
        log("write plist file failed");
    
}

void DictionaryLayer::OnClickMenu2(Ref* pSender)
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
    
    auto root = __Dictionary::createWithContentsOfFile(fullPath.c_str());
    
    string currentTime = MyUtility::getCurrentTime();
    log("%s",currentTime.c_str());
    
    //²åÈëÒ»¸öÔªËØ
    auto dict = __Dictionary::create();
    dict->setObject(String::create(currentTime), "date");
    dict->setObject(String::create("»¶Ó­Ê¹ÓÃMyNote¡£"), "content");
    auto arry = static_cast<__Array*>(root->objectForKey("root"));
    
    arry->addObject(dict);
    
    if(root->writeToFile(fullPath.c_str()))
        log("see the plist file at %s", fullPath.c_str());
    else
        log("write plist file failed");
}

void DictionaryLayer::OnClickMenu3(Ref* pSender)
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
    
    auto root = __Dictionary::createWithContentsOfFile(fullPath.c_str());
    
    //É¾³ýÒ»¸öÔªËØ
    auto arry = static_cast<__Array*>(root->objectForKey("root"));
    if (arry->count() > 0) {
        arry->removeLastObject();
        if(root->writeToFile(fullPath.c_str()))
            log("see the plist file at %s", fullPath.c_str());
        else
            log("write plist file failed");
    }
}

void DictionaryLayer::OnClickMenu4(Ref* pSender)
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
    
    auto root = __Dictionary::createWithContentsOfFile(fullPath.c_str());
    auto arry = static_cast<__Array*>(root->objectForKey("root"));
    Ref *obj = nullptr;
    
    CCARRAY_FOREACH(arry, obj)
    {
        log("-----------------");
        auto dict = static_cast<__Dictionary*>(obj);
        __String* date = static_cast<__String*>(dict->objectForKey("date"));
        __String* content = static_cast<__String*>(dict->objectForKey("content"));
        
        log("===>date: : %s", date->getCString());
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
        string content2 = MyUtility::gbk_2_utf8(content->getCString());
        log("===>content: : %s", content2.c_str());
#else
        log("===>content: : %s", content->getCString());
#endif
        
    }
}

void DictionaryLayer::backMenu(Ref* pSender)
{
    auto sc = HelloWorld::createScene();
    auto reScene = TransitionSlideInL::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
    
}