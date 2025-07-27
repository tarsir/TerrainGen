#include "src/map.h"
#include "nlohmann/json.hpp"
#include "src/generators.h"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

MapConfig::MapConfig(std::string filepath) {
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

void exportMapToJson(const MapConfig &config, const Grid grid,
                     std::string filename) {
  json mapExport;

  mapExport["dimensions"]["width"] = config.width;
  mapExport["dimensions"]["height"] = config.height;

  for (auto terrainType : config.terrainData) {
    mapExport["legend"][terrainType.first] = terrainType.second.name;
  }

  std::cout << "grid: " << grid.mapPlane.size() << ", "
            << grid.mapPlane[0].size() << std::endl;
  mapExport["gridData"] = grid.mapPlane;

  const char *workspace_dir = std::getenv("BUILD_WORKING_DIRECTORY");
  std::filesystem::path output_dir =
      workspace_dir ? workspace_dir : std::filesystem::current_path();
  std::filesystem::path output_file = output_dir / filename;
  std::ofstream outputFile(output_file);

  outputFile << mapExport.dump();
}
