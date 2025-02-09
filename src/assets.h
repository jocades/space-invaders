#include <raylib.h>

#include <string>
#include <unordered_map>

namespace assets {

extern std::unordered_map<std::string, Texture> textures;
extern std::unordered_map<std::string, Sound> sounds;

void loadTexture(const std::string& name, const std::string& path);
void loadSound(const std::string& name, const std::string& path);
void unloadTextures();
void unloadSounds();
void unload();

}  // namespace assets
