#include "Object3D.hpp"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<cmath>

#include "Utils.hpp"
#include "glmutils.hpp"

Object3D::Object3D(const std::array<float, 3>& position, float angle, const std::array<float, 3>& axis, const std::array<float, 3>& scale) 
:
    id{idManager.getNewID()},
    position{position}, 
    velocity{std::array<float,3>{0.0f}}, 
    acceleration{std::array<float,3>{0.0f}},
    angle{angle}, 
    axis{glm::normalize(glm::vec3{axis[0],axis[1],axis[2]})},
    angularVelocity{0.0f},
    angularAcceleration{0.0f},
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

    this->angularVelocity += this->angularAcceleration * deltaTimeSeconds;
    this->angle += this->angularVelocity * deltaTimeSeconds;
    this->angle = copysignf(1.0f,this->angle) * fmodf(fabsf(this->angle),2*M_PI);

    for (size_t i = 0; i < this->velocity.size(); i++){
        this->velocity.at(i) += this->acceleration.at(i) * deltaTimeSeconds;
        this->position.at(i) += this->velocity.at(i) * deltaTimeSeconds;
        this->scaleVelocity.at(i) += this->scaleAcceleration.at(i) * deltaTimeSeconds;
        // this->orientation.at(i) = copysignf(1.0f,this->orientation.at(i)) * fmodf(2*M_PI,fabsf(this->orientation.at(i)));
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
    DBGEXPR(this->angle);
    DBGEXPRVEC3(this->axis);
    DBGEXPR(this->angularVelocity);
    DBGEXPR(this->angularAcceleration);
    DBGEXPRARRAY(this->scale);
    DBGEXPRARRAY(this->scaleVelocity);
    DBGEXPRARRAY(this->scaleAcceleration);
}

void Object3D::setAxis(int axis, float val) {
    this->axis[axis] = val;
    this->axis = glm::normalize(this->axis);
}

float Object3D::getAxis(int axis) {
    return this->axis[axis];
}

glm::vec3 Object3D::getAxis(void) {
    return this->axis;
}
