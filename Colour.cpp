#include "Colour.hpp"

Colour::Colour(double r, double g, double b) {
  this->r = r;
  this->g = g;
  this->b = b;
}
double Colour::getR() { return r; }
double Colour::getG() { return g; }
double Colour::getB() { return b; }
