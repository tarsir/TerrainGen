#include <vector>
#include <random>
#include <iostream>
#include "map.h"

int main() {
    const int featureCount = 6;
    const int mapSize = 24;

    Map *test = new Map(mapSize, featureCount);
    test->printMap();
}
