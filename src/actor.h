#pragma once

#include <raylib.h>

class Actor {
 protected:
  Vector2 _pos;
  Vector2 _dir;
  float _speed;

 public:
  bool discard;

  Actor(Vector2 pos, float speed, Vector2 dir = {0, 0});
  virtual ~Actor() = default;

  virtual void update(float dt) = 0;
  virtual void draw() const = 0;

  Vector2 getPos();
  void setPos(Vector2 pos);

  void move(float dt);
  void checkDiscard();
};
