#include<iostream>
#include<stdlib.h>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Utils.hpp"

#include "Tester.hpp"
#include "TestSphereRender.hpp"

int main(){
    
    std::cout << "Hello Worlds!" << "\n";
    
    auto tester = TestSphereRender();

    int exitcode = tester.runTest();

    DBGEXPR(exitcode);

    return exitcode;
}
