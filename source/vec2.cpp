#include "vec2.hpp"

Vec2& Vec2::operator+=(Vec2 const& v) {
  x += v.x;
  y += v.y;
  return *this;
}

Vec2& Vec2::operator-=(Vec2 const& v) {
  x -= v.x;
  y -= v.y;
  return *this;
}

Vec2& Vec2::operator*=(float s) {
  x *= s;
  y *= s;
  return *this;
}

Vec2& Vec2::operator/=(float s) {
  x /= s;
  y /= s;
  return *this;
}


Vec2 operator+(Vec2 const& u, Vec2 const& v) {
  return Vec2{u} += v;
}

Vec2 operator-(Vec2 const& u, Vec2 const& v) {
  return Vec2{u} -= v;
}

Vec2 operator*(Vec2 const& u, float s) {
  return Vec2{u} *= s;
}

Vec2 operator*(float s, Vec2 const& u) {
  return u * s;
}

Vec2 operator/(Vec2 const& u, float s) {
  return Vec2{u} /= s;
}
