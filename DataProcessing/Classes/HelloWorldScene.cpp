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
    
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "CSVParser");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(HelloWorld::OnClickMenu_1, this));
    
    
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "XMLParser");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(HelloWorld::OnClickMenu_2, this));
    

    Menu* mn = Menu::create(pItmMenu1,pItmMenu2, NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    return true;
}

void HelloWorld::OnClickMenu_1 (Ref* pSender)
{
    __Array* data = CSVParser::parse("Note.csv");
    
    for( int i = 0; i < data->count(); i++ )
    {
        log("--------------Record(%d)-------------------",(i+1));
        __Array* row = static_cast<__Array*>(data->getObjectAtIndex(i));
        for(int j = 0; j < row->count(); j++ )
        {
            __String* str = static_cast<__String*>(row->getObjectAtIndex(j));
            log("%s", str->getCString());
        }
    }
}

void HelloWorld::OnClickMenu_2(Ref* pSender)
{
    auto parser = XmlParser::createWithFile("Notes.xml");
    
    auto list = parser->getList();
    int index = 0;
    for (auto& v: list)
    {
        log("---------------- [%d] -------------------", ++index);
        ValueMap row = v.asValueMap();
        for (auto& pair: row)
        {
            log("===> %s = %s", pair.first.c_str(), pair.second.asString().c_str());
        }
    }
}
