#pragma once
#include "math.h"

class Color {
  double red, green, blue, special;

public:
  Color();

  Color(double, double, double, double);

  double setColorRed(double redValue) { red = redValue; }
  double setColorGreen(double greenValue) { green = greenValue; }
  double setColorBlue(double blueValue) { blue = blueValue; }
  double setColorSpecial(double specialValue) { special = specialValue; }
};

Color::Color() {
  red = 0.5;
  green = 0.5;
  blue = 0.5;
}

Color::Color(double r, double g, double b, double s) {
  red = r;
  green = g;
  blue = b;
  special = s;
}
