#ifndef _okekTEXTURE_
#define _okekTEXTURE_

#include <string>

#include <GL/glew.h>


namespace okek
{
    class Texture2D
    {
public:

    Texture2D( std::string pathtobin, std::string ImagePath, unsigned int type);
    
    void MoveToGPU();

    void use(unsigned int slot);

    unsigned int ID;
    
protected:

    //pointer to data on host ram
    unsigned char* data;  

    //handle to object on GPU
    

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