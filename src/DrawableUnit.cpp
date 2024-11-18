#include "DrawableUnit.hpp"

DrawableUnit::DrawableUnit(
    std::optional<std::unique_ptr<Shape>> shape,
    std::optional<std::unique_ptr<Shader>> shader,
    std::optional<std::unique_ptr<Texture>> texture
):
    shape{std::move(shape)}, shader{std::move(shader)}, texture{std::move(texture)}
{

};
DrawableUnit::~DrawableUnit(){

};
void DrawableUnit::use(){
    if (this->shader.has_value()){
        this->shader.value().get()->use();
    }
    if (this->texture.has_value()){
        this->texture.value().get()->use();
    }
    if (this->shape.has_value()){
        this->shape.value().get()->use();
    }
};
void DrawableUnit::draw(){
    this->use();
    if (this->shape.has_value()){
        this->shape.value().get()->draw();
    }
    else {
        std::cerr << "DrawableUnit::draw(): Shape Not Found! " << "\n";
    }
};

