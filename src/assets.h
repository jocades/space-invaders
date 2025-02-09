#include <raylib.h>

#include <string>
#include <unordered_map>

namespace assets {

extern std::unordered_map<std::string, Texture2D> textures;
extern std::unordered_map<std::string, Sound> sounds;

const Texture2D& loadTexture(const std::string& name, const std::string& path);
void loadSound(const std::string& name, const std::string& path);
void unloadTextures();
void unloadSounds();
void unload();

}  // namespace assets
