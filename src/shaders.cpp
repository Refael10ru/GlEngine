#include "shaders.h"
#include "IO.h"
namespace okek
{

    Shader::Shader(std::string pathtobin,std::string vertexPath,
     std::string fragmentPath)
    {   
        this->PathToBin = pathtobin;
        // 1. retrieve the vertex/fragment source code from filePath
        std::string tmpvertexpath = pathtobin;
        std::string tmpfragmentpath = pathtobin;
        std::string vertexCode;
        std::string fragmentCode;
        tmpvertexpath += vertexPath;
        tmpfragmentpath += fragmentPath;
        //std::cout << pathtobin << "\n";
        vertexCode = IO::GetStringFile(tmpvertexpath);
        fragmentCode =IO::GetStringFile(tmpfragmentpath);
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();
        unsigned int vertex, fragment;
        int success;
        char infoLog[512];
        
        // vertex Shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        // print compile errors if any
        
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(vertex, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        };
        // similiar for Fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        // print compile errors if any
        
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(fragment, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        };
        
       
        
        // shader Program
        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);
        // print linking errors if any
        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(ID, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        
        // delete the shaders as they're linked into our program now and no longer necessary
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    };
    void Shader::use() 
    { glUseProgram(ID);}
        
    void Shader::setBool(const std::string &name, bool value) const
    { glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); }
    
    void Shader::setInt(const std::string &name, int value) const
    { glUniform1i(glGetUniformLocation(ID, name.c_str()), value); }
        
    void Shader::setFloat(const std::string &name, float value) const
    { glUniform1f(glGetUniformLocation(ID, name.c_str()), value); }

    void Shader::setfvec2(const std::string &name, float value, float value2) const
    { glUniform2f(glGetUniformLocation(ID, name.c_str()), value, value2); } 

    void Shader::setfvec3(const std::string &name, float value,float value2,float value3) const
    { glUniform3f(glGetUniformLocation(ID, name.c_str()), value, value2, value3 ); }

    void Shader::setfvec3(const std::string &name, glm::vec3 values) const
    { glUniform3f(glGetUniformLocation(ID, name.c_str()), values.x, values.y, values.z ); }

    void Shader::setfvec4(const std::string &name, float value, float value2, float value3, float value4) const
    { glUniform4f(glGetUniformLocation(ID, name.c_str()), value, value2, value3, value4); }

    void Shader::setMat4f(const std::string &name, glm::mat4& matrix)
    { glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(matrix)); }
};