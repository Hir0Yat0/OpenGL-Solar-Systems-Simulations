#ifndef SHAPENOTEXTURE_HPP
#define SHAPENOTEXTURE_HPP

// #include "ShapeNoTexture.hpp"
#include"Shape.hpp"

class ShapeNoTexture: public Shape {

    private:

    

    public:

    ShapeNoTexture() = default;
    ShapeNoTexture(const std::vector<float> &vertices,const std::vector<unsigned int> &indices);

};


#endif // SHAPENOTEXTURE_HPP
