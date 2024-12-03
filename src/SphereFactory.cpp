#include "SphereFactory.hpp"

/* this makes M_PI works on windows */
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<cmath>

std::unique_ptr<std::vector<float>> SphereFactory::getVertices(void) {

    const unsigned int sectorStepCount = this->numSectorPerStackLevel;
    const unsigned int stackStepCount = this->numStackPerSector;
    const float sectorStepSizeRad = 2 * M_PI * (1 / static_cast<float>(sectorStepCount));
    const float stackStepSizeRad = M_PI * (1 / static_cast<float>(stackStepCount));

    constexpr float radius = 1.0f;

    auto vertices = std::make_unique<std::vector<float>>();
    (*vertices).reserve(5 * sectorStepCount * stackStepCount);

    // this (stack then sector) makes things easier when computing indices
    for (unsigned int stack_i = 0; stack_i < stackStepCount; stack_i++){
        for (unsigned int sector_i = 0; sector_i < sectorStepCount; sector_i++){
            const float phi = sectorStepSizeRad * sector_i;
            const float vertex_z = radius * cosf(phi);
            const float rsin_phi = radius * sinf(phi);
            const float theta = stackStepSizeRad * stack_i;
            const float vertex_x = rsin_phi * cosf(theta);
            const float vertex_y = rsin_phi * sinf(theta);
            (*vertices).push_back(vertex_x);
            (*vertices).push_back(vertex_y);
            (*vertices).push_back(vertex_z);
            (*vertices).push_back(static_cast<float>(sector_i) / static_cast<float>(sectorStepCount)); // texture_coords_x
            (*vertices).push_back(static_cast<float>(stack_i) / static_cast<float>(stackStepCount)); // texture_coords_y
        }   
    }

    return vertices;
}

std::unique_ptr<std::vector<unsigned int>> SphereFactory::getIndices(void) {

    auto indices = std::make_unique<std::vector<unsigned int>>();
    const unsigned int sectorStepCount = this->numSectorPerStackLevel;
    const unsigned int stackStepCount = this->numStackPerSector;
    // const float sectorStepSizeRad = 2 * M_PI * (1 / static_cast<float>(sectorStepCount));
    // const float stackStepSizeRad = M_PI * (1 / static_cast<float>(stackStepCount));
    (*indices).reserve(6 * sectorStepCount * stackStepCount); // more than this

    // handy notes:
    // k1--k1+1
    // |  / |
    // | /  |
    // k2--k2+1
    for (unsigned int stack_i = 0; stack_i < numStackPerSector-1;stack_i++){
        for (unsigned int sector_i = 0;sector_i < numSectorPerStackLevel-1;sector_i++){
            const unsigned int k1 = static_cast<unsigned int>(stack_i*numSectorPerStackLevel + sector_i);
            const unsigned int k1_1 = static_cast<unsigned int>(stack_i*numSectorPerStackLevel + sector_i + 1);
            const unsigned int k2 = static_cast<unsigned int>((stack_i + 1)*numSectorPerStackLevel + sector_i);
            const unsigned int k2_1 = static_cast<unsigned int>((stack_i+1)*numSectorPerStackLevel + sector_i + 1);
            (*indices).push_back(k1);
            (*indices).push_back(k1_1);
            (*indices).push_back(k2);
            (*indices).push_back(k2);
            (*indices).push_back(k1_1);
            (*indices).push_back(k2_1);
        }
        // connect last sectors to the first sectors
        const unsigned int k1 = static_cast<unsigned int>(stack_i*numSectorPerStackLevel + (numSectorPerStackLevel-1));
        const unsigned int k1_1 = static_cast<unsigned int>(stack_i*numSectorPerStackLevel);
        const unsigned int k2 = static_cast<unsigned int>((stack_i + 1)*numSectorPerStackLevel + (numSectorPerStackLevel - 1));
        const unsigned int k2_1 = static_cast<unsigned int>((stack_i+1)*numSectorPerStackLevel);
        (*indices).push_back(k1);
        (*indices).push_back(k1_1);
        (*indices).push_back(k2);
        (*indices).push_back(k2);
        (*indices).push_back(k1_1);
        (*indices).push_back(k2_1);
    }

    return indices;
}

SphereFactory::SphereFactory(size_t numSectorPerStackLevel, size_t numStackPerSector)
: numSectorPerStackLevel{numSectorPerStackLevel}, numStackPerSector{numStackPerSector}
{
}

std::unique_ptr<Shape> SphereFactory::getSphere(void) {

    auto vertices = this->getVertices();
    auto indices = this->getIndices();

    auto shape = std::make_unique<Shape>((*vertices),(*indices));
    // auto shape = Shape(vertices,indices);
    (*shape).initShapeWithTexture();

    return shape;
}

std::unique_ptr<Shape> SphereFactory::getShape() {
    return this->getSphere();
    // return nullptr;
}
