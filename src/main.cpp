#include <iostream>
#include <cstdlib>  // std::exit
#include <GLFW/glfw3.h>


int main() {
    std::cout << "hello, world\nalso hello cmake\n" << std::endl;

    GLFWwindow *window = nullptr;
    int width = 640;
    int height = 480;

    if (!glfwInit()){
        std::cerr << "lol no glfw init 4 u\n";
        std::exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_DEPTH_BITS, 16);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

    window = glfwCreateWindow(width, height, "test", nullptr, nullptr);
    if (!window){
        std::cerr << "lol no window 4 u (VITTU)" << std::endl;
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }
    
    while (!glfwWindowShouldClose(window)){
        // draw


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // mr kill
    glfwTerminate();
    return 0;
}