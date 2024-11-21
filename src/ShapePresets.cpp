#include "ShapePresets.hpp"

#include"SphereFactory.hpp"

std::unique_ptr<Shape> ShapePresets::getSphere(const float center[3], float radius) {
    return SphereFactory(center,radius).makeSphere();
}