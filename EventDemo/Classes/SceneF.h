//
//  SceneF.h
//  EventDemo
//
//  Created by ZhangBo on 15/7/6.
//
//

#ifndef __EventDemo__SceneF__
#define __EventDemo__SceneF__

#include <stdio.h>
#include "ApiAccount.h"



class FLayer : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    

    
    // 返回上一个场景.
    void menReturnPreviousScene(cocos2d::Ref* pSender);
    
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(FLayer);
    
    
    virtual void onEnter();
    
    virtual void onExit();
       
};
#endif /* defined(__EventDemo__SceneF__) */
