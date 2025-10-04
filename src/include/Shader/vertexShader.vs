    #version 330 core
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aColor;
    
    
    uniform float horizontalOffset;
    out vec4 outputPosition;
    void main()
    {
   
    gl_Position = vec4(aPos.x+horizontalOffset, aPos.y, aPos.z, 1.0);
    
    outputPosition=vec4(gl_Position.x, gl_Position.y, gl_Position.z, 1.0);
    };