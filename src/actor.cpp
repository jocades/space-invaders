#include "actor.h"

#include <raymath.h>

Actor::Actor(Vector2 pos, float speed, Vector2 dir) : _pos(pos), _dir(dir), _speed(speed) {}

Vector2 Actor::getPos() {
  return _pos;
}

void Actor::setPos(Vector2 pos) {
  _pos = pos;
}

void Actor::move(float dt) {
  _pos += _dir * _speed * dt;
}
