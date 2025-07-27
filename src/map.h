#include <vector>

class Map {
    int size;
    std::vector< std::vector<int> > mapPlane;
    std::vector< std::pair<int, int> > featureCoords;

    public:
    Map(int size, int featureCount);

    void printMap();
};
