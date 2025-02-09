#pragma once

#include <raylib.h>

namespace conf {

constexpr int scrf = 80;
constexpr float scrw = 16 * scrf;
constexpr float scrh = 9 * scrf;
constexpr const char* title = "Space Invaders";
constexpr Color bg_color = {0x00, 0x0a, 0x0e, 0xff};
constexpr float sheep_speed = 500;
constexpr float laser_speed = 600;

}  // namespace conf
