#ifndef MAT2_HPP
#define MAT2_HPP

#include <array>

struct Mat2 {
  /* layout:
   *   e_00   e_10
   *   e_01   e_11
   */

  float e_00 = 1.0f;
  float e_10 = 0.0f;
  float e_01 = 0.0f;
  float e_11 = 1.0f;

  Mat2& operator*=(Mat2 const& m);
};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2);

#endif // MAT2_HPP
