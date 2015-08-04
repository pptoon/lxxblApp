
#include "FirstViewController.h"
#include "RootWindow.h"
#include "PostsTableCell.h"
#include "WebViewController.h"

FirstViewController::FirstViewController():m_page(1)
{

}

FirstViewController::~FirstViewController()
{

}

void FirstViewController::viewDidLoad()
{
	m_winSize = this->getView()->getBounds().size;
    
    this->loadNavigationItem();
    
    CAHttpRequest *request = new CAHttpRequest();
    std::string url = "http://weichat.lxxbl.com/lists.php?page=1";
    request->setUrl(url.c_str());
    request->setRequestType(CAHttpRequest::kHttpGet);
    request->setResponseCallback(this, httpresponse_selector(FirstViewController::requestresult));
    //request->setTag("GET");
    CAHttpClient::getInstance()->send(request);
    request->release();
    
    //this->loadTableView();
    
    m_load = CAActivityIndicatorView::createWithCenter(CADipRect(m_winSize.width / 2,m_winSize.height / 2, 50,50));
    this->getView()->addSubview(m_load);
    m_load->setLoadingMinTime(0.5f);
    m_load->setTargetOnCancel(this, callfunc_selector(FirstViewController::loadTableView));
    //m_load->stopAnimating();
}

void FirstViewController::alertView() {
    if (m_alertView) {
        this->getView()->removeSubview(m_alertView);
    }
    
    CADipSize winSize = this->getView()->getBounds().size;
    
    m_alertView = CAView::createWithFrame(this->getView()->getBounds());
    this->getView()->addSubview(m_alertView);
    
    CAImageView *bg = CAImageView::createWithFrame(CADipRect(0,0,winSize.width,winSize.height));
    bg->setImageViewScaleType(CAImageViewScaleTypeFitImageCrop);
    bg->setImage(CAImage::create("r/bg1.png"));
    
    CAButton *btn = CAButton::create(CAButtonTypeRoundedRect);
    btn->setCenter(CADipRect(winSize.width / 2,winSize.height / 2,winSize.width,winSize.height));
    btn->setBackGroundViewForState(CAControlStateNormal, bg);
    btn->setBackGroundViewForState(CAControlStateHighlighted, bg);
    btn->setTitleColorForState(CAControlStateNormal, CAColor_white);
    btn->addTarget(this, CAControl_selector(FirstViewController::buttonClick), CAControlEventTouchUpInSide);
    
    m_alertView->addSubview(btn);
    
    CALabel *lable = CALabel::createWithCenter(CADipRect(winSize.width / 2,winSize.height - 100,winSize.width,_px(40)));
    lable->setColor(CAColor_gray);
    lable->setTextAlignment(CATextAlignmentCenter);
    lable->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
    lable->setText("网络不给力，请点击屏幕重新加载〜");
    lable->setFontSize(_px(24));
    m_alertView->addSubview(lable);
    
}

void FirstViewController::buttonClick(CAControl* btn, CCPoint point) {
    this->getView()->removeSubview(m_alertView);
    m_alertView = NULL;
    
    CAHttpRequest *request = new CAHttpRequest();
    std::string url = "http://weichat.lxxbl.com/lists.php?page=1";
    request->setUrl(url.c_str());
    request->setRequestType(CAHttpRequest::kHttpGet);
    request->setResponseCallback(this, httpresponse_selector(FirstViewController::requestresult));
    //request->setTag("GET");
    CAHttpClient::getInstance()->send(request);
    request->release();
    
    //this->loadTableView();
    
    m_load = CAActivityIndicatorView::createWithCenter(CADipRect(m_winSize.width / 2,m_winSize.height / 2, 50,50));
    this->getView()->addSubview(m_load);
    m_load->setLoadingMinTime(0.5f);
    m_load->setTargetOnCancel(this, callfunc_selector(FirstViewController::loadTableView));
    
}

