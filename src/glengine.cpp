#include "glengine.h"

main() 
{
}

namespace GLEngine
{
    void Window::SwapBuffer()
    {
        glfwSwapBuffers(this->GLEwindow);
    }
}