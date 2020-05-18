#define CATCH_CONFIG_RUNNER
#include "vec2.hpp"
#include "mat2.hpp"
#include <catch.hpp>
#include <cmath>

TEST_CASE("vec2 constructor", "[vec2]") {
  Vec2 a;
  REQUIRE(a.x == 0.0f);
  REQUIRE(a.y == 0.0f);
  Vec2 b{4.2f, -9.3f};
  REQUIRE(b.x == Approx(4.2f));
  REQUIRE(b.y == Approx(-9.3f));
}

TEST_CASE("vec2 +=", "[vec2]") {
  Vec2 a{-6.6f, 8.5f};
  Vec2 b{4.2f, -9.3f};
  a += b;
  REQUIRE(a.x == Approx(-6.6f + 4.2f));
  REQUIRE(a.y == Approx(8.5f - 9.3f));
}

TEST_CASE("vec2 -=", "[vec2]") {
  Vec2 a{-6.6f, 8.5f};
  Vec2 b{4.2f, -9.3f};
  a -= b;
  REQUIRE(a.x == Approx(-6.6f - 4.2f));
  REQUIRE(a.y == Approx(8.5f + 9.3f));
}

TEST_CASE("vec2 *=", "[vec2]") {
  Vec2 a{-6.6f, 8.5f};
  const float f = 3.14f;
  a *= f;
  REQUIRE(a.x == Approx(-6.6f * f));
  REQUIRE(a.y == Approx(8.5f * f));
}

TEST_CASE("vec2 /=", "[vec2]") {
  Vec2 a{-6.6f, 8.5f};
  const float f = 3.14f;
  a /= f;
  REQUIRE(a.x == Approx(-6.6f / f));
  REQUIRE(a.y == Approx(8.5f / f));
}

TEST_CASE("vec2 +", "[vec2]") {
  const Vec2 a{-6.6f, 8.5f};
  const Vec2 b{4.2f, -9.3f};
  const Vec2 c = a + b;
  REQUIRE(c.x == Approx(-6.6f + 4.2f));
  REQUIRE(c.y == Approx(8.5f - 9.3f));
  const Vec2 d = b + a;
  REQUIRE(c.x == Approx(d.x));
  REQUIRE(c.y == Approx(d.y));
  const Vec2 e = a + b + c + d;
  REQUIRE(e.x == Approx(a.x + b.x + c.x + d.x));
  REQUIRE(e.y == Approx(a.y + b.y + c.y + d.y));
}

TEST_CASE("vec2 -", "[vec2]") {
  const Vec2 a{-6.6f, 8.5f};
  const Vec2 b{4.2f, -9.3f};
  const Vec2 c = a - b;
  REQUIRE(c.x == Approx(-6.6f - 4.2f));
  REQUIRE(c.y == Approx(8.5f + 9.3f));
  const Vec2 d = a - b - c;
  REQUIRE(d.x == Approx(a.x - b.x - c.x));
  REQUIRE(d.y == Approx(a.y - b.y - c.y));
}

TEST_CASE("vec2 *", "[vec2]") {
  const Vec2 a{-6.6f, 8.5f};
  const float f = 3.14f;
  const Vec2 b = a * f;
  REQUIRE(b.x == Approx(-6.6f * f));
  REQUIRE(b.y == Approx(8.5f * f));
  const Vec2 c = f * a;
  REQUIRE(c.x == Approx(-6.6f * f));
  REQUIRE(c.y == Approx(8.5f * f));
  const Vec2 d = 0.0f * a;
  REQUIRE(d.x == 0.0f);
  REQUIRE(d.y == 0.0f);
}

TEST_CASE("vec2 /", "[vec2]") {
  const Vec2 a{-6.6f, 8.5f};
  const float f = 3.14f;
  const Vec2 b = a / f;
  REQUIRE(b.x == Approx(-6.6f / f));
  REQUIRE(b.y == Approx(8.5f / f));
  const Vec2 c = a / 1;
  REQUIRE(c.x == Approx(a.x));
  REQUIRE(c.y == Approx(a.y));
  const Vec2 d = a / 0;
  REQUIRE(std::isinf(d.x));
  REQUIRE(std::isinf(d.y));
}

TEST_CASE("vec2 multiple ops", "[vec2]") {
  const Vec2 a{-6.6f, 8.5f};
  const Vec2 b{4.2f, -9.3f};
  const float f = 3.14f;
  const float g = 1.23f;
  Vec2 c = b - ((a + (f * b)) / g);
  REQUIRE(c.x == Approx(b.x - ((a.x + (f * b.x)) / g)));
  REQUIRE(c.y == Approx(b.y - ((a.y + (f * b.y)) / g)));
}

TEST_CASE("mat2 constructor", "[mat2]") {
  const Mat2 i{};
  REQUIRE(i.e_00 == 1.0f);
  REQUIRE(i.e_10 == 0.0f);
  REQUIRE(i.e_01 == 0.0f);
  REQUIRE(i.e_11 == 1.0f);
  const Mat2 a{-1.3f, 5.2f, 0.3f, 0.0f};
  REQUIRE(a.e_00 == Approx(-1.3f));
  REQUIRE(a.e_10 == Approx(5.2f));
  REQUIRE(a.e_01 == Approx(0.3f));
  REQUIRE(a.e_11 == 0.0f);
}

