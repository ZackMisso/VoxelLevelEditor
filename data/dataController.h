#pragma once

#include "../dataStructures/array.h"
#include "voxelData.h"
#include "islandData.h"
#include "mapData.h"

class DataController {
private:
  static DataController* instance;
  DataController();
  Array<VoxelData*>* voxelData;
  Array<IslandData*>* islandData;
  Array<MapData*>* mapData;
public:
  ~DataController();
  // class methods
  static DataController* getInstance();
  static void initialize();
  static void destroy();
  void updateAll(); // updates all data from the config files
  void updateVoxelData(); // updates voxel data from the config files
  void updateIslandData(); // updates island data from the config files
  void updateMapData(); // updates map data from the config files
  void addVoxelData(VoxelData* data); // creates voxel data config
  void addIslandData(IslandData* data); // creates island data config
  void addMapData(MapData* data); // creates map data config
};
