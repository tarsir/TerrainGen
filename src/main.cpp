#include "map.h"
#include <iostream>
#include <random>
#include <vector>

int main() {
  const int featureCount = 6;
  const int mapSize = 24;

  Map *test = new Map("config.json");
  test->exportMapToJson("output.json");
}