void FirstViewController::requestresult(CAHttpClient* client, CAHttpResponse* response) {
    if (!response->isSucceed()) {
        return;
    }
    m_page = 1;
    int statusCode = response->getResponseCode();
    if (statusCode == 200) {
        std::vector<char> *buffer = response->getResponseData();
        std::string data(buffer->data(),buffer->size());
        
        m_msg.clear();
        
        CSJson::Reader reader;
        CSJson::Value  value;
        if (reader.parse(data, value)) {
            int status = value["status"].asInt();
            if (status == 200) {
                CSJson::Value& msg = value["msg"];
                int lenght = msg.size();
                
                for (int i = 0; i < lenght; i++) {
                    postsMsg posts;
                    posts.title = msg[i]["title"].asString();
                    posts.desc = msg[i]["desc"].asString();
                    posts.url = msg[i]["url"].asString();
                    posts.add_time = msg[i]["addtime"].asString();
                    
                    m_msg.push_back(posts);
                }
                
            } else {
                CAAlertView* alertView = CAAlertView::createWithText(UTF8("提示"), UTF8("没有更多的数据了"), UTF8("确定"),NULL);
                alertView->show();
            }
        } else {
            CAAlertView* alertView = CAAlertView::createWithText(UTF8("提示"), UTF8("数据解析错误"), UTF8("确定"),NULL);
            alertView->show();
        }
        
    } else {
        CAAlertView* alertView = CAAlertView::createWithText(UTF8("提示"), UTF8("数据解析错误"), UTF8("确定"),NULL);
        alertView->show();
    }
    
    do {
        CC_BREAK_IF(m_load == NULL);
        if (m_load->isAnimating()) {
            m_load->stopAnimating();
        } else {
            tableView->reloadData();
        }
    
    }while(0);
}

void FirstViewController::requestFooterResult(CAHttpClient* client, CAHttpResponse* response) {
    if (!response->isSucceed()) {
        m_page--;
        return;
    }
    
    int statusCode = response->getResponseCode();
    if (statusCode == 200) {
        std::vector<char> *buffer = response->getResponseData();
        std::string data(buffer->data(),buffer->size());
        
        CSJson::Reader reader;
        CSJson::Value  value;
        if (reader.parse(data, value)) {
            int status = value["status"].asInt();
            if (status == 200) {
                CSJson::Value& msg = value["msg"];
                int lenght = msg.size();
                
                for (int i = 0; i < lenght; i++) {
                    postsMsg posts;
                    posts.title = msg[i]["title"].asString();
                    posts.desc = msg[i]["desc"].asString();
                    posts.url = msg[i]["url"].asString();
                    posts.add_time = msg[i]["addtime"].asString();
                    
                    m_msg.push_back(posts);
                }
            } else {
                m_page--;
                CAAlertView* alertView = CAAlertView::createWithText(UTF8("提示"), UTF8("没有更多的数据了"), UTF8("确定"),NULL);
                alertView->show();
            }
        } else {
            m_page--;
            CAAlertView* alertView = CAAlertView::createWithText(UTF8("提示"), UTF8("数据解析错误"), UTF8("确定"),NULL);
            alertView->show();
        }
        
    } else {
        m_page--;
        CAAlertView* alertView = CAAlertView::createWithText(UTF8("提示"), UTF8("数据解析错误"), UTF8("确定"),NULL);
        alertView->show();
    }
    
    do {
        CC_BREAK_IF(m_load == NULL);
        if (m_load->isAnimating()) {
            m_load->stopAnimating();
        } else {
            tableView->reloadData();
        }
        
    }while(0);
}

