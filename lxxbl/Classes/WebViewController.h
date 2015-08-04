//
//  WebViewController.h
//  lxxbl
//
//  Created by 卢喜羲 on 15/8/1.
//
//

#ifndef __lxxbl__WebViewController__
#define __lxxbl__WebViewController__

#include "CrossApp.h"
USING_NS_CC;

class WebViewController : public CAViewController,public CAWebViewDelegate {
    
public:
    WebViewController();
    
    virtual ~WebViewController();
    
    CREATE_FUNC(WebViewController);
    
    void initWithWeb(std::string url);
    
    virtual bool onShouldStartLoading(CAWebView* pWebView, const std::string &url);
    
    virtual void onDidFinishLoading(CAWebView* pWebView, const std::string &url);
    
    virtual void onDidFailLoading(CAWebView* pWebView, const std::string &url);
    
    virtual void onJSCallback(CAWebView* pWebView, const std::string &message);
    
protected:
    void viewDidLoad();
    
    void viewDidUnload();
    
private:
    CADipSize m_winSize;
    
    CAWebView* _webView;
};

#endif /* defined(__lxxbl__WebViewController__) */
