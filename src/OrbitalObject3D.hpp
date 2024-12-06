#ifndef ORBITALOBJECT3D_HPP
#define ORBITALOBJECT3D_HPP

// #include "OrbitalObject3D.hpp"
#include <iostream>
#include "Object3D.hpp"
#include "glmlib.hpp"

class OrbitalObject3D: public Object3D {

    private:

    

    public:

    float gravityToCentralObject;
    glm::vec3 centralObjectPosition;

    OrbitalObject3D(float gravityToCentralObject = 1.0f, const glm::vec3 &centralObjectPosition = glm::vec3(0.0f), const std::array<float,3> &position=std::array<float,3>{0.0f,0.0f,0.0f}, float angle = 0.0f,const std::array<float,3> &axis=std::array<float,3>{1.0f,0.0f,0.0f}, const std::array<float,3> &scale=std::array<float,3>{1.0f,1.0f,1.0f});
    virtual void update(const float &deltaTimeSeconds) override;

};


#endif // ORBITALOBJECT3D_HPP