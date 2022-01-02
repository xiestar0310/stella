#include "HittableList.hpp"

bool HittableList::hit(const Ray &ray, double min, double max,
                       hitLog &record) const {
  hitLog temp;
  bool hitAnything = false;
  double closest = max;

  for (const shared_ptr<Hittable> &object : objects) {
    if (object->hit(ray, min, closest, record)) {
      hitAnything = true;
      closest = temp.t;
      record = temp;
    }
  }
  return hitAnything;
}
