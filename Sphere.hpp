#pragma once
#include "Hittable.hpp"
#include "Object.hpp"
#include "Point.hpp"
#include "Ray.hpp"

class Sphere : public Hittable {
  Point pos;
  double r;

public:
  Sphere() = default;
  Sphere(Point pos, double r) : pos(pos), r(r) {}
  Point getPos() { return pos; }
  double getR() { return r; }
  std::pair<double, double> modified_quadratic_formula(double a, double b,
                                                       double c) const;
  double getIntersectionDistance(Ray ray) const;
  // pass a ray to this sphere -> return
  virtual bool hit(const Ray &ray, double min, double max,
                   hitLog &record) const override;
};

// bool Sphere::hit(const Ray &ray, double min, double max, hitLog &record)
// const;
