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
    std::shared_ptr<Shape> shape, 
    std::shared_ptr<Shader> shader,
    std::shared_ptr<Texture> texture, 
    std::shared_ptr<std::unordered_map<size_t,std::shared_ptr<Object3D>>> objects
):
    shape{shape}, shader{shader}, texture{texture}, objects{objects}
{

}
RenderGroup3D::RenderGroup3D(
    std::shared_ptr<Shape> shape, 
    std::shared_ptr<Shader> shader, 
    std::shared_ptr<Texture> texture 
) :
    shape{shape}, shader{shader}, texture{texture}, objects{std::make_shared<std::unordered_map<size_t,std::shared_ptr<Object3D>>>()} //N
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
    if (objects.get() != nullptr && this->shader.get() != nullptr){
        for (const auto & [id,object] : (*objects.get())){
            if (object){
                // std::cerr << "Rendering ObjectW: " << (*object).id << "\n";
                for (int i = 0; i < 3; i++){
                    this->shader.get()->setFloat(std::string("timeMillis"),static_cast<float>(FrameManager::deltaTimeSinceStart.count()));
                    this->shader.get()->setFloat(std::string("deltaTimeMillis"),static_cast<float>(FrameManager::deltaTime.count()));
                    this->shader.get()->setFloat(std::format("vPosition{}",i),(*object).position.at(i));
                    this->shader.get()->setFloat(std::format("vOrientation{}",i),(*object).orientation.at(i));
                    this->shader.get()->setFloat(std::format("vScale{}",i),(*object).scale.at(i));
                }
                if (this->shape){
                    // Utils::printVectorErr((*(*this->shape).vertices));
                    (*this->shape).draw();
                }
            }
        }
    }
};
void RenderGroup3D::add(std::shared_ptr<Object3D> object){
    if (this->objects.get() == nullptr){
        this->objects = std::make_shared<std::unordered_map<size_t,std::shared_ptr<Object3D>>>();
    }
    if (object){
        (*this->objects)[(*object).id] = object;
    }
}
void RenderGroup3D::remove(std::shared_ptr<Object3D> object) {
    if (this->objects){
        if (object){
            (*this->objects).erase((*object).id);
        }
    }
};
