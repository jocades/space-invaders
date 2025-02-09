#pragma once

#include <raylib.h>

#include <functional>

#include "actor.h"
#include "timer.h"

class Ship : public Actor {
 private:
  const Texture& _texture;
  Timer _timer;

  void input();
  void constrain();
  std::function<void(Vector2)> shootLaser;

 public:
  Ship(const Texture& texture, Vector2 pos, std::function<void(Vector2)> shootLaser);
  void update(float dt) override;
  void draw() const override;
};

class Laser : public Actor {
 private:
  const Texture* _texture;

 public:
  Laser(const Texture* texture, Vector2 pos);
  void update(float dt) override;
  void draw() const override;
};
