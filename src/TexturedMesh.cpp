

#include <iostream>
#include "TexturedMesh.h"
namespace okek
{
    void TexturedMesh::PrintVBO(int i)
    {
        std::cout << this->VBO[i].position.x << this->VBO[i].position.y << this->VBO[i].position.z;
    }
};