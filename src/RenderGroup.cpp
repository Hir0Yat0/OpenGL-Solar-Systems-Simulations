#include"RenderGroup.hpp"

#include<string>
#include<format>
#include<chrono>

#include "FrameManager.hpp"

template<int OBJ_ND>
RenderGroup<OBJ_ND>::RenderGroup(
    std::shared_ptr<Shape> shape, 
    std::shared_ptr<Shader> shader,
    std::shared_ptr<Texture> texture, 
    std::shared_ptr<std::vector<std::shared_ptr<ObjectND<OBJ_ND>>>> objects
):
    shape{shape}, shader{shader}, texture{texture}, objects{objects}
{

}
template<int OBJ_ND>
RenderGroup<OBJ_ND>::RenderGroup(
    std::shared_ptr<Shape> shape, 
    std::shared_ptr<Shader> shader, 
    std::shared_ptr<Texture> texture 
) :
    shape{shape}, shader{shader}, texture{texture}, objects{std::make_shared<std::vector<std::shared_ptr<ObjectND<OBJ_ND>>>>()}
{

};
template<int OBJ_ND>    
void RenderGroup<OBJ_ND>::render(void){
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
            for (int i = 0; i < OBJ_ND; i++){
                this->shader.get()->setFloat(std::string("timeMillis"),FrameManager::getCurrentFrameTimestamp());
                this->shader.get()->setFloat(std::string("deltaTimeMillis"),FrameManager::getDeltaTime());
                this->shader.get()->setFloat(std::format("vPosition{}",i),object.get().position.at(i));
                this->shader.get()->setFloat(std::format("vOrientation{}",i),object.get().orientation.at(i));
                this->shader.get()->setFloat(std::format("vScale{}",i),object.get().scale.at(i));
            }
        }
    }
};
template<int OBJ_ND>    
void RenderGroup<OBJ_ND>::add(std::shared_ptr<ObjectND<OBJ_ND>> object){
    if (this->objects.get() == nullptr){
        this->objects = std::make_shared<std::shared_ptr<std::vector<ObjectND<OBJ_ND>>>>();
    }
    this->objects.get()->add(object);
};
