#include "circle.hpp"
#include <cmath>

Circle::Circle(Vec2 const& center, float radius, Color const& color) :
  center_{center},
  radius_{radius},
  color_{color} {}

float Circle::circumference() const {
  return std::abs(2 * M_PI * radius_);
}
