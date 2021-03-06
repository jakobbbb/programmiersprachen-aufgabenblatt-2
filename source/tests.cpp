#define CATCH_CONFIG_RUNNER
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
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
  a += Vec2{0.f, 0.f};
  REQUIRE(a.x == Approx(-6.6f + 4.2f));
  REQUIRE(a.y == Approx(8.5f - 9.3f));
}

TEST_CASE("vec2 -=", "[vec2]") {
  Vec2 a{-6.6f, 8.5f};
  Vec2 b{4.2f, -9.3f};
  a -= b;
  REQUIRE(a.x == Approx(-6.6f - 4.2f));
  REQUIRE(a.y == Approx(8.5f + 9.3f));
  a -= Vec2{0.f, 0.f};
  REQUIRE(a.x == Approx(-6.6f - 4.2f));
  REQUIRE(a.y == Approx(8.5f + 9.3f));
}

TEST_CASE("vec2 *=", "[vec2]") {
  Vec2 a{-6.6f, 8.5f};
  const float f = 3.14f;
  a *= f;
  REQUIRE(a.x == Approx(-6.6f * f));
  REQUIRE(a.y == Approx(8.5f * f));
  a *= 1;
  REQUIRE(a.x == Approx(-6.6f * f));
  REQUIRE(a.y == Approx(8.5f * f));
  a *= 0;
  REQUIRE(a.x == 0.f);
  REQUIRE(a.y == 0.f);
}

