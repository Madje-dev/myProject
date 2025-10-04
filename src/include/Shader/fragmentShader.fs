    #version 330 core
    
    in vec4 outputPosition;  
    out vec4 FragColor;
    void main()
    {
       FragColor = vec4(outputPosition.x, outputPosition.y, outputPosition.z,1.0);
    };
