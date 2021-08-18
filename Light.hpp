#pragma once
#include "Point.hpp"

class Light {
  Point pos;
  double radius;

public:
  virtual ~Light() {}
};
