#include "assets.h"

#include <filesystem>

namespace assets {

const std::filesystem::path dir = "assets";
const std::filesystem::path images_dir = dir / "images";
const std::filesystem::path sounds_dir = dir / "sounds";

std::unordered_map<std::string, Texture> textures;
std::unordered_map<std::string, Sound> sounds;

void loadTexture(const std::string& name, const std::string& path) {
  textures[name] = LoadTexture((images_dir / path).c_str());
}

void loadSound(const std::string& name, const std::string& path) {
  sounds[name] = LoadSound((sounds_dir / path.c_str()).c_str());
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
