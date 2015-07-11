//
//  SceneA.h
//  EventDemo
//
//  Created by ZhangBo on 15/7/6.
//
//

#ifndef __EventDemo__SceneA__
#define __EventDemo__SceneA__

#include <stdio.h>
#include "ApiAccount.h"



class ALayer : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    // 更新单例对象状态.
    void menUpdate(cocos2d::Ref* pSender);
    
    // 返回上一个场景.
    void menReturnPreviousScene(cocos2d::Ref* pSender);
    
  
    
    // implement the "static create()" method manually
    CREATE_FUNC(ALayer);
    
    
    virtual void onEnter();
    virtual void onExit();
    
    bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void touchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
    void touchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
    
};
#endif /* defined(__EventDemo__SceneA__) */
