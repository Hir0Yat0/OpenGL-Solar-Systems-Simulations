#include "Object3D.hpp"

#define _USE_MATH_DEFINES
#include<cmath>

Object3D::Object3D(const std::array<float, 3>& position, const std::array<float, 3>& orientation, const std::array<float, 3>& scale) 
:
    id{idManager.getNewID()},
    position{position}, 
    velocity{std::array<float,3>{0.0f}}, 
    acceleration{std::array<float,3>{0.0f}}, 
    orientation{orientation},
    angularVelocity{std::array<float,3>{0.0f}},
    angularAcceleration{std::array<float,3>{0.0f}},
    scale{scale},
    scaleVelocity{std::array<float,3>{0.0f}},
    scaleAcceleration{std::array<float,3>{0.0f}}
{
    
}

Object3D::~Object3D() {
    idManager.removeID(this->id);
}
void Object3D::update(const std::chrono::milliseconds &deltaTime) {
    const float deltaTimeSeconds = std::chrono::duration<float>(deltaTime).count();
    for (size_t i = 0; i < this->velocity.size(); i++){
        this->velocity.at(i) += this->acceleration.at(i) * deltaTimeSeconds;
        this->angularVelocity.at(i) += this->angularAcceleration.at(i) * deltaTimeSeconds;
        this->position.at(i) += this->velocity.at(i) * deltaTimeSeconds;
        this->scaleVelocity.at(i) += this->scaleAcceleration.at(i) * deltaTimeSeconds;
        this->orientation.at(i) += this->angularVelocity.at(i) * deltaTimeSeconds;
        this->orientation.at(i) = copysignf(1.0f,this->orientation.at(i)) * fmodf(2*M_PI,fabsf(this->orientation.at(i)));
        this->scale.at(i) += this->scaleVelocity.at(i) * deltaTimeSeconds;
    }
}
void Object3D::updateAllObjects(void) {
    for (auto & [objId,obj] : objs){
        obj.get().update(FrameManager::deltaTime);
    }
}
