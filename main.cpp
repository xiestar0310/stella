/*

Store pixels in image + load & view my image
- use a library to do this
- use a 2D vector array

Field of view
- Put it in camera class
  - use distance and 3D space to get where it is

Rays
- Get 1 ray per pixel

First obj we hit = colour of thing

*/

#include "Camera.hpp"
#include "Colour.hpp"
#include "HittableList.hpp"
#include "Math.hpp"
#include "Point.hpp"
#include "Sphere.hpp"
#include "Vector.hpp"
#include <cmath>
#include <iostream>
#include <memory>
#include <utility>

using std::make_shared;

Colour rayColour(const Ray &ray, const Hittable &world, int depth) {
  hitLog record;

  // Check if we have exceeded the limit
  if (depth <= 0)
    return Colour(0, 0, 0);
  // check hitbox
  if (world.hit(ray, 0, INF, record)) {
    Point target = record.point + record.normal + randomInUnitSphere();
    return 0.5 * rayColour(Ray(record.point, target - record.point), world,
                           depth - 1);
  }
  Vector unitDir = (ray.getDir()).normalize();
  double t = 0.5 * (unitDir.getY() + 1.0);
  return (1.0 - t) * Colour(1.0, 1.0, 1.0) + t * Colour(0.5, 0.7, 1.0);
}

int main() {

  const auto aspectRatio = 16.0 / 9.0;
  const int width = 400;
  const int height = static_cast<int>(width / aspectRatio);
  const int samples = 100;
  const int maxDepth = 50;

  // World
  HittableList world;
  world.add(make_shared<Sphere>(Point(0, 0, -1), 0.5));
  world.add(make_shared<Sphere>(Point(0, -100.5, -1), 100));

  // Camera
  Camera camera;
  // Rendering part

  std::cout << "P3\n" << width << ' ' << height << "\n255\n";

  for (int row = height - 1; row >= 0; row--) {
    std::cerr << "\rScanlines remaining: " << row << ' ' << std::flush;
    for (int col = 0; col < width; col++) {
      Colour colour(0, 0, 0);
      for (int s = 0; s < samples; s++) {
        double u = (col + randDouble()) / (width - 1);
        double v = (row + randDouble()) / (height - 1);
        Ray ray = camera.getRay(u, v);
        colour += rayColour(ray, world, maxDepth);
      }
      printColour(std::cout, colour, samples);
    }
  }
  std::cerr << "\nDone.\n";

  /*
    Ray point1 = camera.getRayFromPixel(0, 0);
    Ray point2 = camera.getRayFromPixel(800, 0);
    Ray point3 = camera.getRayFromPixel(800, 600);
    Ray point4 = camera.getRayFromPixel(0, 600);

    */

  /*std::cout << point1 << std::endl;
  std::cout << point2 << std::endl;
  std::cout << point3 << std::endl;
  std::cout << point4 << std::endl;*/
}
