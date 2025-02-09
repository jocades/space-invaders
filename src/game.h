#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "ship.h"

class Game {
 private:
  std::unordered_map<std::string, Texture2D> _textures;
  std::unique_ptr<Ship> _ship;

 public:
  Game();
  ~Game();
  void load();
  void run();
  void update();
  void draw();
};
