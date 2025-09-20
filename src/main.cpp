// This will be used to draw a windows with openGL


#include </home/dhurianvitoldas/Programming/myProject/src/include/glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>



int main() {
    bool init =false;
    std::cout << "GLFW init status: " << init << std::endl;
    init = glfwInit();
    std::cout << "GLFW initialized successfully" << std::endl;
    std::cout << "GLFW init status: " << init << std::endl;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE); // for macOS
    GLFWwindow* window = glfwCreateWindow(800,600, "LearnOpenGL", NULL, NULL);
    if(window == NULL){    
    std::cout<< "Failed to create GLFW window" <<std::endl ;
     
    return 0;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout<<"Failed to initialize GLAD" <<std::endl;
    }

    glViewport(0,0,800,600);
    //glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while(!glfwWindowShouldClose(window)){
        glfwSwapBuffers(window);
        glfwPollEvents();   
    }

  glfwTerminate();
  return 0;
}
