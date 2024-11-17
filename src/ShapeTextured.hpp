#ifndef ShapeTextured_HPP
#define ShapeTextured_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Shape.hpp"
#include "Texture.hpp"
#include "TextureLoader.hpp"

class ShapeTextured: public Shape {

    private:

    public:
    Texture texture;    
    ShapeTextured() = default;
    ShapeTextured(const std::vector<float> &vertices,const std::vector<unsigned int> &indices, const char * texturePath);
    ShapeTextured(const std::vector<float> &vertices,const std::vector<unsigned int> &indices, const Texture &texture);
    // ~ShapeTextured();
    void use() override;
    void draw() override;

};

#endif // ShapeTextured_HPP
