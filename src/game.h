#pragma once

#include <memory>

#include "ship.h"

class Game {
 private:
  std::unique_ptr<Ship> _ship;
  std::unique_ptr<Laser> _laser;

 public:
  Game();
  ~Game();
  void load();
  void run();
  void update();
  void draw();
};
