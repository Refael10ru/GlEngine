#ifndef _SHADERS_
#define _SHADERS_

#include <string>
#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library
#include <iostream>
#include "typedef.h"
  
namespace okek
{
    class Shader
    {
    public:
        // the program ID
        unsigned int ID;
        // constructor reads and builds the shader
        Shader(const char* pathToBin,const char* vertexPath, const char* fragmentPath);
        // use/activate the shader
        void use();
        // utility uniform functions
        void setBool(const std::string &name, bool value) const;  
        void setInt(const std::string &name, int value) const;   
        void setFloat(const std::string &name, float value) const;
        void setfvec2(const std::string &name, float value, float value2) const;

        void setfvec3(const std::string &name, float value, float value2, float value3) const;
        void setfvec3(const std::string &name, Cvec3 values) const;
        
        void setfvec4(const std::string &name, float value, float value2, float value3, float value4) const;
    protected:
        std::string PathToBin;
    };

};

#endif



