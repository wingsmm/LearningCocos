//
//  SceneB.h
//  AdvancedUI
//
//  Created by ZhangBo on 15/7/3.
//
//

#ifndef __AdvancedUI__SceneB__
#define __AdvancedUI__SceneB__


#define MSG_STATE "scene_notification"


#include <stdio.h>
class  SceneBDelegator
{
public:
    virtual ~SceneBDelegator() {}
    //回调委托对象
    virtual void callBack(void *ctx, const char *str) = 0;
};

class BLayer : public cocos2d::Layer
{
    SceneBDelegator*    _delegator;
public:
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    // 更新单例对象状态.
    void menUpdate(cocos2d::Ref* pSender);
    
    // 返回上一个场景.
    void menReturnPreviousScene(cocos2d::Ref* pSender);
    
    void setDelegator(SceneBDelegator* delegator);
    
    // implement the "static create()" method manually
    CREATE_FUNC(BLayer);
    
};
#endif /* defined(__AdvancedUI__SceneB__) */
