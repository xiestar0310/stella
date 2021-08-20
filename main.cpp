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
#include <cmath>
#include <iostream>
#include <utility>

int main() {

  Camera camera(Point(), Vector(0, 1, 0), Vector(1, 0, 0), 50, 800, 600);

  int width = camera.getWPixel();
  int height = camera.getHPixel();

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      Ray cur = camera.getRayFromPixel(i, j);
    }
  }

  Ray point1 = camera.getRayFromPixel(0, 0);
  Ray point2 = camera.getRayFromPixel(800, 0);
  Ray point3 = camera.getRayFromPixel(800, 600);
  Ray point4 = camera.getRayFromPixel(0, 600);

  /*std::cout << point1 << std::endl;
  std::cout << point2 << std::endl;
  std::cout << point3 << std::endl;
  std::cout << point4 << std::endl;*/

  // hi
}
