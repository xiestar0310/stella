#pragma once

#include "Point.hpp"
#include "Ray.hpp"
#include "Vector.hpp"

struct hitLog {
  Point point;
  Vector normal;
  double t;
  bool front;

  inline void setFaceNormal(const Ray &ray, const Vector &outwardNormal) {
    front = dotProduct(ray.getDir(), outwardNormal) < 0;
    normal = front ? outwardNormal : -outwardNormal;
  }
};

class Hittable {
public:
  virtual bool hit(const Ray &ray, double min, double max,
                   hitLog &record) const = 0;
};
