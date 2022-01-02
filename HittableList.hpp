#pragma once
#include "Hittable.hpp"
#include <memory>
#include <vector>

using std::shared_ptr;

class HittableList : public Hittable {
  std::vector<shared_ptr<Hittable>> objects;

public:
  HittableList() = default;
  HittableList(shared_ptr<Hittable> object) { add(object); }

  void clear() { objects.clear(); }
  void add(shared_ptr<Hittable> object) { objects.push_back(object); }

  virtual bool hit(const Ray &ray, double min, double max,
                   hitLog &record) const override;
};
