#include "Camera.h"

namespace okek
{
    Camera::Camera(glm::vec3 position,
    float yaw, float pitch, glm::vec3 worldup)
    {
        this->Front = Front;
        this->position = position;
        this->WorldUp = worldup;
        this->Yaw = yaw;
        this->Pitch = pitch;
    }
    glm::mat4 Camera::GetMatrix()
    {
        //return glm::mat4(1.0f);
        return glm::lookAt(this->position, this->position + this->Front, this->WorldUp);
    }

};