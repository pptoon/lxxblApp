//
//  PostsTableCell.h
//  lxxbl
//
//  Created by 卢喜羲 on 15/8/2.
//
//

#ifndef __lxxbl__PostsTableCell__
#define __lxxbl__PostsTableCell__

#include "CrossApp.h"
#include "FirstViewController.h"
USING_NS_CC;

class PostsTableCell:public CATableViewCell  {
    
public:
    PostsTableCell();
    
    virtual ~PostsTableCell();
    
    static PostsTableCell* create(const std::string& identifier,const CADipRect& _rect = CADipRectZero);
    
    virtual void highlightedTableViewCell();
    
    virtual void selectedTableViewCell();
    
    void initWithCell();
    
    void setModel(postsMsg& msg);
    
private:
    CALabel* lableTiele;
    
    CALabel* lableDesc;
    
    CALabel* lableTime;
};

#endif /* defined(__lxxbl__PostsTableCell__) */