TEST_CASE("vec2 /=", "[vec2]") {
  Vec2 a{-6.6f, 8.5f};
  const float f = 3.14f;
  a /= f;
  REQUIRE(a.x == Approx(-6.6f / f));
  REQUIRE(a.y == Approx(8.5f / f));
  a /= (1/f);
  REQUIRE(a.x == Approx(-6.6f));
  REQUIRE(a.y == Approx(8.5f));
  a /= 1;
  REQUIRE(a.x == Approx(-6.6f));
  REQUIRE(a.y == Approx(8.5f));

  a /= 0;
  REQUIRE(std::isinf(a.x));
  REQUIRE(std::isinf(a.y));
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
  const Vec2 e = 1.0f * a;
  REQUIRE(e.x == Approx(a.x));
  REQUIRE(e.y == Approx(a.y));
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

TEST_CASE("mat2 * vec2", "[mat2]") {
  const Mat2 m{-1.3f, 5.2f, 0.3f, 0.0f};
  const Vec2 v{-6.6f, 8.5f};
  const Vec2 u = m * v;
  REQUIRE(u.x == Approx(52.78));
  REQUIRE(u.y == Approx(-1.98));
  const Vec2 w = m * Vec2{0.f, 0.f};
  REQUIRE(w.x == Approx(0));
  REQUIRE(w.y == Approx(0));
}

TEST_CASE("mat2 det", "[mat2]") {
  const Mat2 a{-1.3f, 5.2f, 0.3f, 0.0f};
  const Mat2 b{4.2f, -9.3f, 5.2f, -6.2f};
  const Mat2 c{42.f, 0.f, 21.f, 0.f};
  const Mat2 i;
  REQUIRE(a.det() == Approx(-1.56f));
  REQUIRE(b.det() == Approx(22.32));
  REQUIRE(c.det() == 0);
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

  // cannot be inverted, unit matrix should be returned
  const Mat2 c{42.f, 0.f, 21.f, 0.f};
  Mat2 c_inv = inverse(c);
  REQUIRE(i_inv.e_00 == c_inv.e_00);
  REQUIRE(i_inv.e_01 == c_inv.e_01);
  REQUIRE(i_inv.e_10 == c_inv.e_10);
  REQUIRE(i_inv.e_11 == c_inv.e_11);
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

TEST_CASE("vec2 rotation", "[mat2]") {
  const Vec2 u{4.2f, -3.1f};
  const Vec2 v = rotation_matrix(1.2f) * u;
  REQUIRE(v.x == Approx(4.41122f));
  REQUIRE(v.y == Approx(2.79126f));
  const Vec2 w = rotation_matrix(0.0f) * u;
  REQUIRE(w.x == Approx(u.x));
  REQUIRE(w.y == Approx(u.y));
  const Vec2 x = rotation_matrix(2 * M_PI) * u;
  REQUIRE(x.x == Approx(u.x));
  REQUIRE(x.y == Approx(u.y));
}

TEST_CASE("color constructor", "[color]") {
  Color grey;
  REQUIRE(grey.r == Approx(0.5f));
  REQUIRE(grey.g == Approx(0.5f));
  REQUIRE(grey.b == Approx(0.5f));
  Color purple{0.42f, 0.09f, 0.59f};
  REQUIRE(purple.r == Approx(0.42f));
  REQUIRE(purple.g == Approx(0.09f));
  REQUIRE(purple.b == Approx(0.59f));
}

TEST_CASE("circle circumference", "[circle]") {
  REQUIRE((Circle{{}, 4.2f, {}}).circumference() == Approx(26.3894f));
  REQUIRE((Circle{{}, 0, {}}).circumference() == 0);
  REQUIRE((Circle{{}, -4.2f, {}}).circumference() == Approx(26.3894f));
}

TEST_CASE("rectangle circumference", "[rectangle]") {
  Rectangle r({4.2f, -1.4f}, {6.2f, 1.6f}, {});
  REQUIRE(r.circumference() == Approx(10));
  Rectangle s({0.f, 0.f}, {0.f, 0.f}, {});
  REQUIRE(s.circumference() == Approx(0));
  Rectangle t({4.2f, 0.f}, {4.2f, 1.f}, {});
  REQUIRE(t.circumference() == Approx(2));
  Rectangle u({6.2f, 1.6f}, {4.2f, -1.4f}, {});
  REQUIRE(u.circumference() == Approx(10));
}

TEST_CASE("circle is_inside", "[circle]") {
  const Circle c{{0.f, 0.f}, 1, {}};  // unit circle

  REQUIRE(c.is_inside(Vec2{0.f, 0.f}));  // center
  REQUIRE(c.is_inside(Vec2{0.5f, -0.5f}));  // inside
  REQUIRE(c.is_inside(Vec2{-0.5f, 0.5f}));
  REQUIRE(c.is_inside(Vec2{0.42f, 0.12f}));
  REQUIRE(c.is_inside(Vec2{1.f, 0.f}));  // on circumference
  REQUIRE(c.is_inside(Vec2{-1.f, 0.f}));
  REQUIRE(c.is_inside(Vec2{0.f, 1.f}));
  REQUIRE(c.is_inside(Vec2{0.f, -1.f}));

  // outside
  REQUIRE(!c.is_inside(Vec2{1.f, 1.f}));
  REQUIRE(!c.is_inside(Vec2{.9f, .9f}));
  REQUIRE(!c.is_inside(Vec2{1.01f, 0.f}));
  REQUIRE(!c.is_inside(Vec2{1.f, 0.01f}));
}

TEST_CASE("rectangle is_inside", "[rectangle]") {
  const Rectangle r{{-1.f, -1.f}, {1.f, 1.f}, {}};

  REQUIRE(r.is_inside(Vec2{0.f, 0.f}));  // inside
  REQUIRE(r.is_inside(Vec2{0.5f, -0.5f}));
  REQUIRE(r.is_inside(Vec2{1.f, 1.f}));  // corners
  REQUIRE(r.is_inside(Vec2{-1.f, 1.f}));
  REQUIRE(r.is_inside(Vec2{1.f, -1.f}));
  REQUIRE(r.is_inside(Vec2{-1.f, -1.f}));
  REQUIRE(r.is_inside(Vec2{1.f, -0.5f}));  // edges
  REQUIRE(r.is_inside(Vec2{-1.f, -0.5f}));
  REQUIRE(r.is_inside(Vec2{-0.5f, 1.f}));
  REQUIRE(r.is_inside(Vec2{-0.5f, -1.f}));

  // outside
  REQUIRE(!r.is_inside(Vec2{1.01f, 0.f}));
  REQUIRE(!r.is_inside(Vec2{0.f, 1.01f}));
  REQUIRE(!r.is_inside(Vec2{2.f, 2.f}));
  REQUIRE(!r.is_inside(Vec2{0.f, 2.f})); // above
  REQUIRE(!r.is_inside(Vec2{0.f, -2.f})); // below
  REQUIRE(!r.is_inside(Vec2{-2.f, 0.f})); // left
  REQUIRE(!r.is_inside(Vec2{2.f, 0.f})); // right

}

int main(int argc, char *argv[]) { return Catch::Session().run(argc, argv); }
