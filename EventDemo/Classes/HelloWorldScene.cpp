#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SceneA.h"
#include "SceneB.h"
#include "SceneC.h"
#include "SceneD.h"
#include "SceneE.h"
#include "SceneF.h"
#include "SceneG.h"
#include "SceneH.h"

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
    
    
    
    addListView();
    
    
    return true;
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

    return true;
}




void HelloWorld::addListView()
{
    std::vector<std::string> _array;
    
    // create list view ex data
    
    for (int i = 0; i < 20; ++i)
    {
        std::string ccstr = StringUtils::format("listview_item_%d", i);
        _array.push_back(ccstr);
    }
    
    Size winSize = Director::getInstance()->getVisibleSize();
    Vec2 oirgin = Director::getInstance()->getVisibleOrigin();
    
    
    // Create the list view ex
    ListView* listView = ListView::create();
    // set list view ex direction
    listView->setDirection(ui::ScrollView::Direction::VERTICAL);
    listView->setBounceEnabled(true);
    listView->setBackGroundImage("green_edit.png");
    listView->setBackGroundImageScale9Enabled(true);
    listView->setContentSize(Size(winSize.width-2*20, winSize.height-20 * 2));
    listView->setPosition(Vec2(winSize.width/2,winSize.height/2));
    listView->setAnchorPoint(Vec2(0.5, 0.5));
    listView->addEventListener((ListView::ccListViewCallback)CC_CALLBACK_2(HelloWorld::selectedItemEvent, this));
  
    
    addChild(listView);
    
       // add default item
    ssize_t count = _array.size();
    for (int i = 0; i < count / 4; ++i)
    {
        listView->pushBackDefaultItem();
    }
    // insert default item
    for (int i = 0; i < count / 4; ++i)
    {
        listView->insertDefaultItem(0);
    }
    
    listView->removeAllChildren();
    
    // add custom item
    for (int i = 0; i < count / 4; ++i)
    {
        Button* custom_button = Button::create("button.png", "buttonHighlighted.png");
        custom_button->setName("Title Button");
        custom_button->setScale9Enabled(true);
        
        
        
        custom_button->setContentSize(Size(winSize.width-20, 40));
        
        Layout *custom_item = Layout::create();
        custom_item->setContentSize(custom_button->getContentSize());
        custom_button->setPosition(Vec2(custom_item->getContentSize().width / 2.0f, custom_item->getContentSize().height / 2.0f));
        custom_item->addChild(custom_button);
        
        listView->addChild(custom_item);
    }
    // insert custom item
    Vector<Widget*>& items = listView->getItems();
    ssize_t items_count = items.size();
    for (int i = 0; i < count / 4; ++i)
    {
        Button* custom_button = Button::create("button.png", "buttonHighlighted.png");
        custom_button->setName("Title Button");
        custom_button->setScale9Enabled(true);
        custom_button->setContentSize(Size(winSize.width-20, 40));
        
        Layout *custom_item = Layout::create();
        custom_item->setContentSize(custom_button->getContentSize());
        custom_button->setPosition(Vec2(custom_item->getContentSize().width / 2.0f, custom_item->getContentSize().height / 2.0f));
        custom_item->addChild(custom_button);
        custom_item->setTag(1);
        
        listView->insertCustomItem(custom_item, items_count);
    }
    
    // set item data
    items_count = items.size();
    for (int i = 0; i < items_count; ++i)
    {
        Widget* item = listView->getItem(i);
        Button* button = static_cast<Button*>(item->getChildByName("Title Button"));
        ssize_t index = listView->getIndex(item);
        button->setTitleText(_array[index]);
    }
    
    // remove last item
    listView->removeChildByTag(1);
    
    // remove item by index
    items_count = items.size();
    listView->removeItem(items_count - 1);
    
    // set all items layout gravity
    listView->setGravity(ListView::Gravity::CENTER_VERTICAL);
    
    // set items margin
    listView->setItemsMargin(2.0f);
    
}


void HelloWorld::selectedItemEvent(Ref *pSender, ListView::EventType type)
{
    switch (type)
    {
    
        case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_END:
        {
            ListView* listView = static_cast<ListView*>(pSender);
            CC_UNUSED_PARAM(listView);
            CCLOG("select child end index = %ld", listView->getCurSelectedIndex());
            
            ssize_t  index = listView->getCurSelectedIndex();
            
            if (index==0) {
                auto  sc = Scene::create();
                auto  layer = ALayer::create();
                sc->addChild(layer);
                
                auto reScene = TransitionSlideInR::create(1.0f, sc);
                Director::getInstance()->pushScene(reScene);
            }
            
            else if (index==1){
                auto  sc = Scene::create();
                auto  layer = BLayer::create();
                sc->addChild(layer);
                
                auto reScene = TransitionSlideInR::create(1.0f, sc);
                Director::getInstance()->pushScene(reScene);
                
            }
            
            else if (index==2){
                
                auto  sc = Scene::create();
                auto  layer = CLayer::create();
                sc->addChild(layer);
                
                auto reScene = TransitionSlideInR::create(1.0f, sc);
                Director::getInstance()->pushScene(reScene);
                
            }
            
            
            else if (index==3){
                auto  sc = Scene::create();
                auto  layer = DLayer::create();
                sc->addChild(layer);
                
                auto reScene = TransitionSlideInR::create(1.0f, sc);
                Director::getInstance()->pushScene(reScene);
                
                
                
            }
            
            
            
            else if (index==4){
                
                auto  sc = Scene::create();
                auto  layer = ELayer::create();
                sc->addChild(layer);
                
                auto reScene = TransitionSlideInR::create(1.0f, sc);
                Director::getInstance()->pushScene(reScene);
                
            }
            
            else if (index==5){
                auto  sc = Scene::create();
                auto  layer = FLayer::create();
                sc->addChild(layer);
                
                auto reScene = TransitionSlideInR::create(1.0f, sc);
                Director::getInstance()->pushScene(reScene);
                
            }
            
            else if (index==6){
                auto  sc = Scene::create();
                auto  layer = GLayer::create();
                sc->addChild(layer);
                
                auto reScene = TransitionSlideInR::create(1.0f, sc);
                Director::getInstance()->pushScene(reScene);
                
            }
            
            else if (index==7){
                auto  sc = Scene::create();
                auto  layer = HLayer::create();
                sc->addChild(layer);
                
                auto reScene = TransitionSlideInR::create(1.0f, sc);
                Director::getInstance()->pushScene(reScene);
                
            }
            
            
            break;
        }
        default:
            break;
    }
}


