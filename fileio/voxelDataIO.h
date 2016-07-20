#pragma once

class VoxelDataIO {
private:
  static VoxelDataIO* instance;
  VoxelDataIO(string p);

  string path;
public:
  ~VoxelDataIO();
  static VoxelDataIO* getInstance();
  static void initialize(string p);
  static void destroy();
  // methods
  Array<VoxelData*>* readAllVoxelData();
  VoxelData* readVoxelData(string fileName);
  void writeVoxelData(VoxelData* data,string name);
};
