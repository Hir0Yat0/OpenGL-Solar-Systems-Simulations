cmake_minimum_required(VERSION 3.18)

project(SSS VERSION 0.1.0 DESCRIPTION "OpenGL Solar Systems Simulations")

add_executable(sss src/main.cpp src/glad.c)

target_include_directories(sss PUBLIC include)
target_link_directories(sss PUBLIC lib)
# target_link_libraries(sss PRIVATE glfw3)
# target_link_libraries(sss PRIVATE libglfw3dll)

add_custom_command(
    TARGET sss POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/glfw3.dll
        $<TARGET_FILE_DIR:sss>
)
