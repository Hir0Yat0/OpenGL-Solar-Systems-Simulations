#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include "Texture.hpp"

class TextureLoader {
    public:
    static Texture load(const char * texturePath);
};

#endif // TEXTURELOADER_HPP
