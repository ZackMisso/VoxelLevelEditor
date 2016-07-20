#include "voxelData.h"

VoxelData::VoxelData() {
  top = new Texture("none");
  front = new Texture("none");
  back = new Texture("none");
  right = new Texture("none");
  left = new Texture("none");
  bot = new Texture("none");
}

VoxelData::VoxelData(string sTop,string sFront,string sBack,string sRight,string sLeft,string sBot) {
  top = new Texture(sTop);
  front = new Texture(sFront);
  back = new Texture(sBack);
  right = new Texture(sRight);
  left = new Texture(sLeft);
  bot = new Texture(sBot);
}

VoxelData::~VoxelData() {
  delete top;
  delete front;
  delete back;
  delete right;
  delete left;
  delete bot;
}

Texture* VoxelData::getTop() { return top; }
Texture* VoxelData::getFront() { return front; }
Texture* VoxelData::getBack() { return back; }
Texture* VoxelData::getRight() { return right; }
Texture* VoxelData::getLeft() { return left; }
Texture* VoxelData::getBot() { return bot; }

void VoxelData::setTop(Texture* param) { top = param; }
void VoxelData::setFront(Texture* param) { front = param; }
void VoxelData::setBack(Texture* param) { back = param; }
void VoxelData::setRight(Texture* param) { right = param; }
void VoxelData::setLeft(Texture* param) { left = param; }
void VoxelData::setBot(Texture* param) { bot = param; }
