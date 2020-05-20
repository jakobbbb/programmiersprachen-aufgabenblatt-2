#include "rectangle.hpp"
#include <cmath>

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color) :
  min_{min},
  max_{max},
  color_{color} {}

float Rectangle::circumference() const {
  float dx = std::abs(max_.x - min_.x);
  float dy = std::abs(max_.y - min_.y);
  return 2 * (dx + dy);
}
