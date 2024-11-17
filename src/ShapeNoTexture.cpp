#include "ShapeNoTexture.hpp"

ShapeNoTexture::ShapeNoTexture(const std::vector<float> &vertices,const std::vector<unsigned int> &indices) 
: Shape(vertices, indices)
{
    this->Shape::initShape();
}
