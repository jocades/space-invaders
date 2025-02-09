#pragma once

#include <memory>
#include <utility>
#include <vector>

#include "ship.h"

class Game {
 private:
  std::unique_ptr<Ship> _ship;
  std::unique_ptr<Laser> _laser;
  std::vector<std::pair<Vector2, float>> _stars;

 public:
  Game();
  ~Game();
  void load();
  void run();
  void update();
  void draw();
};
