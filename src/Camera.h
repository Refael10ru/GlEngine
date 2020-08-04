#ifndef _CAMERA_
#define _CAMERA_

#include "typedef.h"
#include "inputs.cpp"

namespace okek 
{

class Camera
{

public:

    Camera(glm::vec3 position = glm::vec3(0,0,-4),
    float yaw = 0.0f, float pitch = 0, glm::vec3 WorldUp = glm::vec3(0,1,0));

    glm::mat4 GetMatrix();

//protected:
friend class Window;
    glm::vec3 Up;
    glm::vec3 position;
    glm::vec3 Front;
    glm::vec3 Right;
    glm::vec3 WorldUp;

    float Yaw;
    float Pitch;
    bool constrainPitch;
private:
    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors()
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
};


#endif