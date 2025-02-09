#pragma once

#include <memory>
#include <utility>
#include <vector>

#include "ship.h"
#include "timer.h"

class Game {
 private:
  std::unique_ptr<Ship> _ship;
  std::vector<std::pair<Vector2, float>> _stars;
  std::vector<Laser> _lasers;
  std::vector<Meteor> _meteors;
  Timer _meteor_timer;

  void load();
  void update();
  void discard();
  void draw();

  void createShip();
  void createStars();
  void createMeteor();

  void shootLaser(Vector2 pos);

  void drawStars();

 public:
  Game();
  ~Game();
  void run();
};
