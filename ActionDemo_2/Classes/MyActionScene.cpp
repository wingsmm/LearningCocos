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
	Size size = Director::getInstance()->getVisibleSize();

	ccBezierConfig bezier;

	switch (this->getTag()) {
	case kMoveTo:
		sprite->runAction(MoveTo::create(2,Vec2(size.width - 50, size.height - 50)));
		break;
	case kMoveBy:
		sprite->runAction(MoveBy::create(2,Vec2(-50, -50)));
		break;
	case kJumpTo:
		sprite->runAction(JumpTo::create(2,Vec2(150, 50),30,5));
		break;
	case kJumpBy:
		sprite->runAction(JumpBy::create(2,Vec2(100, 100),30,5));
		break;
	case kBezierBy:
		bezier.controlPoint_1 = Vec2(0, size.height/2);
		bezier.controlPoint_2 = Vec2(300, -size.height/2);
		bezier.endPosition = Vec2(100,100);
		sprite->runAction(BezierBy::create(3,bezier));
		break;
	case kScaleTo:
		sprite->runAction(ScaleTo::create(2, 4));
		break;
	case kScaleBy:
		sprite->runAction(ScaleBy::create(2, 0.5));
		break;
	case kRotateTo:
		sprite->runAction(RotateTo::create(2,180));
		break;
	case kRotateBy:
		sprite->runAction(RotateBy::create(2,-180));
		break;
	case kBlink:
		sprite->runAction(Blink::create(3, 5));
		break;
	case kTintTo:
		sprite->runAction(TintTo::create(2, 255, 0, 0));
		break;
	case kTintBy:
		sprite->runAction(TintBy::create(0.5,0, 255, 255));
		break;
	case kFadeTo:
		sprite->runAction(FadeTo::create(1, 80));
		break;
	case kFadeIn:
		sprite->setOpacity(10);
		sprite->runAction(FadeIn::create(1));
		break;
	case kFadeOut:
		sprite->runAction(FadeOut::create(1));
		break;
	default:
		break;
	}
}