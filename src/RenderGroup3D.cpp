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
                // for (int i = 0; i < 3; i++){
                //     (*this->shader).setFloat(std::format("vPosition{}",i),(*object).position.at(i));
                //     (*this->shader).setFloat(std::format("vOrientation{}",i),(*object).orientation.at(i));
                //     (*this->shader).setFloat(std::format("vScale{}",i),(*object).scale.at(i));
                // }

                // calculate the model matrix for each object and pass it to shader before drawing
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                const glm::vec3 pos = glm::vec3((*object).position[0],(*object).position[1],(*object).position[2]);
                model = glm::translate(model, pos);
                constexpr float angleRads = 1.0f;
                constexpr glm::vec3 axis = glm::vec3(1.0f, 0.3f, 0.5f);
                model = glm::rotate(model, angleRads, axis);
                (*this->shader).setMat4("model", model);

                if (this->shape){
                    // Utils::printVectorErr((*(*this->shape).vertices));
                    std::cerr << "Drawing!" << "\n";
                    (*this->shape).draw();
                }
            }
        }
    }
}
void RenderGroup3D::render(const glm::mat4& projection, const glm::mat4& view) {

    (*this->shader).setMat4("projection", projection);
    (*this->shader).setMat4("view", view);
    this->render();

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