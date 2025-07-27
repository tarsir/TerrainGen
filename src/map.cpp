#include "src/map.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

using json = nlohmann::json;

std::vector<std::pair<int, int>> generateFeatureCoords(int mapSize,
                                                       int featureCount) {
  std::vector<std::pair<int, int>> mapFeatures;
  std::random_device dev;
  std::mt19937 mt(dev());
  std::uniform_int_distribution<int> dist(0, mapSize - 1);

  int x, y;
  for (int i = 0; i < featureCount; i++) {
    x = dist(mt), y = dist(mt);
    mapFeatures.push_back(std::make_pair(x, y));
  }

  return mapFeatures;
}

void applyFeatures(std::vector<std::pair<int, int>> features,
                   std::vector<std::vector<int>> &mapPlane) {
  for (auto it = features.begin(); it != features.end(); it++) {
    mapPlane[it->first][it->second] = 10;
  }
}

Map::Map(int size, int featureCount) {
  this->height = size;
  this->width = size;
  this->mapPlane.reserve(this->height);

  for (int i = 0; i < this->height; i++) {
    std::vector<int> row(this->width);
    this->mapPlane.push_back(row);
  }

  this->featureCoords = generateFeatureCoords(size, featureCount);
  applyFeatures(this->featureCoords, this->mapPlane);
}

Map::Map(std::string filepath) {
  std::ifstream configFile(filepath);
  json config = json::parse(configFile);

  this->width = config["dimensions"]["width"];
  this->height = config["dimensions"]["height"];

  for (const auto &terrain : config["terrain_info"]) {
    std::cout << "Terrain: " << terrain["name"] << ", ID: " << terrain["id"]
              << ", Freq: " << terrain["frequency"] << std::endl;
    struct TerrainInfo terrainInfo = {terrain["id"], terrain["frequency"],
                                      terrain["name"]};
    this->terrainData.emplace(terrain["id"], terrainInfo);
  }
}

void Map::exportMapToJson(std::string filename) {
  json mapExport;

  mapExport["dimensions"]["width"] = this->width;
  mapExport["dimensions"]["height"] = this->height;

  mapExport["gridData"] = this->mapPlane;

  const char *workspace_dir = std::getenv("BUILD_WORKING_DIRECTORY");
  std::filesystem::path output_dir =
      workspace_dir ? workspace_dir : std::filesystem::current_path();
  std::filesystem::path output_file = output_dir / filename;
  std::ofstream outputFile(output_file);

  outputFile << mapExport.dump(2);
}
