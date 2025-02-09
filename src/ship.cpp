#include "ship.h"

#include <iostream>

#include "conf.h"
#include "raymath.h"

Ship::Ship(const Texture& texture, Vector2 pos, std::function<void(Vector2)> shootLaser)
    : Actor(pos, conf::sheep_speed),
      _texture(texture),
      _timer(Timer(2, true, true, []() { std::cout << "Timer done!\n"; })),
      shootLaser(shootLaser) {}

void Ship::input() {
  _dir.x = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
  _dir.y = IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP);
  _dir = Vector2Normalize(_dir);

  if (IsKeyPressed(KEY_SPACE)) {
    shootLaser({
      _pos.x + 0.5f * _texture.width,
      _pos.y,
    });
  }
}

void Ship::constrain() {
  if (_pos.x < 0) _pos.x = 0;
  else if (_pos.x > conf::scrw - _texture.width) _pos.x = conf::scrw - _texture.width;

  if (_pos.y < 0) _pos.y = 0;
  else if (_pos.y > conf::scrh - _texture.height) _pos.y = conf::scrh - _texture.height;
}

void Ship::update(float dt) {
  _timer.update();

  input();
  constrain();
  move(dt);
}

void Ship::draw() const {
  DrawTextureV(_texture, _pos, WHITE);
}

Laser::Laser(const Texture* texture, Vector2 pos)
    : Actor(pos, conf::laser_speed, {0, -1}), _texture(texture) {}

void Laser::update(float dt) {
  move(dt);
  checkDiscard();
}

void Laser::draw() const {
  DrawTextureV(*_texture, _pos, WHITE);
}
