

#include "RootWindow.h"
#include "FirstViewController.h"
#include "MenuViewController.h"

static RootWindow* _window = NULL;

RootWindow* RootWindow::create()
{
    if (_window == NULL) {
        _window = new RootWindow();
        _window->init();
        _window->autorelease();
    }
    
    return _window;
}

RootWindow::RootWindow():m_DrawerController(NULL),m_NavigationController(NULL)
{
    CAApplication::getApplication()->getKeypadDispatcher()->addDelegate(this);
}

RootWindow::~RootWindow()
{
    CAApplication::getApplication()->getKeypadDispatcher()->removeDelegate(this);
}

bool RootWindow::init()
{
    if (!CAWindow::init())
    {
        return false;
    }
    
    FirstViewController *fist = new FirstViewController();
    fist->init();
    fist->autorelease();
    
    m_NavigationController = new CANavigationController();
    m_NavigationController->initWithRootViewController(fist);
    m_NavigationController->setNavigationBarBackGroundColor(ccc4(0, 202, 187, 255));
    m_NavigationController->autorelease();
    //m_NavigationController->set
    //m_NavigationController->setNavigationBarHidden(false, true);
    
    
    MenuViewController *menu = MenuViewController::create();
    
    m_DrawerController = new CADrawerController();
    m_DrawerController->initWithController(menu, m_NavigationController, _px(600));
    m_DrawerController->setBackgroundView(CAImageView::createWithImage(CAImage::create("r/bg.png")));
    m_DrawerController->setEffect3D(true);
    this->setRootViewController(m_DrawerController);
    
    m_DrawerController->autorelease();
    
    return true;
}

