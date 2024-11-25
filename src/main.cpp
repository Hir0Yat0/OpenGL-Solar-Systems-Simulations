#include<iostream>
#include<stdlib.h>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "TestSpherePreview.hpp"
#include "TestRenderGroup.hpp"

int main(){
    
    std::cout << "Hello Worlds!" << "\n";
    
    // auto test = TestSpherePreview();
    // return test.testDrawSphere();
    // return TestRenderGroup().testRenderGroup();

    // TestRenderGroup().testRenderGroup();
    int exitcode = TestRenderGroup::test();
    return exitcode;

    // return 0;
}
