#include"SphereFactory.hpp"

#define _USE_MATH_DEFINES
#include<cmath>

std::unique_ptr<std::vector<float>> SphereFactory::getVertices(const float center[3], float radius, unsigned int stackCountPerSector, unsigned int sectorCountPerStack) const {
    // auto vertices = std::make_unique<std::vector<float>>(new std::vector<float>());
    auto vertices = std::make_unique<std::vector<float>>();
    constexpr int numElementPerVertices{5};
    vertices.get()->reserve(stackCountPerSector*sectorCountPerStack*numElementPerVertices);

    const float stackStepSize{static_cast<float>(M_PI / stackCountPerSector)};
    const float sectorStepSize{static_cast<float>(2*M_PI / sectorCountPerStack)};

    for (unsigned int stack_i = 0; stack_i < stackCountPerSector; stack_i++){
        for (unsigned int sector_i = 0; sector_i < sectorCountPerStack; sector_i++){
            const float phi = static_cast<float>(stackStepSize * stack_i);
            const float theta = static_cast<float>(sectorStepSize * sector_i);
            const float rsin_phi = radius * static_cast<float>(sinf(phi));
            const float vertex_x = center[0] + rsin_phi * cosf(theta);
            const float vertex_y = center[1] + rsin_phi * sinf(theta);
            const float vertex_z = center[2] + radius * cosf(phi);
            vertices.get()->push_back(vertex_x);
            vertices.get()->push_back(vertex_y);
            vertices.get()->push_back(vertex_z);
            if (this->textured){
                vertices.get()->push_back(float(sector_i) / float(sectorCountPerStack)); // texture_coords_x
                vertices.get()->push_back(float(stack_i) / float(stackCountPerSector)); // texture_coords_y
            }
        }
    }
    return std::move(vertices);
}

std::unique_ptr<std::vector<unsigned int>> SphereFactory::getIndices(const float center[3], float radius, unsigned int stackCountPerSector, unsigned int sectorCountPerStack) const {
    // auto indices = std::make_unique<std::vector<unsigned int>>(new std::vector<unsigned int>());
    auto indices = std::make_unique<std::vector<unsigned int>>();
    constexpr int numElementPerVertices{6};
    indices.get()->reserve(stackCountPerSector*sectorCountPerStack * numElementPerVertices);

    const float stackStepSize{static_cast<float>(M_PI / static_cast<float>(stackCountPerSector))};
    const float sectorStepSize{static_cast<float>(2*M_PI / static_cast<float>(sectorCountPerStack))};

    // handy notes:
    // k1--k1+1
    // |  / |
    // | /  |
    // k2--k2+1
    for (unsigned int stack_i = 0; stack_i < stackCountPerSector-1;stack_i++){
        for (unsigned int sector_i = 0;sector_i < sectorCountPerStack-1;sector_i++){
            const unsigned int k1 = (unsigned int)(stack_i*sectorCountPerStack + sector_i);
            const unsigned int k1_1 = (unsigned int)(stack_i*sectorCountPerStack + sector_i + 1);
            const unsigned int k2 = (unsigned int)((stack_i + 1)*sectorCountPerStack + sector_i);
            const unsigned int k2_1 = (unsigned int)((stack_i+1)*sectorCountPerStack + sector_i + 1);
            indices.get()->push_back(k1);
            indices.get()->push_back(k1_1);
            indices.get()->push_back(k2);
            indices.get()->push_back(k2);
            indices.get()->push_back(k1_1);
            indices.get()->push_back(k2_1);
        }
        // connect last sectors to the first sectors
        const unsigned int k1 = (unsigned int)(stack_i*sectorCountPerStack + (sectorCountPerStack-1));
        const unsigned int k1_1 = (unsigned int)(stack_i*sectorCountPerStack);
        const unsigned int k2 = (unsigned int)((stack_i + 1)*sectorCountPerStack + (sectorCountPerStack - 1));
        const unsigned int k2_1 = (unsigned int)((stack_i+1)*sectorCountPerStack);
        indices.get()->push_back(k1);
        indices.get()->push_back(k1_1);
        indices.get()->push_back(k2);
        indices.get()->push_back(k2);
        indices.get()->push_back(k1_1);
        indices.get()->push_back(k2_1);
    }

    return std::move(indices);
}

SphereFactory::SphereFactory(const float center[3], float radius, unsigned int stackCountPerSector, unsigned int sectorCountPerStack,bool textured)
    : center{center[0], center[1], center[2]}, radius{radius}, stackCountPerSector{stackCountPerSector}, sectorCountPerStack{sectorCountPerStack}, textured{textured} {
}
std::unique_ptr<Shape> SphereFactory::makeSphere() const{
    return std::move(this->makeSphere(this->center,this->radius, this->stackCountPerSector, this->sectorCountPerStack));
};
std::unique_ptr<Shape> SphereFactory::makeSphere(const float center[3], float radius, unsigned int stackCountPerSector, unsigned int sectorCountPerStack) const{
    std::unique_ptr<std::vector<float>> vertices = this->getVertices(center,radius,stackCountPerSector,sectorCountPerStack);
    std::unique_ptr<std::vector<unsigned int>> indices = this->getIndices(center,radius,stackCountPerSector,sectorCountPerStack);
    // std::unique_ptr<Shape> shape = std::make_unique<Shape>(new Shape(std::move(vertices),std::move(indices)));
    std::unique_ptr<Shape> shape = std::make_unique<Shape>(std::move(vertices),std::move(indices));
    if (this->textured){
        shape.get()->initShapeWithTexture();
    }
    else {
        shape.get()->initShape();
    }
    return std::move(shape);
}
std::unique_ptr<Shape> SphereFactory::getBaseSphere() const {
    
    const float center[3] = {0.0f,0.0f,0.0f};
    auto vertices = this->getVertices(center,1.0f,20,20);
    auto indices = this->getIndices(center,1.0f,20,20);
    std::unique_ptr<Shape> shape = std::make_unique<Shape>(std::move(vertices),std::move(indices));
    if (this->textured){
        shape.get()->initShapeWithTexture();
    }
    else {
        shape.get()->initShape();
    }
    // return std::move(shape);
    return std::move(shape);

};
