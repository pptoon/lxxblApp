//
//  MenuViewController.h
//  lxxbl
//
//  Created by 卢喜羲 on 15/8/1.
//
//

#ifndef __lxxbl__MenuViewController__
#define __lxxbl__MenuViewController__

#include "CrossApp.h"
USING_NS_CC;

class MenuViewController : public CAViewController {
    
public:
    MenuViewController();
    
    
    virtual ~MenuViewController();
    
    CREATE_FUNC(MenuViewController);
    
    void onClickBlog(CAControl* btn,CCPoint point);
    
    void onClickAbout(CAControl* btn,CCPoint point);
    
    void onClickContact(CAControl* btn,CCPoint point);
    
    void onClickGitHub(CAControl* btn,CCPoint point);
    
protected:
    
    void viewDidLoad();
    
    void viewDidUnload();
    
    
private:
    CADipSize m_winSize;
    
};

#endif /* defined(__lxxbl__MenuViewController__) */
