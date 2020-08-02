#ifndef _CAMERA_
#define _CAMERA_

#include "typedef.h"
#include "inputs.cpp"

namespace okek 
{

class camera
{
public:

    camera(glm::vec3 position = glm::vec3(0,0,-4),
    glm::vec3 rotation = glm::vec3(0,0,-1), glm::vec3 up = glm::vec3(0,1,0));

    glm::mat4 GetMatrix();

//protected:
    
    glm::vec3 position;
    
    glm::vec3 rotation;

    glm::vec3 up;

};
};


#endif