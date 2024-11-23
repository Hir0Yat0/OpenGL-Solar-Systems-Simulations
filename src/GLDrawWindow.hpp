#ifndef GLWINDOW_HPP
#define GLWINDOW_HPP

#include"glad/glad.h"
#include"GLFW/glfw3.h"

#include<vector>
#include<optional>
#include<memory>
#include <chrono>

#include "Shader.hpp"
#include "Shape.hpp"
#include "Texture.hpp"
#include "ShapeTextured.hpp"
#include "DrawableObject.hpp"
#include "RenderGroup3D.hpp"
#include "RenderGroup3DManager.hpp"
#include "FrameManager.hpp"
#include "Object3D.hpp"

class GLDrawWindow
{
private:
    /* data */
    GLFWwindow * window;
    bool polygonFillMode;
    const int SCR_WIDTH;
    const int SCR_HEIGHT;
    static void framebuffer_size_callback(GLFWwindow * window, int width, int height);
public:
    int initSuccess;
    GLDrawWindow(/* args */);
    ~GLDrawWindow();
    int drawWindow(Shader &shaderProgram, Shape & shape,const std::optional<Texture> & texture);
    int drawWindow(Shader &shaderProgram, std::vector<Shape> & shapes,const std::optional<Texture> & texture);
    // int drawWindow(Shader &shaderProgram, std::vector<ShapeTextured> & ShapeTextureds)    ;
    int drawWindow(DrawableObject &obj);
    int drawWindow(std::shared_ptr<RenderGroup3DManager> renderGroupManager);
    void togglePolygonFillMode();
    void processInput();
    int initGLFWWindow();
};


#endif // GLWINDOW_HPP
