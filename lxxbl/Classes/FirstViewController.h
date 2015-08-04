
#ifndef __HelloCpp__ViewController__
#define __HelloCpp__ViewController__

#include <iostream>
#include "CrossApp.h"
#include "CrossAppExt.h"

USING_NS_CC;
USING_NS_CC_EXT;

struct postsMsg{
    std::string title;
    std::string desc;
    std::string url;
    std::string add_time;
};

class FirstViewController: public CAViewController ,public CATableViewDataSource,public CATableViewDelegate,public CAScrollViewDelegate
{
    
public:

	FirstViewController();
    
	virtual ~FirstViewController();
    
    void loadNavigationItem();
    
    void loadTableView();
    
    void onClickLeftButton(CAControl *btn, CCPoint point);
    
    virtual void tableViewDidSelectRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row);
    virtual void tableViewDidDeselectRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row);
    virtual void tableViewWillDisplayCellAtIndex(CATableView* table, CATableViewCell* cell, unsigned int section, unsigned int row);
    virtual CATableViewCell* tableCellAtIndex(CATableView* table, const CCSize& cellSize, unsigned int section, unsigned int row);
    virtual unsigned int numberOfRowsInSection(CATableView *table, unsigned int section);
    virtual unsigned int numberOfSections(CATableView *table);
    virtual unsigned int tableViewHeightForRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row);
    
    virtual void scrollViewHeaderBeginRefreshing(CAScrollView* view);
    virtual void scrollViewFooterBeginRefreshing(CAScrollView* view);
    
    void onHeaderRefresh();
    
    void onFooterRefresh();
    
    void requestresult(CAHttpClient* client, CAHttpResponse* response);
    
    void requestFooterResult(CAHttpClient* client, CAHttpResponse* response);
    
    void alertView();
    
    void buttonClick(CAControl* btn, CCPoint point);
    
protected:
    
    void viewDidLoad();
    
    void viewDidUnload();
    
private:
    
    CADipSize m_winSize;
    
    CATableView* tableView;
    
    CAActivityIndicatorView* m_load;
    
    std::vector<postsMsg> m_msg;
    
    int m_page;
    
    CAView* m_alertView;
};


#endif /* defined(__HelloCpp__ViewController__) */
