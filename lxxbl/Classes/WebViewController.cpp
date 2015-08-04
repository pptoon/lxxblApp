//
//  WebViewController.cpp
//  lxxbl
//
//  Created by 卢喜羲 on 15/8/1.
//
//

#include "WebViewController.h"


WebViewController::WebViewController() {
    
    
    
}


WebViewController::~WebViewController() {
    CCLog("SHIFANG");
    this->getView()->removeSubview(_webView);
    _webView = NULL;
}


void WebViewController::viewDidLoad() {
    m_winSize = this->getView()->getBounds().size;
    
}

void WebViewController::viewDidUnload() {
    
}

void WebViewController::initWithWeb(std::string url) {
    _webView = CAWebView::createWithFrame(CADipRect(0,0,m_winSize.width,m_winSize.height));
    _webView->setWebViewDelegate(this);
    _webView->loadURL(url);
    this->getView()->addSubview(_webView);
}

bool WebViewController::onShouldStartLoading(CAWebView* pWebView, const std::string &url) {
    CCLog("进入webview触发");
    return true;
}

void WebViewController::onDidFinishLoading(CAWebView* pWebView, const std::string &url) {
    CCLog("干嘛有的2");
}

void WebViewController::onDidFailLoading(CAWebView* pWebView, const std::string &url) {
    CCLog("干嘛有的3");
}

void WebViewController::onJSCallback(CAWebView* pWebView, const std::string &message) {
    CCLog("干嘛有的4");
}