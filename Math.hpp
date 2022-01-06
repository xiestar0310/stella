#pragma once
#include <cmath>
#include <limits>

using std::sqrt;

const double INF = std::numeric_limits<double>::infinity();
const double pi = 3.14159265358979323846;

inline double toRadian(double deg) { return deg * pi / 180.0; }

inline double randDouble() {
  // [0, 1)
  return rand() / (RAND_MAX + 1.0);
}

inline double randDouble(double min, double max) {
  //[min, max)
  return min + (max - min) * randDouble();
}
