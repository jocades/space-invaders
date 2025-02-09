#pragma once

#include <raylib.h>

namespace conf {
constexpr int scrf = 80;
constexpr float scrw = 16 * scrf;
constexpr float scrh = 9 * scrf;
constexpr const char* title = "Space Invaders";
constexpr Color bg_color = {0x28, 0x28, 0x28, 0xff};

constexpr float sheep_speed = 500;
constexpr float laser_speed = 200;
}  // namespace conf
