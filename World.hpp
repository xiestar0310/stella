#pragma once
#include "Camera.hpp"
#include "Light.hpp"
#include "Object.hpp"
#include <vector>

class World {
  std::vector<Object *> objs;
  std::vector<Light *> lights;
  Camera cam;

public:
  World(Camera cam);
  void addObj(Object *obj);
  void addLight(Light *light);
  std::vector<Object *> getObjs();
  std::vector<Light *> getLights();
  Camera getCam();
};
