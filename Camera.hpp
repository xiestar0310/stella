#pragma once
#include "Point.hpp"
#include "Vector.hpp"

class Camera {
  Point pos, middle;
  Vector up, dir, right;
  double angle;
  int w_pixel, h_pixel;

public:
  Camera(Point pos, Vector up, Vector dir, double angle, int w_pixel,
         int h_pixel);
  Point getPos();
  Vector getUp();
  Vector getDir();
  Point getPointFromPixel(int x, int y);
};
