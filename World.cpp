#include "World.hpp"

World::World(Camera cam) : cam(cam) {}
void World::addObj(Object *obj) { objs.push_back(obj); }
void World::addLight(Light *light) { lights.push_back(light); }
std::vector<Object *> World::getObjs() { return objs; }
std::vector<Light *> World::getLights() { return lights; }
Camera World::getCam() { return cam; }
