#include "Sphere.hpp"
#include "Math.hpp"
#include <cmath>
#include <utility>

// ax^2 + 2bx + c = 0

std::pair<double, double> Sphere::modified_quadratic_formula(double a, double b,
                                                             double c) const {
  double first, second;
  if (b * b - a * c >= 0) {
    first = (-b - sqrt(b * b - a * c)) / a;
    second = (-b + sqrt(b * b - a * c)) / a;
  } else {
    first = -INF;
    second = -INF;
  }
  return std::make_pair(first, second);
}

double Sphere::getIntersectionDistance(Ray ray) const {
  Point start = ray.getPos();
  Vector dir = ray.getDir();
  double a = dotProduct(dir, dir);
  double b = dotProduct(dir, start - pos);
  double c = dotProduct(start - pos, start - pos) - r * r;
  const auto &[first, second] = modified_quadratic_formula(a, b, c);
  if (first >= 0 && second >= 0) {
    return std::min(first, second);
  } else if (first < 0 && second < 0) {
    return -INF;
  } else {
    return std::max(first, second);
  }
}

bool Sphere::hit(const Ray &ray, double min, double max, hitLog &record) const {
  Point start = ray.getPos();
  Vector dir = ray.getDir();
  double a = dotProduct(dir, dir);
  double b = dotProduct(dir, start - pos);
  double c = dotProduct(start - pos, start - pos) - r * r;
  const auto &[first, second] = modified_quadratic_formula(a, b, c);
  if (first < 0 && second < 0) {
    return false;
  } else if (min <= first && first <= max) {
    record.t = first;
    record.point = ray.getPointAtDistance(record.t);
    // record.normal = (record.point - pos) / r;
    Vector outwardNormal = (record.point - pos) / r;
    record.setFaceNormal(ray, outwardNormal);
    return true;
  } else if (min <= second && second <= max) {
    record.t = second;
    record.point = ray.getPointAtDistance(record.t);
    // record.normal = (record.point - pos) / r;
    Vector outwardNormal = (record.point - pos) / r;
    record.setFaceNormal(ray, outwardNormal);
    return true;
  }
  return false;
}
