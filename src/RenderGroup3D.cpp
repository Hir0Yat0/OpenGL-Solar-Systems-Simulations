#include"RenderGroup3D.hpp"

#include<string>
#include<format>
#include<chrono>
#include<memory>
#include<vector>
#include<unordered_map>

#include "FrameManager.hpp"

#include "Utils.hpp"

RenderGroup3D::RenderGroup3D(
    std::unique_ptr<Shape> shape, 
    std::unique_ptr<Shader> shader, 
    std::unique_ptr<Texture> texture ,
    int initSuccess
) :
    shape{std::move(shape)}, shader{std::move(shader)}, texture{std::move(texture)}, objects{std::make_unique<std::unordered_map<size_t,std::shared_ptr<Object3D>>>()}, initSuccess{initSuccess} //N
{

};    
void RenderGroup3D::render(void){
    std::cerr << "Render Called!" << "\n";
    if (this->shader){
        std::cerr << "Using Shaders!" << "\n";
        (*this->shader).use();
    }
    if (this->texture){
        std::cerr << "Using Textures!" << "\n";
        (*this->texture).use();
    }
    if (this->shape){
        std::cerr << "Using Shapes!" << "\n";
        (*this->shape).use();
    }
    if (objects && this->shader){
        for (const auto & [id,object] : (*objects)){
            if (object){
                std::cerr << "Setting Object Attributes!" << "\n";
                // std::cerr << "Rendering ObjectW: " << (*object).id << "\n";
                (*this->shader).setFloat(std::string("timeMillis"),static_cast<float>(FrameManager::deltaTimeSinceStart.count()));
                (*this->shader).setFloat(std::string("deltaTimeMillis"),static_cast<float>(FrameManager::deltaTime.count()));
                for (int i = 0; i < 3; i++){
                    (*this->shader).setFloat(std::format("vPosition{}",i),(*object).position.at(i));
                    (*this->shader).setFloat(std::format("vOrientation{}",i),(*object).orientation.at(i));
                    (*this->shader).setFloat(std::format("vScale{}",i),(*object).scale.at(i));
                }
                if (this->shape){
                    // Utils::printVectorErr((*(*this->shape).vertices));
                    std::cerr << "Drawing!" << "\n";
                    (*this->shape).draw();
                }
            }
        }
    }
};
void RenderGroup3D::add(std::shared_ptr<Object3D> object){
    if (!this->objects){
        this->objects = std::make_unique<std::unordered_map<size_t,std::shared_ptr<Object3D>>>();
    }
    if (object){
        (*this->objects)[(*object).id] = object;
    }
}
void RenderGroup3D::remove(size_t objectID) {
    if (this->objects){
        (*this->objects).erase(objectID);
    }
};
