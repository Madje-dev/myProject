// This will be used to draw a windows with openGL

#include <stdio.h>

#include <GLFW/glfw3.h>

int main ()
{
    GLFWwindow* window;
    GLFWwindow* secondWindow;
    /* Initialize the library */
    if (!glfwInit()){

        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }
            /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    secondWindow = glfwCreateWindow(640, 480, "Hello World second window", NULL, window);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    if (!secondWindow)
          
    {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */


    
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glfwMakeContextCurrent(window);
    
            /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        
    
        glfwMakeContextCurrent(secondWindow);
        glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(secondWindow);
        glfwPollEvents();
    
    
    }

    glfwTerminate();
    return 0;


}