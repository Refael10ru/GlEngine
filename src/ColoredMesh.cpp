#include "ColoredMesh.h"
namespace okek
{

    void ColoredMesh::debug1(int i)
    { std::cout << this->VBO[i].position.x << " : " << 
    this->VBO[i].position.y << " : " << this->VBO[i].position.z<< "\n"; }

};