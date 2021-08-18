#include "Ray.hpp"

Ray::Ray(Point pos, Vector dir) {
  this->pos = pos;
  this->dir = dir;
}

Point Ray::getPointAtDistance(double distance) {
  return pos + (dir * distance);
}