TEST_CASE("mat2 *=", "[mat2]") {
  const Mat2 a{-6.6f, 8.5f, 3.6f, -0.5f};
  const Mat2 b{4.2f, -9.3f, 5.2f, -6.2f};
  Mat2 c{a};
  c *= b;  // c = a * b
  REQUIRE(c.e_00 == Approx(16.48f));
  REQUIRE(c.e_01 == Approx(12.52f));
  REQUIRE(c.e_10 == Approx(8.68f));
  REQUIRE(c.e_11 == Approx(-30.38f));
  Mat2 d{c};
  d *= Mat2{};
  REQUIRE(d.e_00 == Approx(16.48f));
  REQUIRE(d.e_01 == Approx(12.52f));
  REQUIRE(d.e_10 == Approx(8.68f));
  REQUIRE(d.e_11 == Approx(-30.38f));
}

TEST_CASE("mat2 *", "[mat2]") {
  const Mat2 a{-6.6f, 8.5f, 3.6f, -0.5f};
  const Mat2 b{4.2f, -9.3f, 5.2f, -6.2f};
  Mat2 c = a * b;
  REQUIRE(c.e_00 == Approx(16.48f));
  REQUIRE(c.e_01 == Approx(12.52f));
  REQUIRE(c.e_10 == Approx(8.68f));
  REQUIRE(c.e_11 == Approx(-30.38f));
  Mat2 d = Mat2{} * c;
  REQUIRE(d.e_00 == Approx(16.48f));
  REQUIRE(d.e_01 == Approx(12.52f));
  REQUIRE(d.e_10 == Approx(8.68f));
  REQUIRE(d.e_11 == Approx(-30.38f));
}

TEST_CASE("mat2 det", "[mat2]") {
  const Mat2 a{-1.3f, 5.2f, 0.3f, 0.0f};
  const Mat2 b{4.2f, -9.3f, 5.2f, -6.2f};
  const Mat2 i;
  REQUIRE(a.det() == Approx(-1.56f));
  REQUIRE(b.det() == Approx(22.32));
  REQUIRE(i.det() == 1);
}

TEST_CASE("mat2 inverse", "[mat2]") {
  const Mat2 a{-1.3f, 5.2f, 0.3f, 0.0f};
  Mat2 a_inv = inverse(a);
  REQUIRE(a_inv.e_00 == Approx(0));
  REQUIRE(a_inv.e_01 == Approx(0.192308));
  REQUIRE(a_inv.e_10 == Approx(3.33333));
  REQUIRE(a_inv.e_11 == Approx(0.833333));

  const Mat2 b{4.2f, -9.3f, 5.2f, -6.2f};
  Mat2 b_inv = inverse(b);
  REQUIRE(b_inv.e_00 == Approx(-0.277778));
  REQUIRE(b_inv.e_01 == Approx(-0.232975));
  REQUIRE(b_inv.e_10 == Approx(0.416667));
  REQUIRE(b_inv.e_11 == Approx(0.188172));

  const Mat2 i;
  Mat2 i_inv = inverse(i);
  REQUIRE(i_inv.e_00 == 1);
  REQUIRE(i_inv.e_01 == 0);
  REQUIRE(i_inv.e_10 == 0);
  REQUIRE(i_inv.e_11 == 1);
}

TEST_CASE("mat2 transpose", "[mat2]") {
  const Mat2 a{-1.3f, 5.2f, 0.3f, 0.0f};
  Mat2 a_t = transpose(a);
  REQUIRE(a_t.e_00 == a.e_00);
  REQUIRE(a_t.e_01 == a.e_10);
  REQUIRE(a_t.e_10 == a.e_01);
  REQUIRE(a_t.e_11 == a.e_11);

  const Mat2 i;
  Mat2 i_t = transpose(i);
  REQUIRE(i_t.e_00 == 1);
  REQUIRE(i_t.e_01 == 0);
  REQUIRE(i_t.e_10 == 0);
  REQUIRE(i_t.e_11 == 1);
}
TEST_CASE("mat2 rotation matrix", "[mat2]") {
  // Mat2 rotation_matrix(float phi);
  const float alpha = 0;
  Mat2 alpha_rot = rotation_matrix(alpha);
  REQUIRE(alpha_rot.e_00 == 1);
  REQUIRE(alpha_rot.e_01 == 0);
  REQUIRE(alpha_rot.e_10 == 0);
  REQUIRE(alpha_rot.e_11 == 1);

  const float beta = 4.2f;
  Mat2 beta_rot = rotation_matrix(beta);
  REQUIRE(beta_rot.e_00 == Approx(-0.490261));
  REQUIRE(beta_rot.e_01 == Approx(-0.871576));
  REQUIRE(beta_rot.e_10 == Approx(0.871576));
  REQUIRE(beta_rot.e_11 == Approx(-0.490261));

  const float gamma = 2 * M_PI;
  Mat2 gamma_rot = rotation_matrix(gamma);
  REQUIRE(gamma_rot.e_00 == Approx(1.0f));
  REQUIRE(gamma_rot.e_01 == Approx(0.0f));
  REQUIRE(gamma_rot.e_10 == Approx(0.0f));
  REQUIRE(gamma_rot.e_11 == Approx(1.0f));
}

int main(int argc, char *argv[]) { return Catch::Session().run(argc, argv); }
