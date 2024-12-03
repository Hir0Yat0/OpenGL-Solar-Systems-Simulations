#ifndef SPHERERENDERGROUP_HPP
#define SPHERERENDERGROUP_HPP

// #include "SphereRenderGroup.hpp"
#include<memory>
#include"RenderGroup3D.hpp"
#include"Shape.hpp"
#include"Shader.hpp"
#include"TextureLoader.hpp"
#include"Texture.hpp"
#include"ShaderLoader.hpp"
#include"SphereFactory.hpp"

class SphereRenderGroup {

    private:

    

    public:

    std::unique_ptr<RenderGroup3D> getRenderGroup3D();

};


#endif // SPHERERENDERGROUP_HPP
