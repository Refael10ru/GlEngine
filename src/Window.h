#ifndef _WINDOW_
#define _WINDOW_

#include <GLFW/glfw3.h> // GLFW helper library
#include <string>
#include "Camera.h"

namespace okek
{
    class Window
    {
friend class GLFWwindow;
public:
    Window(std::string PathToBin, Camera* Player,int width = 680,
    int height = 480, int mousesensitivity = 1.0f, float fov = 65.0f);

    void InputHandle();

    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
    void mouseInput(double xpos, double ypos);

    static void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);
    void SizeChanged(GLFWwindow* window, int width, int height);

    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    void scroll(double xoffset, double yoffset);


    void ProcessMouseMovement(float xoffset, float yoffset);

    inline GLFWwindow* GetWindow() { return window; }
    inline std::string GetPath() { return PathToBin; }
//protected:

    GLFWwindow* window;

    Camera* player;

    float Width;
    float Height;

    float deltatime;
    double lastframe;

    float FOV;
    float MouseY;
    float MouseX;
    float MouseSensitivity;
    bool first;

    std::string PathToBin;
    };
};


#endif