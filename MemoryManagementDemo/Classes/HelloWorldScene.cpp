#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <iostream>

#include "Employee_1.h"
#include "Employee_2.h"



USING_NS_CC;

using namespace cocostudio::timeline;
using namespace std;

 /*
  
  第19章Cocos2d-x中的内存管理
  19.1C++内存管理
  19.1.1内存分配区域
  19.1.2动态内存分配
  19.2Ref内存管理
  19.2.1内存引用计数
  19.2.2自动释放池
  19.2.3Ref内存管理规则
  19.3Ref内存管理设计模式
  19.3.1使用静态构造函数
  19.3.2使用访问器
  19.4其他类型内存管理
  19.4.1Value内存管理
  19.4.2Vector和Map内存管理
  
  */

#pragma mark - C++内存管理


class MyObject
{
    public :
    MyObject(){
        cout << "call constructor." << endl;
    }
    
    ~MyObject(){
        cout << "call destructor." << endl;
    }
    
    void initialize(){
        cout << "call initialization." << endl;
    }
    
    void destroy(){
        cout << "call destroy." << endl; 
    }  
};



int test_1(){
    
    MyObject *obj = (MyObject *)malloc(sizeof(MyObject)); // ÉêÇë¶¯Ì¬ÄÚ´æ
    obj->initialize();
    
    //TODO
    
    obj->destroy();
    free(obj);
    obj = NULL;
    
    return 0;
}



int test_2(){
    
    MyObject *obj = new MyObject(); // ÉêÇë¶¯Ì¬ÄÚ´æ
    
    //TODO
    
    delete obj;
    obj = NULL;
    
    return 0;
}





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
    
    auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Music_1");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu1->setTag(200);
    auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Music_2");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu2->setTag(201);
    auto pItmLabel3 = Label::createWithBMFont("fonts/fnt8.fnt", "Music_3");
    auto pItmMenu3 = MenuItemLabel::create(pItmLabel3, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu3->setTag(202);
    auto pItmLabel4 = Label::createWithBMFont("fonts/fnt8.fnt", "Music_4");
    auto pItmMenu4 = MenuItemLabel::create(pItmLabel4, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    pItmMenu4->setTag(203);
    Menu* mn = Menu::create(pItmMenu1,pItmMenu2, pItmMenu3,pItmMenu4,NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    


    return true;
}


void HelloWorld::OnClickMenu(Ref* pSender)
{
    MenuItemLabel * label = dynamic_cast<MenuItemLabel *>(pSender);
    
    long tag = label->getTag();
    
    if (tag==200) {
        test_1();
    }
    
    else if (tag==201){
        test_2();
    }
    
    else if (tag==202){
        Employee_1 e = Employee_1();
    }
    
    else if (tag==203){
        Employee_2 e = Employee_2();
    }
    
    return;
    
    auto  sc = Scene::create();
    
    
    auto reScene = TransitionSlideInR::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
}

