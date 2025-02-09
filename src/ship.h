#pragma once

#include <raylib.h>

#include <functional>

#include "actor.h"

class Ship : public Actor {
 private:
  const Texture& _texture;

  void input();
  void constrain();
  std::function<void(Vector2)> shootLaser;

 public:
  explicit Ship(const Texture& texture, Vector2 pos, std::function<void(Vector2)> shootLaser);
  void update(float dt) override;
  void draw() const override;
};

class Laser : public Actor {
 private:
  const Texture* _texture;

 public:
  explicit Laser(const Texture* texture, Vector2 pos);
  void update(float dt) override;
  void draw() const override;
};

class Meteor : public Actor {
 private:
  const Texture* _texture;

 public:
  Meteor(const Texture* texture);
  void update(float dt) override;
  void draw() const override;
};
