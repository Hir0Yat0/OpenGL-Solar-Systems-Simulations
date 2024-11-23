#include"RenderGroup3DManager.hpp"

RenderGroup3DManager::RenderGroup3DManager()
: rendergroups{std::make_shared<std::unordered_map<int,std::shared_ptr<RenderGroup3D>>>()}
{

};
void RenderGroup3DManager::renderAll(void){
    if (this->rendergroups.get() != nullptr){
        auto rgm = this->rendergroups.get();
        for (auto itr = rgm->begin(); itr != rgm->end(); itr++){
            auto &[groupid, renderGroup] = (*itr);
            if (renderGroup){
                (*renderGroup).render();
            }
        }
    }
};
void RenderGroup3DManager::render(int groupid){
    if (this->rendergroups.get() != nullptr){
        auto rgm = this->rendergroups.get();
        auto &rg = rgm->at(groupid);
        if (rg.get() != nullptr){
            rg.get()->render();
        }
    }
};
void RenderGroup3DManager::addNewGroup(int id,std::shared_ptr<RenderGroup3D> renderGroup){
    if (this->rendergroups.get() == nullptr){
        this->rendergroups = std::make_shared<std::unordered_map<int,std::shared_ptr<RenderGroup3D>>>();
    }
    (*this->rendergroups)[id] = renderGroup;
};
void RenderGroup3DManager::addToGroup(int id, std::shared_ptr<Object3D> object){
    if (this->rendergroups.get() == nullptr){
        this->rendergroups = std::make_shared<std::unordered_map<int,std::shared_ptr<RenderGroup3D>>>();
    }
    auto renderGroup = (*this->rendergroups)[id];
    if (renderGroup){
        (*renderGroup).add(object);
    }
};
void RenderGroup3DManager::removeGroup(int id){
    if (this->rendergroups.get() == nullptr){
        this->rendergroups = std::make_shared<std::unordered_map<int,std::shared_ptr<RenderGroup3D>>>();
    }
    this->rendergroups.get()->erase(id);
};

