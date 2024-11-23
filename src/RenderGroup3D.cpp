#include"RenderGroup3D.hpp"

#include<string>
#include<format>
#include<chrono>

#include "FrameManager.hpp"

RenderGroup3D::RenderGroup3D(
    std::shared_ptr<Shape> shape, 
    std::shared_ptr<Shader> shader,
    std::shared_ptr<Texture> texture, 
    std::shared_ptr<std::vector<std::shared_ptr<Object3D>>> objects
):
    shape{shape}, shader{shader}, texture{texture}, objects{objects}
{

}
RenderGroup3D::RenderGroup3D(
    std::shared_ptr<Shape> shape, 
    std::shared_ptr<Shader> shader, 
    std::shared_ptr<Texture> texture 
) :
    shape{shape}, shader{shader}, texture{texture}, objects{std::make_shared<std::vector<std::shared_ptr<Object3D>>>()} //N
{

};    
void RenderGroup3D::render(void){
    if (this->shader.get() != nullptr){
        this->shader.get()->use();
    }
    if (this->texture.get() != nullptr){
        this->texture.get()->use();
    }
    if (this->shape.get() != nullptr){
        this->shape.get()->use();
    }
    if (objects.get() != nullptr){
        for (const auto & object : (*objects.get())){
            for (int i = 0; i < 3; i++){
                if (object){
                    this->shader.get()->setFloat(std::string("timeMillis"),static_cast<float>(FrameManager::deltaTimeSinceStart.count()));
                    this->shader.get()->setFloat(std::string("deltaTimeMillis"),static_cast<float>(FrameManager::deltaTime.count()));
                    this->shader.get()->setFloat(std::format("vPosition{}",i),(*object).position.at(i));
                    this->shader.get()->setFloat(std::format("vOrientation{}",i),(*object).orientation.at(i));
                    this->shader.get()->setFloat(std::format("vScale{}",i),(*object).scale.at(i));
                }
            }
        }
    }
};
void RenderGroup3D::add(std::shared_ptr<Object3D> object){
    if (this->objects.get() == nullptr){
        this->objects = std::make_shared<std::vector<std::shared_ptr<Object3D>>>();
    }
    this->objects.get()->push_back(object);
};
