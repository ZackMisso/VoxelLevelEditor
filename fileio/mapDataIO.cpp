#include "mapDataIO.h"
#include <iostream>

using namespace std;

MapDataIO* MapDataIO::instance = 0x0;

MapDataIO::MapDataIO(string p) {
  path = p;
}

MapDataIO::~MapDataIO() { }

MapDataIO* MapDataIO::getInstance() {
  return instance;
}

void MapDataIO::initialize(string p) {
  if(!instance) instance = new MapDataIO(p);
}

void MapDataIO::destroy() {
  if(instance) delete instance;
}

Array<MapData*>* MapDataIO::readAllMapData() {
  cout << "readAllMapData not implemented" << endl;
  return 0x0;
}

MapData* MapDataIO::readMapData(string fileName) {
  cout << "readMapData not implemented" << endl;
  return 0x0;
}

void MapDataIO::writeMapData(MapData* data,string name) {
  cout << "writeMapData not implemented" << endl;
}
