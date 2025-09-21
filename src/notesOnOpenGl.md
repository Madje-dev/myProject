# How does OpenGL Works
# OpenGL is a state machine.
The state of OpenGL is normally called OpenGL Context.
We usually change the state by:
1. setting up some options
2. Manipulating some buffers and finally,
3. render the current context

When we want to draw lines instead of triangles we change the state of OpenGL by changing the context of some variables that set how OpenGL should draw. when we change the context by telling to draw lines then the next drawing commands will be to draw lines instead of triangles.

# Objects

An object represents a subset of of OpenGL states.

``` 
// create object
unsigned int objectId = 0;
glGenObject(1, &objectId);
// bind/assign object to context
glBindObject(GL_WINDOW_TARGET, objectId);
// set options of object currently bound to GL_WINDOW_TARGET
glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_WIDTH,  800);
glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_HEIGHT, 600);
// set context target back to default
glBindObject(GL_WINDOW_TARGET, 0);

```
# Notes
One thing is the window and another is the viewport. 
If the window size changes we need to recreate the viewport. 
We allow to have a resizebale window with the following command 
``` 
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

```
And to have a resizeble viewport we need the following:
```  
glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
} 

```  