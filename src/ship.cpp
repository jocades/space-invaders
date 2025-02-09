#include "ship.h"

#include "raymath.h"

Ship::Ship(Texture2D& texture, float speed) : _texture(texture), _pos({0, 0}), _speed(speed) {}

void Ship::update(float dt) {
  _dir.x = int(IsKeyDown(KEY_RIGHT)) - int(IsKeyDown(KEY_LEFT));
  _dir.y = int(IsKeyDown(KEY_DOWN)) - int(IsKeyDown(KEY_UP));
  _dir = Vector2Normalize(_dir);
  _pos += _dir * _speed * dt;
}

void Ship::draw() {
  DrawTextureV(_texture, _pos, WHITE);
}
