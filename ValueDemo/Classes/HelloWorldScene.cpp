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
    
    
    
    ValueVector  vec = FileUtils::getInstance()->getValueVectorFromFile("chinese.plist");
    
    std::string info;
    
    
    for(auto &e : vec ){string
        
        auto map = e.asValueMap();
        int id_int = map.at("key").asInt();
        if (id_int ==10) {
            info = map.at("info").asString();
            log("%s",info.c_str());
        }
        
    }
    
    

    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

    return true;
}
