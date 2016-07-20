#include "viewController.h"
#include "firstView.h"
#include "simpleTriangleView.h"
#include <iostream>

using namespace std;

ViewController* ViewController::instance = 0x0;

ViewController::ViewController() {
  //currentView = new FirstView();
  currentView = new SimpleTriangleView();
  currentView->initialize();
}

ViewController::~ViewController() {
  delete currentView;
}

void ViewController::initialize() {
  if(!instance)
    instance = new ViewController();
}

void ViewController::destroy() {
  if(instance)
    delete instance;
}

ViewController* ViewController::getInstance() {
  return instance;
}

void ViewController::switchToView(View* view) {
  currentView->destroy();
  delete currentView;
  currentView = view;
}

View* ViewController::getCurrentView() { return currentView; }
