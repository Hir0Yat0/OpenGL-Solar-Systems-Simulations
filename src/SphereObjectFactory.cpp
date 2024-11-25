#include "SphereObjectFactory.hpp"

#include<array>
#include<memory>
#include"SphereFactory.hpp"
#include"Shape.hpp"
#include"Shader.hpp"
#include"TextureLoader.hpp"
#include"Texture.hpp"

std::shared_ptr<Object3D> SphereObjectFactory::makeSphereObject(float centerX, float centerY, float centerZ,float radiusScale) {
    return std::make_shared<Object3D>(
        std::array<float,3>{centerX,centerY,centerZ},
        std::array<float,3>{0,0,0},
        std::array<float,3>{radiusScale,radiusScale,radiusScale}
    );
}

std::shared_ptr<RenderGroup3D> SphereObjectFactory::makeSphereRenderGroup(const std::string& texturePath) {
    std::cerr << "Starting makeSphereRenderGroup!" << "\n";
    const float center[3] = {0.0f,0.0f,0.0f};
    const float radius = 1.0f;
    std::cerr << "making sphereFactory!" << "\n";
    auto sphereFactory = SphereFactory(center,radius,20,20,true);
    std::cerr << "making shape!" << "\n";
    std::shared_ptr<Shape> shape = std::move(sphereFactory.makeSphere());
    // std::shared_ptr<Shape> shape = std::move(sphereFactory.makeSphere());
    std::cerr << "making shader!" << "\n";
    auto shader = std::make_shared<Shader>(Shader("src/shaders/object3d.vert","src/shaders/object3d.frag"));
    std::cerr << "making textures!" << "\n";
    std::shared_ptr<Texture> texture = std::move(TextureLoader::load(texturePath.c_str()));
    // auto a = RenderGroup<3>(,);
    std::cerr << "making and returning new renderGroup3D" << "\n";
    return std::make_shared<RenderGroup3D>(shape,shader,texture);
}
