#pragma once

#include <raylib.h>

class Ship {
 private:
  Texture2D& _texture;
  Vector2 _pos;
  Vector2 _dir;
  float _speed;

 public:
  Ship(Texture2D& texture, float speed);
  void update(float dt);
  void draw();
};
