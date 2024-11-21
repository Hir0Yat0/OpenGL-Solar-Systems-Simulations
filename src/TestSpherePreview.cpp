#include "TestSpherePreview.hpp"

#include<iostream>
#include<vector>
#include<memory>
#include<array>
#include<functional>
#include<optional>

#include "GLDrawWindow.hpp"
#include "SphereFactory.hpp"
#include "ShapePresets.hpp"
#include "DrawableObject.hpp"
#include "DrawableUnit.hpp"
#include "Vec3D.hpp"
#include "Utils.hpp"
#include "Shape.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "TextureLoader.hpp"

int TestSpherePreview::testDrawSphere() {

    GLDrawWindow window = GLDrawWindow();
    constexpr const float center[] = {0.0f,0.0f,0.0f};
    SphereFactory sphereFactory = SphereFactory(center);
    sphereFactory.textured = true;
    auto sphere = sphereFactory.makeSphere();
    auto sphereOpt = std::make_optional<std::unique_ptr<Shape>>(std::move(sphere));
    auto shader = std::make_unique<Shader>("src/shaders/sphere.vert","src/shaders/sphere.frag");
    auto texture = TextureLoader::load("assets/sky-and-grass-24.jpg");
    auto unit = std::make_unique<DrawableUnit>(std::move(sphereOpt),std::move(shader),std::move(texture));
    // Utils::printVector(*unit.get()->shape.value().get()->vertices.get());
    auto units = std::make_unique<std::vector<std::unique_ptr<DrawableUnit>>>();
    units.get()->push_back(std::move(unit));
    auto obj = DrawableObject(std::move(units));
    // Utils::printVector(*obj.drawableUnits.get()->at(0).get()->shape.value().get()->vertices);
    // Utils::printVector(*obj.drawableUnits.get()->at(0).get()->shape.value().get()->indices);
    // for (unsigned int i = 0; i < obj.drawableUnits.get()->at(0).get()->shape.value().get()->vertices.get()->size();i += 5){
    //     std::cout << obj.drawableUnits.get()->at(0).get()->shape.value().get()->vertices.get()->at(i) << ", ";
    // }
    obj.broadcastFunctionToAllDrawableUnits([](DrawableUnit& drawableUnit){
        std::cout << "[" << "\n";
        for (unsigned int i = 0; i < drawableUnit.shape.value().get()->vertices.get()->size();i += 5){
            std::cout << drawableUnit.shape.value().get()->vertices.get()->at(i) << ", ";
        }
        std::cout << "\n]" << "\n";
        std::cout << "\n";
    });
    // std::cout << "\n";
    return window.drawWindow(obj);
}