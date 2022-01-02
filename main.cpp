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

Colour rayColour(const Ray &ray, const Hittable &world) {
  hitLog record;
  if (world.hit(ray, 0, INF, record)) {
    return 0.5 * (record.normal + Colour(1, 1, 1));
  }
  Vector unitDir = (ray.getDir()).normalize();
  double t = 0.5 * (unitDir.getY() + 1.0);
  return (1.0 - t) * Colour(1.0, 1.0, 1.0) + t * Colour(0.5, 0.7, 1.0);
}

int main() {

  const auto aspectRatio = 16.0 / 9.0;
  const int width = 400;
  const int height = 225;

  // World
  HittableList world;
  world.add(make_shared<Sphere>(Point(0, 0, -1), 0.5));
  world.add(make_shared<Sphere>(Point(0, -100.5, -1), 100));

  // Camera
  double viewportHeight = 2.0;
  double viewportWidth = aspectRatio * viewportHeight;
  double focalLength = 1.0;

  Point origin = Point();
  Vector horizontal = Vector(viewportWidth, 0, 0);
  Vector vertical = Vector(0, viewportHeight, 0);
  Point bottomLeftCorner =
      origin - horizontal / 2 - vertical / 2 - Vector(0, 0, focalLength);

  // Rendering part

  std::cout << "P3\n" << width << ' ' << height << "\n255\n";

  for (int row = 0; row < height; row++) {
    std::cerr << "\rScanlines remaining: " << height - row - 1 << ' '
              << std::flush;
    for (int col = 0; col < width; col++) {
      double u = double(col) / (width - 1);
      double v = 1 - double(row) / (height - 1);
      Ray ray(origin, bottomLeftCorner + u * horizontal + v * vertical -
                          Point(0, 0, 0)); // - origin instead of point
      Colour pixelColour = rayColour(ray, world);
      printColour(std::cout, pixelColour);
      // Ray cur = camera.getRayFromPixel(i, j);
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
