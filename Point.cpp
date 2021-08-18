#include "Point.hpp"

Point::Point() {
  x = 0;
  y = 0;
  z = 0;
}

Point::Point(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
}
double Point::getX() { return x; }
double Point::getY() { return y; }
double Point::getZ() { return z; }

void Point::add(Vector vect) {
  x += vect.getX();
  y += vect.getY();
  z += vect.getZ();
}

void Point::add(Point pt) {
  x += pt.getX();
  y += pt.getY();
  z += pt.getZ();
}

Point operator+(Point p1, Point p2) {
  return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY(),
               p1.getZ() + p2.getZ());
}

Point operator+(Point p, Vector v) {
  return Point(p.getX() + v.getX(), p.getY() + v.getY(), p.getZ() + v.getZ());
}

Point operator+(Vector v, Point p) {
  return Point(p.getX() + v.getX(), p.getY() + v.getY(), p.getZ() + v.getZ());
}
