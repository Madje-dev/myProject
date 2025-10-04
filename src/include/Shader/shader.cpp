#include "shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath){

    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    
    }
catch(std::ifstream::failure e){
    std::cout<< "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ"<< std::endl;

}
const char* vShaderCode= vertexCode.c_str();
const char* fShaderCode= fragmentCode.c_str();
   
vertex = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vertex,1, &vShaderCode, NULL);
glCompileShader(vertex);

glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
if(!success){
    glGetShaderInfoLog(vertex, 512, NULL, infoLog);
    std::cout<< "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"<<std::endl;
};

fragment = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragment,1, &fShaderCode, NULL);
glCompileShader(fragment);
glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
if(!success){
    glGetShaderInfoLog(fragment, 512, NULL, infoLog);
    std::cout<< "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"<<std::endl;
};





}