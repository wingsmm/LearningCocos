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
* ��ʼ����������
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
	//���Ҫ��ʾ�����ݵĳߴ����ͼ��СС�������ػ���slider
	this->setVisible( !(ratio >= 1) );
}

void ScrollBar::update(float dt)
{
	//�жϵ�ǰ�����Ƿ�����������Ϊ���ݵ�������Ӱ��ContenSize,�Ӷ��޸�slider�Ĵ�С
	auto curContentSize = m_pTarget->getContainer()->getContentSize();
	if ( !(fabsf(curContentSize.height - m_preContentSize.height) <= 0.00001)  || 
		!(fabsf(curContentSize.width - m_preContentSize.width) <= 0.00001) )
	{
		m_preContentSize = curContentSize;
		this->updateSlider();
	}

	//����slider��λ��
	if (m_direction == DIR_VERTICAL)
	{
		//���������λ��
		auto curOffset = m_pTarget->getContentOffset() + (m_preContentSize - m_viewSize) / 2;
		auto sliderOffset = curOffset.y / (m_viewSize.height - curContentSize.height) * 
			(m_viewSize.height - m_pSlider->getContentSize().height);
		//�жϻ����Ƿ񻬳�����
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
	//��������תΪ�ڵ�ǰ�Ӳ��µ�����
	touchPoint = this->convertToNodeSpace(touchPoint);
	//ֻ��Ӧ����˻��鱳���Ĵ���
	if (!m_pBg->getBoundingBox().containsPoint(touchPoint))
	{
		return false;
	}
	//����ȵ���˻��飬�����ñ�־
	if (m_pSlider->getBoundingBox().containsPoint(touchPoint))
	{
		m_sliderTouched = true;
	}
	else//���û�е�����飬�������ǻ��鱳��ͼ
	{
		if (m_direction == DIR_VERTICAL)
		{
			//ͨ������m_pTarget��ƫ�ƣ��Ӷ������˻���slider��λ�ã���Ϊupdate������һֱ����m_pTarget��ƫ��
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
	//ֻ��Ӧ����˻�����ƶ�
	if (m_sliderTouched)
	{
		auto offPos = pTouch->getLocation() - m_firstTouch;
		if (m_direction == DIR_VERTICAL)
		{
			//ͨ������m_pTarget��ƫ�ƣ��Ӷ������˻���slider��λ�ã���Ϊupdate������һֱ����m_pTarget��ƫ��
			auto newOff = m_sliderCurPos.y + offPos.y;
			//�жϻ����Ƿ񻬳�����
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