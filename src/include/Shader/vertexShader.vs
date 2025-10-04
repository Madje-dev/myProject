    #version 330 core
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aColor;
    out vec3 ourColor;
    void main()
    {
    vec3 adjustedaPos = -1*aPos.xyz;
    
    gl_Position = vec4(adjustedaPos, 1.0);
    ourColor= aColor;
    };