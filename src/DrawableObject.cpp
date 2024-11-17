#include "DrawableObject.hpp"



DrawableObject::DrawableObject(
    std::unique_ptr<std::vector<std::optional<std::unique_ptr<Shape>>>> &shapes,
    std::unique_ptr<std::vector<std::optional<std::unique_ptr<Shader>>>> &shaders,
    std::unique_ptr<std::vector<std::optional<std::unique_ptr<Texture>>>> &textures
)
: shapes{std::move(shapes)}, shaders{std::move(shaders)}, textures{std::move(textures)}
{
}

// DrawableObject::DrawableObject(
//     std::vector<std::optional<std::unique_ptr<Shape>>> &shapes, 
//     std::vector<std::optional<std::unique_ptr<Shader>>> &shaders, 
//     std::vector<std::optional<std::unique_ptr<Texture>>> &textures
// ):
//     shapes{std::make_unique<std::vector<std::optional<std::unique_ptr<Shape>>>>(shapes)},
//     shaders{std::make_unique<std::vector<std::optional<std::unique_ptr<Shader>>>>(shaders)},
//     textures{std::make_unique<std::vector<std::optional<std::unique_ptr<Texture>>>>(textures)}
// {
// }

DrawableObject::~DrawableObject()
{
}

void DrawableObject::use(size_t idx)
{
    try {
        if (this->shapes.get()->size() > idx){
            if (this->shapes.get()->at(idx).has_value()){
                this->shapes.get()->at(idx).value().get()->use();
            }
        }
        if (this->shaders.get()->size() > idx){
            if (this->shaders.get()->at(idx).has_value()){
                this->shaders.get()->at(idx).value().get()->use();
            }
        }
        if (this->shaders.get()->size() > idx){
            if (this->shaders.get()->at(idx).has_value()){
                this->shaders.get()->at(idx).value().get()->use();
            }
        }
    }
    catch(const std::out_of_range &e){
        //  empty, silently ignore exceptions
    }
}

void DrawableObject::draw()
{
    auto shapesIter = this->shapes.get()->begin();
    auto shadersIter = this->shaders.get()->begin();
    auto texturesIter = this->textures.get()->begin();

    const auto shapesIterEnd = this->shapes.get()->end();
    const auto shadersIterEnd = this->shaders.get()->end();
    const auto texturesIterEnd = this->textures.get()->end();

    bool shapesIterDone{false};
    bool shadersIterDone{false};
    bool texturesIterDone{false};

    while (!(shapesIterDone && shadersIterDone && texturesIterDone)){

        if (!shadersIterDone){
            if (shadersIter != shadersIterEnd){
                shadersIter;
                if ((*shadersIter).has_value()){
                    (*shadersIter).value().get()->use();
                }
                shadersIter++;
            }
            else {
                shadersIterDone = true;
            }
        }
        if (!texturesIterDone){
            if (texturesIter != texturesIterEnd){
                texturesIter;
                if ((*texturesIter).has_value()){
                    (*texturesIter).value().get()->use();
                }
                texturesIter++;
            }
            else{
                texturesIterDone = true;
            }
        }
        if (!shapesIterDone){
            if (shapesIter != shapesIterEnd){
                shapesIter;
                if ((*shapesIter).has_value()){
                    (*shapesIter).value().get()->use();
                    (*shapesIter).value().get()->draw();
                }
                shapesIter++;
            }
            else{
                shadersIterDone = true;
            }
        }
    }
}
