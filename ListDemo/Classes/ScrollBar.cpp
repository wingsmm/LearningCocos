#include "ScrollBar.h"

ScrollBar::ScrollBar()
: m_pTarget(nullptr)
, m_pBg(nullptr)
, m_pSlider(nullptr)
, m_direction(DIR_NODIR)
, m_preContentSize(Size::ZERO)
, m_viewSize(Size::ZERO)
, m_sliderTouched(false)
, m_firstTouch(Vec2::ZERO)
, m_sliderCurPos(Vec2::ZERO)
, m_targetCurPos(Vec2::ZERO)
{

}

ScrollBar::~ScrollBar()
{

}

ScrollBar * ScrollBar::create(const char * bar_bgFile,const char * bar_sliderFile,TableView * tableView,SclBarDirection dir)
{
	Scale9Sprite * pBg = Scale9Sprite::create(bar_bgFile);
	Scale9Sprite * pSlider = Scale9Sprite::create(bar_sliderFile);

	return create(pBg,pSlider,tableView,dir);
}

ScrollBar * ScrollBar::create(Scale9Sprite * bar_bg,Scale9Sprite * bar_slider,TableView * tableView,SclBarDirection dir)
{
	ScrollBar * pRet = new ScrollBar();
	if (pRet && pRet->myInit(bar_bg,bar_slider,tableView,dir))
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

/**
* 初始化各个数据
*/
bool ScrollBar::myInit(Scale9Sprite * bar_bg,Scale9Sprite * bar_slider,TableView * tableView,SclBarDirection dir)
{
	if (!Layer::init())
	{
		return false;
	}
	
	m_pBg = bar_bg;
	m_pSlider = bar_slider;
	m_pTarget = tableView;
	m_direction = dir;
	m_preContentSize = m_pTarget->getContainer()->getContentSize();
	m_viewSize = m_pTarget->getViewSize();
	
	if (m_direction == DIR_VERTICAL)
	{
		m_pBg->setContentSize(Size(m_pBg->getContentSize().width,m_viewSize.height));
		m_pBg->setPosition(Vec2(m_pBg->getContentSize().width / 2,0));
		m_pSlider->setPositionX(m_pBg->getContentSize().width / 2);
	} 
	else if (m_direction == DIR_HORIZENTAL)
	{
		m_pBg->setContentSize(Size(m_viewSize.width,m_pBg->getContentSize().height));
		m_pBg->setPosition(Vec2(0,-m_pBg->getContentSize().height / 2));
		m_pSlider->setPositionY(-m_pBg->getContentSize().height / 2);
	}
	
	this->addChild(m_pBg,0);

	this->updateSlider();

	this->addChild(m_pSlider,1);

	this->scheduleUpdate();

	auto listenerT = EventListenerTouchOneByOne::create();
	listenerT->onTouchBegan = CC_CALLBACK_2(ScrollBar::onTouchBegan,this);
	listenerT->onTouchMoved = CC_CALLBACK_2(ScrollBar::onTouchMoved,this);
	listenerT->onTouchEnded = CC_CALLBACK_2(ScrollBar::onTouchEnded,this);
	listenerT->setSwallowTouches(false);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerT,this);

	return true;
}

void ScrollBar::updateSlider()
{
	float ratio = 0.0;
	if (m_direction == DIR_VERTICAL)
	{
		 ratio = m_viewSize.height / m_preContentSize.height;
		 m_pSlider->setContentSize(Size(m_pSlider->getContentSize().width,m_viewSize.height * ratio));
	} 
	else if (m_direction == DIR_HORIZENTAL)
	{
		ratio = m_viewSize.width / m_preContentSize.width;
		m_pSlider->setContentSize(Size(m_viewSize.width * ratio,m_pSlider->getContentSize().height));
	}
	//如果要显示的内容的尺寸比视图大小小，则隐藏滑块slider
	this->setVisible( !(ratio >= 1) );
}

void ScrollBar::update(float dt)
{
	//判断当前内容是否有增减，因为内容的增减会影响ContenSize,从而修改slider的大小
	auto curContentSize = m_pTarget->getContainer()->getContentSize();
	if ( !(fabsf(curContentSize.height - m_preContentSize.height) <= 0.00001)  || 
		!(fabsf(curContentSize.width - m_preContentSize.width) <= 0.00001) )
	{
		m_preContentSize = curContentSize;
		this->updateSlider();
	}

	//设置slider的位置
	if (m_direction == DIR_VERTICAL)
	{
		//调整滑块的位置
		auto curOffset = m_pTarget->getContentOffset() + (m_preContentSize - m_viewSize) / 2;
		auto sliderOffset = curOffset.y / (m_viewSize.height - curContentSize.height) * 
			(m_viewSize.height - m_pSlider->getContentSize().height);
		//判断滑块是否滑出界限
		if (fabsf(sliderOffset) > (m_viewSize.height - m_pSlider->getContentSize().height) / 2)
		{
			return ;
		}
		m_pSlider->setPositionY(sliderOffset);
	}
	else if (m_direction == DIR_HORIZENTAL)
	{
		auto curOffset = m_pTarget->getContentOffset() - (m_preContentSize - m_viewSize) / 2;
		auto sliderOffset = -curOffset.x / (m_viewSize.width - curContentSize.width) * 
			(m_viewSize.width - m_pSlider->getContentSize().width);
		if (fabsf(sliderOffset) > (m_viewSize.width - m_pSlider->getContentSize().width) / 2)
		{
			return ;
		}
		m_pSlider->setPositionX(sliderOffset);
	}
}

