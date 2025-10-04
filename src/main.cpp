// This will be used to draw a windows with openGL


#include </home/dhurianvitoldas/Programming/myProject/src/include/glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include </home/dhurianvitoldas/Programming/myProject/src/include/auxOpenGL/AuxFunctions.h>   
#include </home/dhurianvitoldas/Programming/myProject/src/include/Shader/shader.h>





int main() {
    bool init =false;
    float vertices[] = {
        -0.5, -0.5, 0.0,  1.0f, 0.0f, 0.0f,// left  
         0.5, -0.5, 0.0,  0.0f, 1.0f, 0.0f,// right 
         0.0,  0.5, 0.0,  0.0f, 0.0f, 1.0f// top   
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 2  // first Triangle
    };
    float texCoordinates[]={
        0.0, 0.0,
        1.0, 0.0,
        0.5, 1.0
    };
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;
    float timeValue;
    float greenValue;
    int vertexColorLocation;
    int success;
    float moveTriangle;
    char infoLog[512];



    
    std::cout << "GLFW init status: " << init << std::endl;
    init = glfwInit();
    std::cout << "GLFW initialized successfully" << std::endl;
    std::cout << "GLFW init status: " << init << std::endl ;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE); // for macOS
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
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
   
   
    
    Shader ourShader("/home/dhurianvitoldas/Programming/myProject/src/include/Shader/vertexShader.vs",
         "/home/dhurianvitoldas/Programming/myProject/src/include/Shader/fragmentShader.fs");


    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);

 
    glBindVertexArray(VAO); 

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); 
    //color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1); 
    
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        



   
   
   
   
   
    moveTriangle=0.0;   
    // render loop
    while(!glfwWindowShouldClose(window)){
       processInput(window, moveTriangle); 
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // we first need to set the state with the color we want
        glClear(GL_COLOR_BUFFER_BIT);    // After we use the state set to get the clearing color.
        ourShader.use(); 
        int vertexLocation = glGetUniformLocation(ourShader.ID, "horizontalOffset");
        glUniform1f(vertexLocation, moveTriangle);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0, 3);   
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();  
        

    }

  glfwTerminate();
  return 0;
}
