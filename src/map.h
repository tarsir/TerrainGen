#include <string>
#include <unordered_map>
#include <vector>

struct TerrainInfo {
  int id;
  double frequency;
  std::string name;
};

class Map {
private:
  int width;
  int height;
  std::vector<std::vector<int>> mapPlane;
  std::vector<std::pair<int, int>> featureCoords;
  std::unordered_map<int, TerrainInfo> terrainData;

public:
  // init a square grid with a specified number of "features"
  Map(int size, int featureCount);

  // init a grid from a JSON parameter file
  Map(std::string filename);

  void exportMapToJson(std::string filename);
};
