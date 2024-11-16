
#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h> // include glad to get all the required OpenGL headers
  
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
  

class Shader
{
private:
    void initShader(const char * const vertexShaderSource,const char * const fragmentShaderSource);
public:
    // the program ID
    unsigned int ID;
    int vertexStatus;
    int fragmentStatus;
    int shaderLinkingStatus;
    int shaderStatus;
  
    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    // delete shader program
    ~Shader();
    // use/activate the shader
    void use(void);
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;  
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;
};
  
#endif
