#pragma once
#include "Point.hpp"
#include "Vector.hpp"

class Ray {
  Point pos;
  Vector dir;

public:
  Ray();
  Ray(const Point &pos, const Vector &dir);
  Point getPos() const { return pos; }
  Vector getDir() const { return dir; }
  Point getPointAtDistance(double distance) const;
};
