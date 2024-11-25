#include "Object3D.hpp"

#define _USE_MATH_DEFINES
#include<cmath>

#include "Utils.hpp"

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
    Object3D::objs[this->id] =  this;
}

Object3D::~Object3D() {
    idManager.removeID(this->id);
}
void Object3D::update(const std::chrono::milliseconds &deltaTime) {
    const float deltaTimeSeconds = std::chrono::duration<float>(deltaTime).count();
    DBGEXPR(deltaTime);
    DBGEXPR(deltaTimeSeconds);
    for (size_t i = 0; i < this->velocity.size(); i++){
        this->velocity.at(i) += this->acceleration.at(i) * deltaTimeSeconds;
        this->angularVelocity.at(i) += this->angularAcceleration.at(i) * deltaTimeSeconds;
        this->position.at(i) += this->velocity.at(i) * deltaTimeSeconds;
        this->scaleVelocity.at(i) += this->scaleAcceleration.at(i) * deltaTimeSeconds;
        this->orientation.at(i) += this->angularVelocity.at(i) * deltaTimeSeconds;
        // this->orientation.at(i) = copysignf(1.0f,this->orientation.at(i)) * fmodf(2*M_PI,fabsf(this->orientation.at(i)));
        this->orientation.at(i) = copysignf(1.0f,this->orientation.at(i)) * fmodf(fabsf(this->orientation.at(i)),2*M_PI);
        this->scale.at(i) += this->scaleVelocity.at(i) * deltaTimeSeconds;
    }
}
void Object3D::updateAllObjects(void) {
    std::cerr << "Starting updateAllObjects!" << "\n";
    for (auto & [objId,obj] : objs){
        std::cerr << "Updating Objects!" << "\n";
        obj->update(FrameManager::deltaTime);
        obj->printObjectInfo();
    }
    std::cerr << "Done updateAllObjects!" << "\n";
}

void Object3D::printObjectInfo(void) const {
    DBGEXPR(this->id);
    DBGEXPRARRAY(this->position);
    DBGEXPRARRAY(this->velocity);
    DBGEXPRARRAY(this->acceleration);
    DBGEXPRARRAY(this->orientation);
    DBGEXPRARRAY(this->angularVelocity);
    DBGEXPRARRAY(this->angularAcceleration);
    DBGEXPRARRAY(this->scale);
    DBGEXPRARRAY(this->scaleVelocity);
    DBGEXPRARRAY(this->scaleAcceleration);
}
