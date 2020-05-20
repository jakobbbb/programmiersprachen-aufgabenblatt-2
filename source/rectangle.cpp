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


void Rectangle::draw(Window const& win) const {
  draw(win, DEFAULT_DRAW_THICKNESS);
}

void Rectangle::draw(Window const& win, float thickness) const {
  win.draw_line(
    min_.x, min_.y,
    min_.x, max_.y,
    color_.r, color_.g, color_.b, thickness
  );
  win.draw_line(
    min_.x, min_.y,
    max_.x, min_.y,
    color_.r, color_.g, color_.b, thickness
  );
  win.draw_line(
    max_.x, max_.y,
    min_.x, max_.y,
    color_.r, color_.g, color_.b, thickness
  );
  win.draw_line(
    max_.x, max_.y,
    max_.x, min_.y,
    color_.r, color_.g, color_.b, thickness
  );
  return;
}
