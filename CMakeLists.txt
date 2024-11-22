cmake_minimum_required(VERSION 3.18)

project(SSS VERSION 0.1.0 DESCRIPTION "OpenGL Solar Systems Simulations" LANGUAGES CXX C)

# find_library(LIBGLFW3DLL )

add_executable(sss 
            src/main.cpp 
            src/glad.c
            src/GLDrawWindow.cpp
            src/GLDrawWindow.hpp
            src/Shader.cpp
            src/Shader.hpp
            src/Shape.cpp
            src/Shape.hpp
            src/ShapeTextured.cpp
            src/ShapeTextured.hpp
            src/ShapeNoTexture.cpp
            src/ShapeNoTexture.hpp
            src/stb_image.h
            src/Texture.cpp
            src/Texture.hpp
            src/TextureLoader.cpp
            src/TextureLoader.hpp
            src/DrawableObject.cpp
            src/DrawableObject.hpp
            src/DrawableUnit.cpp
            src/DrawableUnit.hpp
            src/SphereFactory.cpp
            src/SphereFactory.hpp
            src/ShapePresets.cpp
            src/ShapePresets.hpp
            src/TestSpherePreview.cpp
            src/TestSpherePreview.hpp
            src/Vec3D.hpp
            src/Utils.hpp
            src/ObjectND.hpp
            src/ObjectND.cpp
            src/RenderGroup.hpp
            src/RenderGroup.cpp
            src/RenderGroupManager.hpp
            src/RenderGroupManager.cpp

)

# target_compile_options(sss PRIVATE -Werror -Wextra -g -std=c++23)
target_compile_options(sss PRIVATE -Werror -Wextra -g)
target_compile_features(sss PUBLIC cxx_std_23)

target_include_directories(sss PUBLIC include)
# target_include_directories(sss PUBLIC lib)
target_link_directories(sss PUBLIC lib)
# target_link_libraries(sss PRIVATE glfw3)
target_link_libraries(sss PUBLIC -lglfw3dll)
# target_link_libraries(sss PUBLIC -Iinclude -Llib)
add_custom_command(
    TARGET sss POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/glfw3.dll
        $<TARGET_FILE_DIR:sss>
)
