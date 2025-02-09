#include "game.h"

#include <raylib.h>

#include <vector>

#include "assets.h"
#include "conf.h"
#include "rng.h"

Game::Game() {
  InitWindow(conf::scrw, conf::scrh, conf::title);
  rng::init();
  load();
}

void Game::load() {
  assets::loadTexture("ship", "images/spaceship.png");
  assets::loadTexture("laser", "images/laser.png");
  assets::loadTexture("star", "images/star.png");
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

void Game::run() {
  while (!WindowShouldClose()) {
    update();
    draw();
  }
}

void Game::update() {
  float dt = GetFrameTime();
  _ship->update(dt);
  discard();
  for (auto& laser : _lasers) laser.update(dt);
}

void Game::discard() {
  std::erase_if(_lasers, [](Laser& laser) { return laser.discard; });
}

void Game::draw() {
  BeginDrawing();
  ClearBackground(conf::bg_color);

  for (const auto& [pos, size] : _stars) {
    DrawTextureEx(assets::textures["star"], pos, 0, size, WHITE);
  }

  for (const auto& laser : _lasers) laser.draw();
  _ship->draw();

  EndDrawing();
}

void Game::shootLaser(Vector2 pos) {
  const Texture* texture = &assets::textures["laser"];
  pos.x -= 0.5f * texture->width;
  pos.y -= 0.2f * texture->height;
  _lasers.emplace_back(texture, pos);
}
