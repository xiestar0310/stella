#include "Camera.hpp"
#include <cmath>
#include <iostream>

Camera::Camera(Point pos, Vector up, Vector dir, double angle, int w_pixel,
               int h_pixel) {
  this->pos = pos;
  this->up = up.normalize();
  this->dir = dir.normalize();
  this->angle = angle * atan(1) * 4 / 180;
  this->w_pixel = w_pixel;
  this->h_pixel = h_pixel;
  right = dir.crossProduct(up);
  middle = pos + dir;
}

Point Camera::getPos() { return pos; }
Vector Camera::getUp() { return up; }
Vector Camera::getDir() { return dir; }
Point Camera::getPointFromPixel(int x, int y) {
  std::cout << right << std::endl;
  std::cout << middle << std::endl;
  double width = 2 * tan(angle / 2);
  double height = ((double)h_pixel / w_pixel) * width;
  std::cout << width << std::endl;
  std::cout << height << std::endl;
  return pos + dir + right * (x - width / 2) * (width / w_pixel) +
         up * (y - height / 2) * (height / h_pixel);
}
