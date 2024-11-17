#ifndef DRAWABLEOBJECT_HPP
#define DRAWABLEOBJECT_HPP

// #include "DrawableObject.hpp"

#include<vector>
#include<memory>
#include<optional>

#include"Shape.hpp"
#include"Shader.hpp"
#include"Texture.hpp"

class DrawableObject {

    private:

    

    public:

    std::unique_ptr<std::vector<std::optional<std::unique_ptr<Shape>>>> shapes;
    std::unique_ptr<std::vector<std::optional<std::unique_ptr<Shader>>>> shaders;
    std::unique_ptr<std::vector<std::optional<std::unique_ptr<Texture>>>> textures;    
    
    DrawableObject(
        std::unique_ptr<std::vector<std::optional<std::unique_ptr<Shape>>>> &shapes,
        std::unique_ptr<std::vector<std::optional<std::unique_ptr<Shader>>>> &shaders,
        std::unique_ptr<std::vector<std::optional<std::unique_ptr<Texture>>>> &textures
    );
    DrawableObject(
        std::vector<std::optional<std::unique_ptr<Shape>>> &shapes,
        std::vector<std::optional<std::unique_ptr<Shader>>> &shaders,
        std::vector<std::optional<std::unique_ptr<Texture>>> &textures
    );
    virtual ~DrawableObject();    

    virtual void use(size_t idx);
    virtual void draw();

};


#endif // DRAWABLEOBJECT_HPP
