#ifndef SHAPE_HPP
#define SHAPE_HPP

#include<vector>
#include<memory>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Shape {
    private:
    public:
    std::unique_ptr<std::vector<float>> vertices;
    std::unique_ptr<std::vector<unsigned int>> indices;
    unsigned int vao;
    unsigned int vbo;
    unsigned int ebo;
    Shape() = default;
    // Shape(const std::vector<float> &vertices,const std::vector<unsigned int> &indices);
    Shape(std::unique_ptr<std::vector<float>> vertices,std::unique_ptr<std::vector<unsigned int>> indices);
    virtual ~Shape();
    virtual void initShape();
    virtual void use();
    virtual void draw();
    template<class T>
    static void groupVertexAttributes(std::vector<T> &out_verticeAttributes, const std::vector<std::vector<T>> &vertexAttributes, const std::vector<unsigned int> &eachAttributesLength);
    void initShapeWithTexture();
};

#endif // SHAPE_HPP


