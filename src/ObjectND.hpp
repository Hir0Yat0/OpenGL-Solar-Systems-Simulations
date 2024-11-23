#ifndef OBJECTND_HPP
#define OBJECTND_HPP

// #include "ObjectND.hpp"
#include<array>
#include<chrono>
#include<unordered_map>
#include<random>
#include<functional>

#include"FrameManager.hpp"
#include"IDManager.hpp"
template<int N>
class ObjectND {

    private:    

    static inline std::unordered_map<size_t,std::reference_wrapper<ObjectND<N>>> objs{};
    static inline IDManager idManager{};

    public:

    size_t id;
    std::array<float,N> position;
    std::array<float,N> velocity;
    std::array<float,N> acceleration;
    std::array<float,N> orientation;
    std::array<float,N> angularVelocity;
    std::array<float,N> angularAcceleration;
    std::array<float,N> scale;
    std::array<float,N> scaleVelocity;
    std::array<float,N> scaleAcceleration;

    ObjectND(const std::array<float,N> &position=std::array<float,N>{0.0f},const std::array<float,N> &orientation=std::array<float,N>{0.0f}, const std::array<float,N> &scale=std::array<float,N>{1.0f});
    virtual ~ObjectND();
    virtual void update(const std::chrono::milliseconds &deltaTime);
    static void updateAllObjects(void);

};


#endif // OBJECTND_HPP
