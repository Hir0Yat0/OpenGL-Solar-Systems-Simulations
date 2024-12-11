#ifndef PLANETSGROUPLOADER_HPP
#define PLANETSGROUPLOADER_HPP

// #include "PlanetsGroupLoader.hpp"
#include <memory>
#include <vector>

#include "RenderGroup3D.hpp"
#include "Object3D.hpp"
#include "SphereRenderGroup.hpp"
#include "OrbitalObjectFactory.hpp"
#include "OrbitalObject3D.hpp"

class PlanetsGroupLoader {

    private:

    constexpr std::unique_ptr<std::vector<std::shared_ptr<Object3D>>> getPlanetsObject3D(std::weak_ptr<Object3D> centralObject) const{

        auto planets = std::make_unique<std::vector<std::shared_ptr<Object3D>>>();

        auto orbitalObjectFactory = OrbitalObjectFactory();

        // get planets
        auto planetMercury = orbitalObjectFactory.getSharedOrbitalObject3D();
        // configure planets
        (*planetMercury).setUniformScale(100.0f);
        (*planetMercury).setAxisY();
        (*planetMercury).angularVelocity = 1.0f;
        (*planetMercury).position[2] = 100.0f * 1.0e+1;
        (*planetMercury).velocity[0] = 10.0f;   
        (*planetMercury).gravityToCentralObject = 1000.0f * 1.0e+1 ;
        (*planetMercury).centralObject = centralObject;
        // add planets
        (*planets).push_back(planetMercury);



        return planets;
    };

    public:

    constexpr std::unique_ptr<RenderGroup3D> getPlanets(std::weak_ptr<Object3D> centralObject) const{

        auto sphereRenderGroup = SphereRenderGroup().getRenderGroup3D();

        auto planets = this->getPlanetsObject3D(centralObject);

        for (auto &planet : (*planets)){
            (*sphereRenderGroup).add(planet);

        }


        return sphereRenderGroup;
    };

};


#endif // PLANETSGROUPLOADER_HPP
