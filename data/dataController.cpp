#include "dataController.h"
#include <iostream>

using namespace std;

DataController* DataController::instance = 0x0;

DataController::DataController() {
  voxelData = new Array<VoxelData*>();
  islandData = new Array<IslandData*>();
  mapData = new Array<MapData*>();
  updateAll();
}

DataController::~DataController() {
  while(voxelData->getSize()) delete voxelData->removeLast();
  while(islandData->getSize()) delete islandData->removeLast();
  while(mapData->getSize()) delete mapData->removeLast();
  delete voxelData;
  delete islandData;
  delete mapData;
}

void DataController::initialize() {
  if(!instance) instance = new DataController();
}

void DataController::destroy() {
  if(instance) delete instance;
}

void DataController::updateAll() {
  updateVoxelData();
  updateIslandData();
  updateMapData();
}

void DataController::updateVoxelData() {
  cout << "updateVoxelData not implemented" << endl;
}

void DataController::updateIslandData() {
  cout << "updateIslandData not implemented" << endl;
}

void DataController::updateMapData() {
  cout << "updateMapData not implemented" << endl;
}

void DataController::addVoxelData(VoxelData* data) {
  cout << "addVoxelData not implemented" << endl;
}

void DataController::addIslandData(IslandData* data) {
  cout << "addIslandData not implemented" << endl;
}

void DataController::addMapData(MapData* data) {
  cout << "addMapData not implemented" << endl;
}
