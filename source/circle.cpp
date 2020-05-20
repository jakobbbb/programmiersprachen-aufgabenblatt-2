#include "circle.hpp"
#include "mat2.hpp"
#include <cmath>

#define CIRCLE_LINE_SEGMENTS 60

Circle::Circle(Vec2 const& center, float radius, Color const& color) :
  center_{center},
  radius_{radius},
  color_{color} {}

float Circle::circumference() const {
  return std::abs(2 * M_PI * radius_);
}

void Circle::draw(Window const& win) const {
  draw(win, DEFAULT_DRAW_THICKNESS);
}

void Circle::draw(Window const& win, float thickness) const {
  for (int i = 0; i < CIRCLE_LINE_SEGMENTS; ++i) {
    float phi_q = (i+0.f)/CIRCLE_LINE_SEGMENTS * M_PI * 2;
    float phi_p = (i+1.f)/CIRCLE_LINE_SEGMENTS * M_PI * 2;
    Vec2 p = rotation_matrix(phi_p) * Vec2{radius_, 0.0f} + center_;
    Vec2 q = rotation_matrix(phi_q) * Vec2{radius_, 0.0f} + center_;
    win.draw_line(
      p.x, p.y,
      q.x, q.y,
      color_.r, color_.g, color_.b, thickness
    );
  }
}

bool Circle::is_inside(Vec2 const& p) const {
  return (p - center_).norm() <= radius_;
}
