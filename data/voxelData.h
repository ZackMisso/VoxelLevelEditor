#pragma once

#include <iostream>
#include "../scene/texture.h"

using namespace std;

class VoxelData {
private:
  Texture* top;
  Texture* front;
  Texture* back;
  Texture* right;
  Texture* left;
  Texture* bot;
public:
  VoxelData();
  VoxelData(string sTop,string sFront,string sBack,string sRight,string sLeft,string sBot);
  ~VoxelData();
  // getter methods
  Texture* getTop();
  Texture* getFront();
  Texture* getBack();
  Texture* getRight();
  Texture* getLeft();
  Texture* getBot();
  // setter methods
  void setTop(Texture* param);
  void setFront(Texture* param);
  void setBack(Texture* param);
  void setRight(Texture* param);
  void setLeft(Texture* param);
  void setBot(Texture* param);
};
