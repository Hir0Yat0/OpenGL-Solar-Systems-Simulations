#ifndef RENDERGROUP3DMANAGER_HPP
#define RENDERGROUP3DMANAGER_HPP

// #include "RenderGroup3DManager.hpp"
#include <unordered_map>
#include <memory>

#include "glmlib.hpp"
#include "RenderGroup3D.hpp"
#include "Object3D.hpp"

class RenderGroup3DManager {

    private:

    

    public:

    std::unordered_map<int, std::unique_ptr<RenderGroup3D>> rendergroups3d;

    [[nodiscard]]
    static constexpr std::unique_ptr<RenderGroup3DManager> makeNew(void) {return std::make_unique<RenderGroup3DManager>();};

    void addNewGroup(int groupid, std::unique_ptr<RenderGroup3D> rendergroup3d);
    void addToGroup(int groupid, std::shared_ptr<Object3D> object3d);
    void render(int groupid);
    void render(int groupid, const glm::mat4& projection, const glm::mat4& view);
    void renderAll(const glm::mat4& projection, const glm::mat4& view);

};


#endif // RENDERGROUP3DMANAGER_HPP