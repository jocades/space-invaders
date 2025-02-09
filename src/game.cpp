#include "game.h"

#include <raylib.h>

#include "conf.h"

Game::Game() {
  InitWindow(conf::scrw, conf::scrh, conf::title);
  load();
}

void Game::load() {
  _textures["ship"] = LoadTexture("./assets/images/spaceship.png");
  _ship = std::make_unique<Ship>(_textures["ship"], 400);
}

Game::~Game() {
  for (const auto& [_, texture] : _textures) {
    UnloadTexture(texture);
  }
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

  EndDrawing();
}
