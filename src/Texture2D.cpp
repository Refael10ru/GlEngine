#include "Texture2D.h"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace okek
{
Texture2D::Texture2D(std::string pathtobin,std::string imagepath)
{
    std::string tmpImagePath(pathtobin);
    tmpImagePath += imagepath;
    this->data = stbi_load(tmpImagePath.c_str(), &this->width,
        &this->height, &this->nrChannels, 0); 
    if(data)
    {
        glGenTextures(1, &this->ID); 
    }
    else
    {
        std::cout << "Error in loading image";
    }
    


}



void Texture2D::MoveToGPU()
{
    glBindTexture(GL_TEXTURE_2D, this->ID); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(this->data);
}
void Texture2D::use()
{
glBindTexture(GL_TEXTURE_2D, this->ID); 
}



};