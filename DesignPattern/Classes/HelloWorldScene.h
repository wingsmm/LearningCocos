#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SceneB.h"

using namespace cocos2d::ui;


class HelloWorld : public cocos2d::Layer ,SceneBDelegator
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    ~HelloWorld();

    
    
    
    void TestSingleton();
    void ClickMe(Ref *pSender, Widget::TouchEventType type);
    void menEnterNextScene(Ref* pSender);

    virtual void callBack(void *ctx, const char *str);
    void callBack(Ref *sender);


};

#endif // __HELLOWORLD_SCENE_H__
