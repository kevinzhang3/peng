#include <iostream>
#include <unistd.h>
#include <Vec2.h>
#include <Body.h>
#include <Util.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#define NUM_BODIES 1
#define TIME_LIM   5

Body bodies[NUM_BODIES];

void framebuffer_size_callback(GLFWwindow*, int width, int height) {
    glViewport(0, 0, width, height);
}

int main(void) {
    std::cout << "Init window...\n";

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow *window = glfwCreateWindow(800, 600, "Simulation", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to init GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, 800, 600);
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // render loop
    
    // square
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
        0.5f, 0.5f, 0.0f
    };

    // vertex buffer object
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    // bind VBO to buffer 
    // (any calls on buffer are done on the currently bound buffer)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    // copy our vertices into the bound buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    

    
    while(!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    
        //draw  
    }

    glfwTerminate();
    return 0;
}
