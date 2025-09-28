// This will be used to draw a windows with openGL


#include </home/dhurianvitoldas/Programming/myProject/src/include/glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include </home/dhurianvitoldas/Programming/myProject/src/include/auxOpenGL/AuxFunctions.h>   



const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
    "}\n\0";



const char *fragmentShaderSourceYellow = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
    "}\n\0";


int main() {
    bool init =false;
    float vertices1[] = {
        -0.5, -0.5, 0.0, // left  
         -0.1, -0.5, 0.0, // right 
         -0.1,  0.5, 0.0,  // top  right
         -0.5,  0.5, 0.0  // top  right
    };

    float vertices2[] = {
         0.5, 0.5, 0.0, // left  
         0.5, -0.5, 0.0, // right 
         0.1,  0.5, 0.0,  // top  right
         0.1,  -0.5, 0.0  // top  right
    };
    unsigned int indices1[] = {  // note that we start from 0!
        0, 1, 2,  // first Triangle
        2, 0, 3  // second Triangle
    };

    unsigned int indices2[] = {  // note that we start from 0!
        0, 1, 2,  // first Triangle
        1, 2, 3  // second Triangle
    };
    unsigned int VBO1;
    unsigned int VBO2;
    unsigned int VAO1;
    unsigned int VAO2;
    unsigned int EBO1;
    unsigned int EBO2;
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int fragmentShaderYellow;
    unsigned int yellowShaderProgram;   
    unsigned int shaderProgram;
    int success;
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
   
   
    vertexShader =  glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout<<"ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"<<infoLog<<std::endl;
    }

    fragmentShader= glCreateShader(GL_FRAGMENT_SHADER);  
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);       

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout<<"ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"<<infoLog<<std::endl;
    }   

    fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderYellow, 1, &fragmentShaderSourceYellow, NULL);
    glCompileShader(fragmentShaderYellow);
    glGetShaderiv(fragmentShaderYellow, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentShaderYellow, 512, NULL, infoLog);
        std::cout<<"ERROR::SHADERYELLOW::FRAGMENT::COMPILATION_FAILED\n"<<infoLog<<std::endl;
    }   

    shaderProgram = glCreateProgram();    
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout<<"ERROR::SHADER::PROGRAM::LINKING_FAILED\n"<<infoLog<<std::endl;
    }
    
    
    yellowShaderProgram = glCreateProgram();
    glAttachShader(yellowShaderProgram, vertexShader);
    glAttachShader(yellowShaderProgram, fragmentShaderYellow);
    glLinkProgram(yellowShaderProgram);
    glGetProgramiv(yellowShaderProgram, GL_LINK_STATUS, &success);
    
    if(!success){
        glGetProgramInfoLog(yellowShaderProgram, 512, NULL, infoLog);
        std::cout<<"ERROR::SHADERYELLOW::PROGRAM::LINKING_FAILED\n"<<infoLog<<std::endl;
    }       

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader); 
    glDeleteShader(fragmentShaderYellow); 

    glGenVertexArrays(1, &VAO1);
    glGenVertexArrays(2, &VAO2);
    glGenBuffers(1, &VBO1);
    glGenBuffers(2, &VBO2);
    glGenBuffers(1, &EBO1);
    glGenBuffers(2, &EBO2);
   
    glBindVertexArray(VAO1);


    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO1);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices1), indices1, GL_STATIC_DRAW);
    
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);   
   
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glBindVertexArray(VAO2);

    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);   
   
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


   
    // render loop
    while(!glfwWindowShouldClose(window)){
       processInput(window); 
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // we first need to set the state with the color we want
        glClear(GL_COLOR_BUFFER_BIT);    // After we use the state set to get the clearing color.
       
        

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO1);
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);   
    glUseProgram(yellowShaderProgram);
    glBindVertexArray(VAO2);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);   
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        glfwSwapBuffers(window);
        glfwPollEvents();  
        

    }

  glfwTerminate();
  return 0;
}
