#include "TestRenderGroup.hpp"

#include<memory>
#include<string>

#include"RenderGroup3D.hpp"
#include"RenderGroup3DManager.hpp"
#include"Object3D.hpp"
#include"SphereFactory.hpp"
#include"SphereObjectFactory.hpp"
#include "GLDrawWindow.hpp"


int TestRenderGroup::test() {

    auto window = GLDrawWindow();
    std::cerr << "Starting Tests!" << "\n";
    constexpr int dimension = 3;
    std::cerr << "making new renderGroupManager" << "\n";
    auto renderGroupManager = std::make_shared<RenderGroup3DManager>();
    std::cerr << "generating sphereObjectFactory" << "\n";
    auto sphereObjectFactory = SphereObjectFactory();
    std::cerr << "making new spheres" << "\n";
    auto sphere1 = sphereObjectFactory.makeSphereObject(0.0f,0.0f,0.0f, 0.5f);
    // auto sphere2 = sphereObjectFactory.makeSphereObject(0.0f,0.0f,-5.0f, 5.0f);
    (*sphere1).angularVelocity[1] = 0.5f;
    (*sphere1).position[2] = -2.5;
    (*sphere1).printObjectInfo();
    std::cerr << "make new sphereRenderGroup" << "\n";
    auto sphereRenderGroup = sphereObjectFactory.makeSphereRenderGroup("assets/sky-and-grass-24.jpg");
    std::cerr << "adding sphere1 and sphere2" << "\n";
    (*sphereRenderGroup).add(sphere1);
    // (*sphereRenderGroup).add(sphere2);
    std::cerr << "addNewRenderGroup" << "\n";
    (*renderGroupManager).addNewGroup(SPHERE_RENDER_GROUP_ID,sphereRenderGroup);
    std::cerr << "Starting Drawing!" << "\n";
    int exitcode = window.drawWindow(renderGroupManager);
    return exitcode;


}