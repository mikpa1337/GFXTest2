cmake_minimum_required(VERSION 3.13)

project(GFXTest2)

# add_subdirectory()
add_subdirectory(external/glfw)
add_subdirectory(external/glm)
add_subdirectory(external/glbinding)

add_executable(${PROJECT_NAME} src/main.cpp src/shaderLoader.cpp)

# Notice for idiots like me:
# these need to be after the add_executable()
# otherwise cmake doesnt build
target_include_directories (${PROJECT_NAME}
    PUBLIC external/glfw/include
    PUBLIC external/glm/glm
    PUBLIC external/glbinding/source/glbinding/include
)


target_link_directories (${PROJECT_NAME}
    PUBLIC external/glfw/src
    PUBLIC external/glm/glm
    PBULIC external/glbinding
)

target_link_libraries(${PROJECT_NAME} glfw glm glbinding)