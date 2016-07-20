#ifndef __VIEWCONTROLLER_H__
#define __VIEWCONTROLLER_H__

#include "view.h"

class ViewController {
private:
  static ViewController* instance;
  View* currentView;
  ViewController();
public:
  ~ViewController();
  void switchToView(View* view);
  // singleton methods
  static void initialize();
  static void destroy();
  static ViewController* getInstance();
  // getter methods
  View* getCurrentView();
};

#endif
