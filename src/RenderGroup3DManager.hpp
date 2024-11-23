#ifndef RENDERGROUPMANAGER_HPP
#define RENDERGROUPMANAGER_HPP

// #include "RenderGroupManager.hpp"
#include<unordered_map>
#include<memory>
#include<vector>

#include"RenderGroup3D.hpp"
#include"Object3D.hpp"

class RenderGroup3DManager {

    private:

    std::shared_ptr<std::unordered_map<int,std::shared_ptr<RenderGroup3D>>> rendergroups;
    // std::unique_ptr<std::vector<unsigned int>>;

    public:

    RenderGroup3DManager();
    void renderAll(void);
    void render(int groupid);
    void addNewGroup(int groupid, std::shared_ptr<RenderGroup3D> renderGroup);
    void addToGroup(int groupid, std::shared_ptr<Object3D> object);
    void removeGroup(int groupid);
    void removeFromGroup(int groupid, std::shared_ptr<Object3D> object);
    

};


#endif // RENDERGROUPMANAGER_HPP
