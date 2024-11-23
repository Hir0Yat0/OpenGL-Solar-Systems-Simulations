#ifndef RENDERGROUP_HPP
#define RENDERGROUP_HPP

#include<memory>
#include<vector>
#include<unordered_map>

// #include "RenderGroup3D.hpp"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Shader.hpp"
#include "Shape.hpp"
#include "Texture.hpp"
#include "TextureLoader.hpp"
#include "Object3D.hpp"

class RenderGroup3D {

    private:

    std::shared_ptr<Shape> shape;
    std::shared_ptr<Shader> shader;
    std::shared_ptr<Texture> texture;
    std::shared_ptr<std::unordered_map<size_t,std::shared_ptr<Object3D>>> objects;

    public:

    RenderGroup3D(std::shared_ptr<Shape> shape, 
                std::shared_ptr<Shader> shader,
                std::shared_ptr<Texture> texture, 
                std::shared_ptr<std::unordered_map<size_t,std::shared_ptr<Object3D>>> objects
    );
    RenderGroup3D(std::shared_ptr<Shape> shape, 
                std::shared_ptr<Shader> shader,
                std::shared_ptr<Texture> texture 
    );
    virtual ~RenderGroup3D() = default;
    virtual void render(void);
    virtual void add(std::shared_ptr<Object3D> object);
    virtual void remove(std::shared_ptr<Object3D> object);

};


#endif // RENDERGROUP_HPP
