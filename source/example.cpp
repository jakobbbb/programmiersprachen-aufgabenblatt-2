#include "window.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  std::vector<Circle> circles;
  std::vector<Rectangle> rectangles;

  for (int i = 1; i <= 8; ++i) {
    circles.push_back(Circle{
        {(float) 60 * i + 50, (float) 700 - 30 * i},
        (float) 50 + 20 * i,
        {0.3, ((float)i)/8, 0.9}
    });
    rectangles.push_back(Rectangle{
        {(float) 10 * i, (float) 15 * i},
        {(float) 15 * i + 200, (float) 30 * i + 200},
        {((float)i)/8, 0, 0.9}
        });
  }

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    auto mouse_position = win.mouse_position();
    Vec2 mouse{(float) mouse_position.first, (float) mouse_position.second};

    for (Circle circ : circles)
      circ.draw(win, (circ.is_inside(mouse) ? 2.f : 1.f) * (2.5 + 0.5 * std::cos(2 * M_PI * t)));
    for (Rectangle rect : rectangles)
      rect.draw(win, rect.is_inside(mouse) ? 3.f : 1.5f);

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);

    Rectangle moving_rectangle{{x2-25, y2-25}, {x2+25, y2+25}, {0.f, 1.f, 1.f}};
    moving_rectangle.draw(win, moving_rectangle.is_inside(mouse) ? 3.f : 1.f);

    Circle moving_circle{{x3, y3}, 50.f, {1.f, 1.f, 0.f}};
    moving_circle.draw(win, moving_circle.is_inside(mouse) ? 3.f : 1.f);

    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    win.update();
  }

  return 0;
}
