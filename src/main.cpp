// This will be used to draw a windows with openGL


#include </home/dhurian/myProgramming/myProject/src/include/glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include </home/dhurian/myProgramming/myProject/src/include/Shader/shader.h>
#include </home/dhurian/myProgramming/myProject/src/src/stb_image.h>
#include </home/dhurian/myProgramming/myProject/src/include/auxOpenGL/AuxFunctions.h>




int main() {
    bool init =false;

float vertices[] = {
    // positions          // colors           // texture coords
     0.5,  0.5, -1.0,   1.0, 0.0, 0.0,   1.0, 1.0,   // top right
     0.5, -0.5, 0.0,   0.0, 1.0, 0.0,   1.0, 0.0,   // bottom right
    -0.5, -0.5, 0.0,   0.0, 0.0, 1.0,   0.0, 0.0,   // bottom left
    -0.5,  0.5, 1.0,   1.0, 1.0, 0.0,   0.0, 1.0    // top left 
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
    int width, height, nrChannels;
    unsigned char *data;
    unsigned int texture;
    
       unsigned int indices[] = {  
        0, 1, 3, // first triangle
         1, 2, 3 // second triangle
    };
    

    

    
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
   
   
    
    Shader ourShader("/home/dhurian/myProgramming/myProject/src/include/Shader/vertexShader.vs",
                     "/home/dhurian/myProgramming/myProject/src/include/Shader/fragmentShader.fs");
                   


    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);

    
    
 
    glBindVertexArray(VAO); 

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
 

    //position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); 
    //color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1); 

    //texturemap attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2); 
    
        
    glGenTextures(1, &texture);

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    data = stbi_load("/home/dhurian/myProgramming/myProject/src/src/container.jpg",&width, &height, &nrChannels,0);

    if(data){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        std::cout<<"Failed loading data"<< std::endl;
    }
    
    stbi_image_free(data);


   
   
   
   

    // render loop
    while(!glfwWindowShouldClose(window)){
       processInput(window, moveTriangle); 
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // we first need to set the state with the color we want
        glClear(GL_COLOR_BUFFER_BIT);    // After we use the state set to get the clearing color.
        ourShader.use(); 
        glBindTexture(GL_TEXTURE_2D, texture);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);   
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();  
        

    }

  glfwTerminate();
  return 0;
}
