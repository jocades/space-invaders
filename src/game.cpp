#include "game.h"

#include <raylib.h>

#include <vector>

#include "assets.h"
#include "conf.h"
#include "rng.h"

Game::Game() : _meteor_timer(Timer(0.4, true, true, [this]() { this->createMeteor(); })) {
  InitWindow(conf::scrw, conf::scrh, conf::title);
  rng::init();
  load();
}

void Game::load() {
  assets::loadTexture("ship", "spaceship.png");
  assets::loadTexture("laser", "laser.png");
  assets::loadTexture("star", "star.png");
  assets::loadTexture("meteor", "meteor.png");
  createShip();
  createStars();
}

Game::~Game() {
  assets::unload();
  CloseWindow();
}

void Game::createShip() {
  const Texture& texture = assets::textures["ship"];

  _ship = std::make_unique<Ship>(
    texture,
    Vector2{
      conf::scrw / 2 - float(texture.width) / 2,
      conf::scrh / 2 - float(texture.height) / 2,
    },
    [this](Vector2 pos) { this->shootLaser(pos); }
  );
}

void Game::createStars() {
  for (int i = 0; i < 30; i++) {
    _stars.emplace_back(rng::randvec2(0, conf::scrw, 0, conf::scrh), rng::uniform(0.5, 1.5));
  }
}

void Game::createMeteor() {
  _meteors.emplace_back(&assets::textures["meteor"]);
}

void Game::run() {
  while (!WindowShouldClose()) {
    update();
    draw();
  }
}

void Game::shootLaser(Vector2 pos) {
  const Texture* texture = &assets::textures["laser"];
  pos.x -= 0.5f * texture->width;
  pos.y -= 0.2f * texture->height;
  _lasers.emplace_back(texture, pos);
}

void Game::discard() {
  std::erase_if(_lasers, [](const Laser& laser) { return laser.discard; });
  std::erase_if(_meteors, [](const Meteor& meteor) { return meteor.discard; });
}

void Game::update() {
  float dt = GetFrameTime();
  _meteor_timer.update();
  discard();
  _ship->update(dt);
  for (auto& laser : _lasers) laser.update(dt);
  for (auto& meteor : _meteors) meteor.update(dt);
}

void Game::drawStars() {
  for (const auto& [pos, size] : _stars) {
    DrawTextureEx(assets::textures["star"], pos, 0, size, WHITE);
  }
}

void Game::draw() {
  BeginDrawing();
  ClearBackground(conf::bg_color);

  drawStars();

  for (const auto& laser : _lasers) laser.draw();
  for (const auto& meteor : _meteors) meteor.draw();

  _ship->draw();

  DrawFPS(0, 0);
  EndDrawing();
}
