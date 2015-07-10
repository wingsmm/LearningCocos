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
	gridNodeTarget = NodeGrid::create();
    addChild(gridNodeTarget);
	
    auto bg = Sprite::create("background.png");
	bg->setPosition(Vec2(visibleSize.width/2, visibleSize.height /2));
	gridNodeTarget->addChild(bg);

    sprite = Sprite::create("hero.png");
    sprite->setPosition(Vec2(visibleSize.width / 2 , visibleSize.height / 2));
    gridNodeTarget->addChild(sprite);
	
	auto backMenuItem = MenuItemImage::create("back-up.png","back-down.png", CC_CALLBACK_1(MyAction::backMenu, this));
	backMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(140, 65)));

	auto goMenuItem = MenuItemImage::create("go-up.png","go-down.png", CC_CALLBACK_1(MyAction::goMenu, this));
	goMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(820, 540)));
 
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
	Size visibleSize = Director::getInstance()->getVisibleSize();
    log("Tag = %i",this->getTag());
    
    switch (this->getTag()) {
		case kFlipX3D:
            gridNodeTarget->runAction(FlipX3D::create(3.0f));
			break;
		case kPageTurn3D:
            gridNodeTarget->runAction(PageTurn3D::create(3.0f, Size(15,10)));
			break;
		case kLens3D:
            gridNodeTarget->runAction(Lens3D::create(3.0f, Size(15,10), Vec2(visibleSize.width/2,visibleSize.height/2), 240));
			break;
		case kShaky3D:
            gridNodeTarget->runAction(Shaky3D::create(3.0f, Size(15,10), 5, false));
			break;
		case kWaves3D:
            gridNodeTarget->runAction(Waves3D::create(3.0f, Size(15,10), 5, 40));
			break;
		case kJumpTiles3D:
            gridNodeTarget->runAction(JumpTiles3D::create(3.0f, Size(15,10), 2, 30));
			break;
		case kShakyTiles3D:
            gridNodeTarget->runAction(ShakyTiles3D::create(3.0f, Size(16,12), 5, false));
			break;
		case kWavesTiles3D:
            gridNodeTarget->runAction(WavesTiles3D::create(3.0f, Size(15,10), 4, 120));
			break;
	}
}
