//
//  VectorScene.h
//  RefValueDemo
//
//  Created by ZhangBo on 15/7/12.
//
//

#ifndef __RefValueDemo__VectorScene__
#define __RefValueDemo__VectorScene__

#include <stdio.h>

#include "cocos2d.h"
USING_NS_CC;

class VectorLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(VectorLayer);
    
    void backMenu(cocos2d::Ref* pSender);
    void goMenu(cocos2d::Ref* pSender);
    
    
    cocos2d::Vector<cocos2d::Sprite*> list;

};

#endif /* defined(__RefValueDemo__VectorScene__) */
