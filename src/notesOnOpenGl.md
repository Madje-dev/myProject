# How does OpenGL Works
# OpenGL is a state machine.
The state of OpenGL is normally called OpenGL Context.
We usually change the state by:
1. setting up some options
2. Manipulating some buffers and finally,
3. render the current context

When we want to draw lines instead of triangles we change the state of OpenGL by changing the context of some variables that set how OpenGL should draw. when we change the context by telling to draw lines then the next drawing commands will be to draw lines instead of triangles.

# Objects
