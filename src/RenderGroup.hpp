#ifndef RENDERGROUP_HPP
#define RENDERGROUP_HPP

#include<memory>
#include<vector>

// #include "RenderGroup.hpp"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Shader.hpp"
#include "Shape.hpp"
#include "Texture.hpp"
#include "TextureLoader.hpp"
#include "ObjectND.hpp"

template<int OBJ_ND>
class RenderGroup {

    private:

    std::shared_ptr<Shape> shape;
    std::shared_ptr<Shader> shader;
    std::shared_ptr<Texture> texture;
    std::shared_ptr<std::vector<std::shared_ptr<ObjectND<OBJ_ND>>>> objects;

    public:

    RenderGroup(std::shared_ptr<Shape> shape, 
                std::shared_ptr<Shader> shader,
                std::shared_ptr<Texture> texture, 
                std::shared_ptr<std::vector<std::shared_ptr<ObjectND<OBJ_ND>>>> objects
    );
    RenderGroup(std::shared_ptr<Shape> shape, 
                std::shared_ptr<Shader> shader,
                std::shared_ptr<Texture> texture 
    );
    virtual ~RenderGroup() = default;
    virtual void render(void);
    virtual void add(std::shared_ptr<ObjectND<OBJ_ND>> object);

};


#endif // RENDERGROUP_HPP
