//
//  MusicScene_1.h
//  MusicDemo
//
//  Created by ZhangBo on 15/7/11.
//
//

#ifndef __MusicDemo__MusicScene_1__
#define __MusicDemo__MusicScene_1__

#include <stdio.h>

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "SettingScene_1.h"

using namespace CocosDenshion;

class MusicLayer_1 : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
    virtual void onExit();
    virtual void onExitTransitionDidStart();
    virtual void cleanup();
    
    void menuItemHelpCallback(cocos2d::Ref* pSender);
    void menuItemStartCallback(cocos2d::Ref* pSender);
    void menuItemSettingCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MusicLayer_1);
};



#endif /* defined(__MusicDemo__MusicScene_1__) */
