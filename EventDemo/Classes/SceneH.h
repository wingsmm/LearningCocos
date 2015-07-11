//
//  SceneH.h
//  EventDemo
//
//  Created by ZhangBo on 15/7/6.
//
//

#ifndef __EventDemo__SceneH__
#define __EventDemo__SceneH__

#include <stdio.h>
#include "ApiAccount.h"

#define SPEED 			30.0
#define kBall_Tag 		100

class HLayer : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    
    
    // 返回上一个场景.
    void menReturnPreviousScene(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HLayer);
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual void onAcceleration(cocos2d::Acceleration* acc, cocos2d::Event *unused_event);

};

#endif /* defined(__EventDemo__SceneH__) */
