#include "voxelDataIO.h"
#include <iostream>

using namespace std;

VoxelDataIO* VoxelDataIO::instance = 0x0;

VoxelDataIO::VoxelDataIO(string p) {
  path = p;
}

VoxelDataIO::~VoxelDataIO() { }

VoxelDataIO* VoxelDataIO::getInstance() {
  return instance;
}

void VoxelDataIO::initialize(string p) {
  if(!instance) instance = new IslandDataIO(p);
}

void VoxelDataIO::destroy() {
  if(instance) delete instance;
}

Array<VoxelData*>* VoxelDataIO::readAllVoxelData() {
  cout << "readAllVoxelData not implemented" << endl;
  return 0x0;
}

VoxelData* VoxelDataIO::readVoxelData(string fileName) {
  cout << "readVoxelData not implemented" << endl;
  return 0x0;
}

void VoxelDataIO::writeVoxelData(VoxelData* data,string name) {
  cout << "writeVoxelData not implemented" << endl;
}
