#ifndef SPHEREOBJECTFACTORY_HPP
#define SPHEREOBJECTFACTORY_HPP

// #include "SphereObjectFactory.hpp"
#include<memory>
#include"Object3D.hpp"
#include"RenderGroup3D.hpp"

class SphereObjectFactory {

    private:

    

    public:

    std::shared_ptr<Object3D> makeSphereObject(float centerX=0.0f, float centerY=0.0f, float centerZ=0.0f,float radius=1.0f);
    std::shared_ptr<RenderGroup3D> makeSphereRenderGroup(const std::string& texturePath);

};


#endif // SPHEREOBJECTFACTORY_HPP
