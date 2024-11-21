#include<iostream>
#include<stdlib.h>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "TestSpherePreview.hpp"

int main(){
    
    std::cout << "Hello Worlds!" << "\n";
    
    auto test = TestSpherePreview();
    return test.testDrawSphere();

    // return 0;
}
