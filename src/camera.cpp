#include "camera.h"

namespace okek
{
    camera::camera(glm::vec3 position,
    glm::vec3 rotation, glm::vec3 up)
    {
        this->rotation = rotation;
        this->position = position;
        this->up = up;
    }
    glm::mat4 camera::GetMatrix()
    {
        //return glm::mat4(1.0f);
        return glm::lookAt(this->position, this->position + rotation, up);
    }

};