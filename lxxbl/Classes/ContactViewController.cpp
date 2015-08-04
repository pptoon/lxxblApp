//
//  ContactViewController.cpp
//  lxxbl
//
//  Created by 卢喜羲 on 15/8/3.
//
//

#include "ContactViewController.h"

ContactViewController::ContactViewController() {
    
}


ContactViewController::~ContactViewController() {
    
    
    
}


void ContactViewController::viewDidLoad() {
    //this->getNavigationController()->setTitle("联系我");
    CADipSize __winSize = this->getView()->getBounds().size;
    
    CALabel *lable = CALabel::createWithFrame(CADipRect(0,0,__winSize.width,__winSize.height));
    lable->setText("如有任何问题请联系我。QQ:254069025,邮箱:254069025@163.com .帮本人介绍对象者，事成之后有重谢^_^");
    lable->setTextAlignment(CATextAlignmentCenter);
    lable->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
    lable->setFontSize(_px(40));
    this->getView()->addSubview(lable);
    
}


void ContactViewController::viewDidUnload() {
    
}