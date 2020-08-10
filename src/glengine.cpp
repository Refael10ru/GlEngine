#include "glengine.h"

namespace GLEngine
{
    void Window::SwapBuffers()
    {
        glfwSwapBuffers(this->GLEwindow);
    }

	void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height) 
    {
        glViewport(0, 0, width, height);
    }
}
