//
//  UserDefaultScene.h
//  FileManagerDemo
//
//  Created by ZhangBo on 15/7/11.
//
//

#ifndef __FileManagerDemo__UserDefaultScene__
#define __FileManagerDemo__UserDefaultScene__

#include <stdio.h>

#include "cocos2d.h"

#include "SettingScene.h"
#include "SystemHeader.h"

class UserDefaultLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(UserDefaultLayer);
    
    
    
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
    virtual void onExit();
    virtual void onExitTransitionDidStart();
    virtual void cleanup();
    
    void menuItemHelpCallback(cocos2d::Ref* pSender);
    void menuItemStartCallback(cocos2d::Ref* pSender);
    void menuItemSettingCallback(cocos2d::Ref* pSender);

    
    void backMenu(Ref* pSender);
    
};

#endif /* defined(__FileManagerDemo__UserDefaultScene__) */
