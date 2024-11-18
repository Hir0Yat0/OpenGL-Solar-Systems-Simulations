#ifndef SPHEREFACTORY_HPP
#define SPHEREFACTORY_HPP

#include<memory>

// #include "SphereFactory.hpp"
#include"Shape.hpp"

class SphereFactory {

    private:

    std::unique_ptr<std::vector<float>> getVertices(const float center[3], float radius, unsigned int stackCountPerSector, unsigned int sectorCountPerStack) const;
    std::unique_ptr<std::vector<unsigned int>> getIndices(const float center[3], float radius, unsigned int stackCountPerSector, unsigned int sectorCountPerStack) const;

    public:

    float center[3];
    float radius;
    bool textured;
    unsigned int stackCountPerSector;
    unsigned int sectorCountPerStack;

    SphereFactory(const float center[3], float radius=5.0f, unsigned int stackCountPerSector=20U,unsigned int sectorCountPerStack=20U,bool textured = true);
    std::unique_ptr<Shape> makeSphere() const;
    std::unique_ptr<Shape> makeSphere(const float center[3], float radius, unsigned int stackCountPerSector, unsigned int sectorCountPerStack) const;


};


#endif // SPHEREFACTORY_HPP
