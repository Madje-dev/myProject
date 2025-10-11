
#include </home/dhurian/myProgramming/myProject/src/include/glad/glad.h>
#include <GLFW/glfw3.h>
#include </home/dhurian/myProgramming/myProject/src/include/auxOpenGL/AuxFunctions.h> 
#include <stdio.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
} 

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);    

    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
       
        std::cout<<"Starting to move up"<<std::endl;
        std::cout<<"UP key is pressed"<<std::endl;  
          std::cout<<"Stopped Pressing"<<std::endl;  
    }
}