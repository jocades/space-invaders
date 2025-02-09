#include "assets.h"

namespace assets {

std::unordered_map<std::string, Texture2D> textures;
std::unordered_map<std::string, Sound> sounds;

const Texture2D& loadTexture(const std::string& name, const std::string& path) {
  textures[name] = LoadTexture(path.c_str());
  return textures[name];
}

void loadSound(const std::string& name, const std::string& path) {
  sounds[name] = LoadSound(path.c_str());
}

void unloadTextures() {
  for (auto it = textures.begin(); it != textures.end();) {
    UnloadTexture(it->second);
    it = textures.erase(it);
  }
}

void unloadSounds() {
  for (auto it = sounds.begin(); it != sounds.end();) {
    UnloadSound(it->second);
    it = sounds.erase(it);
  }
};

void unload() {
  unloadTextures();
  unloadSounds();
}

}  // namespace assets
