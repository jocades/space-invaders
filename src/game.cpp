#include "game.h"

#include <raylib.h>

#include <utility>
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
  const Texture2D& texture = assets::loadTexture("ship", "./assets/images/spaceship.png");
  _ship = std::make_unique<Ship>(
    texture,
    Vector2{
      conf::scrw / 2 - float(texture.width) / 2,
      conf::scrh / 2 - float(texture.height) / 2,
    }
  );

  assets::loadTexture("laser", "./assets/images/laser.png");
  _laser = std::make_unique<Laser>(assets::textures["laser"], Vector2{0, 0});

  assets::loadTexture("star", "./assets/images/star.png");
  for (int i = 0; i < 30; i++) {
    _stars.emplace_back(rng::randvec2(0, conf::scrw, 0, conf::scrh), rng::uniform(0.5, 1.5));
  }
}

Game::~Game() {
  assets::unload();
  CloseWindow();
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
}

void Game::draw() {
  BeginDrawing();
  ClearBackground(conf::bg_color);

  _ship->draw();

  for (const auto& [pos, size] : _stars) {
    DrawTextureEx(assets::textures["star"], pos, 0, size, WHITE);
  }

  EndDrawing();
}
