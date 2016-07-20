#pragma once

class IslandDataIO {
private:
  static IslandDataIO* instance;
  IslandDataIO(string p);

  string path;
public:
  ~IslandDataIO();
  static IslandDataIO* getInstance();
  static void initialize(string p);
  static void destroy();
  // methods
  Array<IslandData*>* readAllIslandData();
  IslandData* readIslandData(string fileName);
  void writeIslandData(IslandData* data,string name);
};
