#include <iostream>
#include <vector>
#include <random>
#include "map.h"


std::vector< std::pair<int, int> > generateFeatureCoords(int mapSize, int featureCount) {
    std::vector< std::pair<int, int> > mapFeatures;
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

void applyFeatures(
    std::vector< std::pair<int, int> > features,
    std::vector< std::vector<int> > &mapPlane
) {
    for (auto it = features.begin(); it != features.end(); it++) {
        mapPlane[it->first][it->second] = 10;
    }
}

Map::Map(int size, int featureCount) {
    this->size = size;
    this->mapPlane.reserve(this->size);

    for (int i = 0; i < this->size; i++) {
        std::vector<int> row(this->size);
        this->mapPlane.push_back(row);
    }

    this->featureCoords = generateFeatureCoords(size, featureCount);
    applyFeatures(this->featureCoords, this->mapPlane);
}

void Map::printMap() {
    for(int i = 0; i < this->size; i++) {
        std::cout << "[";
        for(int j = 0; j < this->size; j++) {
            std::cout << this->mapPlane[i][j];
            if(j != this->size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";

        if (i != this->size - 1) {
            std::cout << ",";
        }
        std::cout << std::endl;
    }
}
