#include "Ray.hpp"

Ray::Ray() : pos(0, 0, 0), dir(0, 0, 0) {}

Ray::Ray(const Point &pos, const Vector &dir) : pos(pos), dir(dir) {}

Point Ray::getPointAtDistance(double distance) const {
  return pos + (dir * distance);
}
