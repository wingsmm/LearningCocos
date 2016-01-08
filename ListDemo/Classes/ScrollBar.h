#ifndef _SCROLL__BAR__H_
#define _SCROLL__BAR__H_

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

enum SclBarDirection
{
	DIR_NODIR = 0,
	DIR_VERTICAL,
	DIR_HORIZENTAL,
};

class ScrollBar : public cocos2d::Layer
{
public:
	ScrollBar();
	~ScrollBar();
    /**
     * 因为九宫图不能缩小到比实际图片要小，所以传入的图片的实际大小要足够小，否则slider的大小会有问题
     */
	static ScrollBar * create(Scale9Sprite * bar_bg,Scale9Sprite * bar_slider,TableView * tableView,SclBarDirection dir);
	static ScrollBar * create(const char * bar_bgFile,const char * bar_sliderFile,TableView * tableView,SclBarDirection dir);
	bool myInit(Scale9Sprite * bar_bg,Scale9Sprite * bar_slider,TableView * tableView,SclBarDirection dir);

protected:
	virtual bool onTouchBegan(Touch* touch, Event* pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);

	virtual void update(float dt) override;
    /**
     * 动态改变slider的大小
     */
	void updateSlider();

private:
	TableView * m_pTarget;
	Scale9Sprite * m_pBg;
	Scale9Sprite * m_pSlider;
	SclBarDirection m_direction;
	Size m_preContentSize;
	Size m_viewSize;
	bool m_sliderTouched;
	Vec2 m_firstTouch;
	Vec2 m_sliderCurPos;
	Vec2 m_targetCurPos;
};

#endif