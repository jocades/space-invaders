#include "rng.h"

#include <random>

namespace {
std::mt19937 rngEngine;
}

namespace rng {

void init() {
  std::random_device rd;
  rngEngine.seed(rd());  // Seed the engine with a random value
}

int randint(int min, int max) {
  std::uniform_int_distribution<int> dist(min, max);
  return dist(rngEngine);
}

float uniform(float min, float max) {
  std::uniform_real_distribution<float> dist(min, max);
  return dist(rngEngine);
}

Vector2 randvec2(float min_x, float max_x, float min_y, float max_y) {
  return {uniform(min_x, max_x), uniform(min_y, max_y)};
}

bool choice() {
  return randint(0, 1) == 1;
}

}  // namespace rng
