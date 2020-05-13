#include "mat2.hpp"

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
