#include"RenderGroupManager.hpp"

template<int OBJ_ND>
RenderGroupManager<OBJ_ND>::RenderGroupManager()
: rendergroups{std::make_shared<std::unordered_map<int,std::shared_ptr<RenderGroup<OBJ_ND>>>>()}
{

};
template<int OBJ_ND>
void RenderGroupManager<OBJ_ND>::renderAll(void){
    if (this->rendergroups.get() != nullptr){
        auto rgm = this->rendergroups.get();
        for (auto itr = rgm->begin(); itr != rgm->end(); itr++){
            if ((*itr).get() != nullptr){
                (*itr).get()->render();
            }
        }
    }
};
template<int OBJ_ND>
void RenderGroupManager<OBJ_ND>::render(int groupid){
    if (this->rendergroups.get() != nullptr){
        auto rgm = this->rendergroups.get();
        auto rg = rgm.at(groupid);
        if (rg.get() != nullptr){
            rg.get()->render();
        }
    }
};
template<int OBJ_ND>
void RenderGroupManager<OBJ_ND>::addNewGroup(int id,std::shared_ptr<RenderGroup<OBJ_ND>> renderGroup){
    if (this->rendergroups.get() == nullptr){
        this->rendergroups = std::make_shared<std::unordered_map<int,std::shared_ptr<RenderGroup<OBJ_ND>>>>();
    }
    (*this->rendergroups)[id] = renderGroup;
};
template<int OBJ_ND>
void RenderGroupManager<OBJ_ND>::addToGroup(int id, std::shared_ptr<ObjectND<OBJ_ND>> object){
    if (this->rendergroups.get() == nullptr){
        this->rendergroups = std::make_shared<std::unordered_map<int,std::shared_ptr<RenderGroup<OBJ_ND>>>>();
    }
    (*this->rendergroups)[id].pushback(object);
};
template<int OBJ_ND>
void RenderGroupManager<OBJ_ND>::removeGroup(int id){
    if (this->rendergroups.get() == nullptr){
        this->rendergroups = std::make_shared<std::unordered_map<int,std::shared_ptr<RenderGroup<OBJ_ND>>>>();
    }
    this->rendergroups.get()->erase(id);
};

