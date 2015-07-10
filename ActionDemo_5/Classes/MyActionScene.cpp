#include "MyActionScene.h"

USING_NS_CC;

Scene* MyAction::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MyAction::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MyAction::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
	
	auto bg = Sprite::create("Background800x480.png");
	bg->setPosition(Vec2(visibleSize.width/2, visibleSize.height /2));
	this->addChild(bg);

    sprite = Sprite::create("Plane.png");
    sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(sprite);

	auto backMenuItem = MenuItemImage::create("Back-up.png","Back-down.png", CC_CALLBACK_1(MyAction::backMenu, this));
	backMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(120, 100)));

	auto goMenuItem = MenuItemImage::create("Go-up.png","Go-down.png", CC_CALLBACK_1(MyAction::goMenu, this));
	goMenuItem->setPosition(visibleSize.width/2, 100);
 
    Menu* mn = Menu::create(backMenuItem, goMenuItem, NULL);
    
	mn->setPosition(Vec2::ZERO);
    this->addChild(mn);
    
    return true;
}

void MyAction::backMenu(Ref* pSender)
{
	auto sc = HelloWorld::createScene();
    auto reScene = TransitionSlideInL::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
    
}

void MyAction::goMenu(Ref* pSender)
{
    log("Tag = %i",this->getTag());
    switch (this->getTag()) {
		case func:
			this->OnCallFunc(pSender);
			break;
		case funcN:
            this->OnCallFuncN(pSender);
			break;
	}
}

void MyAction::OnCallFunc(Ref* pSender)
{
    FiniteTimeAction* ac1 = MoveBy::create(2, Vec2(100, 100));
    FiniteTimeAction* ac2 = ((FiniteTimeAction*)ac1)->reverse();
    
	FiniteTimeAction* acf = CallFunc::create(CC_CALLBACK_0(MyAction::CallBack1, this));
    
    ActionInterval* seq = Sequence::create(ac1, acf, ac2, NULL);
    
    sprite->runAction(Sequence::create(seq, NULL));
}

void MyAction::CallBack1()
{
    sprite->runAction(TintBy::create(0.5, 255, 0, 255));
}

void MyAction::OnCallFuncN(Ref* pSender)
{
    FiniteTimeAction* ac1 = MoveBy::create(2, Vec2(100, 100));
    FiniteTimeAction* ac2 = ((FiniteTimeAction*)ac1)->reverse();
    
    FiniteTimeAction * acf = CallFuncN::create(CC_CALLBACK_1(MyAction::CallBack2,this));
    
    ActionInterval* seq = Sequence::create(ac1, acf, ac2, NULL);
    
    sprite->runAction(Sequence::create(seq, NULL));
}


void MyAction::CallBack2(Ref* pSender)
{
    Sprite* sp = (Sprite*)pSender;
    sp->runAction(TintBy::create(1, 255, 0, 255));
}

