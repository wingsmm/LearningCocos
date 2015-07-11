//
//  FileUtilsScene.cpp
//  FileManagerDemo
//
//  Created by ZhangBo on 15/7/11.
//
//


/**
 * 
 
 14.1使用FileUtils访问文件
 14.1.1Cocos2d-x中的目录
 14.1.2实例： 文件读写
 14.1.3实例： 路径搜索
 */

#include "FileUtilsScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* FileUtilsLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = FileUtilsLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool FileUtilsLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Test ResourcesDir Info");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(FileUtilsLayer::OnClickMenu1, this));
    
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Test WritablePath Info");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(FileUtilsLayer::OnClickMenu2, this));
    
    auto pItmLabel3 = Label::createWithBMFont("fonts/fnt8.fnt", "Read File");
    auto pItmMenu3 = MenuItemLabel::create(pItmLabel3, CC_CALLBACK_1(FileUtilsLayer::OnClickMenu3, this));
    
    auto pItmLabel4 = Label::createWithBMFont("fonts/fnt8.fnt", "Write File");
    auto pItmMenu4 = MenuItemLabel::create(pItmLabel4, CC_CALLBACK_1(FileUtilsLayer::OnClickMenu4, this));
    
    
    
    
    
    
    auto pItmLabel5 = Label::createWithBMFont("fonts/fnt8.fnt", "Advanced Write File");
    auto pItmMenu5 = MenuItemLabel::create(pItmLabel5, CC_CALLBACK_1(FileUtilsLayer::OnClickMenu5, this));
    
    auto pItmLabel6 = Label::createWithBMFont("fonts/fnt8.fnt", "Advanced Search File");
    auto pItmMenu6 = MenuItemLabel::create(pItmLabel6, CC_CALLBACK_1(FileUtilsLayer::OnClickMenu6, this));

   
    auto pItmLabel7 = Label::createWithBMFont("fonts/fnt8.fnt", "Back ");
    auto pItmMenu7 = MenuItemLabel::create(pItmLabel7, CC_CALLBACK_1(FileUtilsLayer::backMenu, this));
    
    
    Menu* mn = Menu::create(pItmMenu1,pItmMenu2, pItmMenu3,pItmMenu4, pItmMenu5,pItmMenu6,pItmMenu7 ,NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    
    
    return true;
}

void FileUtilsLayer::backMenu(Ref* pSender)
{
    auto sc = HelloWorld::createScene();
    auto reScene = TransitionSlideInL::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
    
}


void FileUtilsLayer::OnClickMenu1(Ref* pSender)
{
    auto sharedFileUtils = FileUtils::getInstance();
    std::string fullPathForFilename = sharedFileUtils->fullPathForFilename("test.txt");
    log("fullPathForFilename path = %s", fullPathForFilename.c_str());
    
    bool isExist = false;
    isExist = sharedFileUtils->isFileExist("test.txt");
    log("%s",isExist ? "test.txt exists" : "test.txt doesn't exist");
    
}

void FileUtilsLayer::OnClickMenu2(Ref* pSender)
{
    auto sharedFileUtils = FileUtils::getInstance();
    std::string writablePath = sharedFileUtils->getWritablePath();
    log("writablePath = %s", writablePath.c_str());
}

void FileUtilsLayer::OnClickMenu3(Ref* pSender)
{
    auto sharedFileUtils = FileUtils::getInstance();
    std::string fullPathForFilename = sharedFileUtils->fullPathForFilename("test.txt");
    log("test.txt path = %s", fullPathForFilename.c_str());
    
    Data data = sharedFileUtils->getDataFromFile(fullPathForFilename);
    //Data构建string
    std::string content1 = std::string((const char*)data.getBytes(),0,data.getSize());
    log("content1 : %s",content1.c_str());
    std::string content2 = sharedFileUtils->getStringFromFile(fullPathForFilename);
    log("content2 : %s",content2.c_str());
}

void FileUtilsLayer::OnClickMenu4(Ref* pSender)
{
    auto sharedFileUtils = FileUtils::getInstance();
    //std::string ret;
    
    std::string writablePath = sharedFileUtils->getWritablePath();
    std::string fileName = writablePath+"test.txt";
    char szBuf[100] = "Testing Write to file.";
    FILE* fp = fopen(fileName.c_str(), "wb");
    if (fp)
    {
        size_t ret = fwrite(szBuf, 1, strlen(szBuf), fp);
        fclose(fp);
        if (ret != 0)
            log("Writing file to  path succeed.");
    }
}

void FileUtilsLayer::OnClickMenu5(Ref* pSender)
{
    auto sharedFileUtils = FileUtils::getInstance();
    std::string ret;
    
    sharedFileUtils->purgeCachedEntries();
    std::string writablePath = sharedFileUtils->getWritablePath();
    std::string fileName = writablePath+"test.txt";
    char szBuf[100] = "The file is in the resources directory";
    FILE* fp = fopen(fileName.c_str(), "wb");
    if (fp)
    {
        size_t ret = fwrite(szBuf, 1, strlen(szBuf), fp);
        fclose(fp);
        if (ret != 0)
            log("Writing file to  path succeed.");
    }
}

void FileUtilsLayer::OnClickMenu6(Ref* pSender)
{
    
    auto sharedFileUtils = FileUtils::getInstance();
    
    sharedFileUtils->purgeCachedEntries();
    
    std::vector<std::string> searchPaths = sharedFileUtils->getSearchPaths();
    std::string writablePath = sharedFileUtils->getWritablePath();
    
    searchPaths.insert(searchPaths.begin(), "dir1");
    searchPaths.insert(searchPaths.begin()+1, writablePath);
    sharedFileUtils->setSearchPaths(searchPaths);
    
    std::string fullPathForFilename = sharedFileUtils->fullPathForFilename("test.txt");
    log("test.txt 's fullPathForFilename is : %s",fullPathForFilename.c_str());
    
    Data data = sharedFileUtils->getDataFromFile(fullPathForFilename);
    std::string content = sharedFileUtils->getStringFromFile(fullPathForFilename);
    log("File content is : %s",content.c_str());
}
