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
An iteration of the while loop that is gows through the 
``` 
while(!glfwWindowShouldClose(window)){
        processInput(window); 
        glfwSwapBuffers(window);
        glfwPollEvents();  
        

    }

``` 
is a frame.

# Rendering
Everything we want to render needs to be part of the while loop mentioned aboved.

with glClear we can clear three different buffers:
1. GL_COLOR_BUFFER_BIT
2. GL_DEPTH_BUFFER_BIT
3. GL_STENCIL_BUFFER_BIT

[glClear help](https://registry.khronos.org/OpenGL-Refpages/gl2.1/xhtml/glClear.xml)

# Hello Triangle

The graphics pipeline transforms the 3d Coordinates into 2d pixels to show on the screen.
## Graphics pipeline
The Graphics Pipeline it is composed by two parts, the first part that transforms the 3d coordinate into 2d coordinates and the second part that colors the 2d coordinate.

## Shaders
The Shaders are small programs that run in the on the GPU.
these small programs are very specialized and transform each of the 3d coordinates into a 2d pixel.

We can also right our own shaders and are written on OpenGL Shading Language. (GLSL)
The small programs are called:
1. Vertex Shader
2. Geometry Shader
3. Shape Assembly
4. Rasterization 
5. Fragment Shader
6. Tests and Blending

In order to help OpenGL we should say what we are trying to render and those are called primitives. 
That help is called a hint. Examples of primitives are:
1. GL_POINTS
2. GL_TRIANGLES
3. GL_LINE_STRIP

The first part of the pipeline is the vertex shader and takes as input a single vertex.

A fragment in OpenGL is all the information needs to OpenGL render a single pixel.

# Drawing a triangle
First we create the three vertices, then those vertices are passed to the vertex shader. It creates a memory on the GPU and it stores the vertices.
We manage the memory utilizing the Vertex Buffer Objects (VBO)






