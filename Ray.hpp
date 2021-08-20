#pragma once
#include "Point.hpp"
#include "Vector.hpp"

class Ray {
  Point pos;
  Vector dir;

public:
  Ray(Point pos, Vector dir);
  Point getPos() { return pos; }
  Vector getDir() { return dir; }
  Point getPointAtDistance(double distance);
};
