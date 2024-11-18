#include "DrawableObject.hpp"

DrawableObject::DrawableObject(std::unique_ptr<std::vector<std::unique_ptr<DrawableUnit>>> drawableUnits) 
: drawableUnits{std::move(drawableUnits)}
{
    
}

// DrawableObject::DrawableObject(
//     std::unique_ptr<std::vector<std::optional<std::unique_ptr<Shape>>>> &shapes,
//     std::unique_ptr<std::vector<std::optional<std::unique_ptr<Shader>>>> &shaders,
//     std::unique_ptr<std::vector<std::optional<std::unique_ptr<Texture>>>> &textures)
// : 
//     drawableUnits{std::unique_ptr<std::vector<DrawableUnit>>()}
// {
//     // shapes{std::move(shapes)}, shaders{std::move(shaders)}, textures{std::move(textures)} 
//     auto shapesIter = shapes.get()->begin();
//     auto shadersIter = shaders.get()->begin();
//     auto texturesIter = textures.get()->begin();

//     const auto shapesIterEnd = shapes.get()->end();
//     const auto shadersIterEnd = shaders.get()->end();
//     const auto texturesIterEnd = textures.get()->end();

//     bool shapesIterDone{false};
//     bool shadersIterDone{false};
//     bool texturesIterDone{false};

//     while (!(shapesIterDone && shadersIterDone && texturesIterDone)){

//         if (!shadersIterDone){
//             if (shadersIter != shadersIterEnd){
//                 shadersIter;
//                 if ((*shadersIter).has_value()){
//                     (*shadersIter).value().get()->use();
//                 }
//                 shadersIter++;
//             }
//             else {
//                 shadersIterDone = true;
//             }
//         }
//         if (!texturesIterDone){
//             if (texturesIter != texturesIterEnd){
//                 texturesIter;
//                 if ((*texturesIter).has_value()){
//                     (*texturesIter).value().get()->use();
//                 }
//                 texturesIter++;
//             }
//             else{
//                 texturesIterDone = true;
//             }
//         }
//         if (!shapesIterDone){
//             if (shapesIter != shapesIterEnd){
//                 shapesIter;
//                 if ((*shapesIter).has_value()){
//                     (*shapesIter).value().get()->use();
//                     (*shapesIter).value().get()->draw();
//                 }
//                 shapesIter++;
//             }
//             else{
//                 shadersIterDone = true;
//             }
//         }
// }

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
        this->drawableUnits.get()->at(idx).get()->use();
    }
    catch(const std::out_of_range &e){
        //  empty, silently ignore exceptions
        std::cerr << "DrawableObject: Index Out Of Range" << "\n";
    }
}

void DrawableObject::draw()
{
    for (auto &drawableUnit : *this->drawableUnits.get()){
        drawableUnit.get()->use();
        drawableUnit.get()->draw();
    }        
}

void DrawableObject::draw(size_t idx) {
    try {
        this->use(idx);
        this->drawableUnits.get()->at(idx).get()->draw();
    }
    catch(const std::out_of_range &e) {
        //  empty, silently ignore exceptions
        std::cerr << "DrawableObject: Index Out Of Range" << "\n";
    }
}

void DrawableObject::broadcastFunctionToAllDrawableUnits(std::function<void(DrawableUnit&)> &&fn) {
    for (auto &drawableUnit : *this->drawableUnits.get()){
        fn(*drawableUnit.get());
    }
}

void DrawableObject::setBoolAll(const std::string &name, bool value) const {
    for (auto &drawableUnit : *this->drawableUnits.get()){
        if (drawableUnit.get()->shader.has_value()){
            drawableUnit.get()->shader.value().get()->setBool(name,value);
        }
    }
};
void DrawableObject::setIntAll(const std::string &name, int value) const {
    for (auto &drawableUnit : *this->drawableUnits.get()){
        if (drawableUnit.get()->shader.has_value()){
            drawableUnit.get()->shader.value().get()->setInt(name,value);
        }
    }
};   
void DrawableObject::setFloatAll(const std::string &name, float value) const {
    for (auto &drawableUnit : *this->drawableUnits.get()){
        if (drawableUnit.get()->shader.has_value()){
            drawableUnit.get()->shader.value().get()->setFloat(name,value);
        }
    }
};
