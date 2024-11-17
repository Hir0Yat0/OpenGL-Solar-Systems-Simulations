#include "GLDrawWindow.hpp"
#include <chrono>

GLDrawWindow::GLDrawWindow(/* args */)
: SCR_WIDTH{800}, SCR_HEIGHT{600}, polygonFillMode{true}, initSuccess{0}
{
    this->initSuccess = this->initGLFWWindow() == 0;
}

GLDrawWindow::~GLDrawWindow()
{
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}

void GLDrawWindow::togglePolygonFillMode(){
    if (this->polygonFillMode){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    this->polygonFillMode = !this->polygonFillMode;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void GLDrawWindow::processInput()
{
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(this->window, true);
    }
    if (glfwGetKey(this->window, GLFW_KEY_SPACE) == GLFW_PRESS){
        this->togglePolygonFillMode();
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void GLDrawWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

int GLDrawWindow::initGLFWWindow(){
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // glfw window creation
    // --------------------
    this->window = glfwCreateWindow(this->SCR_WIDTH, this->SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (this->window == NULL)
    {
        std::cerr << "Failed to create GLFW window" << "\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(this->window);
    glfwSetFramebufferSizeCallback(this->window, this->framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << "\n";
        glfwTerminate();
        return -1;
    }
    return 0;
}

int GLDrawWindow::drawWindow(Shader &shaderProgram, Shape & shape,const std::optional<Texture> & texture){    

    glEnable(GL_DEPTH_TEST);

    std::cerr << "Starting Rendering!" << "\n";

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    const auto startTime = std::chrono::system_clock::now();

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        // std::cerr << "Processing Input" << "\n";
        // processInput(window);
        this->processInput();

        // render
        // ------
        // std::cerr << "Clearing Color" << "\n";
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // std::cerr << "Clearing Color" << "\n";
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.use();
        shaderProgram.setFloat("time",std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() / 1000.0);
        
        if (texture.has_value()){
            texture.value().use();
        }
        shape.use(); 
        shape.draw();
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        // std::cout << "Swapping Buffers" << std::endl;
        glfwSwapBuffers(window);
        // std::cout << "Polling Events" << std::endl;
        glfwPollEvents();
    }

    std::cerr << "Done Rendering!" << "\n";

    /* Clean Ups Done In Deconstructors */
    
    return 0;
}

int GLDrawWindow::drawWindow(Shader &shaderProgram, std::vector<Shape> & shapes,const std::optional<Texture> & texture){    

    glEnable(GL_DEPTH_TEST);

    std::cerr << "Starting Rendering!" << "\n";

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    const auto startTime = std::chrono::system_clock::now();

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        // std::cerr << "Processing Input" << "\n";
        // processInput(window);
        this->processInput();

        // render
        // ------
        // std::cerr << "Clearing Color" << "\n";
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // std::cerr << "Clearing Color" << "\n";
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // std::cerr << "Using Shader Program" << "\n";
        shaderProgram.use();
        shaderProgram.setFloat("time",std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() / 1000.0);
        
        if (texture.has_value()){
            texture.value().use();
        }
        for (auto &shape : shapes){
            shape.use();
            shape.draw();
        }
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        // std::cerr << "Swapping Buffers" << "\n";
        glfwSwapBuffers(window);
        // std::cerr << "Polling Events" << "\n";
        glfwPollEvents();
    }

    std::cerr << "Done Rendering!" << "\n";

    /* Clean Ups Done In Deconstructors */

    return 0;
}

int GLDrawWindow::drawWindow(Shader &shaderProgram, std::vector<ShapeTextured> & ShapeTextureds){    

    glEnable(GL_DEPTH_TEST);

    std::cerr << "Starting Rendering!" << "\n";

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    const auto startTime = std::chrono::system_clock::now();

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        // std::cerr << "Processing Input" << "\n";
        // processInput(window);
        this->processInput();

        // render
        // ------
        // std::cerr << "Clearing Color" << "\n";
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // std::cerr << "Clearing Color" << "\n";
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.use();
        shaderProgram.setFloat("time",std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() / 1000.0);
        for (auto &ShapeTextured : ShapeTextureds){
            // ShapeTextured.texture.use();
            // ShapeTextured.shape.use();
            // ShapeTextured.shape.draw();
            ShapeTextured.use();
            ShapeTextured.draw();
        }
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        // std::cerr << "Swapping Buffers" << "\n";
        glfwSwapBuffers(window);
        // std::cerr << "Polling Events" << "\n";
        glfwPollEvents();
    }

    std::cerr << "Done Rendering!" << "\n";

    /* Clean Ups Done In Deconstructors */

    return 0;
}