bool ScrollBar::onTouchBegan(Touch* touch, Event* pEvent)
{
	m_sliderCurPos = m_pSlider->getPosition();
	m_targetCurPos = m_pTarget->getContentOffset();
	auto touchPoint = touch->getLocation();
	m_firstTouch = touchPoint;
	//将触摸点转为在当前子层下的坐标
	touchPoint = this->convertToNodeSpace(touchPoint);
	//只响应点击了滑块背景的触摸
	if (!m_pBg->getBoundingBox().containsPoint(touchPoint))
	{
		return false;
	}
	//如果先点击了滑块，则设置标志
	if (m_pSlider->getBoundingBox().containsPoint(touchPoint))
	{
		m_sliderTouched = true;
	}
	else//如果没有点击滑块，则点击的是滑块背景图
	{
		if (m_direction == DIR_VERTICAL)
		{
			//通过调整m_pTarget的偏移，从而调整了滑块slider的位置，因为update函数会一直监听m_pTarget的偏移
			auto offset = touchPoint.y - m_sliderCurPos.y;
			if (touchPoint.y <= 0)
			{
				offset += m_pSlider->getContentSize().height / 2;
			} 
			else
			{
				offset -= m_pSlider->getContentSize().height / 2;
			}
			auto newOff = m_targetCurPos.y + offset / (m_pSlider->getContentSize().height - m_viewSize.height) 
				* (m_preContentSize.height - m_viewSize.height);
			m_pTarget->setContentOffset(Vec2(0,newOff));
		}
		else if (m_direction == DIR_HORIZENTAL)
		{
			auto offset = touchPoint.x - m_sliderCurPos.x;
			if (touchPoint.x <= 0)
			{
				offset += m_pSlider->getContentSize().width / 2;
			} 
			else
			{
				offset -= m_pSlider->getContentSize().width / 2;
			}
			auto newOff = m_targetCurPos.x + offset / (m_viewSize.width - m_pSlider->getContentSize().width) 
				* (m_preContentSize.width - m_viewSize.width);
			m_pTarget->setContentOffset(Vec2(newOff,0));
		}
	}
	return true;
}
void ScrollBar::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	//只响应点击了滑块的移动
	if (m_sliderTouched)
	{
		auto offPos = pTouch->getLocation() - m_firstTouch;
		if (m_direction == DIR_VERTICAL)
		{
			//通过调整m_pTarget的偏移，从而调整了滑块slider的位置，因为update函数会一直监听m_pTarget的偏移
			auto newOff = m_sliderCurPos.y + offPos.y;
			//判断滑块是否滑出界限
			if (fabsf(newOff) > (m_viewSize.height - m_pSlider->getContentSize().height) / 2)
			{
				(newOff < 0 ? (newOff = (m_pSlider->getContentSize().height - m_viewSize.height) / 2) : 
					(newOff = (m_viewSize.height - m_pSlider->getContentSize().height) / 2));
			}
			newOff -= m_sliderCurPos.y;
			m_pTarget->setContentOffset(Vec2(0,
				m_targetCurPos.y + newOff / (m_pSlider->getContentSize().height - m_viewSize.height) 
				* (m_preContentSize.height - m_viewSize.height)));
		}
		else if (m_direction == DIR_HORIZENTAL)
		{
			auto newOff = m_sliderCurPos.x + offPos.x;
			if (fabsf(newOff) > (m_viewSize.width - m_pSlider->getContentSize().width) / 2)
			{
				(newOff < 0 ? (newOff = (m_pSlider->getContentSize().width - m_viewSize.width) / 2) : 
					(newOff = (m_viewSize.width - m_pSlider->getContentSize().width) / 2));
			}
			newOff -= m_sliderCurPos.x;
			m_pTarget->setContentOffset(Vec2(m_targetCurPos.x + newOff / (m_viewSize.width - m_pSlider->getContentSize().width) 
				* (m_preContentSize.width - m_viewSize.width),0));
		}
	}
}

void ScrollBar::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	m_sliderTouched = false;
}