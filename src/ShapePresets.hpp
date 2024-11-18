#ifndef SHAPEPRESETS_HPP
#define SHAPEPRESETS_HPP

// #include "ShapePresets.hpp"
#include<memory>
#include"Shape.hpp"

class ShapePresets {

    private:

    

    public:

    ShapePresets() = delete;

    static std::unique_ptr<Shape> getSphere(const float center[3], float radius);

};


#endif // SHAPEPRESETS_HPP
