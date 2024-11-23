#include "TestRenderGroup.hpp"

#include<memory>

#include"RenderGroup3D.hpp"
#include"RenderGroup3DManager.hpp"
#include"Object3D.hpp"
#include"SphereFactory.hpp"
#include"SphereObjectFactory.hpp"

void TestRenderGroup::test() {

    constexpr int dimension = 3;
    auto renderGroupManager = std::make_shared<RenderGroup3DManager>();
    auto sphereObjectFactory = SphereObjectFactory();
    auto sphere1 = sphereObjectFactory.makeSphereObject();
    auto sphere2 = sphereObjectFactory.makeSphereObject();
    auto sphereRenderGroup = sphereObjectFactory.makeSphereRenderGroup("assets/sky-and-grass-24.jpg");
    (*sphereRenderGroup).add(sphere1);
    (*sphereRenderGroup).add(sphere2);
    (*renderGroupManager).addNewGroup(SPHERE_RENDER_GROUP_ID,sphereRenderGroup);
    

}