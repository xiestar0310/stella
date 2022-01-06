#pragma once
#include "Math.hpp"
#include "Point.hpp"
#include "Ray.hpp"
#include "Vector.hpp"

class Camera {
  Point origin;
  Point lowerLeftCorner;
  Vector horizontal;
  Vector vertical;

public:
  Camera();

  Ray getRay(double u, double v) const;
};
