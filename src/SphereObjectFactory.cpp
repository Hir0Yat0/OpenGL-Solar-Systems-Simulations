#include "SphereObjectFactory.hpp"

#include<array>
#include<memory>
#include"SphereFactory.hpp"
#include"Shape.hpp"
#include"Shader.hpp"
#include"TextureLoader.hpp"
#include"Texture.hpp"

std::shared_ptr<Object3D> SphereObjectFactory::makeSphereObject(float centerX, float centerY, float centerZ,float radius) {
    return std::make_shared<Object3D>(std::array<float,3>{centerX,centerY,centerZ},std::array<float,3>{radius});
}

std::shared_ptr<RenderGroup3D> SphereObjectFactory::makeSphereRenderGroup(const std::string& texturePath) {
    const float center[3] = {0.0f,0.0f,0.0f};
    const float radius = 1.0f;
    auto sphereFactory = SphereFactory(center,radius,20,20,true);
    std::shared_ptr<Shape> shape = std::move(sphereFactory.getBaseSphere());
    auto shader = std::make_shared<Shader>(Shader("src/shaders/object3d.vert","src/shaders/object3d.frag"));
    std::shared_ptr<Texture> texture = std::move(TextureLoader::load(texturePath.c_str()));
    // auto a = RenderGroup<3>(,);
    return std::make_shared<RenderGroup3D>(shape,shader,texture);
}
