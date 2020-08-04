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

    void Camera::updateCameraVectors()
    {
        // calculate the new Front vector
        glm::vec3 front;
        auto tmp = cos(glm::radians(Pitch/10));
        front.x = sin(glm::radians(Yaw/10)) * tmp;
        front.y = sin(glm::radians(Pitch/10));
        front.z = -cos(glm::radians(Yaw/10)) * tmp;
        Front = glm::normalize(front);
        // also re-calculate the Right and Up vector
        Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Up    = glm::normalize(glm::cross(Right, Front));
    }

};