//
//  DictionaryScene.h
//  FileManagerDemo
//
//  Created by ZhangBo on 15/7/11.
//
//

#ifndef __FileManagerDemo__DictionaryScene__
#define __FileManagerDemo__DictionaryScene__

#include <stdio.h>

#include "cocos2d.h"
#include "MyUtility.h"

using namespace std;

class DictionaryLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    //Init Plist
    void OnClickMenu1(cocos2d::Ref* pSender);
    //Insert Data
    void OnClickMenu2(cocos2d::Ref* pSender);
    //Delete Data
    void OnClickMenu3(cocos2d::Ref* pSender);
    //Read Data
    void OnClickMenu4(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(DictionaryLayer);
    
    void backMenu(Ref* pSender);

};


#endif /* defined(__FileManagerDemo__DictionaryScene__) */
