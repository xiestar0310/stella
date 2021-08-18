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
#include "Vector.hpp"
#include <iostream>

int main() {

  Camera camera(Point(), Vector(0, 1, 0), Vector(1, 0, 0), 50, 800, 600);

  Point point1 = camera.getPointFromPixel(0, 0);
  Point point2 = camera.getPointFromPixel(800, 0);
  Point point3 = camera.getPointFromPixel(800, 600);
  Point point4 = camera.getPointFromPixel(0, 600);
  std::cout << point1 << std::endl;
  std::cout << point2 << std::endl;
  std::cout << point3 << std::endl;
  std::cout << point4 << std::endl;

  // hi
}
