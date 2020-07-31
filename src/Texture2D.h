#ifndef _okekTEXTURE_
#define _okekTEXTURE_

#include <GL/glew.h>


#include <string>

namespace okek
{
    class Texture2D
    {
public:
    Texture2D(std::string pathtobin,std::string ImagePath);
    
    void MoveToGPU();

    void use();

protected:

    unsigned char* data;  

    unsigned int ID;

    int width;

    int height;

    int nrChannels;
    };
};

#endif