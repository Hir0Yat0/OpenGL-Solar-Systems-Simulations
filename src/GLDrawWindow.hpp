#ifndef GLWINDOW_HPP
#define GLWINDOW_HPP

#include"glad/glad.h"
#include"GLFW/glfw3.h"

#include<vector>
#include<optional>

#include "Shader.hpp"
#include "Shape.hpp"
#include "Texture.hpp"
#include "ShapeTextured.hpp"

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
    int drawWindow(Shader &shaderProgram, std::vector<ShapeTextured> & ShapeTextureds)    ;
    void togglePolygonFillMode();
    void processInput();
    int initGLFWWindow();
};


#endif // GLWINDOW_HPP
