//
//  PostsTableCell.cpp
//  lxxbl
//
//  Created by 卢喜羲 on 15/8/2.
//
//

#include "PostsTableCell.h"


PostsTableCell::PostsTableCell():lableTiele(NULL),lableDesc(NULL) {
    this->setAllowsSelected(false);
}

PostsTableCell::~PostsTableCell() {
    
}

PostsTableCell* PostsTableCell::create(const std::string& identifier,const CADipRect& _rect) {
    PostsTableCell *tableViewCell = new PostsTableCell();
    if (tableViewCell->initWithReuseIdentifier(identifier)) {
        tableViewCell->setFrame(_rect);
        tableViewCell->autorelease();
        return tableViewCell;
    }
    delete tableViewCell;
    tableViewCell = NULL;
    return NULL;
}

void PostsTableCell::highlightedTableViewCell() {
    this->setBackgroundView(CAView::createWithColor(ccc4(0, 0, 0, 64)));
}

void PostsTableCell::selectedTableViewCell() {
    this->setBackgroundView(CAView::createWithColor(ccc4(0, 0, 0, 64)));
}

void PostsTableCell::initWithCell() {
    CADipSize _size = this->getFrame().size;
    lableTiele = CALabel::createWithCenter(CADipRect(_px(_size.width / 2),_px(170/2),_size.width-200,_px(170)));
    lableTiele->setColor(CAColor_black);
    lableTiele->setTextAlignment(CATextAlignmentCenter);
    lableTiele->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
    lableTiele->setFontSize(_px(48));
    lableTiele->setNumberOfLine(2);
    this->getContentView()->addSubview(lableTiele);
    
    lableDesc = CALabel::createWithFrame(CADipRect(_px(20),_px(180),_px(_size.width-40),_px(600)));
    lableDesc->setColor(ccc4(9, 9, 9, 255));
    lableDesc->setTextAlignment(CATextAlignmentCenter);
    lableDesc->setVerticalTextAlignmet(CAVerticalTextAlignmentTop);
    lableDesc->setFontSize(_px(32));
    this->getContentView()->addSubview(lableDesc);
    
    lableTime = CALabel::createWithFrame(CADipRect(_px(20),_px(_size.height - 80),_size.width/2,_px(40)));
    lableTime->setColor(CAColor_black);
    lableTime->setTextAlignment(CATextAlignmentLeft);
    lableTime->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
    lableTime->setFontSize(_px(32));
    this->getContentView()->addSubview(lableTime);
    
}

void PostsTableCell::setModel(postsMsg& msg) {
    lableDesc->setText(msg.desc);
    lableTiele->setText(msg.title);
    lableTime->setText(msg.add_time);
}