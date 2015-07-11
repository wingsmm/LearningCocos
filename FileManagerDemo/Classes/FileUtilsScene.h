//
//  FileUtilsScene.h
//  FileManagerDemo
//
//  Created by ZhangBo on 15/7/11.
//
//

#ifndef __FileManagerDemo__FileUtilsScene__
#define __FileManagerDemo__FileUtilsScene__

#include <stdio.h>



#include "cocos2d.h"

class FileUtilsLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(FileUtilsLayer);
    
    
    
    //Test ResourcesDir Info
    void OnClickMenu1(cocos2d::Ref* pSender);
    //Test WritablePath Info
    void OnClickMenu2(cocos2d::Ref* pSender);
    //Read File
    void OnClickMenu3(cocos2d::Ref* pSender);
    //Write File
    void OnClickMenu4(cocos2d::Ref* pSender);
    
    
    void OnClickMenu5(cocos2d::Ref* pSender);
    void OnClickMenu6(cocos2d::Ref* pSender);

    void backMenu(Ref* pSender);

};

#endif /* defined(__FileManagerDemo__FileUtilsScene__) */
