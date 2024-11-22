#include "ObjectND.hpp"

#define _USE_MATH_DEFINES
#include<cmath>
template<int N>
ObjectND<N>::ObjectND(const std::array<float, N> &position, const std::array<float, N> &orientation)
: 
    position{position}, 
    velocity{std::array<float,N>{0.0f}}, 
    acceleration{std::array<float,N>{0.0f}}, 
    orientation{orientation},
    angularVelocity{std::array<float,N>{0.0f}},
    angularAcceleration{std::array<float,N>{0.0f}},
    scale{std::array<float,N>{0.0f}},
    scaleVelocity{std::array<float,N>{0.0f}},
    scaleAcceleration{std::array<float,N>{0.0f}}
{

}
template<int N>
void ObjectND<N>::update(const std::chrono::milliseconds& deltaTime) {
    const float deltaTimeSeconds = std::chrono::duration<float>(deltaTime).count();
    for (int i = 0; i < this->velocity.size(); i++){
        this->velocity.at(i) += this->acceleration.at(i) * deltaTimeSeconds;
        this->angularVelocity.at(i) += this->angularAcceleration.at(i) * deltaTimeSeconds;
        this->position.at(i) += this->velocity.at(i) * deltaTimeSeconds;
        this->scaleVelocity.at(i) += this->scaleAcceleration.at(i) * deltaTimeSeconds;
        this->orientation.at(i) += this->angularVelocity.at(i) * deltaTimeSeconds;
        this->orientation.at(i) = copysignf(1.0f,this->orientation.at(i)) * fmodf(2*M_PI,fabsf(this->orientation.at(i)));
        this->scale.at(i) += this->scaleVelocity.at(i) * deltaTimeSeconds;
    }
}
