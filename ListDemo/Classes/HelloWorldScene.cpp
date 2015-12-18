
#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


USING_NS_CC;

using namespace cocostudio::timeline;
using namespace std;
using namespace cocos2d::ui;

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
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);
    

    ScrollView * list = dynamic_cast<ScrollView *>(rootNode->getChildByName("ListView"));
    list->setContentSize(Size(750, 210));
    
    
    for (int i = 0;  i<10 ; ++i) {
        
        
        Layout* layout = Layout::create();
        layout->setContentSize(Size(733, 55));
        
        
        ImageView* imageView_Center = ImageView::create("List/chapter_cursor_bar.png");
        imageView_Center->setAnchorPoint(Vec2(0.0f,0.5f));
        layout->addChild(imageView_Center);
        
        
        
        Size layoutSize = layout->getContentSize();
        
        Layout* layout2 = Layout::create();
        layout2->setContentSize(Size(layoutSize.width - 10, layoutSize.height));
        layout->addChild(layout2);
        
        
        
        
        
        
        Button * favBtn = Button::create("List/chapter_button_favorite_03.png");
        layout2->addChild(favBtn);
        
        

        
        Button * prewBtn = Button::create("List/chapter_bugle.png");
        layout2->addChild(prewBtn);


        ImageView * difficultyImageView = ImageView::create("List/chapter_difficulty_01.png");
        layout2->addChild(difficultyImageView);


        Size prewBtnSize = prewBtn->getContentSize();
        Size favBtnSize = favBtn->getContentSize();
        Size diffcultySize = difficultyImageView->getContentSize();

        float spaceWidth = 30;
        prewBtn->setPosition(Vec2(layoutSize.width- prewBtnSize.width - spaceWidth ,layoutSize.height/2));
        favBtn->setPosition(Vec2(prewBtn->getPosition().x - favBtnSize.width - spaceWidth,layoutSize.height/2));
        difficultyImageView->setPosition(Vec2(favBtn->getPosition().x - diffcultySize.width/2 ,layoutSize.height/2));











        list->addChild(layout);
    }
    

    

    return true;
}
