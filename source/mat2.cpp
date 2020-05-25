#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>
#include <iostream>

Mat2& Mat2::operator*=(Mat2 const& m) {
  Mat2 r = *this * m;
  e_00 = r.e_00;
  e_01 = r.e_01;
  e_10 = r.e_10;
  e_11 = r.e_11;
  return *this;
}

Mat2 operator*(Mat2 const& a, Mat2 const& b) {
  Mat2 r;
  r.e_00 = a.e_00 * b.e_00 + a.e_10 * b.e_01;
  r.e_10 = a.e_00 * b.e_10 + a.e_10 * b.e_11;
  r.e_01 = a.e_01 * b.e_00 + a.e_11 * b.e_01;
  r.e_11 = a.e_01 * b.e_10 + a.e_11 * b.e_11;
  return r;
}

float Mat2::det() const {
  return e_00 * e_11 - e_10 * e_01;
}

Mat2 operator*(Mat2 const& m, float s) {
  Mat2 r{m};
  r.e_00 *= s;
  r.e_01 *= s;
  r.e_10 *= s;
  r.e_11 *= s;
  return r;
}

Vec2 operator*(Mat2 const& m, Vec2 const& v) {
  return Vec2{m.e_00 * v.x + m.e_10 * v.y,
              m.e_01 * v.x + m.e_11 * v.y};
}

Mat2 inverse(Mat2 const& m) {
  float det = m.det();
  if (det == 0.f) {
    std::cerr << "Matrix cannot be inverted!  Returning unit matrix.";
    return Mat2{};
  }
  return Mat2{ m.e_11 / det, -m.e_10 / det,
              -m.e_01 / det,  m.e_00 / det};
}

Mat2 transpose(Mat2 const& m) {
  return Mat2{m.e_00, m.e_01,
              m.e_10, m.e_11};
}

Mat2 rotation_matrix(float phi) {
  return Mat2{std::cos(phi), -std::sin(phi),
              std::sin(phi), std::cos(phi)};
}
