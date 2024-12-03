#include<iostream>
#include<stdlib.h>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Utils.hpp"

#include "Tester.hpp"
#include "TestSphereRender.hpp"
#include "TestRenderGroup3D.hpp"

int main(){
    
    std::cout << "Hello Worlds!" << "\n";
    
    auto tester = TestRenderGroup3D();

    int exitcode = tester.runTest();

    DBGEXPR(exitcode);

    return exitcode;
}
