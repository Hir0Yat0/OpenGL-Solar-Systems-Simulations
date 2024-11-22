#ifndef RENDERGROUPMANAGER_HPP
#define RENDERGROUPMANAGER_HPP

// #include "RenderGroupManager.hpp"
#include<unordered_map>
#include<memory>
#include<vector>

#include"RenderGroup.hpp"
#include"ObjectND.hpp"

template<int OBJ_ND>
class RenderGroupManager {

    private:

    std::shared_ptr<std::unordered_map<int,std::shared_ptr<RenderGroup<OBJ_ND>>>> rendergroups;
    // std::unique_ptr<std::vector<unsigned int>>;

    public:

    RenderGroupManager();
    void renderAll(void);
    void render(int groupid);
    void addNewGroup(int id, std::shared_ptr<RenderGroup<OBJ_ND>> renderGroup);
    void addToGroup(int id, std::shared_ptr<ObjectND<OBJ_ND>> object);
    void removeGroup(int id);
    // void removeFromGroup(int id, std::shared_ptr<ObjectND<OBJ_ND>> object);
    

};


#endif // RENDERGROUPMANAGER_HPP
