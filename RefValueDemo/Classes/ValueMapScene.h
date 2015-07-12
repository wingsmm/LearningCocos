//
//  ValueMapScene.h
//  RefValueDemo
//
//  Created by ZhangBo on 15/7/12.
//
//

#ifndef __RefValueDemo__ValueMapScene__
#define __RefValueDemo__ValueMapScene__

#include <stdio.h>
#include "cocos2d.h"

class ValueMapLayer : public cocos2d::Layer
{
    cocos2d::ValueMap map1;
    cocos2d::ValueMap map2;

public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(ValueMapLayer);
    
    void backMenu(cocos2d::Ref* pSender);
    void goMenu(cocos2d::Ref* pSender);
    
};

#endif /* defined(__RefValueDemo__ValueMapScene__) */
