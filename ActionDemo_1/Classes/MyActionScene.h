

#ifndef __MYACTION_SCENE_H__
#define __MYACTION_SCENE_H__

#include "cocos2d.h"
#include "HelloWorldScene.h"

typedef enum
{
    PLACE_TAG = 102
    ,FLIPX_TAG
    ,FLIPY_TAG
    ,HIDE_SHOW_TAG
    ,TOGGLE_TAG
} ActionTypes;

class MyAction : public cocos2d::Layer
{
	bool hiddenFlag;
    cocos2d::Sprite *sprite;

public:
	
	static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(MyAction);
	
	// a selector callback
    void goMenu(cocos2d::Ref* pSender);
    void backMenu(cocos2d::Ref* pSender);
};

#endif // __MYACTION_SCENE_H__
