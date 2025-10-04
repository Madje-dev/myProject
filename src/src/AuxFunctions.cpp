
#include </home/dhurianvitoldas/Programming/myProject/src/include/glad/glad.h>
#include <GLFW/glfw3.h>
#include </home/dhurianvitoldas/Programming/myProject/src/include/auxOpenGL/AuxFunctions.h> 
#include <stdio.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
} 

void processInput(GLFWwindow *window, float &increment){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);    

    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
       
        std::cout<<"Starting to move up"<<std::endl;
        std::cout<<"UP key is pressed"<<std::endl;  
          std::cout<<"Stopped Pressing"<<std::endl;  
          increment = increment+0.01;
          std::cout<< increment<< std::endl;
    }
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
       
        std::cout<<"Starting to move up"<<std::endl;
        std::cout<<"UP key is pressed"<<std::endl;  
          std::cout<<"Stopped Pressing"<<std::endl;  
          increment = increment-0.01;
          std::cout<< increment<< std::endl;
    }





}