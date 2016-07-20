#include "islandDataIO.h"
#include <iostream>

using namespace std;

IslandDataIO* IslandDataIO::instance = 0x0;

IslandDataIO::IslandDataIO(string p) {
  path = p;
}

IslandDataIO::~IslandDataIO() { }

IslandDataIO* IslandDataIO::getInstance() {
  return instance;
}

void IslandDataIO::initialize(string p) {
  if(!instance) instance = new IslandDataIO(p);
}

void IslandDataIO::destroy() {
  if(instance) delete instance;
}

Array<IslandData*>* IslandDataIO::readAllIslandData() {
  cout << "readAllIslandData not implemented" << endl;
  return 0x0;
}

IslandData* IslandDataIO::readIslandData(string fileName) {
  cout << "readIslandData not implemented" << endl;
  return 0x0;
}

void IslandDataIO::writeIslandData(IslandData* data,string name) {
  cout << "writeIslandData not implemented" << endl;
}
