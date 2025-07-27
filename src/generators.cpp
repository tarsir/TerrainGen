#include "src/generators.h"
#include "src/map.h"
#include <iostream>
#include <random>
#include <vector>

std::vector<std::pair<int, int>> generateFeatureCoords(int height, int width,
                                                       int featureCount) {
  std::vector<std::pair<int, int>> mapFeatures;
  std::random_device dev;
  std::mt19937 mt(dev());
  std::uniform_int_distribution<int> dist(0, std::max(height, width) - 1);

  int x, y;
  for (int i = 0; i < featureCount; i++) {
    x = dist(mt), y = dist(mt);
    mapFeatures.push_back(std::make_pair(x, y));
  }

  return mapFeatures;
}

static void applyFeatures(std::vector<std::pair<int, int>> features,
                          std::vector<std::vector<int>> &mapPlane) {
  for (auto it = features.begin(); it != features.end(); it++) {
    mapPlane[it->first][it->second] = 10;
  }
}

Grid SimpleGenerator::generate(const MapConfig &config) const {
  int height = config.height;
  int width = config.width;
  Grid grid = Grid{};
  grid.mapPlane.reserve(height);

  for (int i = 0; i < height; i++) {
    std::vector<int> row(width);
    grid.mapPlane.push_back(row);
  }

  auto featureCoords = generateFeatureCoords(height, width, 5);
  for (auto f : featureCoords) {
    std::cout << f.first << "," << f.second << std::endl;
  }
  applyFeatures(featureCoords, grid.mapPlane);
  std::cout << "hi" << std::endl;
  return grid;
}
