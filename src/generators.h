#pragma once

struct Grid;
class MapConfig;

class IGenerator {
public:
  virtual ~IGenerator() = default;
  virtual Grid generate(const MapConfig &config) const = 0;
};

class SimpleGenerator : public IGenerator {
  Grid generate(const MapConfig &) const override;
};
