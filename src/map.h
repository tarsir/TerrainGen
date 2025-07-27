#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class IGenerator;

struct TerrainInfo {
  int id;
  double frequency;
  std::string name;
};

struct Grid {
  std::vector<std::vector<int>> mapPlane;
};

class MapConfig {
public:
  int width;
  int height;
  std::unordered_map<int, TerrainInfo> terrainData;

public:
  // init a grid from a JSON parameter file
  MapConfig(std::string filename);
};

void exportMapToJson(const MapConfig &config, const Grid grid,
                     std::string filename);
