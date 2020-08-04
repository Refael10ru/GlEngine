#ifndef _SHADERS_
#define _SHADERS_

#include <string>
#include "typedef.h"
#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <iostream>

  
namespace okek
{
    class Shader
    {
    public:
        // the program ID
        unsigned int ID;
        // constructor reads and builds the shader
        Shader(std::string pathToBin,std::string vertexPath, std::string fragmentPath);
        // use/activate the shader
        void use();
        // utility uniform functions
        void setBool(const std::string &name, bool value) const;  
        void setInt(const std::string &name, int value) const;   
        void setFloat(const std::string &name, float value) const;
        void setVec2(const std::string &name, float value, float value2) const;

        void setVec3(const std::string &name, float value, float value2, float value3) const;
        void setVec3(const std::string &name, glm::vec3 values) const;
        
        void setVec4(const std::string &name, float value, float value2, float value3, float value4) const;

        void setMat4(const std::string &name, glm::mat4& matrix);
    protected:
        std::string PathToBin;
    };

};

#endif



