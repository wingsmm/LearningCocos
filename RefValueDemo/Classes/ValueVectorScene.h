//
//  ValueVectorScene.h
//  RefValueDemo
//
//  Created by ZhangBo on 15/7/12.
//
//

#ifndef __RefValueDemo__ValueVectorScene__
#define __RefValueDemo__ValueVectorScene__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class ValueVectorLayer : public cocos2d::Layer
{
    cocos2d::ValueVector list;

public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(ValueVectorLayer);
    
    void backMenu(cocos2d::Ref* pSender);
    void goMenu(cocos2d::Ref* pSender);
    
};

#endif /* defined(__RefValueDemo__ValueVectorScene__) */
