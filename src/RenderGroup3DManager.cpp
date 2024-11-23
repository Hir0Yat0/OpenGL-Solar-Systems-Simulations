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
void RenderGroup3DManager::addNewGroup(int groupid,std::shared_ptr<RenderGroup3D> renderGroup){
    if (this->rendergroups.get() == nullptr){
        this->rendergroups = std::make_shared<std::unordered_map<int,std::shared_ptr<RenderGroup3D>>>();
    }
    (*this->rendergroups)[groupid] = renderGroup;
};
void RenderGroup3DManager::addToGroup(int groupid, std::shared_ptr<Object3D> object){
    if (this->rendergroups.get() == nullptr){
        this->rendergroups = std::make_shared<std::unordered_map<int,std::shared_ptr<RenderGroup3D>>>();
    }
    auto renderGroup = (*this->rendergroups)[groupid];
    if (renderGroup){
        (*renderGroup).add(object);
    }
};
void RenderGroup3DManager::removeGroup(int groupid){
    if (this->rendergroups.get() == nullptr){
        this->rendergroups = std::make_shared<std::unordered_map<int,std::shared_ptr<RenderGroup3D>>>();
    }
    this->rendergroups.get()->erase(groupid);
}
void RenderGroup3DManager::removeFromGroup(int groupid, std::shared_ptr<Object3D> object) {
    if (this->rendergroups){
        auto rg = (*this->rendergroups)[groupid];
        if (rg){
            (*rg).remove(object);
        }
    }
};
