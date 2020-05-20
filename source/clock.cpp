#include "window.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "mat2.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>

#define WINDOW_SIZE 800

int main(int argc, char* argv[])
{
  Window win{std::make_pair(WINDOW_SIZE, WINDOW_SIZE)};

  Vec2 center{WINDOW_SIZE/2, WINDOW_SIZE/2};
  Circle outer{center, WINDOW_SIZE/2, {0.8, 0.8, 0.8}};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed =
        win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    outer.draw(win);

    int speed = left_pressed ? 100 : 1;
    auto t = std::floor(win.get_time() * speed);

    float secs = std::fmod(t, 60);
    float mins = std::fmod(t / 60, 60);
    float hours = std::fmod(t / 3600, 12);

    Vec2 p_mins =
        rotation_matrix(M_PI * mins / 30) * Vec2{0, -WINDOW_SIZE/2} + center;
    win.draw_line(center.x, center.y, p_mins.x, p_mins.y, 1, 1, 1, 2);

    Vec2 p_hours =
        rotation_matrix(M_PI * hours / 6) * Vec2{0, -WINDOW_SIZE/3} + center;
    win.draw_line(center.x, center.y, p_hours.x, p_hours.y, 1, 1, 1, 3);

    Vec2 p_secs =
        rotation_matrix(M_PI * secs / 30) * Vec2{0, -WINDOW_SIZE/2} + center;
    win.draw_line(center.x, center.y, p_secs.x, p_secs.y, 1, 0, 0);


    win.update();
  }

  return 0;
}
