#include "Sphere.hpp"
#include "Math.hpp"
#include <cmath>
#include <utility>

Sphere::Sphere(Point pos, double r) {
  this->pos = pos;
  this->r = r;
}

std::pair<double, double> Sphere::modified_quadratic_formula(double a, double b,
                                                             double c) {
  double first, second;
  if (b * b - a * c >= 0) {
    first = (-b + sqrt(b * b - a * c) / a);
    second = (-b - sqrt(b * b - a * c) / a);
  } else {
    first = -INF;
    second = -INF;
  }
  return std::make_pair(first, second);
}

double Sphere::getIntersectionDistance(Ray ray) {
  Point start = ray.getPos();
  Vector dir = ray.getDir();
  double a = dir * dir;
  double b = dir * (start - pos);
  double c = (start - pos) * (start - pos) - r * r;
  const auto &[first, second] = modified_quadratic_formula(a, b, c);
  if (first >= 0 && second >= 0) {
    return std::min(first, second);
  } else if (first < 0 && second < 0) {
    return -INF;
  } else {
    return std::max(first, second);
  }
}