void FirstViewController::viewDidUnload()
{
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

void FirstViewController::loadNavigationItem() {
    CABarButtonItem *left = CABarButtonItem::create("", CAImage::create("r/pop_residemenu_humbger.png"), NULL);
    left->setTarget(this, CAControl_selector(FirstViewController::onClickLeftButton));
    CANavigationBarItem *navigationItem = CANavigationBarItem::create("任性是一种态度");
    navigationItem->addLeftButtonItem(left);
    this->setNavigationBarItem(navigationItem);
    
}

void FirstViewController::loadTableView() {
    //m_msg.clear(); 测试
    if (m_msg.empty()) {
        alertView();
        return;
    }
    
    if (tableView != NULL) {
        this->getView()->removeSubview(tableView);
        tableView = NULL;
    }
    
    tableView = CATableView::createWithFrame(CADipRect(0,0,_px(m_winSize.width),_px(m_winSize.height)));
    tableView->setAllowsMultipleSelection(false);
    tableView->setAllowsSelection(true);
    tableView->setTableViewDataSource(this);
    tableView->setTableViewDelegate(this);
    tableView->setScrollViewDelegate(this);
    tableView->setShowsScrollIndicators(false);
    //tableView->setSeparatorViewHeight(0.f);
    CAPullToRefreshView *headerRefreshView = CAPullToRefreshView::create(CAPullToRefreshView::CAPullToRefreshTypeHeader);
    CAPullToRefreshView *footerRefreshView = CAPullToRefreshView::create(CAPullToRefreshView::CAPullToRefreshTypeHeader);
    tableView->setHeaderRefreshView(headerRefreshView);
    tableView->setFooterRefreshView(footerRefreshView);
    
    this->getView()->addSubview(tableView);
    
}

void FirstViewController::onClickLeftButton(CAControl *btn, CCPoint point) {
    RootWindow::create()->getDrawerController()->showLeftViewController(true);
}


void FirstViewController::tableViewDidSelectRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row) {
    WebViewController *__webView = WebViewController::create();
    __webView->setTitle(m_msg[row].title);
    RootWindow::create()->getNavigationController()->pushViewController(__webView, true);
    __webView->initWithWeb(m_msg[row].url);
    CCLog("%s",m_msg[row].url.c_str());
}

void FirstViewController::tableViewDidDeselectRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row) {
    
}

void FirstViewController::tableViewWillDisplayCellAtIndex(CATableView* table, CATableViewCell* cell, unsigned int section, unsigned int row) {
    
}

CATableViewCell* FirstViewController::tableCellAtIndex(CATableView* table, const CCSize& cellSize, unsigned int section, unsigned int row) {
    CADipSize _size = cellSize;
    PostsTableCell *cell = dynamic_cast<PostsTableCell*>(table->dequeueReusableCellWithIdentifier("CrossApp"));
    if (cell == NULL) {
        cell = PostsTableCell::create("CrossApp",CADipRect(0,0,_px(_size.width),_px(_size.height)));
        cell->initWithCell();
    }
    
    cell->setModel(m_msg[row]);
    return cell;
}

unsigned int FirstViewController::numberOfRowsInSection(CATableView *table, unsigned int section) {
    return m_msg.size();
}

unsigned int FirstViewController::numberOfSections(CATableView *table) {
    return 1;
}

unsigned int FirstViewController::tableViewHeightForRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row) {
    return _px(1000);
}


void FirstViewController::scrollViewHeaderBeginRefreshing(CAScrollView* view) {
    CAHttpRequest *request = new CAHttpRequest();
    std::string url = "http://weichat.lxxbl.com/lists.php?page=1";
    request->setUrl(url.c_str());
    request->setRequestType(CAHttpRequest::kHttpGet);
    request->setResponseCallback(this, httpresponse_selector(FirstViewController::requestresult));
    //request->setTag("GET");
    CAHttpClient::getInstance()->send(request);
    request->release();
    CCLog("上拉");
}

void FirstViewController::scrollViewFooterBeginRefreshing(CAScrollView* view) {
    CAHttpRequest *request = new CAHttpRequest();
    m_page++;
    char url[200];
    sprintf(url, "http://weichat.lxxbl.com/lists.php?page=%d",m_page);
    request->setUrl(url);
    request->setRequestType(CAHttpRequest::kHttpGet);
    request->setResponseCallback(this, httpresponse_selector(FirstViewController::FirstViewController::requestFooterResult));
    //request->setTag("GET");
    CAHttpClient::getInstance()->send(request);
    request->release();
    CCLog("下拉%d",m_page);
}

