#ifndef _SCROLL_BAR_TEST_
#define _SCROLL_BAR_TEST_

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class ScrollBarTest : public Layer,TableViewDataSource,TableViewDelegate
{
public:
	ScrollBarTest();
	~ScrollBarTest();

	static cocos2d::Scene * create();
	virtual bool init();

	virtual Size tableCellSizeForIndex(TableView *table, ssize_t idx);
	virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx);
	virtual ssize_t numberOfCellsInTableView(TableView *table);
	virtual void tableCellTouched(TableView* table, TableViewCell* cell);

	virtual void scrollViewDidScroll(ScrollView* view);
	virtual void scrollViewDidZoom(ScrollView* view);
	
	void onBtnCallback(Ref * obj);
private:
	int m_num;
	TableView * m_tableView;
};

#endif