#include "Colour.hpp"

using std::clamp;

Colour::Colour(double r, double g, double b) : r(r), g(g), b(b) {}
double Colour::getR() const { return r; }
double Colour::getG() const { return g; }
double Colour::getB() const { return b; }

Colour &Colour::operator+=(const Colour &colour) {
  r += colour.r;
  g += colour.g;
  b += colour.b;
  return *this;
}

void printColour(std::ostream &out, const Colour &colour, int samples) {
  double r = colour.getR();
  double g = colour.getG();
  double b = colour.getB();

  double scale = 1.0 / samples;
  r *= sqrt(scale * r);
  g *= sqrt(scale * g);
  b *= sqrt(scale * b);

  out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
      << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
      << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}
