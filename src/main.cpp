#include "generators.h"
#include "map.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {
  MapConfig *test = new MapConfig("config.json");

  std::unique_ptr<IGenerator> generator = std::make_unique<SimpleGenerator>();
  Grid grid = generator->generate(*test);
  std::cout << "grid: " << grid.mapPlane.size() << ", "
            << grid.mapPlane[0].size() << std::endl;
  exportMapToJson(*test, grid, "output.json");
}
