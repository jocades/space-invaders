#pragma once

#include <memory>
#include <utility>
#include <vector>

#include "ship.h"

class Game {
 private:
  std::unique_ptr<Ship> _ship;
  std::vector<std::pair<Vector2, float>> _stars;
  std::vector<Laser> _lasers;

  void load();
  void update();
  void discard();
  void draw();

  void createShip();
  void createStars();

  void shootLaser(Vector2 pos);

 public:
  Game();
  ~Game();
  void run();
};
