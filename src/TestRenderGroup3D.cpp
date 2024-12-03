#include "TestRenderGroup3D.hpp"

#include "Object3D.hpp"
#include "RenderGroup3D.hpp"
#include "GLDrawWindow.hpp"
#include "SphereObjectFactory.hpp"
#include "SphereRenderGroup.hpp"

int TestRenderGroup3D::runTest() {

    auto window = GLDrawWindow();

    if (!window.initSuccess){
        std::cerr << "GLFW Window Initialization Errors" << "\n";
        return -1;
    }

    auto sphereObjectFactory = SphereObjectFactory();

    auto sphere1 = sphereObjectFactory.getSharedObject3D();
    (*sphere1).angularVelocity[1] = 0.5f;

    auto sphereRenderGroup = SphereRenderGroup().getRenderGroup3D();

    if (!(*sphereRenderGroup).initSuccess){
        std::cerr << "Sphere Render Group Initialization Errors!" << "\n";
        return -1;
    }

    (*sphereRenderGroup).add(sphere1);

    int exitcode = window.drawWindow(std::move(sphereRenderGroup));

    return exitcode;
}