#include "window.h"

// constructors to be forward declared.

void GLEngine::Window::FrameBufferSizeCallBack(GLFWwindow* window, int height, int width)
{
	glViewport(0, 0, height, width); 
}

void GLEngine::Window::Close()	
{
	glfwSetWindowShouldClose(this->GLWindow, true);
}	

void GLEngine::Window::ProcessInput()
{
	if (glfwGetKey(this->GLWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		this->Close(); 
}
