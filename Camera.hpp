#pragma once
#include "Point.hpp"
#include "Ray.hpp"
#include "Vector.hpp"

class Camera {
  Point pos, middle;
  Vector up, dir, right;
  double angle;
  int w_pixel, h_pixel;

public:
  Camera(Point pos, Vector up, Vector dir, double angle, int w_pixel,
         int h_pixel);
  Point getPos() { return pos; }
  Point getMiddle() { return middle; }
  Vector getUp() { return up; }
  Vector getDir() { return dir; }
  Vector getRight() { return right; }
  int getWPixel() { return w_pixel; }
  int getHPixel() { return h_pixel; }

  Ray getRayFromPixel(int x, int y);
};
