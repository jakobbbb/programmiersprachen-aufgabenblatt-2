#define CATCH_CONFIG_RUNNER
#include "vec2.hpp"
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
int main(int argc, char *argv[]) { return Catch::Session().run(argc, argv); }
