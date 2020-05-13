#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

TEST_CASE("describe_vec2", "[vec2]") {
  Vec2 a;
  REQUIRE(a.x == 0.0f);
  REQUIRE(a.y == 0.0f);
  Vec2 b{4.2f, -9.3f};
  REQUIRE(b.x == Approx(4.2f));
  REQUIRE(b.y == Approx(-9.3f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
