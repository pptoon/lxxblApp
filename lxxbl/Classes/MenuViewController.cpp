//
//  MenuViewController.cpp
//  lxxbl
//
//  Created by 卢喜羲 on 15/8/1.
//
//

#include "MenuViewController.h"
#include "RootWindow.h"
#include "WebViewController.h"
#include "ContactViewController.h"

MenuViewController::MenuViewController() {
    
}


MenuViewController::~MenuViewController() {
    
    
}


void MenuViewController::viewDidLoad() {
    this->getView()->removeAllSubviews();
    this->getView()->setColor(CAColor_clear);
    m_winSize = this->getView()->getBounds().size;
    
    
    //画圆
    CCPoint cir[2000];
    for (int i=0; i<2000; i++)
    {
        float x = cosf(i * M_PI/180.f) * _px(70);
        float y = sinf(i * M_PI/180.f) * _px(70);
        
        cir[i] = CADipPoint(x, y);
    }
    CADrawView *stencil = CADrawView::create();
    stencil->drawPolygon(cir, 2000, ccc4FFromccc4B(ccc4(36, 191, 207, 255)), 0, ccc4f(1, 1, 0, 1));
    stencil->setCenterOrigin(CADipPoint(_px(210),_px(120)));
    CAClippingView *clipping = CAClippingView::create(stencil);
    CAImageView *imageView = CAImageView::createWithImage(CAImage::create("r/header.png"));
    imageView->setFrame(CADipRect(_px(140),_px(50),_px(140), _px(140)));
    clipping->addSubview(imageView);
    this->getView()->addSubview(clipping);
    
    CALabel *name = CALabel::createWithFrame(CADipRect(_px(135),_px(200),_px(130),_px(40)));
    name->setText(UTF8("卢喜羲"));
    name->setTextAlignment(CATextAlignmentCenter);
    name->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
    name->setFontSize(_px(40));
    name->setColor(CAColor_white);
    this->getView()->addSubview(name);
    
    CALabel *desc = CALabel::createWithFrame(CADipRect(_px(30),_px(250),_px(350),_px(100)));
    desc->setText(UTF8("一个长得很帅的程序员"));
    desc->setTextAlignment(CATextAlignmentCenter);
    desc->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
    desc->setFontSize(_px(32));
    desc->setColor(CAColor_white);
    this->getView()->addSubview(desc);
    
    CAButton *blog = CAButton::create(CAButtonTypeCustom);
    blog->setTitleForState(CAControlStateAll, UTF8("博客"));
    blog->setTitleFontSize(_px(35));
    blog->setTitleColorForState(CAControlStateAll, CAColor_white);
    blog->setFrame(CADipRect(_px(m_winSize.width/2/2),_px(m_winSize.height / 2 / 1.5),_px(130),_px(40)));
    blog->addTarget(this, CAControl_selector(MenuViewController::onClickBlog), CAControlEventTouchDown);
    this->getView()->addSubview(blog);
    
    CAButton *about = CAButton::create(CAButtonTypeCustom);
    about->setTitleFontSize(_px(35));
    about->setTitleForState(CAControlStateAll, UTF8("关于我"));
    about->setTitleFontSize(_px(35));
    about->setTitleColorForState(CAControlStateAll, CAColor_white);
    about->setFrame(CADipRect(_px(m_winSize.width / 2 / 2),_px(m_winSize.height / 2 / 1.2),_px(130),_px(40)));
    about->addTarget(this, CAControl_selector(MenuViewController::onClickAbout), CAControlEventTouchDown);
    this->getView()->addSubview(about);
    
    CAButton *contact = CAButton::create(CAButtonTypeCustom);
    contact->setTitleFontSize(_px(35));
    contact->setTitleForState(CAControlStateAll, UTF8("联系我"));
    contact->setTitleFontSize(_px(35));
    contact->setTitleColorForState(CAControlStateAll, CAColor_white);
    contact->setFrame(CADipRect(_px(m_winSize.width / 2 / 2),_px(m_winSize.height / 2),_px(130),_px(40)));
    contact->addTarget(this, CAControl_selector(MenuViewController::onClickContact), CAControlEventTouchDown);
    this->getView()->addSubview(contact);
    
    CAButton *github = CAButton::create(CAButtonTypeCustom);
    github->setBackGroundViewForState(CAControlStateAll, CAScale9ImageView::createWithImage(CAImage::create("r/github.png")));
    github->setFrame(CADipRect(_px(m_winSize.width / 2 / 2),_px(m_winSize.height / 1.7),_px(130),_px(130)));
    github->addTarget(this, CAControl_selector(MenuViewController::onClickGitHub), CAControlEventTouchDown);
    this->getView()->addSubview(github);
    
}

void MenuViewController::onClickGitHub(CAControl* btn,CCPoint point) {
    RootWindow::create()->dismissModalViewController(true);
    WebViewController *_webView = WebViewController::create();
    _webView->setTitle("我的gitHub");
    RootWindow::create()->getDrawerController()->hideLeftViewController(true);
    RootWindow::create()->getNavigationController()->pushViewController(_webView, false);
    _webView->initWithWeb("https://github.com/lxy254069025");
}

void MenuViewController::onClickBlog(CAControl* btn,CCPoint point) {
    CCLog("blog");
    RootWindow::create()->getDrawerController()->hideLeftViewController(true);
}

void MenuViewController::onClickAbout(CAControl* btn,CCPoint point) {
    RootWindow::create()->dismissModalViewController(true);
    WebViewController *_webView = WebViewController::create();
    _webView->setTitle("关于我");
    RootWindow::create()->getDrawerController()->hideLeftViewController(true);
    RootWindow::create()->getNavigationController()->pushViewController(_webView, false);
    _webView->initWithWeb("http://cv.lxxbl.com");
}


void MenuViewController::onClickContact(CAControl* btn,CCPoint point) {
    ContactViewController *contact = ContactViewController::create();
    contact->setTitle("联系我");
    RootWindow::create()->getDrawerController()->hideLeftViewController(true);
    RootWindow::create()->getNavigationController()->pushViewController(contact, false);
}


void MenuViewController::viewDidUnload() {
    
}