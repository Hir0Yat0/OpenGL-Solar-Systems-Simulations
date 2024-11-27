#ifndef GLWINDOW_HPP
#define GLWINDOW_HPP

#include"glad/glad.h"
#include"GLFW/glfw3.h"

#include<vector>
#include<optional>

#include "Shader.hpp"
#include "Shape.hpp"
#include "Texture.hpp"
#include "ShapeSurface.hpp"

class GLDrawWindow
{
private:
    /* data */
    GLFWwindow * window;
    const int SCR_WIDTH;
    const int SCR_HEIGHT;
    bool polygonFillMode;
    static void framebuffer_size_callback(GLFWwindow * window, int width, int height);
public:
    int initSuccess;
    GLDrawWindow(/* args */);
    ~GLDrawWindow();

    /* this makes -Werror=effc++ compiles for GLFWwindow * window; */
    /* https://stackoverflow.com/a/53892135 */

    GLDrawWindow(const GLDrawWindow&) = delete;              // copy ctor
    GLDrawWindow(GLDrawWindow&&) = delete;                   // move ctor
    GLDrawWindow& operator=(const GLDrawWindow&) = delete;   // copy assignment
    GLDrawWindow& operator=(GLDrawWindow&&) = delete;        // move assignment


    int drawWindow(Shader &shaderProgram, Shape & shape,const std::optional<Texture> & texture);
    int drawWindow(Shader &shaderProgram, std::vector<Shape> & shapes,const std::optional<Texture> & texture);
    // int drawWindow(Shader &shaderProgram, std::vector<ShapeSurface> & shapeSurfaces)    ;
    void togglePolygonFillMode();
    void processInput();
    int initGLFWWindow();
};


#endif // GLWINDOW_HPP
