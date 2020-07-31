#ifndef _okekTEXTURE_
#define _okekTEXTURE_

#include <GL/glew.h>


#include <string>

namespace okek
{
    class Texture2D
    {
public:
    Texture2D(std::string pathtobin,std::string ImagePath, unsigned int type);
    
    void MoveToGPU();

    void use(unsigned int slot);

protected:

    //pointer to data on host ram
    unsigned char* data;  

    //handle to object on GPU
    unsigned int ID;

    //tells openGl how to interpret the texture
    unsigned int type;

    //width of texture
    int width;

    //height of texture
    int height;

    int nrChannels;
    };
};

#endif