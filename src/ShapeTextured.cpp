// #include "ShapeTextured.hpp"

// ShapeTextured::ShapeTextured(const std::vector<float> &vertices,const std::vector<unsigned int> &indices, const char * texturePath)
// : Shape(vertices, indices), texture{TextureLoader::load(texturePath)}
// {
//     this->texture.use();
//     this->initShapeWithTexture();
// }

// ShapeTextured::ShapeTextured(const std::vector<float> &vertices,const std::vector<unsigned int> &indices, const Texture &texture)
// : Shape(vertices, indices), texture{texture}
// {
//     this->texture.use();
//     this->initShapeWithTexture();
// }

// void ShapeTextured::use() {
//     this->texture.use();
//     this->Shape::use();
// }

// void ShapeTextured::draw() {
//     this->use();
//     this->Shape::draw();
// }

// // ShapeTextured::~ShapeTextured(){
//     // texture.~Texture();
//     // shape.~Shape();
// // }
