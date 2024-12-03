#ifndef OBJECT3D_HPP
#define OBJECT3D_HPP

// #include "Object3D.hpp"
#include<array>
#include<chrono>
#include<unordered_map>
#include<random>
#include<functional>

#include"FrameManager.hpp"
#include"IDManager.hpp"

class Object3D {

    private:

    static inline std::unordered_map<size_t,Object3D *> objs{};
    static inline IDManager idManager{};

    public:

    const size_t id;
    std::array<float,3> position;
    std::array<float,3> velocity;
    std::array<float,3> acceleration;
    std::array<float,3> orientation;
    std::array<float,3> angularVelocity;
    //  std::array<float,3> angularVelocity;
    std::array<float,3> angularAcceleration;
    std::array<float,3> scale;
    std::array<float,3> scaleVelocity;
    std::array<float,3> scaleAcceleration;

    Object3D(const std::array<float,3> &position=std::array<float,3>{0.0f,0.0f,0.0f},const std::array<float,3> &orientation=std::array<float,3>{0.0f,0.0f,0.0f}, const std::array<float,3> &scale=std::array<float,3>{1.0f,1.0f,1.0f});
    virtual ~Object3D();
    virtual void update(const std::chrono::milliseconds &deltaTime);
    static void updateAllObjects(void);
    virtual void printObjectInfo(void) const;

};


#endif // OBJECT3D_HPP
