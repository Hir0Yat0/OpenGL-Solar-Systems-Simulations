#include "TestSphereRender.hpp"

#include "Shape.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "TextureLoader.hpp"
#include "GLDrawWindow.hpp"

#include "ShapeFactory.hpp"
#include "SphereFactory.hpp"

int TestSphereRender::runTest() {

    auto window = GLDrawWindow();

    if (!window.initSuccess){
        std::cerr << "GLFW Window Initialization Errors" << "\n";
        return -1;
    }

    Shader shader{"src/shaders/sphere.vert","src/shaders/sphere.frag"};

    if (!shader.shaderStatus){
        std::cerr << "Shader Initialization Errors" << "\n";
        return -1;
    }

    auto texture = TextureLoader::load("assets/sky-and-grass-24.jpg");

    if (!texture.initSuccess) {
        std::cerr << "Texture Initialization Errors" << "\n";
        return -1;
    }

    auto sphereFactory = SphereFactory();
    auto shape = sphereFactory.getSphere();

    int exitcode = window.drawWindow(shader,(*shape),texture);

    return exitcode;
}