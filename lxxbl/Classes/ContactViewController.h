//
//  ContactViewController.h
//  lxxbl
//
//  Created by 卢喜羲 on 15/8/3.
//
//

#ifndef __lxxbl__ContactViewController__
#define __lxxbl__ContactViewController__

#include "CrossApp.h"
USING_NS_CC;

class ContactViewController : public CAViewController {
    
public:
    ContactViewController();
    
    virtual ~ContactViewController();
    
    CREATE_FUNC(ContactViewController);
    
protected:
    void viewDidLoad();
    
    void viewDidUnload();
};


#endif /* defined(__lxxbl__ContactViewController__) */
