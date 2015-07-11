//
//  SceneC.h
//  EventDemo
//
//  Created by ZhangBo on 15/7/6.
//
//

#ifndef __EventDemo__SceneC__
#define __EventDemo__SceneC__

#include <stdio.h>
#include "ApiAccount.h"


class CLayer : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    // 更新单例对象状态.
    void menUpdate(cocos2d::Ref* pSender);
    
    // 返回上一个场景.
    void menReturnPreviousScene(cocos2d::Ref* pSender);
    
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(CLayer);
    
    virtual void onEnter();
    virtual void onExit();
    
};
#endif /* defined(__EventDemo__SceneC__) */
