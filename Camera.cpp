#include "Camera.hpp"

Camera::Camera() {
  double aspectRatio = 16.0 / 9.0;
  double viewportHeight = 2.0;
  double viewportWidth = aspectRatio * viewportHeight;
  double focalLength = 1.0;

  origin = Point(0, 0, 0);
  horizontal = Vector(viewportWidth, 0.0, 0.0);
  vertical = Vector(0.0, viewportHeight, 0.0);
  lowerLeftCorner =
      origin - horizontal / 2 - vertical / 2 - Vector(0, 0, focalLength);
}

Ray Camera::getRay(double u, double v) const {
  return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}
