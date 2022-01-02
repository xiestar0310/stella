#include "Colour.hpp"

Colour::Colour(double r, double g, double b) : r(r), g(g), b(b) {}
double Colour::getR() const { return r; }
double Colour::getG() const { return g; }
double Colour::getB() const { return b; }

void printColour(std::ostream &out, const Colour &colour) {
  out << static_cast<int>(255.999 * colour.getR()) << ' '
      << static_cast<int>(255.999 * colour.getG()) << ' '
      << static_cast<int>(255.999 * colour.getB()) << '\n';
}
