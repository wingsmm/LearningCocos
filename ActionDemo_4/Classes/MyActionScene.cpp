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

	auto bg = Sprite::create("Background.png");
	bg->setPosition(Vec2(visibleSize.width/2, visibleSize.height /2));
	this->addChild(bg);


	sprite = Sprite::create("hero.png");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(sprite);

	auto backMenuItem = MenuItemImage::create("Back-up.png","Back-down.png", CC_CALLBACK_1(MyAction::backMenu, this));
	backMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(140, 65)));

	auto goMenuItem = MenuItemImage::create("Go-up.png","Go-down.png", CC_CALLBACK_1(MyAction::goMenu, this));
	goMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(820, 540)));

	auto mn = Menu::create(backMenuItem, goMenuItem, NULL);

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
    FiniteTimeAction * ac1 = (FiniteTimeAction *)MoveBy::create(2, Vec2(200, 0));
    FiniteTimeAction * ac2 = ((FiniteTimeAction *)ac1)->reverse();
    
    ActionInterval * ac = Sequence::create(ac1, ac2, NULL);
    
    switch (this->getTag()) {
        case kEaseIn:
            sprite->runAction(EaseIn::create(ac, 3));
            break;
        case kEaseOut:
            sprite->runAction(EaseOut::create(ac, 3));
            break;
        case kEaseInOut:
            sprite->runAction(EaseInOut::create(ac, 3));
            break;
        case kEaseSineIn:
            sprite->runAction(EaseSineIn::create(ac));
            break;
        case kEaseSineOut:
            sprite->runAction(EaseSineOut::create(ac));
            break;
        case kEaseSineInOut:
            sprite->runAction(EaseSineInOut::create(ac));
            break;
        case kEaseExponentialIn:
            sprite->runAction(EaseExponentialIn::create(ac));
            break;
        case kEaseExponentialOut:
            sprite->runAction(EaseExponentialOut::create(ac));
            break;
        case kEaseExponentialInOut:
            sprite->runAction(EaseExponentialInOut::create(ac));
            break;
        case kSpeed:
            sprite->runAction(Speed::create(ac, (CCRANDOM_0_1() * 5)));
            break;
    }
}

