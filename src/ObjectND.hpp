#ifndef OBJECTND_HPP
#define OBJECTND_HPP

// #include "ObjectND.hpp"
#include<array>
#include<chrono>

template<int N>
class ObjectND {

    private:    

    

    public:

    std::array<float,N> position;
    std::array<float,N> velocity;
    std::array<float,N> acceleration;
    std::array<float,N> orientation;
    std::array<float,N> angularVelocity;
    std::array<float,N> angularAcceleration;
    std::array<float,N> scale;
    std::array<float,N> scaleVelocity;
    std::array<float,N> scaleAcceleration;

    ObjectND(const std::array<float,N> &position=std::array<float,N>{0.0f},const std::array<float,N> &orientation=std::array<float,N>{0.0f});
    void update(const std::chrono::milliseconds &deltaTime);

};


#endif // OBJECTND_HPP
