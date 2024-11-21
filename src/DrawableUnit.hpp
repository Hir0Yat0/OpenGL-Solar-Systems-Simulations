#ifndef DRAWABLEUNIT_HPP
#define DRAWABLEUNIT_HPP

#include <vector>
#include <memory>
#include <optional>

// #include "DrawableUnit.hpp"
#include "Shape.hpp"
#include "Shader.hpp"
#include "Texture.hpp"

class DrawableUnit {

    private:



    public:

    std::optional<std::unique_ptr<Shape>> shape;
    std::optional<std::unique_ptr<Shader>> shader;
    std::optional<std::unique_ptr<Texture>> texture;
    DrawableUnit(
        std::optional<std::unique_ptr<Shape>> shape,
        std::optional<std::unique_ptr<Shader>> shader,
        std::optional<std::unique_ptr<Texture>> texture
    );
    virtual ~DrawableUnit();
    virtual void use();
    virtual void draw();

};


#endif // DRAWABLEUNIT_HPP
