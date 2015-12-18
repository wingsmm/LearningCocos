#include "ScrollBarTest.h"
#include "ScrollBar.h"

ScrollBarTest::ScrollBarTest()
{
	m_num = 20;
	m_tableView = NULL;
}

ScrollBarTest::~ScrollBarTest()
{

}

Scene * ScrollBarTest::create()
{
	auto scene = Scene::create();
	auto pLayer = new ScrollBarTest();
	if (pLayer && pLayer->init())
	{
		pLayer->autorelease();
		scene->addChild(pLayer);
		return scene;
	}
	else
	{
		CC_SAFE_DELETE(pLayer);
		return NULL;
	}
}

bool ScrollBarTest::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto bgSize = Director::getInstance()->getWinSize();

	auto pBg = Sprite::create("scrollbar/bg_big.png");
	pBg->setPosition(Vec2(bgSize.width / 2,bgSize.height / 2));
	this->addChild(pBg);

	auto pView = Sprite::create("scrollbar/bg_small.png");
	pView->setPosition(Vec2(bgSize.width / 2,bgSize.height / 2));
	this->addChild(pView,2);

	auto BoxSize = pView->getContentSize();
	auto viewSize = Size(BoxSize.width,BoxSize.height * 0.85);
	//Ìí¼Ó±êÌâ
	auto plabel = Label::createWithTTF("ScrollBarTest","fonts/Marker Felt.ttf",30);
	plabel->setPosition(Vec2(BoxSize.width / 2,BoxSize.height * 0.9));
	pView->addChild(plabel);

	m_tableView = TableView::create(this,viewSize);
	m_tableView->ignoreAnchorPointForPosition(false);
	m_tableView->setAnchorPoint(Vec2(0.5,0.5));
	m_tableView->setPosition(Vec2(viewSize.width / 2,viewSize.height / 2));
	m_tableView->setDirection(ScrollView::Direction::VERTICAL);
	m_tableView->setDelegate(this);
	m_tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
	m_tableView->reloadData();
	pView->addChild(m_tableView);

	auto scrollBar_vr = ScrollBar::create("scrollbar/vr_slider_bg.png","scrollbar/vr_slider.png",m_tableView,DIR_VERTICAL);
	scrollBar_vr->setPosition(Vec2(viewSize.width,viewSize.height / 2));
	pView->addChild(scrollBar_vr,2);

	auto addBtn = MenuItemFont::create("Add Content",CC_CALLBACK_1(ScrollBarTest::onBtnCallback,this));
	addBtn->setTag(5);
	addBtn->setPosition(Vec2(viewSize.width / 4,viewSize.height + 80));
	addBtn->setScale(0.5);
	addBtn->setColor(Color3B(255,0,0));
	auto subBtn = MenuItemFont::create("Sub Content",CC_CALLBACK_1(ScrollBarTest::onBtnCallback,this));
	subBtn->setTag(10);
	subBtn->setPosition(Vec2(viewSize.width / 4 * 3,viewSize.height + 80));
	subBtn->setScale(0.5);
	subBtn->setColor(Color3B(255,0,0));
	auto pMenu = Menu::create();
	pMenu->setPosition(Vec2::ZERO);
	pView->addChild(pMenu);
	pMenu->addChild(addBtn);
	pMenu->addChild(subBtn);

	return true;
}

Size ScrollBarTest::tableCellSizeForIndex(TableView *table, ssize_t idx)
{
	return Size(260,60);
}

TableViewCell* ScrollBarTest::tableCellAtIndex(TableView *table, ssize_t idx)
{
	auto cell = table->dequeueCell();
	auto cellSize = this->tableCellSizeForIndex(table, idx);
	auto number = __String::createWithFormat("%d",idx + 1);
	if (!cell)
	{
		cell = new TableViewCell();
		cell->autorelease();

		auto pCellBg = Sprite::create("scrollbar/cell.png");
		pCellBg->setPosition(Vec2(cellSize.width / 2,cellSize.height / 2));
		cell->addChild(pCellBg);

		auto pIcon = Sprite::create("scrollbar/setting.png");
		pIcon->setPosition(Vec2(cellSize.width * 0.85,cellSize.height / 2));
		pIcon->setScale(0.2);
		cell->addChild(pIcon);

		auto pNum = Label::createWithTTF(number->getCString(),"fonts/Marker Felt.ttf",20);
		pNum->setColor(Color3B(255,0,0));
		pNum->setPosition(Vec2(cellSize.width * 0.1,cellSize.height / 2));
		pNum->setTag(100);
		cell->addChild(pNum);
	}
	else
	{
		auto pNum = (Label *)cell->getChildByTag(100);
		pNum->setString(number->getCString());
	}
	return cell;
}

ssize_t ScrollBarTest::numberOfCellsInTableView(TableView *table)
{
	return m_num;
}

void ScrollBarTest::tableCellTouched(TableView* table, TableViewCell* cell)
{

}

void ScrollBarTest::scrollViewDidScroll(ScrollView* view)
{

}
void ScrollBarTest::scrollViewDidZoom(ScrollView* view)
{

}

void ScrollBarTest::onBtnCallback(Ref * obj)
{
	int tag = ((Node *)obj)->getTag();
	if ( tag == 5)
	{
		if (m_num < 100)
		{
			m_num++;
			m_tableView->reloadData();
		}
	}
	else
	{
		if (m_num > 2)
		{
			m_num--;
			m_tableView->reloadData();
		}	
	}
}