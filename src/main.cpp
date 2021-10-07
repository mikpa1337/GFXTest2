// i have no skill

#include <iostream>
#include <array>
#include <chrono>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h> // GLFW

#include <glbinding/gl/gl.h>        // GL
#include <glbinding/glbinding.h>    // GL bindings

#include <glm/glm.hpp>  // glm::

#include "shaderLoader.hpp"

int RunOpenGLShit(const int&,const int&,const std::string&);

int main() {
    const int resX = 1280;
    const int resY = 720;
    const std::string title = "GLFW Works! (wtf)";
    
    std::cout << "helloings\n";


    while(RunOpenGLShit(resX, resY, title)) {
    }

    return 0;
}
int RunOpenGLShit(const int& width, const int& height, const std::string& title) {
    std::array<gl::GLfloat, 4> clearColour;
    auto startTime = std::chrono::system_clock::now();

    // hieno lambda
    // this is straight up stolen from https://dokipen.com/modern-opengl-part-2-window-creation/
    const auto windowPtr = [&](){
        if (!glfwInit()){
            std::cerr << "glfw didnt initialize\n";
            std::exit(EXIT_FAILURE);
        }

        // 4.5
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

        auto windowPtr = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!windowPtr) {
            std::cerr << "window doesnt exist\n";
            glfwTerminate();
            std::exit(EXIT_FAILURE);
        }
        glfwSetWindowPos(windowPtr, 520, 180);
        glfwMakeContextCurrent(windowPtr);
        glbinding::initialize(glfwGetProcAddress, false);
        return windowPtr;
    }();

    // The context has to exist before i can run the shader loader, otherwise the program crashes (segfault)
    ShaderLoader sl("shaders/vertex.vert", "shaders/fragment.frag");

    // run shaders
    sl.use();
    gl::GLuint vao;
    gl::glCreateVertexArrays(1, &vao);

    gl::glBindVertexArray(vao);

    // main loop
    while (!glfwWindowShouldClose(windowPtr)){
        auto currentTime = std::chrono::duration<float>(std::chrono::system_clock::now() - startTime).count();
        
        clearColour = { glm::sin(currentTime) * 0.5f + 0.5f,
                        glm::cos(currentTime) * 0.5f + 0.5f, 0.2f, 1.0f};

        gl::glClearBufferfv(gl::GL_COLOR, 0, clearColour.data());

        // draw
        gl::glDrawArrays(gl::GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(windowPtr);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

// :)