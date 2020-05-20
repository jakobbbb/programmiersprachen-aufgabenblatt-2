#ifndef VEC2_HPP
#define VEC2_HPP

struct Vec2 {
  float x = 0.0f;
  float y = 0.0f;

  Vec2& operator+=(Vec2 const& v);
  Vec2& operator-=(Vec2 const& v);
  Vec2& operator*=(float s);
  Vec2& operator/=(float s);
  float norm() const;
};

Vec2 operator+(Vec2 const& u, Vec2 const& v);
Vec2 operator-(Vec2 const& u, Vec2 const& v);
Vec2 operator*(Vec2 const& u, float s);
Vec2 operator*(float s, Vec2 const& u);
Vec2 operator/(Vec2 const& u, float s);

#endif // VEC2_HPP
