#include "SphereRenderGroup.hpp"

std::unique_ptr<RenderGroup3D> SphereRenderGroup::getRenderGroup3D(const char * texturePath) {

    int initSuccess = 1;

    auto sphereFactory = SphereFactory();

    auto shape = sphereFactory.getShape();

    auto shader = ShaderLoader::loadShader("src/shaders/object3d.vert","src/shaders/object3d.frag");

    if (!(*shader).shaderStatus){
        std::cerr << "Shader Initialization Errors" << "\n";
        initSuccess = 0;
    }

    auto texture = TextureLoader::load(texturePath);

    if (!(*texture).initSuccess) {
        std::cerr << "Texture Initialization Errors" << "\n";
        initSuccess = 0;
    }

    auto renderGroup3D = std::make_unique<RenderGroup3D>(std::move(shape),std::move(shader),std::move(texture),initSuccess);

    return renderGroup3D;
}