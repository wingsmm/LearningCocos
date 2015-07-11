//
//  SettingScene_4.h
//  MusicDemo
//
//  Created by ZhangBo on 15/7/11.
//
//

#ifndef __MusicDemo__SettingScene_4__
#define __MusicDemo__SettingScene_4__

#include <stdio.h>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class Setting_4 : public cocos2d::Layer
{
    bool isEffect;
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
    
    // a selector callback
    void menuSoundToggleCallback(cocos2d::Ref* pSender);
    void menuMusicToggleCallback(cocos2d::Ref* pSender);
    void menuOkCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Setting_4);
};
#endif /* defined(__MusicDemo__SettingScene_4__) */
