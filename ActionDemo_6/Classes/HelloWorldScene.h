#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "MyActionScene.h"


typedef enum {
    kFlipX3D = 101,
    kPageTurn3D,
    kLens3D,
    kShaky3D,
    kWaves3D,
    kJumpTiles3D,
    kShakyTiles3D,
    kWavesTiles3D
} ActionTypes;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    // callback
    void OnClickMenu(cocos2d::Ref* pSender);
};

#endif // __HELLOWORLD_SCENE_H__
