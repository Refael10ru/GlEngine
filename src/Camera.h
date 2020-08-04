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
    void updateCameraVectors();


};
};


#endif