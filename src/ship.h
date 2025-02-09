#pragma once

#include <raylib.h>

#include "actor.h"

class Ship : public Actor {
 private:
  const Texture2D& _texture;
  void input();
  void constrain();

 public:
  Ship(const Texture2D& texture, Vector2 pos);
  void update(float dt) override;
  void draw() const override;
};

class Laser : public Actor {
 private:
  const Texture2D& _texture;

 public:
  Laser(const Texture2D& texture, Vector2 pos);
  void update(float dt) override;
  void draw() const override;
};
