#include "HelloWorldScene.h"




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
    
    rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);
    
    Button * bt1 = dynamic_cast<Button *>(rootNode->getChildByName("Button_1"));

    bt1->addTouchEventListener([&](Ref * pSender,Widget::TouchEventType type){
    
    
        auto layoutParameter = LinearLayoutParameter::create();
        layoutParameter->setGravity(LinearLayoutParameter::LinearGravity::LEFT);
        ScrollView * scrollView = (ScrollView *)rootNode->getChildByName("ScrollView_1");
        Widget * widget = makeWords();
        widget->setLayoutParameter(layoutParameter);
        scrollView->addChild(widget);
        //    scrollView->cocos2d::ui::LayoutProtocol::doLayout();
        log("...%zd",scrollView->getChildren().size());
    
    
    });
    
    
    Button * bt2 = dynamic_cast<Button *>(rootNode->getChildByName("Button_2"));
    
    bt2->addTouchEventListener([&](Ref * p,Widget::TouchEventType type){
    
        auto layoutParameter = LinearLayoutParameter::create();
        layoutParameter->setGravity(LinearLayoutParameter::LinearGravity::RIGHT);
        ScrollView * scrollView = (ScrollView *)rootNode->getChildByName("ScrollView_1");
        Widget * widget = makeWords();
        widget->setLayoutParameter(layoutParameter);
        scrollView->addChild(widget);
        
        log("...%zd",scrollView->getChildren().size());

    
    });
    

    return true;
}




ui::Widget *  HelloWorld::makeWords()
{
    Button * btn = Button::create();
    btn->setTitleText("wingsmm");
    btn->setTitleColor(Color3B(0,0,0));
    return btn;
}
