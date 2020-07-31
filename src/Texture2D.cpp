#include "Texture2D.h"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace okek
{
Texture2D::Texture2D(std::string pathtobin,std::string imagepath, unsigned int type)
{   
    this->type = type;
    std::string tmpImagePath(pathtobin);
    tmpImagePath += imagepath;
    stbi_set_flip_vertically_on_load(true); 
    this->data = stbi_load(tmpImagePath.c_str(), &this->width,
        &this->height, &this->nrChannels, 0); 
    if(data)
    {
        glGenTextures(1, &this->ID); 
    }
    else
    {
        std::cout << "Error in loading image: " + imagepath + "\n";
    }
    


}


//moves Texture to GPU
void Texture2D::MoveToGPU()
{
    glBindTexture(GL_TEXTURE_2D, this->ID); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,this->type , GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(this->data);
}
void Texture2D::use(unsigned int slot)
{
glActiveTexture(GL_TEXTURE0 + slot);
glBindTexture(GL_TEXTURE_2D, this->ID); 
}



};