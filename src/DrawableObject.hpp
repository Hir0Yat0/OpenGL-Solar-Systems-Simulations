#ifndef DRAWABLEOBJECT_HPP
#define DRAWABLEOBJECT_HPP

// #include "DrawableObject.hpp"

#include<iostream>
#include<vector>
#include<memory>
#include<optional>
#include<functional>

#include"Shape.hpp"
#include"Shader.hpp"
#include"Texture.hpp"
#include "DrawableUnit.hpp"

class DrawableObject {

    private:

    

    public:

    std::unique_ptr<std::vector<std::unique_ptr<DrawableUnit>>> drawableUnits;

    DrawableObject(std::unique_ptr<std::vector<std::unique_ptr<DrawableUnit>>> drawableUnits);
    // DrawableObject(
    //     std::unique_ptr<std::vector<std::optional<std::unique_ptr<Shape>>>> &shapes,
    //     std::unique_ptr<std::vector<std::optional<std::unique_ptr<Shader>>>> &shaders,
    //     std::unique_ptr<std::vector<std::optional<std::unique_ptr<Texture>>>> &textures
    // );
    // DrawableObject(
    //     std::vector<std::optional<std::unique_ptr<Shape>>> &shapes,
    //     std::vector<std::optional<std::unique_ptr<Shader>>> &shaders,
    //     std::vector<std::optional<std::unique_ptr<Texture>>> &textures
    // );
    virtual ~DrawableObject();    

    virtual void use(size_t idx);
    virtual void draw();
    virtual void draw(size_t idx);
    void broadcastFunctionToAllDrawableUnits(std::function<void(DrawableUnit&)> &&fn);
    void setBoolAll(const std::string &name, bool value) const;  
    void setIntAll(const std::string &name, int value) const;   
    void setFloatAll(const std::string &name, float value) const;

};


#endif // DRAWABLEOBJECT_HPP
