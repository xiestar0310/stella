#pragma once
#include "Vector.hpp"
#include <iostream>

class Point {
  double x, y, z;

public:
  Point();
  Point(double x, double y, double z);
  double getX();
  double getY();
  double getZ();
  void add(Vector vect);
  void add(Point pt);

  friend std::ostream &operator<<(std::ostream &os, const Point &p) {
    return os << p.x << ", " << p.y << ", " << p.z;
  }
};

Point operator+(Point p1, Point p2);
Point operator+(Point p, Vector v);
Point operator+(Vector v, Point p);
