//
//  ArrayScene.h
//  RefValueDemo
//
//  Created by ZhangBo on 15/7/12.
//
//

#ifndef __RefValueDemo__ArrayScene__
#define __RefValueDemo__ArrayScene__

#include <stdio.h>

#include "cocos2d.h"


USING_NS_CC;

class ArrayLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(ArrayLayer);
    
    
    
    void backMenu(cocos2d::Ref* pSender);
    void goMenu(cocos2d::Ref* pSender);
    
    
    __Array * list;
    
    ~ArrayLayer();

};


#endif /* defined(__RefValueDemo__ArrayScene__) */
