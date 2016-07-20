#pragma once

class MapDataIO {
private:
  static MapDataIO* instance;
  MapDataIO(string p);

  string path;
public:
  ~MapDataIO();
  static MapDataIO* getInstance();
  static void initialize(string p);
  static void destroy();
  // methods
  Array<MapData*>* readAllMapData();
  MapData* readMapData(string fileName);
  void writeMapData(MapData* data,string name);
};
